unit UnitPrincipal;

interface

uses
  Winapi.Windows, Winapi.Messages, Winapi.ShellAPI, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Data.DB,
  FireDAC.Stan.Intf, FireDAC.Stan.Option, FireDAC.Stan.Error, FireDAC.UI.Intf,
  FireDAC.Phys.Intf, FireDAC.Stan.Def, FireDAC.Stan.Pool, FireDAC.Stan.Async,
  FireDAC.Phys, FireDAC.Phys.MSSQL, FireDAC.Phys.MSSQLDef, FireDAC.VCLUI.Wait,
  FireDAC.Stan.Param, FireDAC.DatS, FireDAC.DApt.Intf, FireDAC.DApt,
  Vcl.Grids, Vcl.DBGrids, FireDAC.Comp.DataSet,
  FireDAC.Comp.Client, Vcl.StdCtrls, ppDB, ppCtrls, ppPrnabl, ppClass,
  ppBarCod, ppBands, ppCache, ppDesignLayer, ppParameter, ppProd, ppReport,
  ppComm, ppRelatv, ppDBPipe, Vcl.Imaging.jpeg, Vcl.ExtCtrls,
  FireDAC.Stan.StorageBin, ppTypes, ppDevice, Printers;

type
  TGeradorEtiquetas = class(TForm)
    FDConnection1: TFDConnection;
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
    ppColumnHeaderBand1: TppColumnHeaderBand;
    ppColumnFooterBand1: TppColumnFooterBand;
    Label2: TLabel;
    edtQuantidade: TEdit;
    Label3: TLabel;
    edtColuna: TEdit;
    Label4: TLabel;
    edtLargura: TEdit;
    edtAltura: TEdit;
    Label5: TLabel;
    Label6: TLabel;
    cbUnidade: TComboBox;
    edtEspacamento: TEdit;
    BtnExcel: TButton;
    Label9: TLabel;
    cbTipoImpressao: TComboBox;
    ppDBText2: TppDBText;
    ppDBText3: TppDBText;
    ppLabel1: TppLabel;
    ppDBText1: TppDBText;
    ppLabel2: TppLabel;
    FormatoExportacao: TRadioGroup;
    procedure BtnGerarEtiquetaClick(Sender: TObject);
    procedure BtnExcelClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
  private
    function BuildHTMLTable(DataSet: TDataSet): string;
    function FormatAsCurrency(const Value: Variant): string;
  public
  end;

var
  GeradorEtiquetas: TGeradorEtiquetas;

implementation

{$R *.dfm}

const
  MM_TO_DMM = 10;

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

    // 1. Cabeçalho (Header)
    FieldNames := '';
    for I := 0 to DataSet.Fields.Count - 1 do
      // Aplica NEGRITO e COR DE FUNDO
      FieldNames := FieldNames + '<th style="background-color:#EFEFEF;font-weight:bold;padding:5px;border:1px solid #CCC;">' + DataSet.Fields[I].FieldName + '</th>';
    HTML.Add('<tr>' + FieldNames + '</tr>');

    // 2. Dados (Rows)
    DataSet.DisableControls;
    try
      DataSet.First;
      while not DataSet.Eof do
      begin
        HTML.Add('<tr>');
        for I := 0 to DataSet.Fields.Count - 1 do
        begin
          FieldValue := DataSet.Fields[I].AsString;

          // Formatação de Preço e Alinhamento
          if (DataSet.Fields[I].FieldName = 'PrecoMinimo') or
             (DataSet.Fields[I].FieldName = 'PrecoMaximo') then
          begin
            FieldValue := FormatAsCurrency(DataSet.Fields[I].AsFloat);
            HTML.Add('<td align="right" style="border:1px solid #CCC;">' + FieldValue + '</td>');
          end
          else
          begin
            // Tratamento de caracteres especiais e Alinhamento padrão
            FieldValue := StringReplace(FieldValue, '<', '&lt;', [rfReplaceAll]);
            FieldValue := StringReplace(FieldValue, '>', '&gt;', [rfReplaceAll]);
            HTML.Add('<td style="border:1px solid #CCC;">' + FieldValue + '</td>');
          end;
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
  CaminhoArquivo: string;
  HTMLContent: string;
  TempList: TStringList;
  LinhaDados: string;
  I: Integer;
  FieldValue: string;
  UseXLSFormat: Boolean;
const
  CSV_SEPARATOR = #9; // Usaremos TAB (#9) para CSV/TXT
begin
  // Assume que rgFormatoExportacao está com 2 itens (0=CSV/TXT, 1=XLS/HTML)
  UseXLSFormat := (rgFormatoExportacao.ItemIndex = 1);

  SaveDialog := TSaveDialog.Create(nil);
  TempList := TStringList.Create;
  try
    if UseXLSFormat then
    begin
      // --- EXPORTAÇÃO XLS (HTML ORGANIZADO) ---
      SaveDialog.Filter := 'Arquivo Excel (*.xls)|*.xls';
      SaveDialog.DefaultExt := 'xls';
    end else begin
      // --- EXPORTAÇÃO CSV/TXT (TAB SEPARADO) ---
      SaveDialog.Filter := 'Arquivo Excel CSV (*.csv)|*.csv';
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
        // GERAÇÃO DE HTML (XLS Organizado)
        HTMLContent := BuildHTMLTable(FDQuery2);
        TempList.Text := HTMLContent;
      end else begin
        // GERAÇÃO DE CSV/TXT (Separador TAB)

        // 1. Exporta Cabeçalho CSV
        LinhaDados := '';
        for I := 0 to FDQuery2.Fields.Count - 1 do
        begin
          LinhaDados := LinhaDados + FDQuery2.Fields[I].FieldName;
          if I < FDQuery2.Fields.Count - 1 then
            LinhaDados := LinhaDados + CSV_SEPARATOR;
        end;
        TempList.Add(LinhaDados);

        // 2. Exporta Registros CSV
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
            FDQuery2.Next;
          end;
        finally
          FDQuery2.EnableControls;
        end;
      end;

      // Salva o conteúdo gerado (UTF-8 com BOM para garantir organização no Excel)
      TempList.SaveToFile(CaminhoArquivo, TEncoding.UTF8);

      ShowMessage('Exportação completa para: ' + CaminhoArquivo + '.');
    end;
  finally
    SaveDialog.Free;
    TempList.Free;
  end;
end;

procedure TGeradorEtiquetas.FormCreate(Sender: TObject);
var
  I: Integer;
begin
  cbTipoImpressao.Items.Clear;

  cbTipoImpressao.Items.Add('Visualizar (Prévia)');

  cbTipoImpressao.ItemIndex := 0;

  cbUnidade.Items.Clear;
  cbUnidade.Items.Add('mm');
  cbUnidade.Items.Add('inches');
  cbUnidade.ItemIndex := 0;

  ppDBPipeline1.DataSource := DataSource1;
end;

procedure TGeradorEtiquetas.BtnGerarEtiquetaClick(Sender: TObject);
var
  ListaDeCodigos: string;
  Quantidade: Integer;
  NumColunas: Integer;
  LarguraEtiqueta: Single;
  AlturaEtiqueta: Single;
  EspacamentoColunas: Single;
  BufferSeguranca: Single;
  BufferVertical: Single;
  LarguraColunaFinal: Single;
  LarguraTotalPapel: Single;
  BaseSQL: string;
  FinalSQL: string;
  I: Integer;
  SaveDlg: TSaveDialog;
  SaidaImpressao: string;
begin

  ListaDeCodigos := StringReplace(edtCodigo.Text, ' ', ',', [rfReplaceAll]);
  ListaDeCodigos := StringReplace(ListaDeCodigos, #13#10, ',', [rfReplaceAll]);
  while Pos(',,', ListaDeCodigos) > 0 do
    ListaDeCodigos := StringReplace(ListaDeCodigos, ',,', ',', [rfReplaceAll]);
  if (Length(ListaDeCodigos) > 0) and (ListaDeCodigos[Length(ListaDeCodigos)] = ',') then
    SetLength(ListaDeCodigos, Length(ListaDeCodigos) - 1);
  if (Length(ListaDeCodigos) > 0) and (ListaDeCodigos[1] = ',') then
    ListaDeCodigos := Copy(ListaDeCodigos, 2, Length(ListaDeCodigos));

  if ListaDeCodigos.IsEmpty then
  begin
    ShowMessage('Nenhum código de produto foi fornecido.');
    Exit;
  end;

  if not TryStrToInt(edtQuantidade.Text, Quantidade) then Quantidade := 1;
  if Quantidade <= 0 then Quantidade := 1;

  if not TryStrToInt(edtColuna.Text, NumColunas) then NumColunas := 1;
  if NumColunas <= 0 then NumColunas := 1;

  if not TryStrToFloat(edtLargura.Text, LarguraEtiqueta) then LarguraEtiqueta := 170.0;
  if not TryStrToFloat(edtAltura.Text, AlturaEtiqueta) then AlturaEtiqueta := 20.0;
  if not TryStrToFloat(edtEspacamento.Text, EspacamentoColunas) then EspacamentoColunas := 1.0;

  BufferSeguranca := 1.0;
  BufferVertical := 5.0;
  LarguraColunaFinal := LarguraEtiqueta + EspacamentoColunas;

  Etiqueta.PrinterSetup.Units := utMillimeters;

  if cbUnidade.ItemIndex = 1 then
    Etiqueta.PrinterSetup.Units := utInches;

  LarguraTotalPapel := (NumColunas * LarguraColunaFinal) + 4.0 + BufferSeguranca;
  AlturaEtiqueta := AlturaEtiqueta + BufferVertical;

  with Etiqueta do
  begin
    PrinterSetup.PaperWidth := LarguraTotalPapel;
    PrinterSetup.PaperHeight := AlturaEtiqueta;
    PrinterSetup.MarginLeft := 2;
    PrinterSetup.MarginTop := 2;
    Columns := NumColunas;
    ColumnWidth := LarguraColunaFinal;
    if NumColunas > 1 then
      ppDetailBand1.ColumnTraversal := ctLeftToRight;
  end;

  FDQuery2.Close;

  BaseSQL :=
    'SELECT P.au_ite AS CodigoProduto, P.ab_ite + '' '' + P.ac_ite AS Descricao, P.ad_ite AS CodigoUnidade, A.PrecoVendaMin AS PrecoMinimo, A.PrecoVendaMax AS PrecoMaximo, I.NCM AS NCM_Imposto, I.CSTsaidas AS CST_Saida, I.ALIQUOTAICMS AS AliquotaICMS ' +
    'FROM CE_PRODUTO P INNER JOIN CE_PRODUTOS_ADICIONAIS A ON P.au_ite = A.CodReduzido INNER JOIN CE_PRODUTOS_IMPOSTOS I ON P.au_ite = I.CodReduzido';

  FinalSQL := '';
  for I := 1 to Quantidade do
  begin
    if I > 1 then
      FinalSQL := FinalSQL + ' UNION ALL ';

    FinalSQL := FinalSQL + '(SELECT * FROM (' + BaseSQL + ') AS Base WHERE Base.CodigoProduto IN (''' + ListaDeCodigos + '''))';
  end;

  FDQuery2.SQL.Text := FinalSQL + ' ORDER BY CodigoProduto';
  try
    FDQuery2.Open;
  except
    on E: Exception do
    begin
      ShowMessage('Erro ao executar a consulta (SQL): ' + E.Message);
      Exit;
    end;
  end;

  Etiqueta.ShowPrintDialog := True;
  Etiqueta.PrintReport;

  FDQuery2.Close;
  FDQuery2.SQL.Text := BaseSQL + ' ORDER BY P.au_ite';
  FDQuery2.Open;
end;

end.
