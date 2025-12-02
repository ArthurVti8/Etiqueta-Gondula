unit UnitPrincipal;

interface

uses
  // Bibliotecas padrão do Windows e do Delphi
  Winapi.Windows, Winapi.Messages, Winapi.ShellAPI, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Data.DB, Math, System.IniFiles, // System.IniFiles é vital para salvar configurações
  // Bibliotecas do FireDAC (Acesso ao Banco de Dados)
  FireDAC.Stan.Intf, FireDAC.Stan.Option, FireDAC.Stan.Error, FireDAC.UI.Intf,
  FireDAC.Phys.Intf, FireDAC.Stan.Def, FireDAC.Phys.MSSQL, FireDAC.Phys.MSSQLDef, FireDAC.VCLUI.Wait,
  FireDAC.Stan.Param, FireDAC.DatS, FireDAC.DApt.Intf, FireDAC.DApt,
  Vcl.Grids, Vcl.DBGrids, FireDAC.Comp.DataSet,
  FireDAC.Comp.Client, Vcl.StdCtrls,
  // Bibliotecas do ReportBuilder (Gerador de Relatórios)
  ppDB, ppCtrls, ppPrnabl, ppClass,
  ppBarCod, ppBands, ppCache, ppDesignLayer, ppParameter, ppProd, ppReport,
  ppComm, ppRelatv, ppDBPipe, Vcl.Imaging.jpeg, Vcl.ExtCtrls,
  FireDAC.Stan.StorageBin, ppTypes, ppDevice, Printers, FireDAC.Stan.Pool,
  FireDAC.Stan.Async, FireDAC.Phys;

type
  TGeradorEtiquetas = class(TForm)
    // --- CONEXÃO E DADOS ---
    Conexao: TFDConnection;       // Conecta com o Banco SQL Server
    FDQuery2: TFDQuery;           // Faz a busca (SELECT) dos produtos
    mtEtiquetas: TFDMemTable;     // [PERFORMANCE] Tabela na memória RAM para duplicar etiquetas
    DataSource1: TDataSource;     // Liga os dados ao Grid
    ppDBPipeline1: TppDBPipeline; // Liga os dados ao Relatório
    Etiqueta: TppReport;          // O desenho da etiqueta em si

    // --- COMPONENTES DO REPORT BUILDER ---
    ppParameterList1: TppParameterList;
    ppDesignLayers1: TppDesignLayers;
    ppDesignLayer1: TppDesignLayer;
    ppDetailBand1: TppDetailBand;
    ppDBBarCode1: TppDBBarCode; // Código de Barras
    ppDBText2: TppDBText;
    ppDBText3: TppDBText;
    ppLabel1: TppLabel;
    ppDBText1: TppDBText;
    ppLabel2: TppLabel;
    ppColumnHeaderBand1: TppColumnHeaderBand;
    ppColumnFooterBand1: TppColumnFooterBand;
    ppShape1: TppShape;

    // --- ESTRUTURA VISUAL (PAINÉIS) ---
    Panel1: TPanel; // Topo (Título)
    Panel2: TPanel; // Lateral Azul (Menu de Opções)
    DBGrid1: TDBGrid; // Grade que mostra os dados
    Label1: TLabel; // Título "Gerador de Etiqueta"
    Image1: TImage; // Logotipo

    // --- CAMPOS E RÓTULOS (INPUTS) ---
    Label2: TLabel; // Rótulo "Código"
    Label7: TLabel; // Rótulo "Quantidade"
    Label3: TLabel; // Rótulo "Colunas"
    Label8: TLabel; // Rótulo "Unidade de Medida"
    Label4: TLabel; // Rótulo "Largura"
    Label5: TLabel; // Rótulo "Altura"
    Label6: TLabel; // Rótulo "Espaçamento"
    label9: TLabel; // Rótulo "Tipo Impressão"

    edtCodigo: TEdit;       // Onde digita os códigos (ex: 1, 2, 3)
    edtQuantidade: TEdit;   // Quantas cópias de cada
    edtColuna: TEdit;       // Quantas colunas na folha
    cbUnidade: TComboBox;   // Polegadas ou Milímetros
    edtLargura: TEdit;      // Largura da etiqueta
    edtAltura: TEdit;       // Altura da etiqueta
    edtEspacamento: TEdit;  // Espaço entre colunas

    cbTipoImpressao: TComboBox;     // Tela ou Impressora
    rgFormatoExportacao: TRadioGroup; // CSV ou Excel
    BtnGerarEtiqueta: TButton;      // Botão Principal
    BtnExcel: TButton;              // Botão Exportar

    // --- MÉTODOS (Ações do Sistema) ---
    procedure BtnGerarEtiquetaClick(Sender: TObject); // Clique no Gerar
    procedure BtnExcelClick(Sender: TObject);         // Clique no Exportar
    procedure FormCreate(Sender: TObject);            // Quando a janela abre
    procedure FormClose(Sender: TObject; var Action: TCloseAction); // Quando fecha
    procedure FormResize(Sender: TObject);            // Quando muda o tamanho da tela

  private
    // Funções Auxiliares (Ajudam o código principal a ficar limpo)
    function BuildHTMLTable(DataSet: TDataSet): string; // Cria o HTML para o Excel
    function FormatAsCurrency(const Value: Variant): string; // Formata R$ 0,00

    // Configura o papel e margens do ReportBuilder via código
    procedure ConfigureReportForLabels(NumColunas: Integer; LarguraEtiqueta, AlturaEtiqueta, Espacamento: Single);

    // Salva e Carrega as preferências do usuário (INI)
    procedure CarregarConfiguracoes;
    procedure SalvarConfiguracoes;

    // Ajusta o visual (Posiciona botões e campos manualmente)
    procedure PosicionarCampo(Lb: TLabel; Ctrl: TControl; X, Y, W: Integer);
    procedure AjustarLayoutGeral;
  public
  end;

var
  GeradorEtiquetas: TGeradorEtiquetas;

implementation

{$R *.dfm}

// ============================================================================
//  LAYOUT INTELIGENTE
//  Aqui definimos onde cada campo vai ficar na tela.
//  Usamos código em vez de arrastar o mouse para garantir que fiquem alinhados.
// ============================================================================

// Helper: Funçãozinha simples para colar o Rótulo (Label) em cima do Campo (Edit)
procedure TGeradorEtiquetas.PosicionarCampo(Lb: TLabel; Ctrl: TControl; X, Y, W: Integer);
begin
  if Assigned(Ctrl) then
  begin
    Ctrl.Left  := X;      // Posição Horizontal
    Ctrl.Top   := Y;      // Posição Vertical
    Ctrl.Width := W;      // Largura do campo

    if Assigned(Lb) then
    begin
      Lb.Left := X;
      Lb.Top  := Y - Lb.Height - 3; // Coloca o texto 3 pixels acima do campo
    end;
  end;
end;

// A MÁGICA DO VISUAL: Organiza tudo quando a tela muda de tamanho
procedure TGeradorEtiquetas.AjustarLayoutGeral;
var
  i: Integer;
  LarguraTotal, LarguraMedia: Integer;
  MargemInferior, AlturaLinha: Integer;
  Col1, Col2: Integer; // Define onde começa a coluna da esquerda e a da direita
  Y: Integer;          // Funciona como um cursor vertical (onde estou desenhando agora)
  PainelLateral: TPanel;
begin
  PainelLateral := Panel2; // Aponta para o painel azul

  // 1. AJUSTA O GRID (Lado Direito)
  // Divide a largura da tela pelo número de colunas para preencher tudo
  if DBGrid1.Columns.Count > 0 then
  begin
    LarguraTotal := DBGrid1.ClientWidth - 25; // Desconta a barra de rolagem
    if LarguraTotal > 0 then
    begin
      LarguraMedia := LarguraTotal div DBGrid1.Columns.Count;
      for i := 0 to DBGrid1.Columns.Count - 1 do
        DBGrid1.Columns[i].Width := LarguraMedia;
    end;
  end;

  // 2. ORGANIZA OS CAMPOS (Painel Azul)
  Col1 := 20;   // Margem da Esquerda
  Col2 := 180;  // Margem da Direita (Segunda coluna de campos)
  Y    := 50;   // Começa na altura 50
  AlturaLinha := 55; // Pula 55 pixels a cada linha

  // --- LINHA 1: Código e Quantidade ---
  PosicionarCampo(Label2, edtCodigo,      Col1, Y, 140);
  PosicionarCampo(Label7, edtQuantidade,  Col2, Y, 80);

  // --- LINHA 2: Colunas e Unidade de Medida ---
  Y := Y + AlturaLinha; // Desce uma linha
  PosicionarCampo(Label3, edtColuna,      Col1, Y, 80);
  PosicionarCampo(Label8, cbUnidade,      Col2, Y, 130);

  // --- LINHA 3: Dimensões (Largura, Altura, Espaço) ---
  Y := Y + AlturaLinha;
  PosicionarCampo(Label4, edtLargura,     Col1, Y, 60);
  // Aqui fazemos um ajuste manual pra caber 3 campos na mesma linha
  PosicionarCampo(Label5, edtAltura,      Col1 + 70, Y, 60);
  PosicionarCampo(Label6, edtEspacamento, Col1 + 140, Y, 60);

  // --- LINHA 4: Tipo de Impressão ---
  Y := Y + AlturaLinha;
  PosicionarCampo(label9, cbTipoImpressao, Col1, Y, 210);

  // --- LINHA 5: Exportação ---
  Y := Y + AlturaLinha;
  if Assigned(rgFormatoExportacao) then
  begin
    rgFormatoExportacao.Left := Col1;
    rgFormatoExportacao.Top  := Y;
    rgFormatoExportacao.Width := 290;
    rgFormatoExportacao.Height := 75;
  end;

  // 3. POSICIONA OS BOTÕES NO RODAPÉ
  // Isso garante que os botões fiquem sempre lá embaixo, mesmo se a tela for gigante
  MargemInferior := 20;
  if PainelLateral.Height > 500 then
  begin
    // Botão GERAR na Esquerda
    BtnGerarEtiqueta.Left  := Col1;
    BtnGerarEtiqueta.Width := 140;
    BtnGerarEtiqueta.Top   := PainelLateral.Height - BtnGerarEtiqueta.Height - MargemInferior;

    // Botão EXCEL na Direita
    BtnExcel.Left  := Col2;
    BtnExcel.Width := 140;
    BtnExcel.Top   := BtnGerarEtiqueta.Top;
  end;
end;

// Evento disparado pelo Windows quando redimensiona a janela
procedure TGeradorEtiquetas.FormResize(Sender: TObject);
begin
  AjustarLayoutGeral; // Chama nossa função de layout
end;

// ============================================================================
//  PERSISTÊNCIA (INI) - Salvar o que o usuário digitou
// ============================================================================

procedure TGeradorEtiquetas.CarregarConfiguracoes;
var
  ArquivoIni: TIniFile;
begin
  // Abre um arquivo .ini com o mesmo nome do executável
  ArquivoIni := TIniFile.Create(ChangeFileExt(Application.ExeName, '.ini'));
  try
    // Lê os valores. Se não existir, usa um valor padrão (ex: '4,0')
    edtLargura.Text     := ArquivoIni.ReadString('ConfigEtiqueta', 'Largura', '4,0');
    edtAltura.Text      := ArquivoIni.ReadString('ConfigEtiqueta', 'Altura', '2,0');
    edtColuna.Text      := ArquivoIni.ReadString('ConfigEtiqueta', 'Colunas', '1');
    edtEspacamento.Text := ArquivoIni.ReadString('ConfigEtiqueta', 'Espacamento', '0,1');
    edtQuantidade.Text  := ArquivoIni.ReadString('ConfigEtiqueta', 'QuantidadePadrao', '1');

    // Recupera a seleção dos Combos
    if ArquivoIni.ValueExists('ConfigEtiqueta', 'TipoImpressao') then
      cbTipoImpressao.ItemIndex := ArquivoIni.ReadInteger('ConfigEtiqueta', 'TipoImpressao', 0);

    if ArquivoIni.ValueExists('ConfigEtiqueta', 'UnidadeMedida') then
      cbUnidade.ItemIndex := ArquivoIni.ReadInteger('ConfigEtiqueta', 'UnidadeMedida', 0);
  finally
    ArquivoIni.Free; // Fecha o arquivo
  end;
end;

procedure TGeradorEtiquetas.SalvarConfiguracoes;
var
  ArquivoIni: TIniFile;
begin
  ArquivoIni := TIniFile.Create(ChangeFileExt(Application.ExeName, '.ini'));
  try
    // Grava tudo o que está na tela
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
//  INICIALIZAÇÃO DO FORMULÁRIO (Ao abrir o programa)
// ============================================================================
procedure TGeradorEtiquetas.FormCreate(Sender: TObject);
var
  i: Integer;
begin
  Self.WindowState := wsMaximized; // Abre em Tela Cheia

  // 1. Configura os Painéis
  if Assigned(Panel1) then Panel1.Align := alTop;   // Topo
  if Assigned(Panel2) then
  begin
    Panel2.Align := alLeft;  // Lateral
    Panel2.Width := 340;     // Largura fixa
    Panel2.ParentBackground := False; // Evita bugs visuais

    // TRUQUE IMPORTANTE: Desativa as "âncoras" automáticas do Delphi.
    // Isso impede que os botões mudem de lugar sozinhos ao maximizar.
    // Deixamos nosso código "AjustarLayoutGeral" cuidar disso.
    for i := 0 to Panel2.ControlCount - 1 do
      Panel2.Controls[i].Anchors := [akLeft, akTop];
  end;
  DBGrid1.Align := alClient; // Grid preenche o resto

  // 2. Preenche as opções dos Combos
  cbUnidade.Items.Clear;
  cbUnidade.Items.Add('Polegadas (inches)');
  cbUnidade.Items.Add('Milímetros (mm)');
  cbUnidade.ItemIndex := 0;

  cbTipoImpressao.Items.Clear;
  cbTipoImpressao.Items.Add('Visualizar (Prévia)');
  cbTipoImpressao.Items.Add('Imprimir Direto');
  cbTipoImpressao.ItemIndex := 0;

  // 3. Define a ordem do TAB (Para o cursor pular corretamente ao dar Enter)
  edtCodigo.TabOrder       := 0;
  edtQuantidade.TabOrder   := 1;
  edtColuna.TabOrder       := 2;
  cbUnidade.TabOrder       := 3;
  edtLargura.TabOrder      := 4;
  edtAltura.TabOrder       := 5;
  edtEspacamento.TabOrder  := 6;
  cbTipoImpressao.TabOrder := 7;
  rgFormatoExportacao.TabOrder := 8;
  BtnGerarEtiqueta.TabOrder    := 9;
  BtnExcel.TabOrder            := 10;

  // 4. Carrega configurações salvas e ajusta o layout
  CarregarConfiguracoes;
  AjustarLayoutGeral;

  // 5. Configura o Pipeline do Relatório
  // Dizemos pro relatório olhar para a Tabela de Memória, e não pro SQL direto.
  //
  DataSource1.DataSet := mtEtiquetas;
  ppDBPipeline1.DataSource := DataSource1;
end;

// Ao fechar, salva tudo
procedure TGeradorEtiquetas.FormClose(Sender: TObject; var Action: TCloseAction);
begin
  SalvarConfiguracoes;
end;

// ============================================================================
//  LÓGICA PRINCIPAL: GERAR ETIQUETA
// ============================================================================
procedure TGeradorEtiquetas.BtnGerarEtiquetaClick(Sender: TObject);
var
  ListaDeCodigos: string;
  Quantidade, NumColunas, I: Integer;
  LarguraEtiqueta, AlturaEtiqueta, EspacamentoColunas: Single;
  BaseSQL: string;
  ListaDeCodigosFormatada: string;
begin
  // 1. Validação básica
  if Trim(edtCodigo.Text) = '' then
  begin
    ShowMessage('Informe os códigos dos produtos.');
    edtCodigo.SetFocus;
    Exit;
  end;

  // 2. Tratamento da string de códigos (Limpeza)
  // Transforma "1 2 3" ou "1, 2, 3" em "1,2,3"
  ListaDeCodigos := StringReplace(edtCodigo.Text, ' ', ',', [rfReplaceAll]);
  ListaDeCodigos := StringReplace(ListaDeCodigos, #13#10, ',', [rfReplaceAll]); // Remove quebra de linha
  while Pos(',,', ListaDeCodigos) > 0 do
    ListaDeCodigos := StringReplace(ListaDeCodigos, ',,', ',', [rfReplaceAll]); // Remove virgulas duplas

  // Remove virgulas no começo ou fim
  if (ListaDeCodigos <> '') and (ListaDeCodigos[Length(ListaDeCodigos)] = ',') then
    Delete(ListaDeCodigos, Length(ListaDeCodigos), 1);
  if (ListaDeCodigos <> '') and (ListaDeCodigos[1] = ',') then
    Delete(ListaDeCodigos, 1, 1);

  // Formata para SQL: De 1,2,3 para '1','2','3' (Necessário para campos String)
  ListaDeCodigosFormatada := '''' + StringReplace(ListaDeCodigos, ',', ''',''', [rfReplaceAll]) + '''';
  if ListaDeCodigosFormatada = '''''' then Exit;

  // 3. Captura Valores da Tela (Convertendo Texto para Número)
  Quantidade := StrToIntDef(edtQuantidade.Text, 1);
  if Quantidade <= 0 then Quantidade := 1;
  NumColunas := StrToIntDef(edtColuna.Text, 1);
  LarguraEtiqueta := StrToFloatDef(edtLargura.Text, 4.0);
  AlturaEtiqueta  := StrToFloatDef(edtAltura.Text, 2.0);
  EspacamentoColunas := StrToFloatDef(edtEspacamento.Text, 0);

  // 4. Configura o Relatório Visualmente (Tamanho do Papel)
  ConfigureReportForLabels(NumColunas, LarguraEtiqueta, AlturaEtiqueta, EspacamentoColunas);

  // 5. Monta e Executa o SQL
  //

[Image of SQL Inner Join Venn Diagram]

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
    FDQuery2.Open; // Vai no banco buscar os dados

    if FDQuery2.IsEmpty then
    begin
      ShowMessage('Nenhum produto encontrado com esses códigos.');
      Exit;
    end;

    // 6. PERFORMANCE (Memória RAM)
    // Em vez de pedir pro banco repetir 1000 vezes, a gente copia pra RAM e repete lá.
    // Isso evita travar o servidor.
    mtEtiquetas.Close;
    mtEtiquetas.FieldDefs.Clear;
    mtEtiquetas.FieldDefs.Assign(FDQuery2.FieldDefs); // Copia estrutura
    mtEtiquetas.CreateDataSet; // Cria tabela virtual

    mtEtiquetas.DisableControls; // Trava o grid visualmente pra ser mais rápido
    try
      // Loop 1: Quantidade de cópias
      for I := 1 to Quantidade do
      begin
        FDQuery2.First;
        // Loop 2: Percorre todos os produtos encontrados
        while not FDQuery2.Eof do
        begin
          mtEtiquetas.Append; // Cria linha nova na RAM
          mtEtiquetas.CopyFields(FDQuery2); // Copia dados
          mtEtiquetas.Post; // Salva
          FDQuery2.Next;
        end;
      end;
    finally
      mtEtiquetas.First;
      mtEtiquetas.EnableControls; // Destrava o grid
    end;

    AjustarLayoutGeral; // Garante que o visual não quebrou

    // 7. Imprime
    DataSource1.DataSet := mtEtiquetas; // Aponta pra memória
    Etiqueta.ShowPrintDialog := True;

    // Escolhe tela ou impressora
    if cbTipoImpressao.ItemIndex = 0 then
       Etiqueta.DeviceType := 'Screen'
    else
       Etiqueta.DeviceType := 'Printer';

    Etiqueta.Print;

  except
    on E: Exception do
      ShowMessage('Erro ao gerar: ' + E.Message);
  end;
end;

// ============================================================================
//  CONFIGURAÇÃO DO RELATÓRIO (ReportBuilder)
// ============================================================================
procedure TGeradorEtiquetas.ConfigureReportForLabels(NumColunas: Integer;
  LarguraEtiqueta, AlturaEtiqueta, Espacamento: Single);
var
  LarguraTotalPapel, MargemSeguranca: Double;
begin
  // Define a unidade de medida (Polegadas ou mm)
  if cbUnidade.ItemIndex = 1 then
     Etiqueta.Units := utMillimeters
  else
     Etiqueta.Units := utInches;

  MargemSeguranca := 0.1; // Margem pequena de segurança

  // Calcula largura total da página baseada nas colunas
  if NumColunas > 1 then
    LarguraTotalPapel := (LarguraEtiqueta * NumColunas) + (Espacamento * (NumColunas - 1)) + (MargemSeguranca * 2)
  else
    LarguraTotalPapel := LarguraEtiqueta + (MargemSeguranca * 2);

  // Configura a impressora virtual
  with Etiqueta.PrinterSetup do
  begin
    PaperName   := 'Custom'; // Customizado
    PaperWidth  := LarguraTotalPapel;
    PaperHeight := AlturaEtiqueta;
    // Zera margens do driver pra gente controlar
    MarginTop := 0; MarginBottom := 0; MarginLeft := MargemSeguranca; MarginRight := MargemSeguranca;

    // Define paisagem ou retrato automaticamente
    if PaperWidth > PaperHeight then Orientation := poLandscape else Orientation := poPortrait;
  end;

  // Configura colunas no componente
  Etiqueta.Columns := NumColunas;
  if NumColunas > 1 then
  begin
    Etiqueta.ColumnWidth := LarguraEtiqueta;
    ppDetailBand1.ColumnTraversal := ctLeftToRight; // Preenche da esquerda pra direita
  end
  else
    Etiqueta.ColumnWidth := LarguraTotalPapel;
end;

// ============================================================================
//  EXPORTAÇÃO PARA EXCEL / CSV
// ============================================================================

// Formata valor monetário para texto (R$ 10,00)
function TGeradorEtiquetas.FormatAsCurrency(const Value: Variant): string;
var FormatSettings: TFormatSettings;
begin
  FormatSettings := TFormatSettings.Create;
  FormatSettings.CurrencyString := 'R$ ';
  FormatSettings.CurrencyFormat := 2;
  Result := FormatFloat('#,##0.00', Value, FormatSettings);
  Result := StringReplace(Result, '.', ',', [rfReplaceAll]); // Garante vírgula
end;

// Cria uma tabela HTML simples que o Excel consegue ler como planilha
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

    // Cabeçalho
    FieldNames := '';
    for I := 0 to DataSet.Fields.Count - 1 do
      FieldNames := FieldNames + '<th>' + DataSet.Fields[I].FieldName + '</th>';
    HTML.Add('<tr>' + FieldNames + '</tr>');

    // Dados
    DataSet.DisableControls;
    try
      DataSet.First;
      while not DataSet.Eof do
      begin
        HTML.Add('<tr>');
        for I := 0 to DataSet.Fields.Count - 1 do
        begin
          FieldValue := DataSet.Fields[I].AsString;
          // Formata moeda se for número
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
  TempList: TStringList;
  I: Integer;
  UseXLS: Boolean;
  LinhaDados: string;
const CSV_SEP = #9; // Tabulação (Melhor que ponto e vírgula pro Excel)
begin
  UseXLS := (rgFormatoExportacao.ItemIndex = 1);
  SaveDialog := TSaveDialog.Create(nil);
  TempList := TStringList.Create;
  try
    // Configura filtro do diálogo de salvar
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
      // Decide qual fonte de dados usar (Memória ou Banco direto)
      if mtEtiquetas.Active and (mtEtiquetas.RecordCount > 0) then mtEtiquetas.First
      else if not FDQuery2.Active then FDQuery2.Open;

      if mtEtiquetas.Active and (mtEtiquetas.RecordCount > 0) then
      begin
         if UseXLS then
             TempList.Text := BuildHTMLTable(mtEtiquetas) // Gera HTML/XLS
         else begin
            // Gera CSV na mão
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
         if UseXLS then TempList.Text := BuildHTMLTable(FDQuery2);
      end;

      TempList.SaveToFile(SaveDialog.FileName, TEncoding.UTF8);
      ShowMessage('Exportado com sucesso!');
    end;
  finally
    SaveDialog.Free;
    TempList.Free;
  end;
end;

end.
