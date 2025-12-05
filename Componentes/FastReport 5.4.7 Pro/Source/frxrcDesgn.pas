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

unit frxrcDesgn;

interface

implementation

uses frxRes;

const resXML =
'<?xml version="1.1" encoding="utf-8"?><Resources CodePage="1252"><StrRes Name="2000" Text="Inspector de Objectos"/><StrRes Name="oiProp" Text="Proprie' + 
'dades"/><StrRes Name="oiEvent" Text="Eventos"/><StrRes Name="2100" Text="Árvore de dados"/><StrRes Name="2101" Text="Dados"/><StrRes Name="2102" Text' + 
'="Variáveis"/><StrRes Name="2103" Text="Funções"/><StrRes Name="2104" Text="Criar campo"/><StrRes Name="2105" Text="Criar rótulo"/><StrRes Name="2' + 
'106" Text="Classes"/><StrRes Name="dtNoData" Text="Sem dados disponíveis."/><StrRes Name="dtNoData1" Text="Seleccione o menu &#38;#34;Relatório|Dado' + 
's...&#38;#34; para adicionar &#38;#34;datasets&#38;#34; existentes ao relatório, ou mude para o separador &#38;#34;Dados&#38;#34; e crie novos &#38;#' + 
'34;datasets&#38;#34;."/><StrRes Name="dtData" Text="Dados"/><StrRes Name="dtSysVar" Text="Variáveis do Sistema"/><StrRes Name="dtVar" Text="Variávei' + 
's"/><StrRes Name="dtFunc" Text="Funções"/><StrRes Name="2200" Text="Árvore do Relatório"/><StrRes Name="2300" Text="Abrir ficheiro de Script"/><St' + 
'rRes Name="2301" Text="Guardar Script num ficheiro"/><StrRes Name="2302" Text="Executar Script"/><StrRes Name="2303" Text="Passo a passo"/><StrRes Nam' + 
'e="2304" Text="Terminar Script"/><StrRes Name="2305" Text="Avaliar"/><StrRes Name="2306" Text="Linguagem:"/><StrRes Name="2307" Text="Alinhar"/><StrRe' + 
's Name="2308" Text="Alinhar à esquerda"/><StrRes Name="2309" Text="Centrar"/><StrRes Name="2310" Text="Alinhar à direita"/><StrRes Name="2311" Text=' + 
'"Alinhar em cima"/><StrRes Name="2312" Text="Centrar"/><StrRes Name="2313" Text="Alinhar em baixo"/><StrRes Name="2314" Text="Espaçar Horizontalmente' + 
'"/><StrRes Name="2315" Text="Espaçar Verticalmente"/><StrRes Name="2316" Text="Centrar Horizontalmente na Banda"/><StrRes Name="2317" Text="Centrar V' + 
'erticalmente na Banda"/><StrRes Name="2318" Text="Mesma Largura"/><StrRes Name="2319" Text="Mesma Altura"/><StrRes Name="2320" Text="Texto"/><StrRes N' + 
'ame="2321" Text="Estilo"/><StrRes Name="2322" Text="Tipo de Letra"/><StrRes Name="2323" Text="Tamanho de Letra"/><StrRes Name="2324" Text="Negrito"/><' + 
'StrRes Name="2325" Text="Itálico"/><StrRes Name="2326" Text="Sublinhado"/><StrRes Name="2327" Text="Cor da Letra"/><StrRes Name="2328" Text="Destacar' + 
'"/><StrRes Name="2329" Text="Rotação do Texto"/><StrRes Name="2330" Text="Alinhar à esquerda"/><StrRes Name="2331" Text="Centrar"/><StrRes Name="23' + 
'32" Text="Alinhar à direita"/><StrRes Name="2333" Text="Alinhar tudo"/><StrRes Name="2334" Text="Alinhar em cima"/><StrRes Name="2335" Text="Alinhar ' + 
'ao centro"/><StrRes Name="2336" Text="Alinhar em baixo"/><StrRes Name="2337" Text="Limites"/><StrRes Name="2338" Text="Linha Superior"/><StrRes Name="' + 
'2339" Text="Linha Inferior"/><StrRes Name="2340" Text="Linha à Esquerda"/><StrRes Name="2341" Text="Linha à Direita"/><StrRes Name="2342" Text="Toda' + 
's as linhas"/><StrRes Name="2343" Text="Sem linhas"/><StrRes Name="2344" Text="Editar limites"/><StrRes Name="2345" Text="Cor do fundo"/><StrRes Name=' + 
'"2346" Text="Cor dos limites"/><StrRes Name="2347" Text="Estilo dos limites"/><StrRes Name="2348" Text="Largura dos limites"/><StrRes Name="2349" Text' + 
'="Padrão"/><StrRes Name="2350" Text="Novo Relatório"/><StrRes Name="2351" Text="Abrir Relatório"/><StrRes Name="2352" Text="Guardar Relatório"/><S' + 
'trRes Name="2353" Text="Pré-Visualizar"/><StrRes Name="2354" Text="Nova Página de Relatório"/><StrRes Name="2355" Text="Nova Página de Diálogo"/>' + 
'<StrRes Name="2356" Text="Eliminar Página"/><StrRes Name="2357" Text="Configuração da Página"/><StrRes Name="2358" Text="Variáveis"/><StrRes Name' + 
'="2359" Text="Cortar"/><StrRes Name="2360" Text="Copiar"/><StrRes Name="2361" Text="Colar"/><StrRes Name="2362" Text="Copiar formatação"/><StrRes Na' + 
'me="2363" Text="Desfazer"/><StrRes Name="2364" Text="Refazer"/><StrRes Name="2365" Text="Agrupar"/><StrRes Name="2366" Text="Desagregar"/><StrRes Name' + 
'="2367" Text="Mostrar Grelha"/><StrRes Name="2368" Text="Alinhar à Grelha"/><StrRes Name="2369" Text="Ajustar à Grelha"/><StrRes Name="2370" Text="A' + 
'mpliar"/><StrRes Name="2371" Text="Ferramentas Extra"/><StrRes Name="2372" Text="Ferramenta Seleccionar"/><StrRes Name="2373" Text="Ferramenta Mover"/' + 
'><StrRes Name="2374" Text="Ferramenta Zoom"/><StrRes Name="2375" Text="Ferramenta Editar Texto"/><StrRes Name="2376" Text="Ferramenta Copiar Formataç' + 
'ão"/><StrRes Name="2377" Text="Inserir Banda"/><StrRes Name="2378" Text="&amp;Ficheiro"/><StrRes Name="2379" Text="&amp;Editar"/><StrRes Name="2380" ' + 
'Text="Localizar..."/><StrRes Name="2381" Text="Localizar Próximo"/><StrRes Name="2382" Text="Substituir..."/><StrRes Name="2383" Text="&amp;Relatóri' + 
'o"/><StrRes Name="2384" Text="Dados..."/><StrRes Name="2385" Text="Opções..."/><StrRes Name="2386" Text="Estilos..."/><StrRes Name="2387" Text="&amp' + 
';Ver"/><StrRes Name="2388" Text="Barras de Ferramentas"/><StrRes Name="2389" Text="Padrão"/><StrRes Name="2390" Text="Texto"/><StrRes Name="2391" Tex' + 
't="Limites"/><StrRes Name="2392" Text="Paleta de Alinhamento"/><StrRes Name="2393" Text="Ferramentas Extra"/><StrRes Name="2394" Text="Inspector de Ob' + 
'jectos"/><StrRes Name="2395" Text="Árvore de Dados"/><StrRes Name="2396" Text="Árvore do Relatório"/><StrRes Name="2397" Text="Réguas"/><StrRes Na' + 
'me="2398" Text="Guias"/><StrRes Name="2399" Text="Apagar Guias"/><StrRes Name="2400" Text="Opções..."/><StrRes Name="2401" Text="&amp;Ajuda"/><StrRe' + 
's Name="2402" Text="Conteúdo da Ajuda..."/><StrRes Name="2403" Text="Sobre o FastReport..."/><StrRes Name="2404" Text="Ordem das Tabulações..."/><S' + 
'trRes Name="2405" Text="Desfazer"/><StrRes Name="2406" Text="Refazer"/><StrRes Name="2407" Text="Cortar"/><StrRes Name="2408" Text="Copiar"/><StrRes N' + 
'ame="2409" Text="Colar"/><StrRes Name="2410" Text="Agrupar"/><StrRes Name="2411" Text="Desagregar"/><StrRes Name="2412" Text="Apagar"/><StrRes Name="2' + 
'413" Text="Apagar Página"/><StrRes Name="2414" Text="Seleccionar Tudo"/><StrRes Name="2415" Text="Editar..."/><StrRes Name="2416" Text="Trazer para a' + 
' Frente"/><StrRes Name="2417" Text="Enviar para Trás"/><StrRes Name="2418" Text="Novo..."/><StrRes Name="2419" Text="Novo Relatório"/><StrRes Name="' + 
'2420" Text="Nova Página"/><StrRes Name="2421" Text="Novo Diálogo"/><StrRes Name="2422" Text="Abrir..."/><StrRes Name="2423" Text="Guardar"/><StrRes ' + 
'Name="2424" Text="Guardar Como..."/><StrRes Name="2425" Text="Variáveis..."/><StrRes Name="2426" Text="Configuração da Página..."/><StrRes Name="2' + 
'427" Text="Pré-Visualizar"/><StrRes Name="2428" Text="Sair"/><StrRes Name="2429" Text="Título do Relatório"/><StrRes Name="2430" Text="Sumário do ' + 
'Relatório"/><StrRes Name="2431" Text="Cabeçalho de Página"/><StrRes Name="2432" Text="Rodapé de Página"/><StrRes Name="2433" Text="Cabeçalho"/><' + 
'StrRes Name="2434" Text="Rodapé"/><StrRes Name="2435" Text="Dados Mestre"/><StrRes Name="2436" Text="Dados de Detalhe"/><StrRes Name="2437" Text="Dad' + 
'os de Sub-detalhe"/><StrRes Name="2438" Text="Dados de 4º nível"/><StrRes Name="2439" Text="Dados de 5º nível"/><StrRes Name="2440" Text="Dados de' + 
' 6º nível"/><StrRes Name="2441" Text="Cabeçalho de Grupo"/><StrRes Name="2442" Text="Rodapé de Grupo"/><StrRes Name="2443" Text="Filha"/><StrRes N' + 
'ame="2444" Text="Cabeçalho de Coluna"/><StrRes Name="2445" Text="Rodapé de Coluna"/><StrRes Name="2446" Text="Deslocamento"/><StrRes Name="2447" Tex' + 
't="Bandas verticais"/><StrRes Name="2448" Text="Cabeçalho"/><StrRes Name="2449" Text="Rodapé"/><StrRes Name="2450" Text="Dados Mestre"/><StrRes Name' + 
'="2451" Text="Dados de Detalhe"/><StrRes Name="2452" Text="Dados de Sub-detalhe"/><StrRes Name="2453" Text="Cabeçalho de Grupo"/><StrRes Name="2454" ' + 
'Text="Rodapé de Grupo"/><StrRes Name="2455" Text="Filha"/><StrRes Name="2456" Text="0°"/><StrRes Name="2457" Text="45°"/><StrRes Name="2458" Text="' + 
'90°"/><StrRes Name="2459" Text="180°"/><StrRes Name="2460" Text="270°"/><StrRes Name="2461" Text="Configuração da Letra"/><StrRes Name="2462" Tex' + 
't="Negrito"/><StrRes Name="2463" Text="Itálico"/><StrRes Name="2464" Text="Sublinhado"/><StrRes Name="2465" Text="Sobrescrito"/><StrRes Name="2466" T' + 
'ext="Subscrito"/><StrRes Name="2467" Text="Condensado"/><StrRes Name="2468" Text="Largo"/><StrRes Name="2469" Text="12 cpi"/><StrRes Name="2470" Text=' + 
'"15 cpi"/><StrRes Name="2471" Text="Relatório (*.fr3)|*.fr3"/><StrRes Name="2472" Text="Ficheiros Pascal (*.pas)|*.pas|Ficheiros C++ (*.cpp)|*.cpp|Fi' + 
'cheiros JavaScript (*.js)|*.js|Ficheiros Basic (*.vb)|*.vb|Todos |*.*"/><StrRes Name="2473" Text="Ficheiros Pascal (*.pas)|*.pas|Ficheiros C++ (*.cpp)' + 
'|*.cpp|Ficheiros JavaScript (*.js)|*.js|Ficheiros Basic (*.vb)|*.vb|Todos |*.*"/><StrRes Name="2474" Text="Ligações..."/><StrRes Name="2475" Text="L' + 
'inguagem"/><StrRes Name="2476" Text="Marcar ponto de paragem"/><StrRes Name="2477" Text="Executar até ao cursor"/><StrRes Name="2478" Text="Adicionar' + 
' banda filha"/><StrRes Name="2479" Text="Edit Fundo"/><StrRes Name="dsCm" Text="Centímetros"/><StrRes Name="dsInch" Text="Polegadas"/><StrRes Name="d' + 
'sPix" Text="Pixels"/><StrRes Name="dsChars" Text="Caracteres"/><StrRes Name="dsCode" Text="Código"/><StrRes Name="dsData" Text="Data"/><StrRes Name="' + 
'dsPage" Text="Página"/><StrRes Name="dsRepFilter" Text="Relatório (*.fr3)|*.fr3"/><StrRes Name="dsComprRepFilter" Text="Relatório comprimido (*.fr3' + 
')|*.fr3"/><StrRes Name="dsSavePreviewChanges" Text="Guardar alterações na página de pré-visualização?"/><StrRes Name="dsSaveChangesTo" Text="Gua' + 
'rdar alterações para "/><StrRes Name="dsCantLoad" Text="Impossível carregar ficheiro"/><StrRes Name="dsStyleFile" Text="Estilo"/><StrRes Name="dsCa' + 
'ntFindProc" Text="Impossível localizar o procedimento principal"/><StrRes Name="dsClearScript" Text="Irá apagar todo o código. Quer continuar?"/><S' + 
'trRes Name="dsNoStyle" Text="Sem estilo"/><StrRes Name="dsStyleSample" Text="Exemplo de estilo"/><StrRes Name="dsTextNotFound" Text="Texto ''%s'' não e' + 
'ncontrado"/><StrRes Name="dsReplace" Text="Substituir esta ocorrência de ''%s''?"/><StrRes Name="2600" Text="Sobre o FastReport"/><StrRes Name="2601" T' + 
'ext="Visite a nossa página:"/><StrRes Name="2602" Text="Vendas:"/><StrRes Name="2603" Text="Suporte:"/><StrRes Name="2700" Text="Opções de Página"' + 
'/><StrRes Name="2701" Text="Papel"/><StrRes Name="2702" Text="Largura"/><StrRes Name="2703" Text="Altura"/><StrRes Name="2704" Text=" Tamanho "/><StrR' + 
'es Name="2705" Text=" Orientação "/><StrRes Name="2706" Text="Esquerda"/><StrRes Name="2707" Text="Superior"/><StrRes Name="2708" Text="Direita"/><S' + 
'trRes Name="2709" Text="Inferior"/><StrRes Name="2710" Text=" Margens "/><StrRes Name="2711" Text=" Origem do Papel "/><StrRes Name="2712" Text="Prime' + 
'ira Página"/><StrRes Name="2713" Text="Outras páginas"/><StrRes Name="2714" Text="Retrato"/><StrRes Name="2715" Text="Paisagem"/><StrRes Name="2716"' + 
' Text="Outras Opções"/><StrRes Name="2717" Text=" Colunas "/><StrRes Name="2718" Text="Número"/><StrRes Name="2719" Text="Largura"/><StrRes Name="2' + 
'720" Text="Posições"/><StrRes Name="2721" Text=" Outros "/><StrRes Name="2722" Text="Duplex"/><StrRes Name="2723" Text="Imprimir na página anterior' + 
'"/><StrRes Name="2724" Text="Margens simétricas"/><StrRes Name="2725" Text="Altura maior em modo de desenho"/><StrRes Name="2726" Text="Largura de p�' + 
'�gina sem fim"/><StrRes Name="2727" Text="Altura de página sem fim"/><StrRes Name="2800" Text="Seleccione os Datasets do Relatório"/><StrRes Name="2' + 
'900" Text="Editar Variáveis"/><StrRes Name="2901" Text="Categoria"/><StrRes Name="2902" Text="Variável"/><StrRes Name="2903" Text="Editar"/><StrRes ' + 
'Name="2904" Text="Apagar"/><StrRes Name="2905" Text="Listar"/><StrRes Name="2906" Text="Carregar"/><StrRes Name="2907" Text="Guardar"/><StrRes Name="2' + 
'908" Text=" Expressão:"/><StrRes Name="2909" Text="Dicionário (*.fd3)|*.fd3"/><StrRes Name="2910" Text="Dicionário (*.fd3)|*.fd3"/><StrRes Name="va' + 
'NoVar" Text="(sem variáveis definidas)"/><StrRes Name="vaVar" Text="Variáveis"/><StrRes Name="vaDupName" Text="Nome Duplicado"/><StrRes Name="3000" ' + 
'Text="Opções do Desenhador"/><StrRes Name="3001" Text=" Grelha "/><StrRes Name="3002" Text="Tipo"/><StrRes Name="3003" Text="Tamanho"/><StrRes Name=' + 
'"3004" Text="Formulário de Diálogo:"/><StrRes Name="3005" Text=" Outro "/><StrRes Name="3006" Text=" Tipos de Letra "/><StrRes Name="3007" Text="Jan' + 
'ela de código"/><StrRes Name="3008" Text="Editor de texto"/><StrRes Name="3009" Text="Tamanho"/><StrRes Name="3010" Text="Tamanho"/><StrRes Name="301' + 
'1" Text=" Cores "/><StrRes Name="3012" Text="Espaço entre bandas:"/><StrRes Name="3013" Text="cm"/><StrRes Name="3014" Text="pol"/><StrRes Name="3015' + 
'" Text="pt"/><StrRes Name="3016" Text="pt"/><StrRes Name="3017" Text="pt"/><StrRes Name="3018" Text="Centímetros:"/><StrRes Name="3019" Text="Polegad' + 
'as:"/><StrRes Name="3020" Text="Pixels:"/><StrRes Name="3021" Text="Mostrar Grelha"/><StrRes Name="3022" Text="Alinhar à grelha"/><StrRes Name="3023"' + 
' Text="Mostrar editor após inserir"/><StrRes Name="3024" Text="Usar tipo de letra do objecto"/><StrRes Name="3025" Text="Espaço de trabalho"/><StrRe' + 
's Name="3026" Text="Janelas de Ferramentas"/><StrRes Name="3027" Text="Cor da grelha LCD"/><StrRes Name="3028" Text="Colocação livre das bandas"/><S' + 
'trRes Name="3029" Text="Mostrar lista de campos"/><StrRes Name="3030" Text="Mostrar ecran inicial"/><StrRes Name="3031" Text="Restaurar valores padrã' + 
'o"/><StrRes Name="3032" Text="Mostrar rótulos das bandas"/><StrRes Name="3100" Text="Seleccionar DataSet"/><StrRes Name="3101" Text="Numero de regist' + 
'os:"/><StrRes Name="3102" Text="Dataset"/><StrRes Name="3103" Text="Filtro"/><StrRes Name="dbNotAssigned" Text="[não atribuído]"/><StrRes Name="3200' + 
'" Text="Grupo"/><StrRes Name="3201" Text=" Quebrar em "/><StrRes Name="3202" Text=" Opções "/><StrRes Name="3203" Text="Campo de dados"/><StrRes Nam' + 
'e="3204" Text="Expressão"/><StrRes Name="3205" Text="Manter agrupado"/><StrRes Name="3206" Text="Iniciar nova página"/><StrRes Name="3207" Text="Mos' + 
'trar no resumo"/><StrRes Name="3300" Text="Memo do Sistema"/><StrRes Name="3301" Text="Banda de dados"/><StrRes Name="3302" Text="DataSet"/><StrRes Na' + 
'me="3303" Text="Campo"/><StrRes Name="3304" Text="Função"/><StrRes Name="3305" Text="Expressão"/><StrRes Name="3306" Text="Valor agregado"/><StrRes' + 
' Name="3307" Text="Variável de sistema"/><StrRes Name="3308" Text="Contar bandas invisíveis"/><StrRes Name="3309" Text="Texto"/><StrRes Name="3310" ' + 
'Text="Total Geral"/><StrRes Name="agAggregate" Text="Inserir Agregado"/><StrRes Name="vt1" Text="[DATE]"/><StrRes Name="vt2" Text="[TIME]"/><StrRes Na' + 
'me="vt3" Text="[PAGE#]"/><StrRes Name="vt4" Text="[TOTALPAGES#]"/><StrRes Name="vt5" Text="[PAGE#] de [TOTALPAGES#]"/><StrRes Name="vt6" Text="[LINE#]' + 
'"/><StrRes Name="3400" Text="Objecto OLE"/><StrRes Name="3401" Text="Inserir..."/><StrRes Name="3402" Text="Editar..."/><StrRes Name="3403" Text="Fech' + 
'ar"/><StrRes Name="olStretched" Text="Esticado"/><StrRes Name="3500" Text="Editor de Códigos de Barras"/><StrRes Name="3501" Text="Código"/><StrRes ' + 
'Name="3502" Text="Tipo de Barras"/><StrRes Name="3503" Text="Zoom:"/><StrRes Name="3504" Text=" Opções "/><StrRes Name="3505" Text=" Rotação "/><S' + 
'trRes Name="3506" Text="Calc. Dígito de Controlo"/><StrRes Name="3507" Text="Texto"/><StrRes Name="3508" Text="0°"/><StrRes Name="3509" Text="90°"/' + 
'><StrRes Name="3510" Text="180°"/><StrRes Name="3511" Text="270°"/><StrRes Name="bcCalcChecksum" Text="Calc. Dígito de Controlo"/><StrRes Name="bcS' + 
'howText" Text="Mostrar Texto"/><StrRes Name="3600" Text="Editar Aliases"/><StrRes Name="3601" Text="Carregue em Enter para editar o item"/><StrRes Nam' + 
'e="3602" Text="Nome do Dataset"/><StrRes Name="3603" Text="Nomes dos Campos"/><StrRes Name="3604" Text="Limpar"/><StrRes Name="3605" Text="Actualizar"' + 
'/><StrRes Name="alUserName" Text="Utilizador"/><StrRes Name="alOriginal" Text="Nome Original"/><StrRes Name="3700" Text="Editor de Parâmetros"/><StrR' + 
'es Name="qpName" Text="Nome"/><StrRes Name="qpDataType" Text="Tipo"/><StrRes Name="qpValue" Text="Valor"/><StrRes Name="3800" Text="Ligação Mestre-D' + 
'etalhe"/><StrRes Name="3801" Text="Campos de Detalhe"/><StrRes Name="3802" Text="Campos Mestre"/><StrRes Name="3803" Text="Campos Ligados"/><StrRes Na' + 
'me="3804" Text="Adicionar"/><StrRes Name="3805" Text="Limpar"/><StrRes Name="3900" Text="Memo"/><StrRes Name="3901" Text="Inserir Expressão"/><StrRes' + 
' Name="3902" Text="Inserir Agregado"/><StrRes Name="3903" Text="Inserir Formatação"/><StrRes Name="3904" Text="Quebrar Linhas"/><StrRes Name="3905" ' + 
'Text="Texto"/><StrRes Name="3906" Text="Formato"/><StrRes Name="3907" Text="Destaque"/><StrRes Name="4000" Text="Figura"/><StrRes Name="4001" Text="Ca' + 
'rregar"/><StrRes Name="4002" Text="Copiar"/><StrRes Name="4003" Text="Colar"/><StrRes Name="4004" Text="Limpar"/><StrRes Name="piEmpty" Text="Vazio"/>' + 
'<StrRes Name="4100" Text="Editor de Gráficos"/><StrRes Name="4101" Text="Adicionar Séries"/><StrRes Name="4102" Text="Apagar Séries"/><StrRes Name=' + 
'"4103" Text="Editar Gráfico"/><StrRes Name="4104" Text="Banda"/><StrRes Name="4105" Text="Dados Fixos"/><StrRes Name="4106" Text="Dados do relatório' + 
'"/><StrRes Name="4107" Text="Origem de Dados"/><StrRes Name="4108" Text="Valores"/><StrRes Name="4109" Text="Seleccione a série ou adicione uma nova.' + 
'"/><StrRes Name="4114" Text=" Outras Opções "/><StrRes Name="4115" Text="Primeiros N valores"/><StrRes Name="4116" Text="Primeiros N rótulos"/><Str' + 
'Res Name="4117" Text="Ordem"/><StrRes Name="4126" Text="Eixo X"/><StrRes Name="ch3D" Text="Vista 3D"/><StrRes Name="chAxis" Text="Mostrar Eixos"/><Str' + 
'Res Name="chsoNone" Text="Nenhuma"/><StrRes Name="chsoAscending" Text="Crescente"/><StrRes Name="chsoDescending" Text="Decrescente"/><StrRes Name="chx' + 
'tText" Text="Texto"/><StrRes Name="chxtNumber" Text="Numérico"/><StrRes Name="chxtDate" Text="Data"/><StrRes Name="4200" Text="Editor de Texto"/><Str' + 
'Res Name="4201" Text="Abrir Ficheiro"/><StrRes Name="4202" Text="Guardar Ficheiro"/><StrRes Name="4203" Text="Desfazer"/><StrRes Name="4204" Text="Tip' + 
'o de Letra"/><StrRes Name="4205" Text="Inserir Expressão"/><StrRes Name="4206" Text="Negrito"/><StrRes Name="4207" Text="Italico"/><StrRes Name="4208' + 
'" Text="Sublinhado"/><StrRes Name="4209" Text="Alinhar à Esquerda"/><StrRes Name="4210" Text="Centrar"/><StrRes Name="4211" Text="Alinhar à Direita"' + 
'/><StrRes Name="4212" Text="Alinhar Tudo"/><StrRes Name="4213" Text="Marcadores"/><StrRes Name="4300" Text="Editor de Grelhas"/><StrRes Name="4301" Te' + 
'xt=" Fonte de Dados "/><StrRes Name="4302" Text=" Dimensões "/><StrRes Name="4303" Text="Linhas"/><StrRes Name="4304" Text="Colunas"/><StrRes Name="4' + 
'305" Text="Células"/><StrRes Name="4306" Text=" Estrutura da Grelha "/><StrRes Name="4307" Text="Cabeçalho da Linha"/><StrRes Name="4308" Text="Cabe' + 
'çalho da Coluna"/><StrRes Name="4309" Text="Total Geral da Linha"/><StrRes Name="4310" Text="Total Geral da Coluna"/><StrRes Name="4311" Text="Trocar' + 
' Linhas/Colunas"/><StrRes Name="4312" Text="Seleccionar estilo"/><StrRes Name="4313" Text="Guardar estilo actual..."/><StrRes Name="4314" Text="Mostra' + 
'r título"/><StrRes Name="4315" Text="Mostrar canto"/><StrRes Name="4316" Text="Reimprimir cabeçalhos na nova página"/><StrRes Name="4317" Text="Aut' + 
'o-dimensionar"/><StrRes Name="4318" Text="Limites das células"/><StrRes Name="4319" Text="Imprimir para baixo, para a direita"/><StrRes Name="4320" T' + 
'ext="Células lado a lado"/><StrRes Name="4321" Text="Unir células iguais"/><StrRes Name="4322" Text="Nenhum"/><StrRes Name="4323" Text="Soma"/><StrR' + 
'es Name="4324" Text="Min"/><StrRes Name="4325" Text="Max"/><StrRes Name="4326" Text="Média"/><StrRes Name="4327" Text="Contagem"/><StrRes Name="4328"' + 
' Text="Crescente (A-Z)"/><StrRes Name="4329" Text="Decrescente (Z-A)"/><StrRes Name="4330" Text="Sem ordem"/><StrRes Name="crStName" Text="Digite nome' + 
' do estilo:"/><StrRes Name="crResize" Text="Para redimensionar uma grelha, seleccione &#38;#34;False&#38;#34; para a propriedade &#38;#34;AutoSize&#38' + 
';#34;."/><StrRes Name="crSubtotal" Text="Subtotal"/><StrRes Name="crNone" Text="Nenhum"/><StrRes Name="crSum" Text="Soma"/><StrRes Name="crMin" Text="' + 
'Min"/><StrRes Name="crMax" Text="Max"/><StrRes Name="crAvg" Text="Média"/><StrRes Name="crCount" Text="Contagem"/><StrRes Name="crAsc" Text="A-Z"/><S' + 
'trRes Name="crDesc" Text="Z-A"/><StrRes Name="4400" Text="Editor de Expressões"/><StrRes Name="4401" Text="Expressão:"/><StrRes Name="4500" Text="Fo' + 
'rmato de apresentação"/><StrRes Name="4501" Text="Categoria"/><StrRes Name="4502" Text="Formato"/><StrRes Name="4503" Text="Formato(string):"/><StrR' + 
'es Name="4504" Text="Separador Decimal:"/><StrRes Name="fkText" Text="Texto (sem formatação)"/><StrRes Name="fkNumber" Text="Número"/><StrRes Name=' + 
'"fkDateTime" Text="Data/Hora"/><StrRes Name="fkBoolean" Text="Lógico"/><StrRes Name="fkNumber1" Text="1234.5;%g"/><StrRes Name="fkNumber2" Text="1234' + 
'.50;%2.2f"/><StrRes Name="fkNumber3" Text="1,234.50;%2.2n"/><StrRes Name="fkNumber4" Text="$1,234.50;%2.2m"/><StrRes Name="fkDateTime1" Text="11.28.20' + 
'06;mm.dd.yyyy"/><StrRes Name="fkDateTime2" Text="28 nov 2006;dd mmm yyyy"/><StrRes Name="fkDateTime3" Text="Novembro 28, 2006;mmmm dd, yyyy"/><StrRes ' + 
'Name="fkDateTime4" Text="02:14;hh:mm"/><StrRes Name="fkDateTime5" Text="02:14am;hh:mm am/pm"/><StrRes Name="fkDateTime6" Text="02:14:00;hh:mm:ss"/><St' + 
'rRes Name="fkDateTime7" Text="02:14am, Novembro 28, 2006;hh:mm am/pm, mmmm dd, yyyy"/><StrRes Name="fkBoolean1" Text="0,1;0,1"/><StrRes Name="fkBoolea' + 
'n2" Text="Não,Sim;Não,Sim"/><StrRes Name="fkBoolean3" Text="_,x;_,x"/><StrRes Name="fkBoolean4" Text="Falso,Verdadeiro;Falso,Verdadeiro"/><StrRes Na' + 
'me="4600" Text="Editor de Destaque"/><StrRes Name="4601" Text="Condições"/><StrRes Name="4602" Text="Adicionar"/><StrRes Name="4603" Text="Apagar"/>' + 
'<StrRes Name="4604" Text="Editar"/><StrRes Name="4605" Text="Estilo"/><StrRes Name="4606" Text="Limites"/><StrRes Name="4607" Text="Fundo"/><StrRes Na' + 
'me="4608" Text="Letra"/><StrRes Name="4609" Text="Visível"/><StrRes Name="4700" Text="Configuração do Relatório"/><StrRes Name="4701" Text="Geral"' + 
'/><StrRes Name="4702" Text="Configuração da Impressora "/><StrRes Name="4703" Text="Cópias"/><StrRes Name="4704" Text="Geral "/><StrRes Name="4705"' + 
' Text="Password"/><StrRes Name="4706" Text="Agrupar cópias"/><StrRes Name="4707" Text="Duplo passo"/><StrRes Name="4708" Text="Imprimir mesmo vazio"/' + 
'><StrRes Name="4709" Text="Descrição"/><StrRes Name="4710" Text="Nome"/><StrRes Name="4711" Text="Descrição"/><StrRes Name="4712" Text="Figura"/><' + 
'StrRes Name="4713" Text="Autor"/><StrRes Name="4714" Text="Maior"/><StrRes Name="4715" Text="Menor"/><StrRes Name="4716" Text="Revisão"/><StrRes Name' + 
'="4717" Text="Compilação"/><StrRes Name="4718" Text="Criado"/><StrRes Name="4719" Text="Modificado"/><StrRes Name="4720" Text="Descrição "/><StrRe' + 
's Name="4721" Text="Versão "/><StrRes Name="4722" Text="Procurar..."/><StrRes Name="4723" Text="Hereditariedade"/><StrRes Name="4724" Text="Seleccion' + 
'e a opção:"/><StrRes Name="4725" Text="Não alterar"/><StrRes Name="4726" Text="Separar do relatório base"/><StrRes Name="4727" Text="Herdar do rel' + 
'atório base:"/><StrRes Name="4728" Text="Hereditariedade"/><StrRes Name="4729" Text="Modelos em:"/><StrRes Name="rePrnOnPort" Text="em"/><StrRes Name' + 
'="riNotInherited" Text="Este relatório não é herdado."/><StrRes Name="riInherited" Text="Este relatório é herdado do relatório base: %s"/><StrRe' + 
's Name="4800" Text="Linhas"/><StrRes Name="4900" Text="SQL"/><StrRes Name="4901" Text="Query Builder"/><StrRes Name="5000" Text="Password"/><StrRes Na' + 
'me="5001" Text="Escreva a password:"/><StrRes Name="5100" Text="Editor de Estilos"/><StrRes Name="5101" Text="Cor..."/><StrRes Name="5102" Text="Letra' + 
'..."/><StrRes Name="5103" Text="Limites..."/><StrRes Name="5104" Text="Adicionar"/><StrRes Name="5105" Text="Apagar"/><StrRes Name="5106" Text="Editar' + 
'"/><StrRes Name="5107" Text="Carregar"/><StrRes Name="5108" Text="Guardar"/><StrRes Name="5200" Text="Editor de Limites"/><StrRes Name="5201" Text="Li' + 
'mites"/><StrRes Name="5202" Text="Linha"/><StrRes Name="5203" Text="Sombra"/><StrRes Name="5211" Text="Estilo:"/><StrRes Name="5214" Text="Cor:"/><Str' + 
'Res Name="5215" Text="Largura:"/><StrRes Name="5216" Text="Choose the line style, then choose the line to apply the style."/><StrRes Name="5300" Text=' + 
'"Novo Item"/><StrRes Name="5301" Text="Itens"/><StrRes Name="5302" Text="Modelos"/><StrRes Name="5303" Text="Herdar o relatório"/><StrRes Name="5400"' + 
' Text="Ordem das Tabulações"/><StrRes Name="5401" Text="Controlos listados por ordem de tabulação:"/><StrRes Name="5402" Text="Para cima"/><StrRes' + 
' Name="5403" Text="Para baixo"/><StrRes Name="5500" Text="Avaliar"/><StrRes Name="5501" Text="Expressão"/><StrRes Name="5502" Text="Resultado"/><StrR' + 
'es Name="5600" Text="Assistente de Relatórios"/><StrRes Name="5601" Text="Dados"/><StrRes Name="5602" Text="Campos"/><StrRes Name="5603" Text="Grupos' + 
'"/><StrRes Name="5604" Text="Configuração"/><StrRes Name="5605" Text="Estilo"/><StrRes Name="5606" Text="Passo 1. Seleccionar os dados."/><StrRes Na' + 
'me="5607" Text="Passo 2. Seleccionar os campos a apresentar."/><StrRes Name="5608" Text="Passo 3. Criar os grupos (opcional)."/><StrRes Name="5609" Te' + 
'xt="Passo 4. Definir a orientação da página e formato dos dados."/><StrRes Name="5610" Text="Passo 5. Escolher o estilo do relatório."/><StrRes Na' + 
'me="5611" Text="Adicionar &#62;"/><StrRes Name="5612" Text="Adicionar todos&#62;&#62;"/><StrRes Name="5613" Text="&#60; Remover"/><StrRes Name="5614" ' + 
'Text="&#60;&#60; Remover todos"/><StrRes Name="5615" Text="Adicionar &#62;"/><StrRes Name="5616" Text="&#60; Remover"/><StrRes Name="5617" Text="Campo' + 
's seleccionados:"/><StrRes Name="5618" Text="Campos disponíveis:"/><StrRes Name="5619" Text="Grupos:"/><StrRes Name="5620" Text=" Orientação "/><St' + 
'rRes Name="5621" Text="Layout"/><StrRes Name="5622" Text="Retrato"/><StrRes Name="5623" Text="Paisagem"/><StrRes Name="5624" Text="Tabular"/><StrRes N' + 
'ame="5625" Text="Em colunas"/><StrRes Name="5626" Text="Ajustar campos à largura da página"/><StrRes Name="5627" Text="&#60;&#60; Anterior"/><StrRes' + 
' Name="5628" Text="Seguinte &#62;&#62;"/><StrRes Name="5629" Text="Terminar"/><StrRes Name="5630" Text="Nova tabela..."/><StrRes Name="5631" Text="Nov' + 
'a pesquisa..."/><StrRes Name="5632" Text="Seleccione uma ligação à base de dados:"/><StrRes Name="5633" Text="Seleccione uma tabela:"/><StrRes Name' + 
'="5634" Text="ou"/><StrRes Name="5635" Text="Criar pesquisa..."/><StrRes Name="5636" Text="Configure ligações"/><StrRes Name="wzStd" Text="Assistent' + 
'e Padrão de Relatórios"/><StrRes Name="wzDMP" Text="Assistente de Relatórios para Imp. Matricial"/><StrRes Name="wzStdEmpty" Text="Relatório Padr�' + 
'�o"/><StrRes Name="wzDMPEmpty" Text="Relatório Matricial"/><StrRes Name="5700" Text="Assistente de ligações"/><StrRes Name="5701" Text="Ligação"/' + 
'><StrRes Name="5702" Text="Escolha o tipo de documento:"/><StrRes Name="5703" Text="Escolha a base de dados:"/><StrRes Name="5704" Text="Login"/><StrR' + 
'es Name="5705" Text="Password"/><StrRes Name="5706" Text="Titulo de login"/><StrRes Name="5707" Text="Utilizar login/password:"/><StrRes Name="5708" T' + 
'ext="Tabela"/><StrRes Name="5709" Text="Escolher o nome da tabela:"/><StrRes Name="5710" Text="Filtrar registos:"/><StrRes Name="5711" Text="Pesquisa"' + 
'/><StrRes Name="5712" Text="Comando SQL:"/><StrRes Name="5713" Text="Query Builder"/><StrRes Name="5714" Text="Editar parâmetros da pesquisa"/><StrRe' + 
's Name="ftAllFiles" Text="Todos os Ficheiros"/><StrRes Name="ftPictures" Text="Figuras"/><StrRes Name="ftDB" Text="Bases de Dados"/><StrRes Name="ftRi' + 
'chFile" Text="Ficheiro RichText"/><StrRes Name="ftTextFile" Text="Ficheiro de texto"/><StrRes Name="prNotAssigned" Text="(Não atribuído)"/><StrRes N' + 
'ame="prInvProp" Text="Valor inválido da propriedade"/><StrRes Name="prDupl" Text="Nome duplicado"/><StrRes Name="prPict" Text="(Figura)"/><StrRes Nam' + 
'e="mvExpr" Text="Permitir Expressões"/><StrRes Name="mvStretch" Text="Esticar"/><StrRes Name="mvStretchToMax" Text="Esticar até Altura Máxima"/><St' + 
'rRes Name="mvShift" Text="Deslocar"/><StrRes Name="mvShiftOver" Text="Deslocar quando sobreposto"/><StrRes Name="mvVisible" Text="Visível"/><StrRes N' + 
'ame="mvPrintable" Text="Imprimível"/><StrRes Name="mvFont" Text="Letra..."/><StrRes Name="mvFormat" Text="Formato..."/><StrRes Name="mvClear" Text="L' + 
'impar conteúdo"/><StrRes Name="mvAutoWidth" Text="Largura auto"/><StrRes Name="mvWWrap" Text="Quebrar linhas"/><StrRes Name="mvSuppress" Text="Suprim' + 
'ir valores repetidos"/><StrRes Name="mvHideZ" Text="Esconder zeros"/><StrRes Name="mvHTML" Text="Permitir HTML"/><StrRes Name="lvDiagonal" Text="Diago' + 
'nal"/><StrRes Name="pvAutoSize" Text="Tamanho auto"/><StrRes Name="pvCenter" Text="Centrar"/><StrRes Name="pvAspect" Text="Manter proporcionalidade"/>' + 
'<StrRes Name="bvSplit" Text="Permitir separação"/><StrRes Name="bvKeepChild" Text="Manter filha unida"/><StrRes Name="bvPrintChild" Text="Imprimir f' + 
'ilha se invisível"/><StrRes Name="bvStartPage" Text="Iniciar nova página"/><StrRes Name="bvPrintIfEmpty" Text="Imprimir se detalhe vazio"/><StrRes N' + 
'ame="bvKeepDetail" Text="Manter detalhe unido"/><StrRes Name="bvKeepFooter" Text="Manter rodapé unido"/><StrRes Name="bvReprint" Text="Reimprimir na ' + 
'nova página"/><StrRes Name="bvOnFirst" Text="Imprimir na primeira página"/><StrRes Name="bvOnLast" Text="Imprimir na última página"/><StrRes Name=' + 
'"bvKeepGroup" Text="Manter Junto"/><StrRes Name="bvFooterAfterEach" Text="Rodapé depois de cada linha"/><StrRes Name="bvDrillDown" Text="Expansível"' + 
'/><StrRes Name="bvResetPageNo" Text="Inicializar números de página"/><StrRes Name="srParent" Text="Imprimir no Pai"/><StrRes Name="bvKeepHeader" Tex' + 
't="Manter Cabeçalho Junto"/><StrRes Name="obCatDraw" Text="Desenho"/><StrRes Name="obCatOther" Text="Outros objectos"/><StrRes Name="obCatOtherContro' + 
'ls" Text="Outros Controlos"/><StrRes Name="obDiagLine" Text="Linha Diagonal"/><StrRes Name="obRect" Text="Rectângulo"/><StrRes Name="obRoundRect" Tex' + 
't="Rectângulo Arredondado"/><StrRes Name="obEllipse" Text="Elipse"/><StrRes Name="obTrian" Text="Triângulo"/><StrRes Name="obDiamond" Text="Diamante' + 
'"/><StrRes Name="obLabel" Text="Rótulo"/><StrRes Name="obEdit" Text="Caixa de Texto"/><StrRes Name="obMemoC" Text="Notas"/><StrRes Name="obButton" Te' + 
'xt="Botão"/><StrRes Name="obChBoxC" Text="Caixa de verificação"/><StrRes Name="obRButton" Text="Botão de opção"/><StrRes Name="obLBox" Text="Lis' + 
'ta"/><StrRes Name="obCBox" Text="Caixa de verificação"/><StrRes Name="obDateEdit" Text="Editor de datas"/><StrRes Name="obImageC" Text="Imagem"/><St' + 
'rRes Name="obPanel" Text="Painel"/><StrRes Name="obGrBox" Text="Caixa de Grupo"/><StrRes Name="obBBtn" Text="Botão com imagem"/><StrRes Name="obSBtn"' + 
' Text="Botão rápido"/><StrRes Name="obMEdit" Text="Máscara de edição"/><StrRes Name="obChLB" Text="Lista de Verificação"/><StrRes Name="obDBLoo' + 
'kup" Text="Caixa de pesquisa BD"/><StrRes Name="obBevel" Text="Cercadura"/><StrRes Name="obShape" Text="Forma"/><StrRes Name="obText" Text="Texto"/><S' + 
'trRes Name="obSysText" Text="Texto do Sistema"/><StrRes Name="obLine" Text="Linha"/><StrRes Name="obPicture" Text="Figura"/><StrRes Name="obBand" Text' + 
'="Banda"/><StrRes Name="obDataBand" Text="Banda de dados"/><StrRes Name="obSubRep" Text="Sub-Relatório"/><StrRes Name="obDlgPage" Text="Formulário d' + 
'e Diálogo"/><StrRes Name="obRepPage" Text="Página de Relatório"/><StrRes Name="obReport" Text="Relatório"/><StrRes Name="obRich" Text="Texto com f' + 
'ormatação"/><StrRes Name="obOLE" Text="Objecto OLE"/><StrRes Name="obChBox" Text="Caixa de Verificação"/><StrRes Name="obChart" Text="Gráfico"/><' + 
'StrRes Name="obBarC" Text="Código de Barras"/><StrRes Name="obCross" Text="Grelha Cross-tab"/><StrRes Name="obDBCross" Text="Grelha Cross-tab DB"/><S' + 
'trRes Name="obGrad" Text="Gradiente"/><StrRes Name="obDMPText" Text="Texto (Matricial)"/><StrRes Name="obDMPLine" Text="Linha (Matricial)"/><StrRes Na' + 
'me="obDMPCmd" Text="Comando (Matricial)"/><StrRes Name="obBDEDB" Text="Base de Dados BDE"/><StrRes Name="obBDETb" Text="Tabela BDE"/><StrRes Name="obB' + 
'DEQ" Text="Query BDE"/><StrRes Name="obBDEComps" Text="Componentes BDE"/><StrRes Name="obIBXDB" Text="Base de Dados IBX"/><StrRes Name="obIBXTb" Text=' + 
'"Tabela IBX"/><StrRes Name="obIBXQ" Text="Query IBX"/><StrRes Name="obIBXComps" Text="Componentes IBX"/><StrRes Name="obADODB" Text="Base de Dados ADO' + 
'"/><StrRes Name="obADOTb" Text="Tabela ADO"/><StrRes Name="obADOQ" Text="Query ADO"/><StrRes Name="obADOComps" Text="Componentes ADO"/><StrRes Name="o' + 
'bDBXDB" Text="Base de Dados DBX"/><StrRes Name="obDBXTb" Text="Tabelas DBX"/><StrRes Name="obDBXQ" Text="Query DBX"/><StrRes Name="obDBXComps" Text="C' + 
'omponentes DBX"/><StrRes Name="obFIBDB" Text="Base de Dados FIB"/><StrRes Name="obFIBTb" Text="Tabela FIB"/><StrRes Name="obFIBQ" Text="Query FIB"/><S' + 
'trRes Name="obFIBComps" Text="Componentes FIB"/><StrRes Name="obDataBases" Text="DataBases"/><StrRes Name="obTables" Text="Tables"/><StrRes Name="obQu' + 
'eries" Text="Queries"/><StrRes Name="ctString" Text="Texto"/><StrRes Name="ctDate" Text="Data e Hora"/><StrRes Name="ctConv" Text="Conversão"/><StrRe' + 
's Name="ctFormat" Text="Formatação"/><StrRes Name="ctMath" Text="Matemáticas"/><StrRes Name="ctOther" Text="Outras"/><StrRes Name="IntToStr" Text="' + 
'Converte um número inteiro para texto"/><StrRes Name="FloatToStr" Text="Converte um número para texto"/><StrRes Name="DateToStr" Text="Converte uma ' + 
'data para texto"/><StrRes Name="TimeToStr" Text="Converte uma hora para texto"/><StrRes Name="DateTimeToStr" Text="Converte uma data-e-hora para texto' + 
'"/><StrRes Name="VarToStr" Text="Converte um valor &#38;#34;variant&#38;#34; para texto"/><StrRes Name="StrToInt" Text="Converte texto num número int' + 
'eiro"/><StrRes Name="StrToInt64" Text="Converte texto para um inteiro(Int64)"/><StrRes Name="StrToFloat" Text="Converte texto num número"/><StrRes Na' + 
'me="StrToDate" Text="Converte texto numa data"/><StrRes Name="StrToTime" Text="Converte texto numa hora"/><StrRes Name="StrToDateTime" Text="Converte ' + 
'texto para uma data/hora"/><StrRes Name="Format" Text="Devolve texto formatado a partir de uma lista de argumentos"/><StrRes Name="FormatFloat" Text="' + 
'Formata números em ponto flutuante"/><StrRes Name="FormatDateTime" Text="Formata valores data/hora"/><StrRes Name="FormatMaskText" Text="Devolve text' + 
'o formatado usando uma máscara de edição"/><StrRes Name="EncodeDate" Text="Devolve um valor TDateTime a partir do Ano, Mês, Dia"/><StrRes Name="De' + 
'codeDate" Text="Separa um valor TDateTime em Ano, Mês, Dia"/><StrRes Name="EncodeTime" Text="Devolve um valor TDateTime a partir de Hora, Min, Seg, M' + 
'Seg"/><StrRes Name="DecodeTime" Text="Separa um valor TDateTime em horas, minutos, segundos, e milisegundos"/><StrRes Name="Date" Text="Devolve a data' + 
' actual"/><StrRes Name="Time" Text="Devolve a hora actual"/><StrRes Name="Now" Text="Devolve a data e hora actuais"/><StrRes Name="DayOfWeek" Text="De' + 
'volve o dia da semana para a data especificada"/><StrRes Name="IsLeapYear" Text="Indica se um ano é bissexto"/><StrRes Name="DaysInMonth" Text="Devol' + 
've o número de dias de um mês"/><StrRes Name="Length" Text="Devolve o comprimento do texto"/><StrRes Name="Copy" Text="Devolve uma parte de uma cade' + 
'ia de caracteres"/><StrRes Name="Pos" Text="Devolve a posição de um texto dentro de outro"/><StrRes Name="Delete" Text="Remove um texto de outro"/><' + 
'StrRes Name="Insert" Text="Insere um texto em outro"/><StrRes Name="Uppercase" Text="Converte todos os caracteres para maiúsculas"/><StrRes Name="Low' + 
'ercase" Text="Converte todos os caracteres para minúsculas"/><StrRes Name="Trim" Text="Remove os espaços iniciais e finais de um texto"/><StrRes Nam' + 
'e="NameCase" Text="Converte o primeiro carácter de cada palavra para maiúscula"/><StrRes Name="CompareText" Text="Compara dois textos"/><StrRes Name' + 
'="Chr" Text="Converte um número inteiro para um carácter"/><StrRes Name="Ord" Text="Converte um carácter para um número inteiro"/><StrRes Name="Se' + 
'tLength" Text="Especifica o comprimento de um texto"/><StrRes Name="Round" Text="Arredonda um número para o valor inteiro mais próximo"/><StrRes Nam' + 
'e="Trunc" Text="Trunca um número para o inteiro imediatamente inferior"/><StrRes Name="Int" Text="Devolve a parte inteira de um número"/><StrRes Nam' + 
'e="Frac" Text="Devolve a parte fraccionária de um número"/><StrRes Name="Sqrt" Text="Devolve a raíz quadrada de um número"/><StrRes Name="Abs" Tex' + 
't="Devolve o valor absoluto"/><StrRes Name="Sin" Text="Devolve o seno de um ângulo (em radianos)"/><StrRes Name="Cos" Text="Devolve o coseno de um â' + 
'ngulo (em radianos)"/><StrRes Name="ArcTan" Text="Devolve o arco-tangente"/><StrRes Name="Tan" Text="Devolve a tangente de um ângulo"/><StrRes Name="' + 
'Exp" Text="Devolve o exponencial"/><StrRes Name="Ln" Text="Devolve o logaritmo natural de um número"/><StrRes Name="Pi" Text="Devolve o valor 3.14159' + 
'26..."/><StrRes Name="Inc" Text="Incrementa um valor"/><StrRes Name="Dec" Text="Decrementa um valor"/><StrRes Name="RaiseException" Text="Gera uma exc' + 
'epção"/><StrRes Name="ShowMessage" Text="Mostra uma mensagem"/><StrRes Name="Randomize" Text="Inicializa o gerador de números aleatórios"/><StrRes' + 
' Name="Random" Text="Devolve um número aleatório"/><StrRes Name="ValidInt" Text="Devolve &#38;#34;Verdadeiro&#38;#34; se o texto contém um número ' + 
'inteiro válido"/><StrRes Name="ValidFloat" Text="Devolve &#38;#34;Verdadeiro&#38;#34; se o texto contém um número válido"/><StrRes Name="ValidDate' + 
'" Text="Devolve &#38;#34;Verdadeiro&#38;#34; se o texto contém uma data válida"/><StrRes Name="IIF" Text="Devolve &#38;#34;Verdadeiro&#38;#34; se a ' + 
'expressão é verdadeira, caso contrário devolve &#38;#34;Falso&#38;#34;"/><StrRes Name="Get" Text="Apenas para uso interno"/><StrRes Name="Set" Text' + 
'="Apenas para uso interno"/><StrRes Name="InputBox" Text="Mostra uma caixa que permite digitar um texto"/><StrRes Name="InputQuery" Text="Mostra uma c' + 
'aixa que permite digitar um texto"/><StrRes Name="MessageDlg" Text="Mostra uma mensagem"/><StrRes Name="CreateOleObject" Text="Cria um objecto OLE"/><' + 
'StrRes Name="VarArrayCreate" Text="Cria um &#34;variant array&#34;"/><StrRes Name="VarType" Text="Devolve o tipo de um valor &#38;#34;variant&#38;#34;' + 
'"/><StrRes Name="DayOf" Text="Devolve o dia (1..31) de uma data"/><StrRes Name="MonthOf" Text="Devolve o mês (1..12) de uma data"/><StrRes Name="Year' + 
'Of" Text="Devolve o ano de uma data"/><StrRes Name="ctAggregate" Text="Estatísticas"/><StrRes Name="Sum" Text="Calcula a soma de &#38;#60;Expr&#38;#6' + 
'2; para a linha de dados da banda"/><StrRes Name="Avg" Text="Calcula a média de &#38;#60;Expr&#38;#62; para a linha de dados da banda"/><StrRes Name=' + 
'"Min" Text="Calcula o mínimo de &#38;#60;Expr&#38;#62; para a linha de dados da banda"/><StrRes Name="Max" Text="Calcula o máximo de &#38;#60;Expr&#' + 
'38;#62; para a linha de dados da banda"/><StrRes Name="Count" Text="Calcula o número de linhas de dados"/><StrRes Name="wzDBConn" Text="Novo assisten' + 
'te de Ligações"/><StrRes Name="wzDBTable" Text="Novo assistente de Tabelas"/><StrRes Name="wzDBQuery" Text="Novo assistente de Pesquisa"/><StrRes Na' + 
'me="5800" Text="Ligações"/><StrRes Name="5801" Text="Nova"/><StrRes Name="5802" Text="Eliminar"/><StrRes Name="cpName" Text="Nome"/><StrRes Name="cp' + 
'ConnStr" Text="Cadeia de ligação"/><StrRes Name="startCreateNew" Text="Criar novo relatório"/><StrRes Name="startCreateBlank" Text="Criar relatóri' + 
'o vazio"/><StrRes Name="startOpenReport" Text="Abrir relatório"/><StrRes Name="startOpenLast" Text="Abrir o último relatório"/><StrRes Name="startE' + 
'ditAliases" Text="Editar nomes das ligações"/><StrRes Name="startHelp" Text="Ajuda"/><StrRes Name="5900" Text="Mostrador"/><StrRes Name="5901" Text=' + 
'"Adicionar mostrador"/><StrRes Name="5902" Text="Apagar mostrador"/><StrRes Name="5903" Text="Editar mostrador"/><StrRes Name="6000" Text="Herdar erro' + 
'"/><StrRes Name="6001" Text="Relatórios base ou herdados têm objectos duplicados. Que devo fazer?"/><StrRes Name="6002" Text="Apagar duplicados"/><S' + 
'trRes Name="6003" Text="Renomear duplicados"/><StrRes Name="6004" Text="Ordenar por nome"/><StrRes Name="crGroup" Text="Grupo"/><StrRes Name="4331" Te' + 
'xt="Agrupamento"/><StrRes Name="dsColorOth" Text="Outra..."/><StrRes Name="6100" Text="Editor do Fundo"/><StrRes Name="6101" Text="Pincel"/><StrRes Na' + 
'me="6102" Text="Gradiente"/><StrRes Name="6103" Text="Vidro"/><StrRes Name="6104" Text="Estilo do Pincel:"/><StrRes Name="6105" Text="Cor do Fundo:"/>' + 
'<StrRes Name="6106" Text="Cor da Letra:"/><StrRes Name="6107" Text="Estilo de Gradiente:"/><StrRes Name="6108" Text="Cor inicial:"/><StrRes Name="6109' + 
'" Text="Cor final:"/><StrRes Name="6110" Text="Orientação:"/><StrRes Name="6111" Text="Cor:"/><StrRes Name="6112" Text="Mistura:"/><StrRes Name="611' + 
'3" Text="Show hatch"/><StrRes Name="bsSolid" Text="Sólido"/><StrRes Name="bsClear" Text="Vazio"/><StrRes Name="bsHorizontal" Text="Horizontal"/><StrR' + 
'es Name="bsVertical" Text="Vertical"/><StrRes Name="bsFDiagonal" Text="Diagonal p/Frente"/><StrRes Name="bsBDiagonal" Text="Diagonal p/Trás"/><StrRes' + 
' Name="bsCross" Text="Cruzado"/><StrRes Name="bsDiagCross" Text="Diagonal cruzado"/><StrRes Name="gsHorizontal" Text="Horizontal"/><StrRes Name="gsVer' + 
'tical" Text="Vertical"/><StrRes Name="gsElliptic" Text="Elíptico"/><StrRes Name="gsRectangle" Text="Rectangular"/><StrRes Name="gsVertCenter" Text="C' + 
'entro Vertical"/><StrRes Name="gsHorizCenter" Text="Centro Horizontal"/><StrRes Name="foVertical" Text="Vertical"/><StrRes Name="foHorizontal" Text="H' + 
'orizontal"/><StrRes Name="foVerticalMirror" Text="Espelho Vertical"/><StrRes Name="foHorizontalMirror" Text="Espelho Horizontal"/><StrRes Name="6200" ' + 
'Text="Editor de Hiperligações"/><StrRes Name="6201" Text="Tipo de Hiperligação"/><StrRes Name="6202" Text="URL"/><StrRes Name="6203" Text="Nº de ' + 
'Pág."/><StrRes Name="6204" Text="Âncora"/><StrRes Name="6205" Text="Relatório"/><StrRes Name="6206" Text="Página de Relatório"/><StrRes Name="620' + 
'7" Text="Personalizado"/><StrRes Name="6208" Text="Propriedades"/><StrRes Name="6209" Text="Indique um URL (exemplo: http://www.url.com):"/><StrRes Na' + 
'me="6210" Text="ou indique uma expressão que resulte num URL:"/><StrRes Name="6211" Text="Indique um nº de página:"/><StrRes Name="6212" Text="ou u' + 
'ma expressão que resulte num nº de página:"/><StrRes Name="6213" Text="Indique o nome de uma âncora:"/><StrRes Name="6214" Text="or uma expressão' + 
' que resulte no nome de uma âncora:"/><StrRes Name="6215" Text="Nome do relatório:"/><StrRes Name="6216" Text="Variável do relatório:"/><StrRes Na' + 
'me="6217" Text="Indique o valor da variável:"/><StrRes Name="6218" Text="ou uma expressão que resulte num valor para a variável:"/><StrRes Name="62' + 
'19" Text="Página do relatório:"/><StrRes Name="6220" Text="Indique uma hiperligação:/><StrRes Name="6221" Text="ou uma expressão que resulte numa' + 
' hiperligação:"/><StrRes Name="6222" Text="O que acontece se clicar neste objecto na janela de pré-visualização:"/><StrRes Name="6223" Text="O UR' + 
'L especificado será aberto."/><StrRes Name="6224" Text="Irá para a página especificada."/><StrRes Name="6225" Text="Irá para o objecto que contém' + 
' a âncora especificada."/><StrRes Name="6226" Text="O relatório especificado será gerado e aberto num separador de pré-visualização."/><StrRes N' + 
'ame="6227" Text="A página especificada será gerada e aberta num separador de pré-visualização."/><StrRes Name="6228" Text="Deveria criar um manip' + 
'ulador de eventos OnClick para definir uma acção personalizada."/><StrRes Name="6229" Text="Modifica a aparência do objecto de modo a parecer uma h' + 
'iperligação"/><StrRes Name="mvHyperlink" Text="Hiperligação..."/><StrRes Name="6300" Text="Select same type on Parent"/><StrRes Name="6301" Text="' + 
'Select same type on Page"/><StrRes Name="6302" Text="Reset to Parent object"/><StrRes Name="6303" Text="Reset to Parent object with childs"/></Resourc' + 
'es>' + 
' ';

initialization
  frxResources.AddXML(resXML);

end.
