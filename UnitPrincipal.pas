unit UnitPrincipal;

interface

uses
  // Bibliotecas padrão
  Winapi.Windows, Winapi.Messages, Winapi.ShellAPI, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Data.DB, Math, System.IniFiles,
  // Bibliotecas FireDAC
  FireDAC.Stan.Intf, FireDAC.Stan.Option, FireDAC.Stan.Error, FireDAC.UI.Intf,
  FireDAC.Phys.Intf, FireDAC.Stan.Def, FireDAC.Phys.MSSQL, FireDAC.Phys.MSSQLDef, FireDAC.VCLUI.Wait,
  FireDAC.Stan.Param, FireDAC.DatS, FireDAC.DApt.Intf, FireDAC.DApt,
  Vcl.Grids, Vcl.DBGrids, FireDAC.Comp.DataSet,
  FireDAC.Comp.Client, Vcl.StdCtrls,
  // Bibliotecas ReportBuilder
  ppDB, ppCtrls, ppPrnabl, ppClass,
  ppBarCod, ppBands, ppCache, ppDesignLayer, ppParameter, ppProd, ppReport,
  ppComm, ppRelatv, ppDBPipe, Vcl.Imaging.jpeg, Vcl.ExtCtrls,
  FireDAC.Stan.StorageBin, ppTypes, ppDevice, Printers, FireDAC.Stan.Pool,
  FireDAC.Stan.Async, FireDAC.Phys;

type
  TGeradorEtiquetas = class(TForm)
    // --- COMPONENTES VISUAIS E DADOS ---
    Conexao: TFDConnection;
    FDQuery2: TFDQuery;
    mtEtiquetas: TFDMemTable;
    DataSource1: TDataSource;
    ppDBPipeline1: TppDBPipeline;
    Etiqueta: TppReport;

    // ReportBuilder Components
    ppParameterList1: TppParameterList;
    ppDesignLayers1: TppDesignLayers;
    ppDesignLayer1: TppDesignLayer;
    ppDetailBand1: TppDetailBand;
    ppDBBarCode1: TppDBBarCode;
    ppDBText2: TppDBText;
    ppDBText3: TppDBText;
    ppLabel1: TppLabel;
    ppDBText1: TppDBText;
    ppLabel2: TppLabel;
    ppColumnHeaderBand1: TppColumnHeaderBand;
    ppColumnFooterBand1: TppColumnFooterBand;
    ppShape1: TppShape;

    // Estrutura Visual
    Panel1: TPanel;
    Panel2: TPanel;
    DBGrid1: TDBGrid;
    Label1: TLabel;
    Image1: TImage;

    // Inputs (Campos de Texto)
    Label2: TLabel; // Código
    Label7: TLabel; // Quantidade
    Label3: TLabel; // Colunas
    Label8: TLabel; // Unidade
    Label4: TLabel; // Largura
    Label5: TLabel; // Altura
    Label6: TLabel; // Espaçamento
    label9: TLabel; // Tipo Impressão

    edtCodigo: TEdit;
    edtQuantidade: TEdit;
    edtColuna: TEdit;
    cbUnidade: TComboBox;
    edtLargura: TEdit;
    edtAltura: TEdit;
    edtEspacamento: TEdit;

    cbTipoImpressao: TComboBox;
    rgFormatoExportacao: TRadioGroup;
    BtnGerarEtiqueta: TButton;
    BtnExcel: TButton;

    // --- EVENTOS E MÉTODOS ---
    procedure BtnGerarEtiquetaClick(Sender: TObject);
    procedure BtnExcelClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure FormResize(Sender: TObject);

    // [NOVO] Este evento roda DEPOIS que a tela aparece (Resolve o 000001)
    procedure FormShow(Sender: TObject);

    // Evento para controlar a troca de produtos
    procedure EventoAposRolar(DataSet: TDataSet);

  private
    dsRelatorio: TDataSource;

    function BuildHTMLTable(DataSet: TDataSet): string;
    function FormatAsCurrency(const Value: Variant): string;
    function StrToFloatSafe(const S: string; Default: Single): Single;

    procedure ConfigureReportForLabels(NumColunas: Integer; LarguraEtiqueta, AlturaEtiqueta, Espacamento: Single);
    procedure CarregarConfiguracoes;
    procedure SalvarConfiguracoes;
    procedure PosicionarCampo(Lb: TLabel; Ctrl: TControl; X, Y, W: Integer);
    procedure AjustarLayoutGeral;
  public
  end;

var
  GeradorEtiquetas: TGeradorEtiquetas;

implementation

{$R *.dfm}

// ============================================================================
//  PROTEÇÃO CONTRA DADOS ERRADOS NO CAMPO
// ============================================================================
procedure TGeradorEtiquetas.EventoAposRolar(DataSet: TDataSet);
begin
  if (DataSet.Active) and (not DataSet.IsEmpty) then
  begin
    // Joga o código certo para o campo "CÓDIGO DO PRODUTO"
    edtCodigo.Text := DataSet.FieldByName('CodigoProduto').AsString;

    // FORÇA O CAMPO COLUNAS A SER "1"
    edtColuna.Text := '1';

    if Trim(edtQuantidade.Text) = '' then edtQuantidade.Text := '1';
  end;
end;

// ============================================================================
//  LAYOUT INTELIGENTE
// ============================================================================
procedure TGeradorEtiquetas.PosicionarCampo(Lb: TLabel; Ctrl: TControl; X, Y, W: Integer);
begin
  if Assigned(Ctrl) then
  begin
    Ctrl.Left  := X;
    Ctrl.Top   := Y;
    Ctrl.Width := W;
    Ctrl.Visible := True;
    Ctrl.BringToFront;

    if Assigned(Lb) then
    begin
      Lb.Left := X;
      Lb.Top  := Y - Lb.Height - 3;
      Lb.Visible := True;
      Lb.BringToFront;
    end;
  end;
end;

procedure TGeradorEtiquetas.AjustarLayoutGeral;
var
  Col1, Col2, Y, AlturaLinha: Integer;
  PainelLateral: TPanel;
begin
  PainelLateral := Panel2;

  // 1. AJUSTA GRID
  if DBGrid1.Columns.Count > 0 then
    DBGrid1.Columns[0].Width := 100;

  // 2. NOMES DOS RÓTULOS
  if Assigned(Label2) then Label2.Caption := 'CÓDIGO DO PRODUTO';
  if Assigned(Label7) then Label7.Caption := 'QUANTIDADE';
  if Assigned(Label3) then Label3.Caption := 'NÚMERO DE COLUNAS';
  if Assigned(Label8) then Label8.Caption := 'UNIDADE DE MEDIDA';
  if Assigned(Label4) then Label4.Caption := 'LARGURA';
  if Assigned(Label5) then Label5.Caption := 'ALTURA';
  if Assigned(Label6) then Label6.Caption := 'ESPAÇAMENTO';
  if Assigned(label9) then label9.Caption := 'TIPO DE IMPRESSÃO';

  // 3. POSICIONAMENTO
  Col1 := 15;
  Col2 := 170;
  Y    := 50;
  AlturaLinha := 55;

  // LINHA 1
  PosicionarCampo(Label2, edtCodigo,      Col1, Y, 140);
  PosicionarCampo(Label7, edtQuantidade,  Col2, Y, 140);

  // LINHA 2
  Y := Y + AlturaLinha;
  PosicionarCampo(Label3, edtColuna,      Col1, Y, 80);
  PosicionarCampo(Label8, cbUnidade,      Col2, Y, 140);

  // LINHA 3
  Y := Y + AlturaLinha;
  PosicionarCampo(Label4, edtLargura,     Col1, Y, 60);
  PosicionarCampo(Label5, edtAltura,      Col1 + 70, Y, 60);
  PosicionarCampo(Label6, edtEspacamento, Col2, Y, 140);

  // LINHA 4
  Y := Y + AlturaLinha;
  PosicionarCampo(label9, cbTipoImpressao, Col1, Y, 300);

  // LINHA 5
  Y := Y + AlturaLinha;
  if Assigned(rgFormatoExportacao) then
  begin
    rgFormatoExportacao.Left := Col1;
    rgFormatoExportacao.Top  := Y;
    rgFormatoExportacao.Width := 300;
    rgFormatoExportacao.Height := 75;
  end;

  // BOTÕES
  if PainelLateral.Height > 400 then
  begin
    BtnGerarEtiqueta.Left  := Col1;
    BtnGerarEtiqueta.Width := 145;
    BtnGerarEtiqueta.Top   := PainelLateral.Height - BtnGerarEtiqueta.Height - 20;

    BtnExcel.Left  := Col2;
    BtnExcel.Width := 145;
    BtnExcel.Top   := BtnGerarEtiqueta.Top;
  end;
end;

procedure TGeradorEtiquetas.FormResize(Sender: TObject);
begin
  AjustarLayoutGeral;
end;

// ============================================================================
//  FUNÇÕES AUXILIARES
// ============================================================================
function TGeradorEtiquetas.StrToFloatSafe(const S: string; Default: Single): Single;
var TempS: string;
begin
  if Trim(S) = '' then Exit(Default);
  TempS := S;
  if FormatSettings.DecimalSeparator = ',' then
    TempS := StringReplace(TempS, '.', ',', [rfReplaceAll])
  else
    TempS := StringReplace(TempS, ',', '.', [rfReplaceAll]);
  Result := StrToFloatDef(TempS, Default);
end;

// ============================================================================
//  PERSISTÊNCIA (INI)
// ============================================================================
procedure TGeradorEtiquetas.CarregarConfiguracoes;
var ArquivoIni: TIniFile;
begin
  ArquivoIni := TIniFile.Create(ChangeFileExt(Application.ExeName, '.ini'));
  try
    // LÊ O ARQUIVO. Se não tiver nada (ou se você apagou o arquivo), usa os novos padrões.
    edtLargura.Text     := ArquivoIni.ReadString('ConfigEtiqueta', 'Largura', '5');
    edtAltura.Text      := ArquivoIni.ReadString('ConfigEtiqueta', 'Altura', '10');
    edtEspacamento.Text := ArquivoIni.ReadString('ConfigEtiqueta', 'Espacamento', '1');

    edtColuna.Text      := ArquivoIni.ReadString('ConfigEtiqueta', 'Colunas', '1');
    if (edtColuna.Text = '') or (edtColuna.Text = '0') then edtColuna.Text := '1';

    edtQuantidade.Text  := ArquivoIni.ReadString('ConfigEtiqueta', 'QuantidadePadrao', '1');

    if ArquivoIni.ValueExists('ConfigEtiqueta', 'TipoImpressao') then
      cbTipoImpressao.ItemIndex := ArquivoIni.ReadInteger('ConfigEtiqueta', 'TipoImpressao', 0);

    if ArquivoIni.ValueExists('ConfigEtiqueta', 'UnidadeMedida') then
      cbUnidade.ItemIndex := ArquivoIni.ReadInteger('ConfigEtiqueta', 'UnidadeMedida', 0);
  finally
    ArquivoIni.Free;
  end;
end;

procedure TGeradorEtiquetas.SalvarConfiguracoes;
var ArquivoIni: TIniFile;
begin
  ArquivoIni := TIniFile.Create(ChangeFileExt(Application.ExeName, '.ini'));
  try
    ArquivoIni.WriteString('ConfigEtiqueta', 'Largura', edtLargura.Text);
    ArquivoIni.WriteString('ConfigEtiqueta', 'Altura', edtAltura.Text);
    ArquivoIni.WriteString('ConfigEtiqueta', 'Colunas', edtColuna.Text);
    ArquivoIni.WriteString('ConfigEtiqueta', 'Espacamento', edtEspacamento.Text);
    ArquivoIni.WriteString('ConfigEtiqueta', 'QuantidadePadrao', edtQuantidade.Text);
    ArquivoIni.WriteInteger('ConfigEtiqueta', 'TipoImpressao', cbTipoImpressao.ItemIndex);
    ArquivoIni.WriteInteger('ConfigEtiqueta', 'UnidadeMedida', cbUnidade.ItemIndex);
  finally
    ArquivoIni.Free;
  end;
end;

// ============================================================================
//  INICIALIZAÇÃO (FORM CREATE)
// ============================================================================
procedure TGeradorEtiquetas.FormCreate(Sender: TObject);
var i: Integer;
begin
  Self.WindowState := wsMaximized;

  // Configura Paineis e Combos
  if Assigned(Panel1) then Panel1.Align := alTop;
  if Assigned(Panel2) then
  begin
    Panel2.Align := alLeft;
    Panel2.Width := 340;
    Panel2.ParentBackground := False;
    for i := 0 to Panel2.ControlCount - 1 do
      Panel2.Controls[i].Anchors := [akLeft, akTop];
  end;
  DBGrid1.Align := alClient;

  cbUnidade.Items.Clear;
  cbUnidade.Items.Add('Polegadas (inches)');
  cbUnidade.Items.Add('Milímetros (mm)');
  cbUnidade.ItemIndex := 0;

  cbTipoImpressao.Items.Clear;
  cbTipoImpressao.Items.Add('Visualizar (Prévia)');
  cbTipoImpressao.Items.Add('Imprimir Direto');
  cbTipoImpressao.ItemIndex := 0;

  // Lógica de Dados
  DataSource1.DataSet := FDQuery2;
  FDQuery2.AfterScroll := EventoAposRolar; // Liga a proteção

  dsRelatorio := TDataSource.Create(Self);
  dsRelatorio.DataSet := mtEtiquetas;
  ppDBPipeline1.DataSource := dsRelatorio;

  // Carrega e Ajusta
  CarregarConfiguracoes;
  AjustarLayoutGeral;
end;

// [NOVO] ESSE EVENTO RODA DEPOIS QUE TUDO CARREGOU - AQUI É A MÁGICA
procedure TGeradorEtiquetas.FormShow(Sender: TObject);
begin
  if not FDQuery2.Active then
  begin
    try
      FDQuery2.Open;
      // Força a limpeza do campo Colunas DEPOIS que a tela já apareceu
      if not FDQuery2.IsEmpty then
      begin
         edtCodigo.Text := FDQuery2.FieldByName('CodigoProduto').AsString;
         edtColuna.Text := '1'; // TIRA O 000001
      end;
    except
      // Erro silencioso na abertura (se banco desconectado)
    end;
  end;
end;

procedure TGeradorEtiquetas.FormClose(Sender: TObject; var Action: TCloseAction);
begin
  SalvarConfiguracoes;
end;

// ============================================================================
//  GERAR ETIQUETA
// ============================================================================
procedure TGeradorEtiquetas.BtnGerarEtiquetaClick(Sender: TObject);
var
  ListaDeCodigos, ListaDeCodigosFormatada: string;
  Quantidade, NumColunas, I: Integer;
  LarguraEtiqueta, AlturaEtiqueta, EspacamentoColunas: Single;
  BaseSQL, SQLOriginal: string;
begin
  if not Conexao.Connected then
  begin
    try Conexao.Connected := True; except on E: Exception do begin ShowMessage('Erro Conexão: ' + E.Message); Exit; end; end;
  end;

  if Trim(edtCodigo.Text) = '' then
  begin
    if (FDQuery2.Active) and (not FDQuery2.IsEmpty) then
       edtCodigo.Text := FDQuery2.FieldByName('CodigoProduto').AsString;

    if Trim(edtCodigo.Text) = '' then
    begin
      ShowMessage('Informe o Código no campo "CÓDIGO DO PRODUTO" ou clique na tabela.');
      if edtCodigo.CanFocus then edtCodigo.SetFocus;
      Exit;
    end;
  end;

  SQLOriginal := FDQuery2.SQL.Text;

  try
      ListaDeCodigos := StringReplace(edtCodigo.Text, ' ', ',', [rfReplaceAll]);
      ListaDeCodigosFormatada := '''' + StringReplace(ListaDeCodigos, ',', ''',''', [rfReplaceAll]) + '''';

      Quantidade := StrToIntDef(edtQuantidade.Text, 1);
      NumColunas := StrToIntDef(edtColuna.Text, 1);
      if NumColunas <= 0 then NumColunas := 1;

      LarguraEtiqueta := StrToFloatSafe(edtLargura.Text, 5.0);
      AlturaEtiqueta  := StrToFloatSafe(edtAltura.Text, 10.0);
      EspacamentoColunas := StrToFloatSafe(edtEspacamento.Text, 1.0);

      ConfigureReportForLabels(NumColunas, LarguraEtiqueta, AlturaEtiqueta, EspacamentoColunas);

      if Assigned(ppDBBarCode1) then ppDBBarCode1.DataField := 'CodigoProduto';

      FDQuery2.Close;
      BaseSQL := 'SELECT P.au_ite AS CodigoProduto, P.ab_ite + '' '' + P.ac_ite AS Descricao, ' +
                 'P.ad_ite AS CodigoUnidade, A.PrecoVendaMin AS PrecoMinimo, A.PrecoVendaMax AS PrecoMaximo, ' +
                 'I.NCM AS NCM_Imposto, I.CSTsaidas AS CST_Saida, I.ALIQUOTAICMS AS AliquotaICMS ' +
                 'FROM CE_PRODUTO P ' +
                 'INNER JOIN CE_PRODUTOS_ADICIONAIS A ON P.au_ite = A.CodReduzido ' +
                 'INNER JOIN CE_PRODUTOS_IMPOSTOS I ON P.au_ite = I.CodReduzido ' +
                 'WHERE P.au_ite IN (' + ListaDeCodigosFormatada + ') ORDER BY P.au_ite';
      FDQuery2.SQL.Text := BaseSQL;

      FDQuery2.Open;

      if FDQuery2.IsEmpty then
      begin
        FDQuery2.Close;
        FDQuery2.SQL.Text := SQLOriginal;
        FDQuery2.Open;
        ShowMessage('Produto não encontrado.');
        Exit;
      end;

      mtEtiquetas.Close;
      mtEtiquetas.FieldDefs.Clear;
      mtEtiquetas.FieldDefs.Assign(FDQuery2.FieldDefs);
      mtEtiquetas.CreateDataSet;

      mtEtiquetas.DisableControls;
      try
        FDQuery2.First;
        while not FDQuery2.Eof do
        begin
           for I := 1 to Quantidade do
           begin
             mtEtiquetas.Append;
             mtEtiquetas.CopyFields(FDQuery2);
             mtEtiquetas.Post;
           end;
           FDQuery2.Next;
        end;
      finally
        mtEtiquetas.First;
        mtEtiquetas.EnableControls;
      end;

      AjustarLayoutGeral;
      Etiqueta.ShowPrintDialog := True;
      if cbTipoImpressao.ItemIndex = 0 then Etiqueta.DeviceType := 'Screen' else Etiqueta.DeviceType := 'Printer';
      Etiqueta.Print;

  finally
      if (SQLOriginal <> '') and (FDQuery2.SQL.Text <> SQLOriginal) then
      begin
        FDQuery2.Close;
        FDQuery2.SQL.Text := SQLOriginal;
        FDQuery2.Open;
        EventoAposRolar(FDQuery2);
      end;
  end;
end;

// ============================================================================
//  CONFIGURAÇÃO IMPRESSORA
// ============================================================================
procedure TGeradorEtiquetas.ConfigureReportForLabels(NumColunas: Integer; LarguraEtiqueta, AlturaEtiqueta, Espacamento: Single);
var LarguraPapel, Margem: Double;
begin
  if cbUnidade.ItemIndex = 1 then Etiqueta.Units := utMillimeters else Etiqueta.Units := utInches;
  Margem := 0.1;

  if NumColunas > 1 then
    LarguraPapel := (LarguraEtiqueta * NumColunas) + (Espacamento * (NumColunas - 1)) + (Margem * 2)
  else
    LarguraPapel := LarguraEtiqueta + (Margem * 2);

  with Etiqueta.PrinterSetup do
  begin
    PaperName := 'Custom';
    PaperWidth := LarguraPapel;
    PaperHeight := AlturaEtiqueta;
    MarginTop := 0; MarginBottom := 0; MarginLeft := Margem; MarginRight := Margem;
    if PaperWidth > PaperHeight then Orientation := poLandscape else Orientation := poPortrait;
  end;

  Etiqueta.Columns := NumColunas;
  if Assigned(Etiqueta.ColumnPositions) then Etiqueta.ColumnPositions.Clear;

  if NumColunas > 1 then
  begin
    Etiqueta.ColumnWidth := LarguraEtiqueta;
    ppDetailBand1.ColumnTraversal := ctLeftToRight;
  end
  else
    Etiqueta.ColumnWidth := LarguraPapel;
end;

// ============================================================================
//  EXPORTAÇÃO EXCEL
// ============================================================================
function TGeradorEtiquetas.FormatAsCurrency(const Value: Variant): string;
var FS: TFormatSettings;
begin
  FS := TFormatSettings.Create; FS.CurrencyString := 'R$ '; FS.CurrencyFormat := 2;
  Result := StringReplace(FormatFloat('#,##0.00', Value, FS), '.', ',', [rfReplaceAll]);
end;

function TGeradorEtiquetas.BuildHTMLTable(DataSet: TDataSet): string;
var I: Integer; HTML: TStringList; Val: string;
begin
  HTML := TStringList.Create;
  try
    HTML.Add('<html><body><table border="1"><tr>');
    for I := 0 to DataSet.Fields.Count - 1 do HTML.Add('<th>' + DataSet.Fields[I].FieldName + '</th>');
    HTML.Add('</tr>');
    DataSet.DisableControls;
    try
      DataSet.First;
      while not DataSet.Eof do
      begin
        HTML.Add('<tr>');
        for I := 0 to DataSet.Fields.Count - 1 do
        begin
          if (DataSet.Fields[I].DataType in [ftCurrency, ftFloat]) then Val := FormatAsCurrency(DataSet.Fields[I].AsFloat)
          else Val := DataSet.Fields[I].AsString;
          HTML.Add('<td>' + Val + '</td>');
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
var SD: TSaveDialog; SL: TStringList; I: Integer; UseXLS: Boolean; Line: string;
begin
  UseXLS := (rgFormatoExportacao.ItemIndex = 1);
  SD := TSaveDialog.Create(nil); SL := TStringList.Create;
  try
    if UseXLS then begin SD.Filter := 'Excel|*.xls'; SD.DefaultExt := 'xls'; end
    else begin SD.Filter := 'CSV|*.txt'; SD.DefaultExt := 'txt'; end;
    SD.FileName := 'Exp_' + FormatDateTime('hhmmss', Now);

    if SD.Execute then
    begin
      if mtEtiquetas.Active and (mtEtiquetas.RecordCount > 0) then mtEtiquetas.First else if not FDQuery2.Active then FDQuery2.Open;

      if (mtEtiquetas.Active) and (mtEtiquetas.RecordCount > 0) then
      begin
          if UseXLS then SL.Text := BuildHTMLTable(mtEtiquetas)
          else begin
             Line := ''; for I := 0 to mtEtiquetas.Fields.Count - 1 do Line := Line + mtEtiquetas.Fields[I].FieldName + #9;
             SL.Add(Line);
             mtEtiquetas.First;
             while not mtEtiquetas.Eof do begin
               Line := ''; for I := 0 to mtEtiquetas.Fields.Count - 1 do Line := Line + mtEtiquetas.Fields[I].AsString + #9;
               SL.Add(Line); mtEtiquetas.Next;
             end;
          end;
      end
      else if UseXLS then SL.Text := BuildHTMLTable(FDQuery2);

      SL.SaveToFile(SD.FileName, TEncoding.UTF8);
      ShowMessage('Salvo!');
    end;
  finally
    SD.Free; SL.Free;
  end;
end;

end.
