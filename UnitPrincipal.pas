unit UnitPrincipal;

interface

uses
  Winapi.Windows, Winapi.Messages, Winapi.ShellAPI, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Data.DB, Math,
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
    // cbUnidade: TComboBox; // Removido ou ignorado se ainda estiver na tela
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
    procedure BtnGerarEtiquetaClick(Sender: TObject);
    procedure BtnExcelClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
  private
    function BuildHTMLTable(DataSet: TDataSet): string;
    function FormatAsCurrency(const Value: Variant): string;
    procedure ConfigureReportForLabels(NumColunas: Integer; LarguraEtiqueta, AlturaEtiqueta, Espacamento: Single);
  public
  end;

var
  GeradorEtiquetas: TGeradorEtiquetas;

implementation

{$R *.dfm}

// ============================================================================
// FUNÇÕES AUXILIARES
// ============================================================================

function TGeradorEtiquetas.FormatAsCurrency(const Value: Variant): string;
var
  FormatSettings: TFormatSettings;
begin
  FormatSettings := TFormatSettings.Create;
  FormatSettings.DecimalSeparator := ',';
  FormatSettings.ThousandSeparator := '.';
  FormatSettings.CurrencyString := 'R$ ';
  FormatSettings.CurrencyFormat := 2;

  Result := FormatFloat('#,##0.00', Value, FormatSettings);
  Result := StringReplace(Result, '.', ',', [rfReplaceAll]);
end;

function TGeradorEtiquetas.BuildHTMLTable(DataSet: TDataSet): string;
var
  I: Integer;
  HTML: TStringList;
  FieldNames: string;
  FieldValue: string;
begin
  if not DataSet.Active then
    raise Exception.Create('DataSet não está ativo para exportação.');

  HTML := TStringList.Create;
  try
    HTML.Add('<html><head><meta charset="UTF-8"></head><body>');
    HTML.Add('<table border="1" style="font-size:9pt;border-collapse:collapse;">');

    FieldNames := '';
    for I := 0 to DataSet.Fields.Count - 1 do
      FieldNames := FieldNames + '<th style="background-color:#EFEFEF;font-weight:bold;padding:5px;border:1px solid #CCC;">' + DataSet.Fields[I].FieldName + '</th>';
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

          if (DataSet.Fields[I].FieldName = 'PrecoMinimo') or
             (DataSet.Fields[I].FieldName = 'PrecoMaximo') then
          begin
            FieldValue := FormatAsCurrency(DataSet.Fields[I].AsFloat);
            HTML.Add('<td align="right" style="border:1px solid #CCC;">' + FieldValue + '</td>');
          end
          else
          begin
            FieldValue := StringReplace(FieldValue, '<', '&lt;', [rfReplaceAll]);
            FieldValue := StringReplace(FieldValue, '>', '&gt;', [rfReplaceAll]);
            HTML.Add('<td style="border:1px solid #CCC;">' + FieldValue + '</td>');
          end;
        end;
        HTML.Add('</tr>');
        DataSet.Next();
      end;
    finally
      DataSet.EnableControls();
    end;

    HTML.Add('</table></body></html>');
    Result := HTML.Text;
  finally
    HTML.Free;
  end;
end;

// ============================================================================
// CONFIGURAÇÃO DO RELATÓRIO (FIXO EM POLEGADAS)
// ============================================================================

procedure TGeradorEtiquetas.ConfigureReportForLabels(NumColunas: Integer;
  LarguraEtiqueta, AlturaEtiqueta, Espacamento: Single);
var
  LarguraTotalPapel: Double;
  MargemSeguranca: Double;
begin
  // 1. Configura a Unidade de Medida FIXA para POLEGADAS
  Etiqueta.Units := utInches;

  // 2. Margens de segurança (pequenas para evitar corte físico)
  MargemSeguranca := 0.1;

  // 3. Cálculo da Largura Total do Papel
  // Fórmula: (Largura * Colunas) + (Espaços) + Margens
  if NumColunas > 1 then
    LarguraTotalPapel := (LarguraEtiqueta * NumColunas) + (Espacamento * (NumColunas - 1)) + (MargemSeguranca * 2)
  else
    LarguraTotalPapel := LarguraEtiqueta + (MargemSeguranca * 2);

  // 4. Aplica configurações ao PrinterSetup do ReportBuilder
  with Etiqueta.PrinterSetup do
  begin
    PaperName   := 'Custom'; // Essencial para aceitar tamanhos fora do padrão Windows
    PaperWidth  := LarguraTotalPapel;
    PaperHeight := AlturaEtiqueta;

    // Remove margens do driver para controlar pelo designer
    MarginTop    := 0;
    MarginBottom := 0;
    MarginLeft   := MargemSeguranca;
    MarginRight  := MargemSeguranca;

    // Orientação Automática
    if PaperWidth > PaperHeight then
      Orientation := poLandscape
    else
      Orientation := poPortrait;
  end;

  // 5. Configuração de Colunas
  Etiqueta.Columns := NumColunas;

  if NumColunas > 1 then
  begin
    Etiqueta.ColumnWidth := LarguraEtiqueta;
    ppDetailBand1.ColumnTraversal := ctLeftToRight; // Preenche da esquerda para direita
  end
  else
  begin
    Etiqueta.ColumnWidth := LarguraTotalPapel;
  end;
end;

// ============================================================================
// EXPORTAÇÃO EXCEL / CSV
// ============================================================================

procedure TGeradorEtiquetas.BtnExcelClick(Sender: TObject);
var
  SaveDialog: TSaveDialog;
  CaminhoArquivo: string;
  HTMLContent: string;
  TempList: TStringList;
  LinhaDados: string;
  I: Integer;
  FieldValue: string;
  UseXLSFormat: Boolean;
const
  CSV_SEPARATOR = #9; // Tabulação para melhor compatibilidade com Excel
begin
  UseXLSFormat := (rgFormatoExportacao.ItemIndex = 1);

  SaveDialog := TSaveDialog.Create(nil);
  TempList := TStringList.Create;
  try
    if UseXLSFormat then
    begin
      SaveDialog.Filter := 'Arquivo Excel (*.xls)|*.xls';
      SaveDialog.DefaultExt := 'xls';
    end else begin
      SaveDialog.Filter := 'Arquivo de Texto (*.txt)|*.txt|Arquivo Excel CSV (*.csv)|*.csv';
      SaveDialog.DefaultExt := 'txt';
    end;

    SaveDialog.FileName := 'Export_Dados_' + FormatDateTime('yyyymmdd_hhmmss', Now());

    if SaveDialog.Execute then
    begin
      CaminhoArquivo := SaveDialog.FileName;

      if not FDQuery2.Active then
        FDQuery2.Open;

      if UseXLSFormat then
      begin
        HTMLContent := BuildHTMLTable(FDQuery2);
        TempList.Text := HTMLContent;
      end else begin
        // GERAÇÃO DE CSV/TXT
        LinhaDados := '';
        for I := 0 to FDQuery2.Fields.Count - 1 do
        begin
          LinhaDados := LinhaDados + FDQuery2.Fields[I].FieldName;
          if I < FDQuery2.Fields.Count - 1 then
            LinhaDados := LinhaDados + CSV_SEPARATOR;
        end;
        TempList.Add(LinhaDados);

        FDQuery2.DisableControls;
        try
          FDQuery2.First;
          while not FDQuery2.Eof do
          begin
            LinhaDados := '';
            for I := 0 to FDQuery2.Fields.Count - 1 do
            begin
              FieldValue := FDQuery2.Fields[I].AsString;
              FieldValue := StringReplace(FieldValue, '"', '', [rfReplaceAll]);
              FieldValue := StringReplace(FieldValue, CSV_SEPARATOR, ' ', [rfReplaceAll]);

              LinhaDados := LinhaDados + FieldValue;

              if I < FDQuery2.Fields.Count - 1 then
                LinhaDados := LinhaDados + CSV_SEPARATOR;
            end;
            TempList.Add(LinhaDados);
            FDQuery2.Next();
          end;
        finally
          FDQuery2.EnableControls();
        end;
      end;

      TempList.SaveToFile(CaminhoArquivo, TEncoding.UTF8);
      ShowMessage('Exportação completa para: ' + CaminhoArquivo + '.');
    end;
  finally
    SaveDialog.Free;
    TempList.Free;
  end;
end;

// ============================================================================
// INICIALIZAÇÃO
// ============================================================================

procedure TGeradorEtiquetas.FormCreate(Sender: TObject);
begin
  // Configura opções de Impressão
  cbTipoImpressao.Items.Clear;
  cbTipoImpressao.Items.Add('Visualizar (Prévia)');
  cbTipoImpressao.Items.Add('Imprimir Direto');
  cbTipoImpressao.ItemIndex := 0;

  // REMOVIDO: Configuração de cbUnidade (Agora é sempre Inches)

  // Garante os links de dados
  DataSource1.DataSet := FDQuery2;
  ppDBPipeline1.DataSource := DataSource1;
end;

// ============================================================================
// GERAÇÃO DAS ETIQUETAS
// ============================================================================

procedure TGeradorEtiquetas.BtnGerarEtiquetaClick(Sender: TObject);
var
  ListaDeCodigos: string;
  Quantidade, NumColunas: Integer;
  LarguraEtiqueta, AlturaEtiqueta, EspacamentoColunas: Single;
  BaseSQL, FinalSQL: string;
  I: Integer;
  ListaDeCodigosFormatada: string;
begin
  // 1. Validação de Entrada
  if Trim(edtCodigo.Text) = '' then
  begin
    ShowMessage('Por favor, informe os códigos dos produtos.');
    edtCodigo.SetFocus;
    Exit;
  end;

  // 2. Normalização e Limpeza dos Códigos
  ListaDeCodigos := StringReplace(edtCodigo.Text, ' ', ',', [rfReplaceAll]);
  ListaDeCodigos := StringReplace(ListaDeCodigos, #13#10, ',', [rfReplaceAll]);

  // Remove vírgulas repetidas e nas pontas
  while Pos(',,', ListaDeCodigos) > 0 do
    ListaDeCodigos := StringReplace(ListaDeCodigos, ',,', ',', [rfReplaceAll]);

  if (ListaDeCodigos <> '') and (ListaDeCodigos[Length(ListaDeCodigos)] = ',') then
    Delete(ListaDeCodigos, Length(ListaDeCodigos), 1);
  if (ListaDeCodigos <> '') and (ListaDeCodigos[1] = ',') then
    Delete(ListaDeCodigos, 1, 1);

  // Formata para SQL: de 1,2,3 para '1','2','3'
  ListaDeCodigosFormatada := '''' + StringReplace(ListaDeCodigos, ',', ''',''', [rfReplaceAll]) + '''';

  if ListaDeCodigosFormatada = '''''' then Exit;

  // 3. Captura dos Parâmetros da UI (Assumindo Polegadas)
  Quantidade := StrToIntDef(edtQuantidade.Text, 1);
  if Quantidade <= 0 then Quantidade := 1;

  NumColunas := StrToIntDef(edtColuna.Text, 1);
  if NumColunas <= 0 then NumColunas := 1;

  LarguraEtiqueta := StrToFloatDef(edtLargura.Text, 4.0); // Default 4 polegadas
  AlturaEtiqueta  := StrToFloatDef(edtAltura.Text, 2.0);  // Default 2 polegadas
  EspacamentoColunas := StrToFloatDef(edtEspacamento.Text, 0);

  // 4. Configura o Relatório Visualmente
  ConfigureReportForLabels(NumColunas, LarguraEtiqueta, AlturaEtiqueta, EspacamentoColunas);

  // 5. Construção do SQL (Lógica de Multiplicação de Linhas)
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
             'INNER JOIN CE_PRODUTOS_IMPOSTOS I ON P.au_ite = I.CodReduzido ';

  FinalSQL := '';

  // Alerta de segurança se a quantidade for muito grande
  if Quantidade > 500 then
  begin
    if MessageDlg('Você solicitou ' + IntToStr(Quantidade) + ' cópias. Isso pode demorar. Continuar?',
      mtConfirmation, [mbYes, mbNo], 0) = mrNo then Exit;
  end;

  // Monta o UNION ALL
  for I := 1 to Quantidade do
  begin
    if FinalSQL <> '' then
      FinalSQL := FinalSQL + ' UNION ALL ';

    FinalSQL := FinalSQL + ' SELECT * FROM (' + BaseSQL + ') AS SubQuery ' +
                           ' WHERE CodigoProduto IN (' + ListaDeCodigosFormatada + ')';
  end;

  FinalSQL := FinalSQL + ' ORDER BY CodigoProduto';

  FDQuery2.SQL.Text := FinalSQL;

  try
    FDQuery2.Open;

    if FDQuery2.IsEmpty then
    begin
      ShowMessage('Nenhum produto encontrado com os códigos informados.');
      Exit;
    end;

    // --- 6. Vínculo do Relatório e Impressão ---

    // Assegura que o pipeline esteja ligado corretamente
    ppDBPipeline1.DataSource := DataSource1;

    Etiqueta.ShowPrintDialog := True;

    if cbTipoImpressao.ItemIndex = 0 then
      Etiqueta.DeviceType := 'Screen'  // Visualizar
    else
      Etiqueta.DeviceType := 'Printer'; // Imprimir direto

    Etiqueta.Print;

  except
    on E: Exception do
      ShowMessage('Erro ao gerar etiquetas: ' + E.Message);
  end;
end;

end.
