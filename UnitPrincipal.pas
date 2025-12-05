unit UnitPrincipal;

interface

uses
  // --- BIBLIOTECAS ---
  Winapi.Windows, Winapi.Messages, Winapi.ShellAPI, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Data.DB, Math, System.IniFiles,
  // FireDAC
  FireDAC.Stan.Intf, FireDAC.Stan.Option, FireDAC.Stan.Error, FireDAC.UI.Intf,
  FireDAC.Phys.Intf, FireDAC.Stan.Def, FireDAC.Phys.MSSQL, FireDAC.Phys.MSSQLDef, FireDAC.VCLUI.Wait,
  FireDAC.Stan.Param, FireDAC.DatS, FireDAC.DApt.Intf, FireDAC.DApt,
  Vcl.Grids, Vcl.DBGrids, FireDAC.Comp.DataSet,
  FireDAC.Comp.Client, Vcl.StdCtrls,
  // ReportBuilder
  ppDB, ppCtrls, ppPrnabl, ppClass,
  ppBarCod, ppBands, ppCache, ppDesignLayer, ppParameter, ppProd, ppReport,
  ppComm, ppRelatv, ppDBPipe, Vcl.Imaging.jpeg, Vcl.ExtCtrls,
  FireDAC.Stan.StorageBin, ppTypes, ppDevice, Printers, FireDAC.Stan.Pool,
  FireDAC.Stan.Async, FireDAC.Phys;

type
  TGeradorEtiquetas = class(TForm)
    // --- CONEXÃO E DADOS ---
    Conexao: TFDConnection;
    FDQuery2: TFDQuery;
    mtEtiquetas: TFDMemTable;
    DataSource1: TDataSource;
    ppDBPipeline1: TppDBPipeline;

    // --- RELATÓRIO 1: GÔNDOLA (AMARELA) ---
    EtiquetaGondula: TppReport;
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

    // --- RELATÓRIO 2: 33x22 (BRANCA 3 COLUNAS) ---
    Etiqueta33x22: TppReport;
    ppColumnHeaderBand2: TppColumnHeaderBand;
    ppDetailBand2: TppDetailBand;
    ppColumnFooterBand2: TppColumnFooterBand;
    ppDesignLayers2: TppDesignLayers;
    ppDesignLayer2: TppDesignLayer;
    ppParameterList2: TppParameterList;
    ppDBText5: TppDBText;
    ppDBText6: TppDBText; // <--- AQUI ESTÁ O CARA (UNIDADE)
    ppLabel3: TppLabel;
    ppDBText7: TppDBText;
    ppLabel4: TppLabel;

    // --- VISUAL ---
    Panel1: TPanel;
    Panel2: TPanel;
    DBGrid1: TDBGrid;
    Label1: TLabel;
    Image1: TImage;

    // Inputs e Labels
    Label2: TLabel; Label7: TLabel; Label3: TLabel; Label8: TLabel;
    Label4: TLabel; Label5: TLabel; Label6: TLabel; label9: TLabel; Label10: TLabel;

    edtCodigo: TEdit;
    edtQuantidade: TEdit;
    edtColuna: TEdit;
    cbUnidade: TComboBox;
    edtLargura: TEdit;
    edtAltura: TEdit;
    edtEspacamento: TEdit;

    cbTipoImpressao: TComboBox;
    rgFormatoExportacao: TRadioGroup;
    CheckSim: TCheckBox;

    // Botões
    BtnGerarEtiqueta: TButton;
    BtnGerar33x22: TButton;
    BtnExcel: TButton;

    // --- MÉTODOS ---
    procedure BtnGerarEtiquetaClick(Sender: TObject);
    procedure BtnGerar33x22Click(Sender: TObject);
    procedure BtnExcelClick(Sender: TObject);
    procedure CheckSimClick(Sender: TObject);

    procedure FormCreate(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure FormResize(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure DBGrid1CellClick(Column: TColumn);

  private
    dsRelatorio: TDataSource;

    function BuildHTMLTable(DataSet: TDataSet): string;
    function FormatAsCurrency(const Value: Variant): string;
    function StrToFloatSafe(const S: string; Default: Single): Single;

    procedure ConfigureReportGeneric(Report: TppReport; NumColunas: Integer; LarguraEtiqueta, AlturaEtiqueta, Espacamento: Single);
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
//  CHECKBOX (SELECIONAR TODOS)
// ============================================================================
procedure TGeradorEtiquetas.CheckSimClick(Sender: TObject);
begin
  edtCodigo.Enabled := not CheckSim.Checked;
  if CheckSim.Checked then edtCodigo.Text := ''
  else if FDQuery2.Active then edtCodigo.Text := FDQuery2.FieldByName('CodigoProduto').AsString;
end;

procedure TGeradorEtiquetas.DBGrid1CellClick(Column: TColumn);
begin
  if (FDQuery2.Active) and (not FDQuery2.IsEmpty) and (not CheckSim.Checked) then
     edtCodigo.Text := FDQuery2.FieldByName('CodigoProduto').AsString;
end;

// ============================================================================
//  LAYOUT (VISUAL DA TELA)
// ============================================================================
procedure TGeradorEtiquetas.PosicionarCampo(Lb: TLabel; Ctrl: TControl; X, Y, W: Integer);
begin
  if Assigned(Ctrl) then
  begin
    Ctrl.Left := X; Ctrl.Top := Y;
    if W > 0 then Ctrl.Width := W;
    Ctrl.Visible := True; Ctrl.BringToFront;
    if Assigned(Lb) then begin Lb.Left := X; Lb.Top := Y - Lb.Height - 3; Lb.Visible := True; Lb.BringToFront; end;
  end;
end;

procedure TGeradorEtiquetas.AjustarLayoutGeral;
var Col1, Col2, Y, AlturaLinha: Integer;
begin
  if DBGrid1.Columns.Count > 0 then DBGrid1.Columns[0].Width := 100;

  if Assigned(Label2) then Label2.Caption := 'CÓDIGO DO PRODUTO';
  if Assigned(Label7) then Label7.Caption := 'QUANTIDADE';
  if Assigned(Label3) then Label3.Caption := 'NÚMERO DE COLUNAS';
  if Assigned(Label8) then Label8.Caption := 'UNIDADE DE MEDIDA';
  if Assigned(Label4) then Label4.Caption := 'LARGURA (MM)';
  if Assigned(Label5) then Label5.Caption := 'ALTURA (MM)';
  if Assigned(Label6) then Label6.Caption := 'ESPAÇAMENTO';
  if Assigned(label9) then label9.Caption := 'TIPO DE IMPRESSÃO';
  if Assigned(Label10) then Label10.Caption := 'SELECIONAR TODOS?';

  Col1 := 15; Col2 := 170; Y := 40; AlturaLinha := 50;

  if Assigned(CheckSim) then begin PosicionarCampo(Label10, CheckSim, Col1, Y, 0); CheckSim.Width := 50; end;

  Y := Y + 40;
  PosicionarCampo(Label2, edtCodigo, Col1, Y, 140);
  PosicionarCampo(Label7, edtQuantidade, Col2, Y, 140);

  Y := Y + AlturaLinha;
  PosicionarCampo(Label3, edtColuna, Col1, Y, 80);
  PosicionarCampo(Label8, cbUnidade, Col2, Y, 140);

  Y := Y + AlturaLinha;
  PosicionarCampo(Label4, edtLargura, Col1, Y, 60);
  PosicionarCampo(Label5, edtAltura, Col1 + 70, Y, 60);
  PosicionarCampo(Label6, edtEspacamento, Col2, Y, 140);

  Y := Y + AlturaLinha;
  PosicionarCampo(label9, cbTipoImpressao, Col1, Y, 300);

  Y := Y + AlturaLinha;
  if Assigned(rgFormatoExportacao) then begin
    rgFormatoExportacao.Left := Col1; rgFormatoExportacao.Top := Y;
    rgFormatoExportacao.Width := 300; rgFormatoExportacao.Height := 65;
  end;

  if Panel2.Height > 400 then begin
    BtnGerarEtiqueta.Left := Col1; BtnGerarEtiqueta.Width := 145;
    BtnGerarEtiqueta.Top := Panel2.Height - BtnGerarEtiqueta.Height - 50;
    BtnGerar33x22.Left := Col2; BtnGerar33x22.Width := 145; BtnGerar33x22.Top := BtnGerarEtiqueta.Top;
    BtnExcel.Left := Col1; BtnExcel.Width := 300; BtnExcel.Top := BtnGerarEtiqueta.Top + BtnGerarEtiqueta.Height + 5;
  end;
end;

procedure TGeradorEtiquetas.FormResize(Sender: TObject);
begin AjustarLayoutGeral; end;

// ============================================================================
//  UTILITÁRIOS
// ============================================================================
function TGeradorEtiquetas.StrToFloatSafe(const S: string; Default: Single): Single;
var TempS: string;
begin
  if Trim(S) = '' then Exit(Default);
  TempS := S;
  if FormatSettings.DecimalSeparator = ',' then TempS := StringReplace(TempS, '.', ',', [rfReplaceAll])
  else TempS := StringReplace(TempS, ',', '.', [rfReplaceAll]);
  Result := StrToFloatDef(TempS, Default);
end;

procedure TGeradorEtiquetas.CarregarConfiguracoes;
var ArquivoIni: TIniFile;
begin
  ArquivoIni := TIniFile.Create(ChangeFileExt(Application.ExeName, '.ini'));
  try
    edtLargura.Text := ArquivoIni.ReadString('ConfigEtiqueta', 'Largura', '100');
    edtAltura.Text := ArquivoIni.ReadString('ConfigEtiqueta', 'Altura', '29,5');
    edtEspacamento.Text := ArquivoIni.ReadString('ConfigEtiqueta', 'Espacamento', '0');
    edtColuna.Text := ArquivoIni.ReadString('ConfigEtiqueta', 'Colunas', '1');
    if (edtColuna.Text = '') or (edtColuna.Text = '0') then edtColuna.Text := '1';
    edtQuantidade.Text := ArquivoIni.ReadString('ConfigEtiqueta', 'QuantidadePadrao', '1');
    if ArquivoIni.ValueExists('ConfigEtiqueta', 'TipoImpressao') then cbTipoImpressao.ItemIndex := ArquivoIni.ReadInteger('ConfigEtiqueta', 'TipoImpressao', 0);
    if ArquivoIni.ValueExists('ConfigEtiqueta', 'UnidadeMedida') then cbUnidade.ItemIndex := ArquivoIni.ReadInteger('ConfigEtiqueta', 'UnidadeMedida', 0);
  finally ArquivoIni.Free; end;
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
  finally ArquivoIni.Free; end;
end;

// ============================================================================
//  INICIALIZAÇÃO
// ============================================================================
procedure TGeradorEtiquetas.FormCreate(Sender: TObject);
var i: Integer;
begin
  Self.WindowState := wsMaximized;
  if Assigned(Panel1) then Panel1.Align := alTop;
  if Assigned(Panel2) then begin
    Panel2.Align := alLeft; Panel2.Width := 340; Panel2.ParentBackground := False;
    for i := 0 to Panel2.ControlCount - 1 do Panel2.Controls[i].Anchors := [akLeft, akTop];
  end;
  DBGrid1.Align := alClient;

  cbUnidade.Items.Clear; cbUnidade.Items.Add('Polegadas (inches)'); cbUnidade.Items.Add('Milímetros (mm)'); cbUnidade.ItemIndex := 0;
  cbTipoImpressao.Items.Clear; cbTipoImpressao.Items.Add('Visualizar (Prévia)'); cbTipoImpressao.Items.Add('Imprimir Direto'); cbTipoImpressao.ItemIndex := 0;

  DataSource1.DataSet := FDQuery2;
  dsRelatorio := TDataSource.Create(Self);
  dsRelatorio.DataSet := mtEtiquetas;
  ppDBPipeline1.DataSource := dsRelatorio;

  CarregarConfiguracoes;
  AjustarLayoutGeral;
end;

procedure TGeradorEtiquetas.FormShow(Sender: TObject);
begin
  if not FDQuery2.Active then
  try
    FDQuery2.Open;
    if (not CheckSim.Checked) and (edtCodigo.Text = '') and (not FDQuery2.IsEmpty) then
       edtCodigo.Text := FDQuery2.FieldByName('CodigoProduto').AsString;
  except end;
end;

procedure TGeradorEtiquetas.FormClose(Sender: TObject; var Action: TCloseAction);
begin SalvarConfiguracoes; end;

// ============================================================================
//  CONFIGURAÇÃO DE PAPEL
// ============================================================================
procedure TGeradorEtiquetas.ConfigureReportGeneric(Report: TppReport; NumColunas: Integer; LarguraEtiqueta, AlturaEtiqueta, Espacamento: Single);
var
  LarguraPapel, Margem: Double;
  i: Integer;
  lDetail: TppDetailBand;
begin
  if cbUnidade.ItemIndex = 1 then Report.Units := utMillimeters else Report.Units := utInches;
  Margem := 0.1;

  if NumColunas > 1 then LarguraPapel := (LarguraEtiqueta * NumColunas) + (Espacamento * (NumColunas - 1)) + (Margem * 2)
  else LarguraPapel := LarguraEtiqueta + (Margem * 2);

  with Report.PrinterSetup do begin
    PaperName := 'Custom'; PaperWidth := LarguraPapel; PaperHeight := AlturaEtiqueta;
    MarginTop := 0; MarginBottom := 0; MarginLeft := Margem; MarginRight := Margem;
    Orientation := poPortrait;
  end;

  lDetail := nil;
  for i := 0 to Report.BandCount - 1 do if Report.Bands[i] is TppDetailBand then begin lDetail := TppDetailBand(Report.Bands[i]); Break; end;

  if Assigned(lDetail) then begin
     lDetail.Height := AlturaEtiqueta - 0.1;
     Report.Columns := NumColunas;
     if Assigned(Report.ColumnPositions) then Report.ColumnPositions.Clear;

     if NumColunas > 1 then begin
       Report.ColumnWidth := LarguraEtiqueta;
       lDetail.ColumnTraversal := ctLeftToRight;
     end
     else begin
       Report.ColumnWidth := LarguraPapel;
       lDetail.ColumnTraversal := ctTopToBottom;
     end;
  end;
end;

// ============================================================================
//  BOTÃO 1: GÔNDOLA (AMARELA) - COM LEFT JOIN (Traz todos)
// ============================================================================
procedure TGeradorEtiquetas.BtnGerarEtiquetaClick(Sender: TObject);
var
  ListaDeCodigos, ListaDeCodigosFormatada: string;
  Quantidade, NumColunas, I: Integer;
  LarguraEtiqueta, AlturaEtiqueta, EspacamentoColunas: Single;
  BaseSQL, SQLOriginal: string;
begin
  if not Conexao.Connected then try Conexao.Connected := True; except Exit; end;

  if (not CheckSim.Checked) and (Trim(edtCodigo.Text) = '') then begin ShowMessage('Informe o Código.'); Exit; end;

  SQLOriginal := FDQuery2.SQL.Text;

  try
      Quantidade := StrToIntDef(edtQuantidade.Text, 1);
      NumColunas := StrToIntDef(edtColuna.Text, 1); if NumColunas <= 0 then NumColunas := 1;
      LarguraEtiqueta := StrToFloatSafe(edtLargura.Text, 100);
      AlturaEtiqueta  := StrToFloatSafe(edtAltura.Text, 29.5);
      EspacamentoColunas := StrToFloatSafe(edtEspacamento.Text, 0);

      ConfigureReportGeneric(EtiquetaGondula, NumColunas, LarguraEtiqueta, AlturaEtiqueta, EspacamentoColunas);

      if Assigned(ppDBBarCode1) then ppDBBarCode1.DataField := 'CodigoProduto';
      if Assigned(ppDBText3) then ppDBText3.DataField := 'CodigoUnidade';

      FDQuery2.Close;

      // [LEFT JOIN] Para trazer os produtos mesmo sem imposto cadastrado
      BaseSQL := 'SELECT P.au_ite AS CodigoProduto, P.ab_ite + '' '' + P.ac_ite AS Descricao, ' +
                 'CASE WHEN P.ad_ite = ''01'' THEN ''UN'' WHEN P.ad_ite = ''02'' THEN ''KG'' ' +
                 'WHEN P.ad_ite = ''03'' THEN ''LT'' WHEN P.ad_ite = ''04'' THEN ''CX'' ELSE P.ad_ite END AS CodigoUnidade, ' +
                 'A.PrecoVendaMin AS PrecoMinimo, A.PrecoVendaMax AS PrecoMaximo, I.NCM AS NCM_Imposto, I.CSTsaidas AS CST_Saida ' +
                 'FROM CE_PRODUTO P ' +
                 'LEFT JOIN CE_PRODUTOS_ADICIONAIS A ON P.au_ite = A.CodReduzido ' +
                 'LEFT JOIN CE_PRODUTOS_IMPOSTOS I ON P.au_ite = I.CodReduzido ';

      if CheckSim.Checked then
         BaseSQL := BaseSQL + ' ORDER BY P.au_ite'
      else
      begin
         ListaDeCodigos := StringReplace(edtCodigo.Text, ' ', ',', [rfReplaceAll]);
         ListaDeCodigosFormatada := '''' + StringReplace(ListaDeCodigos, ',', ''',''', [rfReplaceAll]) + '''';
         BaseSQL := BaseSQL + ' WHERE P.au_ite IN (' + ListaDeCodigosFormatada + ') ORDER BY P.au_ite';
      end;

      FDQuery2.SQL.Text := BaseSQL;
      FDQuery2.Open;

      if FDQuery2.IsEmpty then begin FDQuery2.Close; FDQuery2.SQL.Text := SQLOriginal; FDQuery2.Open; ShowMessage('Produto não encontrado.'); Exit; end;

      mtEtiquetas.Close; mtEtiquetas.FieldDefs.Clear; mtEtiquetas.FieldDefs.Assign(FDQuery2.FieldDefs);
      mtEtiquetas.CreateDataSet;
      mtEtiquetas.DisableControls;
      try
        FDQuery2.First;
        while not FDQuery2.Eof do begin
           for I := 1 to Quantidade do begin mtEtiquetas.Append; mtEtiquetas.CopyFields(FDQuery2); mtEtiquetas.Post; end;
           FDQuery2.Next;
        end;
      finally mtEtiquetas.First; mtEtiquetas.EnableControls; end;

      AjustarLayoutGeral;
      EtiquetaGondula.ShowPrintDialog := True;
      if cbTipoImpressao.ItemIndex = 0 then EtiquetaGondula.DeviceType := 'Screen' else EtiquetaGondula.DeviceType := 'Printer';
      EtiquetaGondula.Print;

  finally
      if (SQLOriginal <> '') and (FDQuery2.SQL.Text <> SQLOriginal) then begin FDQuery2.Close; FDQuery2.SQL.Text := SQLOriginal; FDQuery2.Open; end;
  end;
end;

// ============================================================================
//  BOTÃO 2: ETIQUETA 33x22 (BRANCA - 3 COLUNAS) - [CORREÇÃO UNIDADE]
// ============================================================================
procedure TGeradorEtiquetas.BtnGerar33x22Click(Sender: TObject);
var
  ListaDeCodigos, ListaDeCodigosFormatada: string;
  Quantidade, NumColunas, I: Integer;
  LarguraEtiqueta, AlturaEtiqueta, EspacamentoColunas: Single;
  BaseSQL, SQLOriginal: string;
begin
  if not Conexao.Connected then try Conexao.Connected := True; except Exit; end;

  if (not CheckSim.Checked) and (Trim(edtCodigo.Text) = '') then begin ShowMessage('Informe o Código.'); Exit; end;

  SQLOriginal := FDQuery2.SQL.Text;

  try
      Quantidade := StrToIntDef(edtQuantidade.Text, 1);

      // Lê o que você digitou na tela (Agora é DINÂMICO)
      NumColunas := StrToIntDef(edtColuna.Text, 3); if NumColunas <= 1 then NumColunas := 3;
      LarguraEtiqueta := StrToFloatSafe(edtLargura.Text, 33.5);
      AlturaEtiqueta  := StrToFloatSafe(edtAltura.Text, 22.0);
      EspacamentoColunas := StrToFloatSafe(edtEspacamento.Text, 2.0);

      ConfigureReportGeneric(Etiqueta33x22, NumColunas, LarguraEtiqueta, AlturaEtiqueta, EspacamentoColunas);

      // --- [CORREÇÃO] FORÇA A UNIDADE (ppDBText6) A APARECER ---
      if Assigned(ppDBText6) then ppDBText6.DataField := 'CodigoUnidade';

      FDQuery2.Close;

      // [LEFT JOIN] Para trazer todos
      BaseSQL := 'SELECT P.au_ite AS CodigoProduto, P.ab_ite + '' '' + P.ac_ite AS Descricao, ' +
                 'CASE WHEN P.ad_ite = ''01'' THEN ''UN'' WHEN P.ad_ite = ''02'' THEN ''KG'' ' +
                 'WHEN P.ad_ite = ''03'' THEN ''LT'' ELSE P.ad_ite END AS CodigoUnidade, ' +
                 'A.PrecoVendaMin AS PrecoMinimo, A.PrecoVendaMax AS PrecoMaximo ' +
                 'FROM CE_PRODUTO P ' +
                 'LEFT JOIN CE_PRODUTOS_ADICIONAIS A ON P.au_ite = A.CodReduzido ' +
                 'LEFT JOIN CE_PRODUTOS_IMPOSTOS I ON P.au_ite = I.CodReduzido ';

      if CheckSim.Checked then
         BaseSQL := BaseSQL + ' ORDER BY P.au_ite'
      else
      begin
         ListaDeCodigos := StringReplace(edtCodigo.Text, ' ', ',', [rfReplaceAll]);
         ListaDeCodigosFormatada := '''' + StringReplace(ListaDeCodigos, ',', ''',''', [rfReplaceAll]) + '''';
         BaseSQL := BaseSQL + ' WHERE P.au_ite IN (' + ListaDeCodigosFormatada + ') ORDER BY P.au_ite';
      end;

      FDQuery2.SQL.Text := BaseSQL;
      FDQuery2.Open;

      if FDQuery2.IsEmpty then begin FDQuery2.Close; FDQuery2.SQL.Text := SQLOriginal; FDQuery2.Open; ShowMessage('Nenhum produto encontrado.'); Exit; end;

      mtEtiquetas.Close; mtEtiquetas.FieldDefs.Clear; mtEtiquetas.FieldDefs.Assign(FDQuery2.FieldDefs);
      mtEtiquetas.CreateDataSet;
      mtEtiquetas.DisableControls;
      try
        FDQuery2.First;
        while not FDQuery2.Eof do begin
           for I := 1 to Quantidade do begin mtEtiquetas.Append; mtEtiquetas.CopyFields(FDQuery2); mtEtiquetas.Post; end;
           FDQuery2.Next;
        end;
      finally mtEtiquetas.First; mtEtiquetas.EnableControls; end;

      Etiqueta33x22.ShowPrintDialog := True;
      if cbTipoImpressao.ItemIndex = 0 then Etiqueta33x22.DeviceType := 'Screen' else Etiqueta33x22.DeviceType := 'Printer';
      Etiqueta33x22.Print;

  finally
      if (SQLOriginal <> '') and (FDQuery2.SQL.Text <> SQLOriginal) then begin FDQuery2.Close; FDQuery2.SQL.Text := SQLOriginal; FDQuery2.Open; end;
  end;
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
    finally DataSet.EnableControls; end;
    HTML.Add('</table></body></html>');
    Result := HTML.Text;
  finally HTML.Free; end;
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
  finally SD.Free; SL.Free; end;
end;

end.
