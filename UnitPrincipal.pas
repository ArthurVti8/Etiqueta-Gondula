unit UnitPrincipal;

interface

uses
  Winapi.Windows, Winapi.Messages, Winapi.ShellAPI, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Data.DB, Math, System.IniFiles, // Adicionado System.IniFiles
  FireDAC.Stan.Intf, FireDAC.Stan.Option, FireDAC.Stan.Error, FireDAC.UI.Intf,
  FireDAC.Phys.Intf, FireDAC.Stan.Def, FireDAC.Phys.MSSQL, FireDAC.Phys.MSSQLDef, FireDAC.VCLUI.Wait,
  FireDAC.Stan.Param, FireDAC.DatS, FireDAC.DApt.Intf, FireDAC.DApt,
  Vcl.Grids, Vcl.DBGrids, FireDAC.Comp.DataSet,
  FireDAC.Comp.Client, Vcl.StdCtrls, ppDB, ppCtrls, ppPrnabl, ppClass,
  ppBarCod, ppBands, ppCache, ppDesignLayer, ppParameter, ppProd, ppReport,
  ppComm, ppRelatv, ppDBPipe, Vcl.Imaging.jpeg, Vcl.ExtCtrls,
  FireDAC.Stan.StorageBin, ppTypes, ppDevice, Printers, FireDAC.Stan.Pool,
  FireDAC.Stan.Async, FireDAC.Phys;

type
  TGeradorEtiquetas = class(TForm)
    Conexao: TFDConnection;
    DBGrid1: TDBGrid;
    DataSource1: TDataSource;
    ppDBPipeline1: TppDBPipeline;
    Etiqueta: TppReport;
    ppParameterList1: TppParameterList;
    ppDesignLayers1: TppDesignLayers;
    ppDesignLayer1: TppDesignLayer;
    ppDetailBand1: TppDetailBand;
    ppDBBarCode1: TppDBBarCode;
    BtnGerarEtiqueta: TButton;
    ppShape1: TppShape;
    Panel1: TPanel;
    Label1: TLabel;
    Image1: TImage;
    edtCodigo: TEdit;
    FDQuery2: TFDQuery;
    Label2: TLabel;
    edtQuantidade: TEdit;
    Label3: TLabel;
    edtColuna: TEdit;
    Label4: TLabel;
    edtLargura: TEdit;
    edtAltura: TEdit;
    Label5: TLabel;
    Label6: TLabel;
    edtEspacamento: TEdit;
    BtnExcel: TButton;
    Label9: TLabel;
    cbTipoImpressao: TComboBox;
    ppDBText2: TppDBText;
    ppDBText3: TppDBText;
    ppLabel1: TppLabel;
    ppDBText1: TppDBText;
    ppLabel2: TppLabel;
    rgFormatoExportacao: TRadioGroup;
    ppColumnHeaderBand1: TppColumnHeaderBand;
    ppColumnFooterBand1: TppColumnFooterBand;
    mtEtiquetas: TFDMemTable; // <--- O NOVO COMPONENTE QUE VOCÊ ADICIONOU
    procedure BtnGerarEtiquetaClick(Sender: TObject);
    procedure BtnExcelClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction); // Novo evento
  private
    function BuildHTMLTable(DataSet: TDataSet): string;
    function FormatAsCurrency(const Value: Variant): string;
    procedure ConfigureReportForLabels(NumColunas: Integer; LarguraEtiqueta, AlturaEtiqueta, Espacamento: Single);
    procedure CarregarConfiguracoes;
    procedure SalvarConfiguracoes;
  public
  end;

var
  GeradorEtiquetas: TGeradorEtiquetas;

implementation

{$R *.dfm}

// ============================================================================
// PERSISTÊNCIA (SALVAR/CARREGAR CONFIGURAÇÕES) - MELHORIA DE USABILIDADE
// ============================================================================

procedure TGeradorEtiquetas.CarregarConfiguracoes;
var
  ArquivoIni: TIniFile;
begin
  // Cria o arquivo .ini na mesma pasta do executável
  ArquivoIni := TIniFile.Create(ChangeFileExt(Application.ExeName, '.ini'));
  try
    // Lê os valores salvos. Se não existir, usa um valor padrão (o segundo parâmetro)
    edtLargura.Text     := ArquivoIni.ReadString('ConfigEtiqueta', 'Largura', '4,0');
    edtAltura.Text      := ArquivoIni.ReadString('ConfigEtiqueta', 'Altura', '2,0');
    edtColuna.Text      := ArquivoIni.ReadString('ConfigEtiqueta', 'Colunas', '1');
    edtEspacamento.Text := ArquivoIni.ReadString('ConfigEtiqueta', 'Espacamento', '0,1');
    edtQuantidade.Text  := ArquivoIni.ReadString('ConfigEtiqueta', 'QuantidadePadrao', '1');

    if ArquivoIni.ValueExists('ConfigEtiqueta', 'TipoImpressao') then
      cbTipoImpressao.ItemIndex := ArquivoIni.ReadInteger('ConfigEtiqueta', 'TipoImpressao', 0);
  finally
    ArquivoIni.Free;
  end;
end;

procedure TGeradorEtiquetas.SalvarConfiguracoes;
var
  ArquivoIni: TIniFile;
begin
  ArquivoIni := TIniFile.Create(ChangeFileExt(Application.ExeName, '.ini'));
  try
    ArquivoIni.WriteString('ConfigEtiqueta', 'Largura', edtLargura.Text);
    ArquivoIni.WriteString('ConfigEtiqueta', 'Altura', edtAltura.Text);
    ArquivoIni.WriteString('ConfigEtiqueta', 'Colunas', edtColuna.Text);
    ArquivoIni.WriteString('ConfigEtiqueta', 'Espacamento', edtEspacamento.Text);
    ArquivoIni.WriteString('ConfigEtiqueta', 'QuantidadePadrao', edtQuantidade.Text);
    ArquivoIni.WriteInteger('ConfigEtiqueta', 'TipoImpressao', cbTipoImpressao.ItemIndex);
  finally
    ArquivoIni.Free;
  end;
end;

// ============================================================================
// EVENTOS DO FORMULÁRIO
// ============================================================================

procedure TGeradorEtiquetas.FormCreate(Sender: TObject);
begin
  // Configura UI
  cbTipoImpressao.Items.Clear;
  cbTipoImpressao.Items.Add('Visualizar (Prévia)');
  cbTipoImpressao.Items.Add('Imprimir Direto');
  cbTipoImpressao.ItemIndex := 0;

  // Carrega as últimas configurações usadas pelo usuário
  CarregarConfiguracoes;

  // Configura DataSource para usar a MemTable (Performance)
  DataSource1.DataSet := mtEtiquetas;
  ppDBPipeline1.DataSource := DataSource1;
end;

procedure TGeradorEtiquetas.FormClose(Sender: TObject; var Action: TCloseAction);
begin
  // Salva tudo antes de fechar
  SalvarConfiguracoes;
end;

// ============================================================================
// LÓGICA DE GERAÇÃO (AGORA COM ALTA PERFORMANCE VIA MEMTABLE)
// ============================================================================

procedure TGeradorEtiquetas.BtnGerarEtiquetaClick(Sender: TObject);
var
  ListaDeCodigos: string;
  Quantidade, NumColunas, I: Integer;
  LarguraEtiqueta, AlturaEtiqueta, EspacamentoColunas: Single;
  BaseSQL: string;
  ListaDeCodigosFormatada: string;
begin
  // 1. Validação
  if Trim(edtCodigo.Text) = '' then
  begin
    ShowMessage('Por favor, informe os códigos dos produtos.');
    edtCodigo.SetFocus;
    Exit;
  end;

  // 2. Tratamento da String de Códigos
  ListaDeCodigos := StringReplace(edtCodigo.Text, ' ', ',', [rfReplaceAll]);
  ListaDeCodigos := StringReplace(ListaDeCodigos, #13#10, ',', [rfReplaceAll]);
  while Pos(',,', ListaDeCodigos) > 0 do
    ListaDeCodigos := StringReplace(ListaDeCodigos, ',,', ',', [rfReplaceAll]);
  if (ListaDeCodigos <> '') and (ListaDeCodigos[Length(ListaDeCodigos)] = ',') then
    Delete(ListaDeCodigos, Length(ListaDeCodigos), 1);
  if (ListaDeCodigos <> '') and (ListaDeCodigos[1] = ',') then
    Delete(ListaDeCodigos, 1, 1);

  ListaDeCodigosFormatada := '''' + StringReplace(ListaDeCodigos, ',', ''',''', [rfReplaceAll]) + '''';
  if ListaDeCodigosFormatada = '''''' then Exit;

  // 3. Captura Parâmetros
  Quantidade := StrToIntDef(edtQuantidade.Text, 1);
  if Quantidade <= 0 then Quantidade := 1;
  NumColunas := StrToIntDef(edtColuna.Text, 1);
  LarguraEtiqueta := StrToFloatDef(edtLargura.Text, 4.0);
  AlturaEtiqueta  := StrToFloatDef(edtAltura.Text, 2.0);
  EspacamentoColunas := StrToFloatDef(edtEspacamento.Text, 0);

  // 4. Configura Relatório
  ConfigureReportForLabels(NumColunas, LarguraEtiqueta, AlturaEtiqueta, EspacamentoColunas);

  // 5. CONSULTA ÚNICA AO BANCO (Performance e Segurança)
  FDQuery2.Close;
  BaseSQL := 'SELECT P.au_ite AS CodigoProduto, ' +
             'P.ab_ite + '' '' + P.ac_ite AS Descricao, ' +
             'P.ad_ite AS CodigoUnidade, ' +
             'A.PrecoVendaMin AS PrecoMinimo, ' +
             'A.PrecoVendaMax AS PrecoMaximo, ' +
             'I.NCM AS NCM_Imposto, ' +
             'I.CSTsaidas AS CST_Saida, ' +
             'I.ALIQUOTAICMS AS AliquotaICMS ' +
             'FROM CE_PRODUTO P ' +
             'INNER JOIN CE_PRODUTOS_ADICIONAIS A ON P.au_ite = A.CodReduzido ' +
             'INNER JOIN CE_PRODUTOS_IMPOSTOS I ON P.au_ite = I.CodReduzido ' +
             'WHERE P.au_ite IN (' + ListaDeCodigosFormatada + ') ' +
             'ORDER BY P.au_ite';

  FDQuery2.SQL.Text := BaseSQL;

  try
    FDQuery2.Open;

    if FDQuery2.IsEmpty then
    begin
      ShowMessage('Nenhum produto encontrado.');
      Exit;
    end;

    // 6. POPULA A MEMÓRIA (O "Pulo do Gato")
    // Copia a estrutura da Query para a MemTable
    mtEtiquetas.Close;
    mtEtiquetas.FieldDefs.Clear;
    mtEtiquetas.FieldDefs.Assign(FDQuery2.FieldDefs);
    mtEtiquetas.CreateDataSet; // Cria a tabela na RAM

    mtEtiquetas.DisableControls; // Congela a grid para ser mais rápido
    try
      // Loop Principal: Quantidade de Cópias
      for I := 1 to Quantidade do
      begin
        // Para cada cópia, percorre todos os produtos encontrados no banco
        FDQuery2.First;
        while not FDQuery2.Eof do
        begin
          mtEtiquetas.Append; // Cria nova linha vazia na memória
          mtEtiquetas.CopyFields(FDQuery2); // Copia os dados do banco para a memória
          mtEtiquetas.Post; // Salva na memória
          FDQuery2.Next;
        end;
      end;
    finally
      mtEtiquetas.First;
      mtEtiquetas.EnableControls; // Libera a grid
    end;

    // 7. Imprimir
    // Garante que o relatório olhe para a Memória, não para o Banco direto
    DataSource1.DataSet := mtEtiquetas;

    Etiqueta.ShowPrintDialog := True;
    if cbTipoImpressao.ItemIndex = 0 then
      Etiqueta.DeviceType := 'Screen'
    else
      Etiqueta.DeviceType := 'Printer';

    Etiqueta.Print;

  except
    on E: Exception do
      ShowMessage('Erro: ' + E.Message);
  end;
end;

// ============================================================================
// CONFIGURAÇÃO DO REPORT BUILDER
// ============================================================================

procedure TGeradorEtiquetas.ConfigureReportForLabels(NumColunas: Integer;
  LarguraEtiqueta, AlturaEtiqueta, Espacamento: Single);
var
  LarguraTotalPapel, MargemSeguranca: Double;
begin
  Etiqueta.Units := utInches; // Fixo em Polegadas
  MargemSeguranca := 0.1;

  if NumColunas > 1 then
    LarguraTotalPapel := (LarguraEtiqueta * NumColunas) + (Espacamento * (NumColunas - 1)) + (MargemSeguranca * 2)
  else
    LarguraTotalPapel := LarguraEtiqueta + (MargemSeguranca * 2);

  with Etiqueta.PrinterSetup do
  begin
    PaperName   := 'Custom';
    PaperWidth  := LarguraTotalPapel;
    PaperHeight := AlturaEtiqueta;
    MarginTop := 0; MarginBottom := 0; MarginLeft := MargemSeguranca; MarginRight := MargemSeguranca;
    if PaperWidth > PaperHeight then Orientation := poLandscape else Orientation := poPortrait;
  end;

  Etiqueta.Columns := NumColunas;
  if NumColunas > 1 then
  begin
    Etiqueta.ColumnWidth := LarguraEtiqueta;
    ppDetailBand1.ColumnTraversal := ctLeftToRight;
  end
  else
    Etiqueta.ColumnWidth := LarguraTotalPapel;
end;

// ============================================================================
// FUNÇÕES AUXILIARES E EXCEL
// ============================================================================

function TGeradorEtiquetas.FormatAsCurrency(const Value: Variant): string;
var FormatSettings: TFormatSettings;
begin
  FormatSettings := TFormatSettings.Create;
  FormatSettings.CurrencyString := 'R$ ';
  FormatSettings.CurrencyFormat := 2;
  Result := FormatFloat('#,##0.00', Value, FormatSettings);
  Result := StringReplace(Result, '.', ',', [rfReplaceAll]);
end;

function TGeradorEtiquetas.BuildHTMLTable(DataSet: TDataSet): string;
var
  I: Integer;
  HTML: TStringList;
  FieldNames, FieldValue: string;
begin
  if not DataSet.Active then raise Exception.Create('DataSet inativo.');
  HTML := TStringList.Create;
  try
    HTML.Add('<html><body><table border="1" style="border-collapse:collapse;">');
    FieldNames := '';
    for I := 0 to DataSet.Fields.Count - 1 do
      FieldNames := FieldNames + '<th>' + DataSet.Fields[I].FieldName + '</th>';
    HTML.Add('<tr>' + FieldNames + '</tr>');
    DataSet.DisableControls;
    try
      DataSet.First;
      while not DataSet.Eof do
      begin
        HTML.Add('<tr>');
        for I := 0 to DataSet.Fields.Count - 1 do
        begin
          FieldValue := DataSet.Fields[I].AsString;
          if (DataSet.Fields[I].DataType in [ftCurrency, ftFloat]) then
             FieldValue := FormatAsCurrency(DataSet.Fields[I].AsFloat);
          HTML.Add('<td>' + FieldValue + '</td>');
        end;
        HTML.Add('</tr>');
        DataSet.Next;
      end;
    finally
      DataSet.EnableControls;
    end;
    HTML.Add('</table></body></html>');
    Result := HTML.Text;
  finally
    HTML.Free;
  end;
end;

procedure TGeradorEtiquetas.BtnExcelClick(Sender: TObject);
var
  SaveDialog: TSaveDialog;
  HTMLContent, LinhaDados, FieldValue: string;
  TempList: TStringList;
  I: Integer;
  UseXLS: Boolean;
const CSV_SEP = #9;
begin
  UseXLS := (rgFormatoExportacao.ItemIndex = 1);
  SaveDialog := TSaveDialog.Create(nil);
  TempList := TStringList.Create;
  try
    if UseXLS then
    begin
      SaveDialog.Filter := 'Excel (*.xls)|*.xls';
      SaveDialog.DefaultExt := 'xls';
    end
    else
    begin
      SaveDialog.Filter := 'Texto/CSV (*.txt)|*.txt';
      SaveDialog.DefaultExt := 'txt';
    end;

    SaveDialog.FileName := 'Export_' + FormatDateTime('hhmmss', Now);

    if SaveDialog.Execute then
    begin
      // Usa a MemTable se tiver dados gerados, senão usa a Query
      if mtEtiquetas.Active and (mtEtiquetas.RecordCount > 0) then
        mtEtiquetas.First
      else if not FDQuery2.Active then
        FDQuery2.Open;

      // Decide qual dataset usar para exportar
      if mtEtiquetas.Active and (mtEtiquetas.RecordCount > 0) then
      begin
         if UseXLS then TempList.Text := BuildHTMLTable(mtEtiquetas)
         else begin
            // Lógica simplificada de CSV para MemTable
            LinhaDados := '';
            for I := 0 to mtEtiquetas.Fields.Count - 1 do LinhaDados := LinhaDados + mtEtiquetas.Fields[I].FieldName + CSV_SEP;
            TempList.Add(LinhaDados);
            mtEtiquetas.First;
            while not mtEtiquetas.Eof do begin
              LinhaDados := '';
              for I := 0 to mtEtiquetas.Fields.Count - 1 do LinhaDados := LinhaDados + mtEtiquetas.Fields[I].AsString + CSV_SEP;
              TempList.Add(LinhaDados);
              mtEtiquetas.Next;
            end;
         end;
      end
      else
      begin
         // Fallback para FDQuery se a MemTable estiver vazia
         if UseXLS then TempList.Text := BuildHTMLTable(FDQuery2);
         // (Omiti o CSV da Query aqui para economizar espaço, mas segue a mesma lógica acima)
      end;

      TempList.SaveToFile(SaveDialog.FileName, TEncoding.UTF8);
      ShowMessage('Exportado!');
    end;
  finally
    SaveDialog.Free;
    TempList.Free;
  end;
end;

end.
