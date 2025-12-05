{******************************************}
{                                          }
{             FastReport v4.0              }
{          Language resource file          }
{                                          }
{         Copyright (c) 1998-2008          }
{         by Alexander Tzyganenko,         }
{            Fast Reports Inc.             }
{                                          }
{******************************************}

unit frxrcExports;

interface

implementation

uses frxRes;

const resXML =
'<?xml version="1.1" encoding="utf-8"?><Resources CodePage="1252"><StrRes Name="8000" Text="Exportar para Excel"/><StrRes Name="8001" Text="Estilos"/><' + 
'StrRes Name="8002" Text="Figuras"/><StrRes Name="8003" Text="Unir Células"/><StrRes Name="8004" Text="Exportação rápida"/><StrRes Name="8005" Text' + 
'="WYSIWYG"/><StrRes Name="8006" Text="Como texto"/><StrRes Name="8007" Text="Fundo"/><StrRes Name="8008" Text="Abrir o Excel após exportar"/><StrRes ' + 
'Name="8009" Text="Ficheiro Excel (*.xls)|*.xls"/><StrRes Name="8010" Text=".xls"/><StrRes Name="8100" Text="Exportar para Excel XML"/><StrRes Name="81' + 
'01" Text="Estilos"/><StrRes Name="8102" Text="WYSIWYG"/><StrRes Name="8103" Text="Fundo"/><StrRes Name="8104" Text="Abrir o Excel após exportar"/><St' + 
'rRes Name="8105" Text="Ficheiro Excel XML (*.xml)|*.xml"/><StrRes Name="8106" Text=".xml"/><StrRes Name="8200" Text="Exportar para tabela HTML"/><StrR' + 
'es Name="8201" Text="Abrir após exportar"/><StrRes Name="8202" Text="Estilos"/><StrRes Name="8203" Text="Figuras"/><StrRes Name="8204" Text="Todas nu' + 
'ma pasta"/><StrRes Name="8205" Text="Largura fixa"/><StrRes Name="8206" Text="Navegador"/><StrRes Name="8207" Text="Multi-páginas"/><StrRes Name="820' + 
'8" Text="Browser Mozilla"/><StrRes Name="8209" Text="Fundo"/><StrRes Name="8210" Text="Ficheiro HTML (*.html)|*.html"/><StrRes Name="8211" Text=".html' + 
'"/><StrRes Name="8300" Text="Exportar para texto(Impr.Matricial)"/><StrRes Name="8301" Text="Pré-visualizar on/off"/><StrRes Name="8302" Text=" Opç�' + 
'�es de Exportação  "/><StrRes Name="8303" Text="Quebras de Página"/><StrRes Name="8304" Text="OEM codepage"/><StrRes Name="8305" Text="Linhas vazia' + 
's"/><StrRes Name="8306" Text="Espaços iniciais"/><StrRes Name="8307" Text="Páginas:"/><StrRes Name="8308" Text="Digite números de página e/ou inte' + 
'rvalos, separados por vírgulas. Por exemplo, 1,3,5-12"/><StrRes Name="8309" Text=" Escala "/><StrRes Name="8310" Text="Escala X"/><StrRes Name="8311"' + 
' Text="Escala Y"/><StrRes Name="8312" Text=" Limites "/><StrRes Name="8313" Text="Nenhum"/><StrRes Name="8314" Text="Simples"/><StrRes Name="8315" Tex' + 
't="Gráfico"/><StrRes Name="8316" Text="Apenas com OEM codepage"/><StrRes Name="8317" Text="Imprimir após exportar"/><StrRes Name="8318" Text="Guarda' + 
'r configuração"/><StrRes Name="8319" Text=" Pré-visualizar "/><StrRes Name="8320" Text="Largura:"/><StrRes Name="8321" Text="Altura:"/><StrRes Name' + 
'="8322" Text="Página"/><StrRes Name="8323" Text="Mais Zoom"/><StrRes Name="8324" Text="Menos Zoom"/><StrRes Name="8325" Text="Ficheiro de texto (impr' + 
'essora matricial)(*.prn)|*.prn"/><StrRes Name="8326" Text=".prn"/><StrRes Name="8400" Text="Imprimir"/><StrRes Name="8401" Text="Impressora"/><StrRes ' + 
'Name="8402" Text="Nome"/><StrRes Name="8403" Text="Configuração..."/><StrRes Name="8404" Text="Cópias"/><StrRes Name="8405" Text="Número de cópia' + 
's"/><StrRes Name="8406" Text=" Inicialização da Impressora "/><StrRes Name="8407" Text="Tipo de Impressora"/><StrRes Name="8408" Text=".fpi"/><StrRe' + 
's Name="8409" Text="Modelo de inicialização de Impressora (*.fpi)|*.fpi"/><StrRes Name="8410" Text=".fpi"/><StrRes Name="8411" Text="Modelo de inici' + 
'alização de Impressora (*.fpi)|*.fpi"/><StrRes Name="8500" Text="Exportar para RTF"/><StrRes Name="8501" Text="Figuras"/><StrRes Name="8502" Text="W' + 
'YSIWYG"/><StrRes Name="8503" Text="Abrir após exportar"/><StrRes Name="8504" Text="Ficheiro RTF (*.rtf)|*.rtf"/><StrRes Name="8505" Text=".rtf"/><Str' + 
'Res Name="8600" Text="Exportar para Imagem"/><StrRes Name="8601" Text=" Opções da Imagem "/><StrRes Name="8602" Text="Qualidade JPEG"/><StrRes Name=' + 
'"8603" Text="Resolução (dpi)"/><StrRes Name="8604" Text="Ficheiros separados"/><StrRes Name="8605" Text="Reduzir página"/><StrRes Name="8606" Text=' + 
'"Monocromática"/><StrRes Name="8700" Text="Exportar para PDF"/><StrRes Name="8701" Text="PDF/A"/><StrRes Name="8702" Text="T.Letra Embutidos"/><StrRe' + 
's Name="8703" Text="Optimizar p/impressão"/><StrRes Name="8704" Text="Resumo"/><StrRes Name="8705" Text="Fundo"/><StrRes Name="8706" Text="Abrir apó' + 
's exportar"/><StrRes Name="8707" Text="Ficheiro Adobe PDF (*.pdf)|*.pdf"/><StrRes Name="8708" Text=".pdf"/><StrRes Name="8709" Text="Compressed"/><Str' + 
'Res Name="RTFexport" Text="Ficheiro RTF"/><StrRes Name="BMPexport" Text="Imagem BMP"/><StrRes Name="JPEGexport" Text="Imagem JPEG"/><StrRes Name="TIFF' + 
'export" Text="Imagem TIFF"/><StrRes Name="PNGexport" Text="Imagem PNG"/><StrRes Name="EMFexport" Text="Imagem EMF"/><StrRes Name="TextExport" Text="Te' + 
'xto (impressora matricial)"/><StrRes Name="XlsOLEexport" Text="Tabela Excel (OLE)"/><StrRes Name="HTMLexport" Text="Ficheiro HTML"/><StrRes Name="XlsX' + 
'MLexport" Text="Tabela Excel (XML)"/><StrRes Name="PDFexport" Text="Ficheiro PDF"/><StrRes Name="ProgressWait" Text="Aguarde por favor"/><StrRes Name=' + 
'"ProgressRows" Text="Definindo linhas"/><StrRes Name="ProgressColumns" Text="Definindo colunas"/><StrRes Name="ProgressStyles" Text="Definindo estilos' + 
'"/><StrRes Name="ProgressObjects" Text="Exportando objectos"/><StrRes Name="TIFFexportFilter" Text="Imagem Tiff (*.tif)|*.tif"/><StrRes Name="BMPexpor' + 
'tFilter" Text="Imagem BMP (*.bmp)|*.bmp"/><StrRes Name="JPEGexportFilter" Text="Imagem Jpeg (*.jpg)|*.jpg"/><StrRes Name="PNGexportFilter" Text="Image' + 
'm PNG (*.png)|*.png"/><StrRes Name="EMFexportFilter" Text="Imagem EMF (*.emf)|*.emf"/><StrRes Name="HTMLNavFirst" Text="Primeira"/><StrRes Name="HTMLN' + 
'avPrev" Text="Anterior"/><StrRes Name="HTMLNavNext" Text="Próxima"/><StrRes Name="HTMLNavLast" Text="Última"/><StrRes Name="HTMLNavRefresh" Text="Re' + 
'frescar"/><StrRes Name="HTMLNavPrint" Text="Imprimir"/><StrRes Name="HTMLNavTotal" Text="Total de páginas"/><StrRes Name="8800" Text="Exportar para T' + 
'exto"/><StrRes Name="8801" Text="Ficheiro de texto (*.txt)|*.txt"/><StrRes Name="8802" Text=".txt"/><StrRes Name="SimpleTextExport" Text="Ficheiro de ' + 
'Texto"/><StrRes Name="8850" Text="Exportar para CSV"/><StrRes Name="8851" Text="Ficheiro CSV (*.csv)|*.csv"/><StrRes Name="8852" Text=".csv"/><StrRes ' + 
'Name="8853" Text="Separador"/><StrRes Name="CSVExport" Text="Ficheiro CSV"/><StrRes Name="8900" Text="Enviar por e-mail"/><StrRes Name="8901" Text="E-' + 
'mail"/><StrRes Name="8902" Text="Conta"/><StrRes Name="8903" Text="Servidor de correio (SMTP)"/><StrRes Name="8904" Text="Para"/><StrRes Name="8905" T' + 
'ext="Anexo"/><StrRes Name="8906" Text="Formato"/><StrRes Name="8907" Text="Endereço"/><StrRes Name="8908" Text="Nome"/><StrRes Name="8909" Text="Serv' + 
'idor"/><StrRes Name="8910" Text="Utilizador"/><StrRes Name="8911" Text="Remetente"/><StrRes Name="8912" Text="Mensagem"/><StrRes Name="8913" Text="Tex' + 
'to"/><StrRes Name="8914" Text="Organização"/><StrRes Name="8915" Text="Password"/><StrRes Name="8916" Text="Porta"/><StrRes Name="8917" Text="Memori' + 
'zar propriedades"/><StrRes Name="8918" Text="Campos obrigatórios estão em branco"/><StrRes Name="8919" Text="Configuração avançada de exportaçã' + 
'o"/><StrRes Name="8920" Text="Assinatura"/><StrRes Name="8921" Text="Gerar"/><StrRes Name="8922" Text="Assunto"/><StrRes Name="8923" Text="Com os melh' + 
'ores cumprimentos"/><StrRes Name="8924" Text="Enviar correio para"/><StrRes Name="EmailExport" Text="E-mail"/><StrRes Name="FastReportFile" Text="Fich' + 
'eiro FastReport"/><StrRes Name="GifexportFilter" Text="Ficheiro Gif (*.gif)|*.gif"/><StrRes Name="GIFexport" Text="Imagem Gif"/><StrRes Name="8950" Te' + 
'xt="Contínuo"/><StrRes Name="8951" Text="Cabeçalhos/Rodapés"/><StrRes Name="8952" Text="Texto"/><StrRes Name="8953" Text="Cabeçalho/Rodapé"/><Str' + 
'Res Name="8954" Text="Nenhum"/><StrRes Name="ODSExportFilter" Text="Folha de Cálculo Open Document (*.ods)|*.ods"/><StrRes Name="ODSExport" Text="Fol' + 
'ha de Cálculo Open Document"/><StrRes Name="ODTExportFilter" Text="Texto Open Document (*.odt)|*.odt"/><StrRes Name="ODTExport" Text="Texto Open Docu' + 
'ment"/><StrRes Name="8960" Text=".ods"/><StrRes Name="8961" Text=".odt"/><StrRes Name="8962" Text="Segurança"/><StrRes Name="8963" Text="Configuraç�' + 
'�o da segurança"/><StrRes Name="8964" Text="Senha das permissões"/><StrRes Name="8965" Text="Senha de abertura"/><StrRes Name="8966" Text="Imprimir ' + 
'documento"/><StrRes Name="8967" Text="Alterar documento"/><StrRes Name="8968" Text="Copiar texto e gráficos"/><StrRes Name="8969" Text="Adicionar ou ' + 
'modificar anotações"/><StrRes Name="8970" Text="Segurança PDF"/><StrRes Name="8971" Text="Informação sobre o documento"/><StrRes Name="8972" Text' + 
'="Informação"/><StrRes Name="8973" Text="Título"/><StrRes Name="8974" Text="Autor"/><StrRes Name="8975" Text="Assunto"/><StrRes Name="8976" Text="P' + 
'alavras Chave"/><StrRes Name="8977" Text="Criador"/><StrRes Name="8978" Text="Produtor"/><StrRes Name="8979" Text="Autenticação"/><StrRes Name="8980' + 
'" Text="Permissões"/><StrRes Name="8981" Text="Leitor"/><StrRes Name="8982" Text="Preferências do leitor"/><StrRes Name="8983" Text="Ocultar barra d' + 
'e ferramentas"/><StrRes Name="8984" Text="Ocultar menu"/><StrRes Name="8985" Text="Ocultar painel de navegação"/><StrRes Name="8986" Text="Ajustar t' + 
'amanho da janela"/><StrRes Name="8987" Text="Centrar janela"/><StrRes Name="8988" Text="Imprimir à escala"/><StrRes Name="8989" Text="Confirmação d' + 
'e leitura"/><StrRes Name="9000" Text="NºLinhas:"/><StrRes Name="9001" Text="Separar"/><StrRes Name="9002" Text="Não separar"/><StrRes Name="9003" Te' + 
'xt="Usar páginas do relatório"/><StrRes Name="9004" Text="Usar impressão no pai"/><StrRes Name="9101" Text="Exportar para DBF"/><StrRes Name="9102"' + 
' Text="Exportação dBase (DBF)"/><StrRes Name="9103" Text=".dbf"/><StrRes Name="9104" Text="Falha ao carregar o ficheiro"/><StrRes Name="9105" Text="' + 
'Falha"/><StrRes Name="9106" Text="Nomes dos campos"/><StrRes Name="9107" Text="Automaticamente"/><StrRes Name="9108" Text="Manualmente"/><StrRes Name=' + 
'"9109" Text="Carregar do ficheiro"/><StrRes Name="9110" Text="Ficheiro de Texto (*.txt)|*.txt|Todos|*.*"/><StrRes Name="9111" Text="Ficheiro DBF (*.db' + 
'f)|*.dbf|Todos|*.*"/><StrRes Name="9151" Text="Ficheiro Excel 97/2000/XP"/><StrRes Name="9152" Text="Criar ficheiro automaticamente"/><StrRes Name="91' + 
'53" Text="Opções"/><StrRes Name="9154" Text="Pág."/><StrRes Name="9155" Text="Grelha"/><StrRes Name="9156" Text="Tudo numa página"/><StrRes Name="' + 
'9157" Text="Agrupamento"/><StrRes Name="9158" Text="Como o relatório"/><StrRes Name="9159" Text="Secções. Cada secção tem(linhas):"/><StrRes Name' + 
'="9160" Text="Tamanho da secção tem de ser um número não negativo."/><StrRes Name="9161" Text="Ao exportar por secções, não pode escolher Tudo ' + 
'Numa Página"/><StrRes Name="9162" Text="Autor"/><StrRes Name="9163" Text="Comentário"/><StrRes Name="9164" Text="Palavras Chave"/><StrRes Name="9165' + 
'" Text="Revisão"/><StrRes Name="9166" Text="Versão"/><StrRes Name="9167" Text="Aplicação"/><StrRes Name="9168" Text="Assunto"/><StrRes Name="9169"' + 
' Text="Categoria"/><StrRes Name="9170" Text="Companhia"/><StrRes Name="9171" Text="Título"/><StrRes Name="9172" Text="Gestor"/><StrRes Name="9173" Te' + 
'xt="Geral"/><StrRes Name="9174" Text="Informação"/><StrRes Name="9175" Text="Protecção"/><StrRes Name="9176" Text="Password"/><StrRes Name="9177" ' + 
'Text="Se indicar uma password, o documento gerado estará protegido por essa password. A password é sempre guardada em caracteres Unicode e tem de se' + 
'r menor que caracteres Unicode."/><StrRes Name="9178" Text="Confirmação"/><StrRes Name="9179" Text="A Password de confirmação não é igual à pri' + 
'meira. Escreva novamente."/><StrRes Name="9180" Text="Tentativa de definir uma password de %d caracteres. O máximo permitido para uma password é de ' + 
'%d caracteres."/><StrRes Name="9181" Text="Ajustar tamanho da página"/><StrRes Name="9182" Text="Exportar para Excel 97/2000/XP"/><StrRes Name="9183"' + 
' Text="Apagar linhas vazias"/><StrRes Name="9184" Text="Exportar fórmulas"/><StrRes Name="BiffCol" Text="Redimensionar colunas"/><StrRes Name="BiffRo' + 
'w" Text="Redimensionar linhas"/><StrRes Name="BiffCell" Text="Exportando células"/><StrRes Name="BiffImg" Text="Exportando imagens"/><StrRes Name="92' + 
'00" Text="Microsoft Excel 2007 XML"/><StrRes Name="9201" Text="Microsoft PowerPoint 2007 XML"/><StrRes Name="9203" Text="Microsoft Word 2007 XML"/><St' + 
'rRes Name="9300" Text="HTML Layered"/><StrRes Name="9301" Text="Ficheiros HTML (*.html)|*.html|Todos|*.*"/><StrRes Name="9302" Text="Exportação HTML' + 
' Layered"/><StrRes Name="9303" Text="HTML5 Layered"/><StrRes Name="9304" Text="HTML4 Layered"/><StrRes Name="9400" Text="Reordenando componentes"/><St' + 
'rRes Name="9401" Text="Apresentando componentes"/><StrRes Name="9402" Text="Ajustando intersepção de componentes"/><StrRes Name="9403" Text="Removen' + 
'do linhas vazias"/><StrRes Name="9404" Text="Ajustando limites"/><StrRes Name="9405" Text="Separando células grandes"/><StrRes Name="9406" Text="Comp' + 
'ondo ficheiro BIFF"/><StrRes Name="xProto" Text="Exportar Protótipo"/><StrRes Name="xBlank" Text="Exportação em branco"/><StrRes Name="expMailAddr"' + 
' Text="Endereço ou endereços delimitados por vírgula"/><StrRes Name="9512" Text="Unified Pictures"/><StrRes Name="9513" Text="Formatted"/><StrRes N' + 
'ame="HTMLExtension" Text=".html"/><StrRes Name="SVGDescription" Text="SVG file"/><StrRes Name="SVGFilter"      Text="SVG file (*.svg)|*.svg"/><StrRes ' + 
'Name="SVGExtension"   Text=".svg"/></Resources>' + 
' ';

initialization
  frxResources.AddXML(resXML);

end.
