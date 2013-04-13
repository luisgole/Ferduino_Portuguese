///*****************************************************************************************************************************************************
//......................................................................................................................................................
//...............           .           ...           .....         . .....     ..... .   ...     ...     .....     .....           ....................
//..............                                       ...             . .       ....      .       .         .       ...     ...     . .................
//.............  2@B@B@B@B@.  @B@B@B@B@B,  N@B@B@@@BN:  . iB@B@B@@@B5:     .@@@i .... vB@@   .@B@i   N@B@B:   . OB@;  .  :qB@@@B@BM7   .................
//.............  ZB@BXqGZ8Z  .B@BMX00GGM.  BB@BXNZB@B@q   r@@@N00MB@B@B:   ,B@Br ...  L@B@   .B@B7   @B@B@B:    B@B7    8@B@M1JUO@B@B: .................
//.............  S@BO         @B@.         G@Bk    j@B@.  iB@B     ,@B@B.  .@B@:  ... vB@B   .@B@i   O@@YB@B.   M@@i   B@B@.      BB@B  ................
//.............  XB@O         @@B:         8B@F    J@@B   i@B@       @B@G  .B@Bi ...  7@B@   .B@Bi   MB@ rB@B   G@@i  r@B@,       .@B@v  ...............
//.............  F@B@q8OMB5   @B@B@B@@@,   Z@BBJ2UMB@B:   iB@@  . .  P@B@  .@B@i  ... vB@B   .@B@i   M@@, E@@B  GB@i  qB@B  .....  B@BN  ...............
//.............. kB@B@@@B@M   B@@8XZGOO.   8B@B@B@B@v     i@B@   .   qB@B  .B@B: ...  r@B@   .B@B;   MB@:  MB@G S@Bi  q@B@   ...   @B@k  ...............
//.............  S@BM         @B@,         Z@Bq  :@@@5    iB@B       B@BZ  .@B@:      7B@B   .@B@i   O@Bi   @B@7uB@i  uB@@.   .   ,@@B7 ................
//.............  kB@M      .  B@B:         8B@N   :@B@Y   i@@@      O@B@.   B@@0      M@BM   .B@B;   MB@i    @@@B@@i  .@B@G       B@B@   ...............
//.............  q@@@   ....  @B@Nju1UFk.  M@BM    1@B@:  rB@B2u1X@B@B@:    r@@B@Jrr2B@B@.   .@B@r   B@Br    ,@B@B@r   i@B@BS777NB@@@   ................
//.............. NB@B  ..... .B@B@B@B@@@:  MB@O  .  B@B@  i@B@B@B@B@q;   ..  ,P@B@B@B@Bu   . ,@@B7   @@@;  .  i@B@Bi     1B@B@B@B@O7   .................
//.............   ..  .......   . ... ..    ..  ...  ...   ..   .       ....    .:::,     ... ...     ..  ...   . .  ..     ,:::.     ..................
//..............     .........           .     .....     .           ....... .         . ....     ..     .....     .......         .....................
//................................... ................. ......... ............... . ........... ................. ........... . . ......................
//******************************************************************************************************************************************************
//***********************              Desenvolvido por Fernando Garcia         ************************************************************************
//******************************************************************************************************************************************************
//******* Dúvidas, sugestões e elogios: fefegarcia_1@hotmail.com ***************************************************************************************
//*****************************************************************************************************************************************************/

// Este programa é compatível com a IDE 1.0.4 desde que as bibliotecas "WConstants.h" e "wiring.h" sejam colocadas na pasta ...arduino-1.0.2\hardware\arduino\cores\arduino.

//---------------------------------------------------------

// Este programa foi desenvolvido com base na versão Stilo 2.1
// Disponível nesta página http://code.google.com/p/stilo/ 

//---------------------------------------------------------

// Algoritmo de controle de LED é baseado em Krusduino de Hugh Dangerfield
// http://Code.Google.com/p/dangerduino/
// Algoritmo da fase lunar foi escrito por Jamie Jardin vulgo "TheDOdblG", baseado no código de NightAtTheOpera's Lunar Phase 
// http://www.nano-reef.com/forums/index.php?showtopic=217305

//-----------------------------------------------------------
// Este programa é software livre; Você pode redistribuí-lo e/ou
// modificá-lo sob os termos da GNU General Public License
// como publicada pela Free Software Foundation versão 3
// da licença, ou (por sua opção) qualquer versão posterior.
// Este programa é distribuído na esperança que seja útil,
// mas sem qualquer garantia; sem mesmo a garantia implícita de
// comercialização ou propósito particular. Consulte o
// GNU General Public License para mais detalhes.

//*************************************************************************************************
//*************** Biliotecas utilizadas ***********************************************************
//*************************************************************************************************
#include <UTFT.h>    
#include <UTouch.h> 
#include <Wire.h>
#include <EEPROM.h>
#include <writeAnything.h> // Funções de leitura e gravação da EEPROM.
#include <DS1307henning.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <SdFat.h>
#include <SdFatUtil.h>
#include <EtherCard.h>
#include <avr/pgmspace.h>
//#include <PCF8575.h>
//#include <JeeLib.h>
//****************************************************************************************************
//***************** Sensores de temperatura **********************************************************
//****************************************************************************************************
OneWire OneWireBus(47);                   //Sensor de temperatura da água e dissipador ligados ao pino 47.
DallasTemperature sensors(&OneWireBus);  // Pass our oneWire reference to Dallas Temperature. 
DeviceAddress sensor_agua= {0x28, 0x9C, 0xA9, 0xAA, 0x03, 0x00, 0x00, 0x44 }; // Atribui os endereços dos sensores de temperatura. Adicionar / Alterar os endereços conforme necessário.
DeviceAddress sensor_dissipador = {0x28, 0xE1, 0x96, 0xAA, 0x03, 0x00, 0x00, 0x7D }; // Atribui os endereços dos sensores de temperatura. Adicionar / Alterar os endereços conforme necessário.

//****************************************************************************************************
//****************** Variáveis de textos e fontes ****************************************************
//****************************************************************************************************
#define LARGE true
#define SMALL false
extern uint8_t SmallFont[];   // Declara que fontes vamos usar
extern uint8_t BigFont[];     // Declara que fontes vamos usar
char buffer[45];

//****************************************************************************************************
//****************** Define funções dos pinos digitais e analógicos **********************************
//****************************************************************************************************
// Pino 2 reservado para INT do RFM12B.
// Pinos 3, 4, 5, 6 e 7 reservados para o Touch. 
const int ledPinMoon = 8;      // Pino que liga os leds da luz noturna
const int ledPinBlue = 9;      // Pino que liga os leds azuis
const int ledPinWhite = 10;     // Pino que liga os leds brancos
const int ledPinRoyBlue = 11;   // Pino que liga os leds "royal blue"
const int ledPinRed = 12;      // Pino que liga os leds vermelho
const int fanPin = 13;         // Pino que controla a velocidade das ventoinhas do dissipador
const int ledPinUV = 44;       // Pino que liga os leds ultra violeta
// Pinos 42 e 43 reservados para o RTC.
const int aquecedorPin = 45;   // Pino que liga o aquecedor
const int chillerPin = 46;     // Pino que liga o chiller
// Pino 47 reservado para os sensores de temperatura
const int ozonizadorPin = 48; // pino que liga o ozonizador
const int reatorPin = 49;      // Pino que liga o CO2 do reator.
const int sensor1 = A0;        //Pino analógico que verifica se há tensão na bóia da quarentena.
const int sensor2 = A1;        //Pino analógico que verifica se há tensão na bóia inferior do sump.
const int sensor3 = A2;        //Pino analógico que verifica se há tensão na bóia superior do sump.
const int sensor4 = A3;        //Pino analógico que verifica se há tensão na bóia inferior do reservatório.
const int sensor5 = A4;        //Pino analógico que verifica o nível do reef.
const int sensor6 = A5;        //Pino analógico que verifica o nível do fish only.
const int dosadora1 = A6;     // Bomba dosadora 1
const int dosadora2 = A7;     // Bomba dosadora 2
const int dosadora3 = A8;     // Bomba dosadora 3
const int dosadora4 = A9;     // Bomba dosadora 4
const int dosadora5 = A10;     // Bomba dosadora 5
const int dosadora6 = A11;     // Bomba dosadora 6
// Pino A12 reservado para SS do RFM12B
const int bomba1Pin = A13;      // Bomba que tira água da quarentena.
const int bomba2Pin = A14;     // Bomba que tira água do sump.
const int bomba3Pin = A15;     // Bomba que coloca água no sump.

///**************** PCF8575TS **********************************
const int temporizador1 = 0;       //P0        //Pino que liga o timer 1.
const int temporizador2 = 1;       //P1        //Pino que liga o timer 2.
const int temporizador3 = 2;       //P2         //Pino que liga o timer 3.
const int temporizador4 = 3;       //P3        //Pino que liga o timer 4.
const int temporizador5 = 4;       //P4        //Pino que liga o timer 5.
const int alarmPin = 5;            //P5     // Pino que aciona o alarme
const int multiplexadorS0Pin = 6;  //P6 // Pino S0 de controle dos stamps
const int multiplexadorS1Pin = 7;  //P7 // Pino S1 de controle dos stamps
const int desativarFanPin = 8;     //P10 // Pino que desativa os coolers.
const int solenoide1Pin = 9;       //P11 // Liga a reposicao de água doce.

//*******************************************************************************************************
//********************** Funções do RTC ********************************************************************
//*******************************************************************************************************
DS1307 rtc(20, 21); // Indica em quais pinos o RTC está conectado.
Time t_temp, t;

//*******************************************************************************************************
//********************** Variáveis das fuções do touch screen e tela inicial ****************************
//*******************************************************************************************************
UTFT        myGLCD(ITDB32WC, 38,39,40,41);   //"X" é o modelo do LCD
UTouch      myTouch(6,5,4,3,2); 
//UTouch      myTouch(7,6,5,4,3);

long previousMillis = 0;
byte data[56];
String day; 
int whiteLed, blueLed;    // Valor anterior de PWM.
int dispScreen = 0;

// tela inicio =0, 
// tela de menu = 1, 
// tela do relogio = 2,
// tela de teste = 3,
// tela controle de temperatua = 4, 
// tela alterar valores dos led = 5
// tela para alterar potencia dos leds = 6,
// tela tpa = 7, 
// tela config. bombas dosadoras = 8,
// tela graficos = 9,
// tela wavemaker = 10, 
// tela grafico temperatura = 11,
// tela grafico orp = 12, 
// tela grafico ph do aquario = 13,
// tela configuracao parametros = 14, 
// tela configuracao de ph do reator de calcio = 15, 
// tela configuracao orp = 16, 
// tela grafico de ph do reator de calcio = 17, 
// tela configuracao de ph do aquario = 18, 
// tela grafico de densidade = 19,
// tela configurar densidade = 20, 
// tela esolha uma dosadora = 21,.... 
//*****************************************************************************************
//*********************** Parâmetros ******************************************************
//*****************************************************************************************
byte status_parametros = 0x0;
//bit 0;    tempCflag    // Sinaliza que o aquecedor está ligado / desligado
//bit 1;    tempHflag    // Sinaliza que o chiller está ligado / desligado
//bit 2;    tempAflag    // Sinaliza que o alarme de temperatura está ativo
//bit 3;    PHAAflag     // Sinaliza que o PH do aquário esta fora do especificado
//bit 4;    DENAflag     // Sinaliza que a densidade esta fora do especificado
//bit 5;    PHRflag      // Sinaliza que CO2 esta ligado / desligado
//bit 6;    PHRAflag     // Sinaliza que o PH do reator de cálcio esta fora do especificado
//bit 7;    ORPflag      // Sinaliza que o ozonizador esta ligado / desligado
byte status_parametros_1 = 0x0;
//bit 0     ORPAflag = 0;        // Sinaliza que a ORP esta fora do especificado

//*****************************************************************************************
//*********************** Variáveis do controle de temperatura da água ********************
//*****************************************************************************************
float tempC = 0;              // Temperatura da água
float setTempC = 0;          // Temperatura desejada
float offTempC = 0;          // Variacao permitida da temperatura
float alarmTempC = 0;        // Variacao para acionar o alarme de temperatura da água
int contador_temp = 0;
float temperatura_agua_temp = 0; // Temperatura temporária
float temperatura_dissipador_temp = 0; // Temperatura temporária


//*****************************************************************************************
//************************ Variáveis do controle do PH do aquário *************************
//*****************************************************************************************
float PHA = 0;               // PH do aquário
float setPHA = 0;           // PH desejado do aquário
float offPHA = 0;           // Variaçãoo permitida do PH do aquário
float alarmPHA = 0;         // Variação para acionar o alarme de ph do aquário

//*****************************************************************************************
//************************ Variáveis de controle de densidade *****************************
//*****************************************************************************************
int DEN = 0;                 // Densidade
int setDEN = 0;             // Densidade desejada
int offDEN = 0;             // Variação permitida da densidade
int alarmDEN = 0;           // Variação para acionar o alarme de densidade

//*****************************************************************************************
//************************ Variáveis de controle do PH do reator de cálcio ****************
//*****************************************************************************************
float PHR = 0;               // Valores PH reator
float setPHR = 0;           // PH do reator desejado
float offPHR = 0;           // Variacao permitida do PH do reator
float alarmPHR = 0;         // Variacao para acionar o alarme do PH do reator de calcio

//*****************************************************************************************
//************************ Variáveis de controle da  ORP **********************************
//*****************************************************************************************
int ORP = 0;                 // Valores ORP
float setORP = 0;           // ORP desejada
float offORP = 0;           // Variação permitida da ORP
float alarmORP = 0;         // Variacão para acionar o alarme da ORP

//*****************************************************************************************
//************************ Variáveis de controle de velocidade dos coolers ****************
//*****************************************************************************************
const int HtempMin = 30;    // Declara a temperatura para iniciar o funcionamento das ventoinhas do dissipador 
const int HtempMax = 40;    // Declara que as ventoinhas devem estar em sua velocidade máxima quando o dissipador estiver com 40°c

//*****************************************************************************************
//************************ Variável de controle da temperatura do dissipador **************
//*****************************************************************************************
float tempH = 0;            // Temperatura do dissipador

//*****************************************************************************************
//************************ Variáveis temporárias de controle de temperatura da água *******
//*****************************************************************************************
float temp2beS;           
float temp2beO;
float temp2beA;

//*****************************************************************************************
//************************ Variáveis temporárias de controle do PH do reator de cálcio ****
//*****************************************************************************************
float PHR2beS;             
float PHR2beO;
float PHR2beA;

//*****************************************************************************************
//************************ Variáveis temporárias de controle do PH do aquário *************
//*****************************************************************************************
float PHA2beS;             
float PHA2beO;
float PHA2beA;

//*****************************************************************************************
//************************ Variáveis temporárias de controle da ORP ***********************
//*****************************************************************************************
float ORP2beS;               //orp temporaria
float ORP2beO;
float ORP2beA;

//*****************************************************************************************
//************************ Variáveis temporárias de controle da densidade *****************
//*****************************************************************************************
float DEN2beS;            
float DEN2beO;
float DEN2beA;

//*****************************************************************************************
//************************ Variáveis de controle da iluminação ****************************
//*****************************************************************************************
int LedChangTime = 0;             // Página de alteração do leds, tempo e valores.
boolean MeanWell = true;  // Se estiver usando drivers cuja potência máxima seja obtida aplicando zero volt e a mínima seja 5 volts altere de "true" para "false".
boolean LEDtestTick = false;   // Acelerar o tempo durante o teste dos leds. 
int min_cnt ;
int bled_out;
int wled_out;
int rbled_out;
int rled_out;
int uvled_out;
int bled_out_temp;
int wled_out_temp;
int rbled_out_temp;
int rled_out_temp;
int uvled_out_temp;
int moonled_out;
boolean periodo_selecionado = false;
int y_tocado;
boolean teste_em_andamento = false;
int b_out, w_out, moon_out, rb_out, r_out, uv_out;
byte cor_selecionada = 0x0;
// bit 1 = led branco
// bit 2 = led azul
// bit 3 = led azul royal
// bit 4 = led vermelho
// bit 5 = led violeta
int setor_selecionado = 0;
boolean mensagem = true;
float suavizar = 0.0; // LEDS iniciam suavemente e chega ao valor especificado em 50 segundos.

//*************************************************************************************************
//***************LED design ***********************************************************
//*************************************************************************************************     
const byte cor_canal1[] = {255, 255, 255};  // Branco 
const byte cor_canal2[] = {9, 184, 255};    // Azul
const byte cor_canal3[] = {58, 95, 205};    // Azul Royal 
const byte cor_canal4[] = {255, 0, 0};      // Vermelho
const byte cor_canal5[] = {224, 102, 255};  // Violeta

//*****************************************************************************************
//************************ Variáveis da fase lunar ******************************************
//*****************************************************************************************
float LC = 29.53059;  // 1 ciclo lunar = 29.53059 dias.
String LP;
double AG;
int MaxI , tMaxI;  // Potência  máxima na Lua cheia.             
int MinI, tMinI;  // Potência  mínima na Lua nova.

//*****************************************************************************************
//************************ Variáveis da TPA automática ************************************
//*****************************************************************************************
int hora = 0;
int minuto = 0;
int duracaomaximatpa = 0;
int segunda = 0;
int terca = 0;
int quarta = 0;
int quinta = 0;
int sexta = 0;
int sabado = 0;
int domingo = 0;
int tpa = 0;                             // Controla os estágios da TPA automática
boolean tpa_em_andamento = false;           // Sinaliza TPA automática em andamento
boolean falha_tpa = false;           // Sinaliza falha durante a TPA automática
unsigned long tempo = 0;                 // Duração de cada estágio da TPA automática
unsigned long marcadoriniciotpa = 0;   // Evita que uma tpa inicie próximo do millis zerar
unsigned long shiftedmillis = 0;       // Evita que uma tpa inicie próximo do millis zerar

//*****************************************************************************************
//************************ Variáveis temporárias da TPA (Troca Parcial de Água) automática ************************************
//*****************************************************************************************
int temp2hora;
int temp2minuto;
int temp2duracaomaximatpa;
int temp2segunda;
int temp2terca;
int temp2quarta;
int temp2quinta;
int temp2sexta;
int temp2sabado;
int temp2domingo;

//****************************************************************************************
//*********************** Variáveis de controle das funções que utilizam o cartao SD *****
//****************************************************************************************
unsigned long logtempminutoantes = 0;  // Variável que controla o tempo para gravação dos parâmetros no cartão SD 
const int chipselect = 4;            // Para utilizar o Sd card do LCD altere para 53
Sd2Card card;
SdFile file;
SdFile root;
SdVolume volume;
char time1;
char time2;
char time3;
char time4;
char time5;

//*****************************************************************************************
//*********************** Variável do controle de níveis **********************************
//*****************************************************************************************
boolean nivel_status = 0;             // Sinaliza nivel baixo em um dos aquários

//*****************************************************************************************
//************************ Variável de controle da reposição de água doce *****************
//*****************************************************************************************
boolean ato = 0;                      // Sinaliza reposição ligada / desligada

//*****************************************************************************************
//************************ Variáveis de envio da informações ao cosm.com ******************
//*****************************************************************************************
long previous_Millis = 0; // Variável que controla o tempo para envio dos dados
byte Status = 0x0;
// bit 1 int reposicao_status;
// bit 2 niveis_status;
// bit 3 tpa_status;

//*****************************************************************************************
//************************* Funções do ethernet shield ************************************
//*****************************************************************************************
boolean Ethernet_Shield = false; // Altere para "false" caso não tenha um Ethernet Shield conectado ao Arduino.
#define FEED    "xxxxx"               // Número do projeto(cosm.com).
#define APIKEY  "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" //Senha do projeto(cosm.com)
static byte mymac[] = {0x54, 0x55, 0x58, 0x10, 0x00, 0x26}; // Este mac deve ser único na rede.
static byte myip[] = {192, 168, 2, 105};
static byte gwip[] = {192, 168, 2, 1};
char website[] PROGMEM = "api.cosm.com";
byte Ethernet::buffer[500];
Stash stash;

//*****************************************************************************************
//************************** Variáveis de controle do multiplexador ***********************
//*****************************************************************************************
boolean Stamps = false; // Altere para "false" caso não tenha ao menos um dos circuitos de PH, ORP e EC da Atlas Scientific.
long millis_antes = 0;
int DENT; // Densidade temporária.
float PHT; // PH temporário.
int ORPT; // ORP temporária
char sensorstring[15];
byte holding;
short ph1=0; // Y0
short ph2=1; // Y1
short orp=2; // Y2
short ec=3; // Y3
int done = 0;

//*****************************************************************************************
//************************** Variáveis da solicitação de senha ****************************
//*****************************************************************************************
char stCurrent[7]="";
char limpar_senha [7] = "";
int stCurrentLen=0;
char senha [7] = {'1','2','3','4','5','6','\0'}; // Insira sua senha aqui. O caracter '\0' não deve ser alterado.

//*****************************************************************************************
//************************** Variáveis dosadoras ******************************************
//*****************************************************************************************
boolean dosadoras = true; //Altere para "false" caso não tenha as dosadoras.
char time9;
char time10;
char time11;
char time15;
char time16;
char time17;
int contador = 0;
int minuto01 = 0;
int minuto11 = 0;
//int deslocamento_botao_x = 155;
long tempo_dosagem = 0;
float dose_dosadora_1_manual = 0.0;
float dose_dosadora_2_manual = 0.0;
float dose_dosadora_3_manual = 0.0;
float dose_dosadora_4_manual = 0.0;
float dose_dosadora_5_manual = 0.0;
float dose_dosadora_6_manual = 0.0;
boolean modo_manual = false;
boolean modo_personalizado = false;
boolean modo_calibrar = false;
byte dosadora_selecionada = 0x0; // 0 = false, 1 = true
// bit 1 = dosadora 1
// bit 2 = dosadora 2
// bit 3 = dosadora 3
// bit 4 = dosadora 4
// bit 5 = dosadora 5
// bit 6 = dosadora 6
int ativar_desativar_1 = 0;
int ativar_desativar_2 = 0;
int ativar_desativar_3 = 0;
int modo_personalizado_on_1 = 0;
int modo_personalizado_on_2 = 0;
int modo_personalizado_on_3 = 0;
float fator_calib_dosadora_1 = 0.0;
float fator_calib_dosadora_2 = 0.0;
float fator_calib_dosadora_3 = 0.0;
float dose_dosadora_1_personalizada = 0.0;
float dose_dosadora_2_personalizada = 0.0;
float dose_dosadora_3_personalizada = 0.0;
int hora_inicial_dosagem_personalizada_1 = 0;
int minuto_inicial_dosagem_personalizada_1 = 0;
int hora_final_dosagem_personalizada_1 = 0;
int minuto_final_dosagem_personalizada_1 = 0;
int segunda_dosagem_personalizada_1 = 0;
int terca_dosagem_personalizada_1 = 0;
int quarta_dosagem_personalizada_1 = 0;
int quinta_dosagem_personalizada_1 = 0;
int sexta_dosagem_personalizada_1 = 0;
int sabado_dosagem_personalizada_1 = 0;
int domingo_dosagem_personalizada_1 = 0;
int hora_inicial_dosagem_personalizada_2 = 0;
int minuto_inicial_dosagem_personalizada_2 = 0;
int hora_final_dosagem_personalizada_2 = 0;
int minuto_final_dosagem_personalizada_2 = 0;
int segunda_dosagem_personalizada_2 = 0;
int terca_dosagem_personalizada_2 = 0;
int quarta_dosagem_personalizada_2 = 0;
int quinta_dosagem_personalizada_2 = 0;
int sexta_dosagem_personalizada_2 = 0;
int sabado_dosagem_personalizada_2 = 0;
int domingo_dosagem_personalizada_2 = 0;
int hora_inicial_dosagem_personalizada_3 = 0;
int minuto_inicial_dosagem_personalizada_3 = 0;
int hora_final_dosagem_personalizada_3 = 0;
int minuto_final_dosagem_personalizada_3 = 0;
int segunda_dosagem_personalizada_3 = 0;
int terca_dosagem_personalizada_3 = 0;
int quarta_dosagem_personalizada_3 = 0;
int quinta_dosagem_personalizada_3 = 0;
int sexta_dosagem_personalizada_3 = 0;
int sabado_dosagem_personalizada_3 = 0;
int domingo_dosagem_personalizada_3 = 0;
int quantidade_dose_dosadora_1_personalizada = 0;
int quantidade_dose_dosadora_2_personalizada = 0;
int quantidade_dose_dosadora_3_personalizada = 0;
int ativar_desativar_4 = 0;
int ativar_desativar_5 = 0;
int ativar_desativar_6 = 0;
int modo_personalizado_on_4 = 0;
int modo_personalizado_on_5 = 0;
int modo_personalizado_on_6 = 0;
float fator_calib_dosadora_4 = 0.0;
float fator_calib_dosadora_5 = 0.0;
float fator_calib_dosadora_6 = 0.0;
float dose_dosadora_4_personalizada = 0.0;
float dose_dosadora_5_personalizada = 0.0;
float dose_dosadora_6_personalizada = 0.0;
int hora_inicial_dosagem_personalizada_4 = 0;
int minuto_inicial_dosagem_personalizada_4 = 0;
int hora_final_dosagem_personalizada_4 = 0;
int minuto_final_dosagem_personalizada_4 = 0;
int segunda_dosagem_personalizada_4 = 0;
int terca_dosagem_personalizada_4 = 0;
int quarta_dosagem_personalizada_4 = 0;
int quinta_dosagem_personalizada_4 = 0;
int sexta_dosagem_personalizada_4 = 0;
int sabado_dosagem_personalizada_4 = 0;
int domingo_dosagem_personalizada_4 = 0;
int hora_inicial_dosagem_personalizada_5 = 0;
int minuto_inicial_dosagem_personalizada_5 = 0;
int hora_final_dosagem_personalizada_5 = 0;
int minuto_final_dosagem_personalizada_5 = 0;
int segunda_dosagem_personalizada_5 = 0;
int terca_dosagem_personalizada_5 = 0;
int quarta_dosagem_personalizada_5 = 0;
int quinta_dosagem_personalizada_5 = 0;
int sexta_dosagem_personalizada_5 = 0;
int sabado_dosagem_personalizada_5 = 0;
int domingo_dosagem_personalizada_5 = 0;
int hora_inicial_dosagem_personalizada_6 = 0;
int minuto_inicial_dosagem_personalizada_6 = 0;
int hora_final_dosagem_personalizada_6 = 0;
int minuto_final_dosagem_personalizada_6 = 0;
int segunda_dosagem_personalizada_6 = 0;
int terca_dosagem_personalizada_6 = 0;
int quarta_dosagem_personalizada_6 = 0;
int quinta_dosagem_personalizada_6 = 0;
int sexta_dosagem_personalizada_6 = 0;
int sabado_dosagem_personalizada_6 = 0;
int domingo_dosagem_personalizada_6 = 0;
int quantidade_dose_dosadora_4_personalizada = 0;
int quantidade_dose_dosadora_5_personalizada = 0;
int quantidade_dose_dosadora_6_personalizada = 0;
//*****************************************************************************************
//************************** Variáveis temporárias das dosadoras **************************
//*****************************************************************************************
float fator_calib_dosadora_1_temp2;
float fator_calib_dosadora_2_temp2;
float fator_calib_dosadora_3_temp2;
float dose_dosadora_1_personalizada_temp2;
float dose_dosadora_2_personalizada_temp2;
float dose_dosadora_3_personalizada_temp2;
float dose_dosadora_1_manual_temp2;
float dose_dosadora_2_manual_temp2;
float dose_dosadora_3_manual_temp2;
int temp2hora_inicial_dosagem_personalizada_1;
int temp2minuto_inicial_dosagem_personalizada_1;
int temp2hora_final_dosagem_personalizada_1;
int temp2minuto_final_dosagem_personalizada_1;
int temp2segunda_dosagem_personalizada_1;
int temp2terca_dosagem_personalizada_1;
int temp2quarta_dosagem_personalizada_1;
int temp2quinta_dosagem_personalizada_1;
int temp2sexta_dosagem_personalizada_1;
int temp2sabado_dosagem_personalizada_1;
int temp2domingo_dosagem_personalizada_1;
int temp2hora_inicial_dosagem_personalizada_2;
int temp2minuto_inicial_dosagem_personalizada_2;
int temp2hora_final_dosagem_personalizada_2;
int temp2minuto_final_dosagem_personalizada_2;
int temp2segunda_dosagem_personalizada_2;
int temp2terca_dosagem_personalizada_2;
int temp2quarta_dosagem_personalizada_2;
int temp2quinta_dosagem_personalizada_2;
int temp2sexta_dosagem_personalizada_2;
int temp2sabado_dosagem_personalizada_2;
int temp2domingo_dosagem_personalizada_2;
int temp2hora_inicial_dosagem_personalizada_3;
int temp2minuto_inicial_dosagem_personalizada_3;
int temp2hora_final_dosagem_personalizada_3;
int temp2minuto_final_dosagem_personalizada_3;
int temp2segunda_dosagem_personalizada_3;
int temp2terca_dosagem_personalizada_3;
int temp2quarta_dosagem_personalizada_3;
int temp2quinta_dosagem_personalizada_3;
int temp2sexta_dosagem_personalizada_3;
int temp2sabado_dosagem_personalizada_3;
int temp2domingo_dosagem_personalizada_3;
int quantidade_dose_dosadora_1_personalizada_temp2;
int quantidade_dose_dosadora_2_personalizada_temp2;
int quantidade_dose_dosadora_3_personalizada_temp2;
int modo_personalizado_on_1_temp2;
int modo_automatico_on_1_temp2;
int modo_personalizado_on_2_temp2;
int modo_personalizado_on_3_temp2;
float fator_calib_dosadora_4_temp2;
float fator_calib_dosadora_5_temp2;
float fator_calib_dosadora_6_temp2;
float dose_dosadora_4_personalizada_temp2;
float dose_dosadora_5_personalizada_temp2;
float dose_dosadora_6_personalizada_temp2;
float dose_dosadora_4_manual_temp2;
float dose_dosadora_5_manual_temp2;
float dose_dosadora_6_manual_temp2;
int temp2hora_inicial_dosagem_personalizada_4;
int temp2minuto_inicial_dosagem_personalizada_4;
int temp2hora_final_dosagem_personalizada_4;
int temp2minuto_final_dosagem_personalizada_4;
int temp2segunda_dosagem_personalizada_4;
int temp2terca_dosagem_personalizada_4;
int temp2quarta_dosagem_personalizada_4;
int temp2quinta_dosagem_personalizada_4;
int temp2sexta_dosagem_personalizada_4;
int temp2sabado_dosagem_personalizada_4;
int temp2domingo_dosagem_personalizada_4;
int temp2hora_inicial_dosagem_personalizada_5;
int temp2minuto_inicial_dosagem_personalizada_5;
int temp2hora_final_dosagem_personalizada_5;
int temp2minuto_final_dosagem_personalizada_5;
int temp2segunda_dosagem_personalizada_5;
int temp2terca_dosagem_personalizada_5;
int temp2quarta_dosagem_personalizada_5;
int temp2quinta_dosagem_personalizada_5;
int temp2sexta_dosagem_personalizada_5;
int temp2sabado_dosagem_personalizada_5;
int temp2domingo_dosagem_personalizada_5;
int temp2hora_inicial_dosagem_personalizada_6;
int temp2minuto_inicial_dosagem_personalizada_6;
int temp2hora_final_dosagem_personalizada_6;
int temp2minuto_final_dosagem_personalizada_6;
int temp2segunda_dosagem_personalizada_6;
int temp2terca_dosagem_personalizada_6;
int temp2quarta_dosagem_personalizada_6;
int temp2quinta_dosagem_personalizada_6;
int temp2sexta_dosagem_personalizada_6;
int temp2sabado_dosagem_personalizada_6;
int temp2domingo_dosagem_personalizada_6;
int quantidade_dose_dosadora_4_personalizada_temp2;
int quantidade_dose_dosadora_5_personalizada_temp2;
int quantidade_dose_dosadora_6_personalizada_temp2;
int modo_personalizado_on_4_temp2;
int modo_personalizado_on_5_temp2;
int modo_personalizado_on_6_temp2;
//*****************************************************************************************
//************************** Variáveis dos timers *****************************************
//*****************************************************************************************
byte temporizador =0x0; // 0 = false, 1 = true
//bit 1 = temporizador 1
//bit 2 = temporizador 2
//bit 3 = temporizador 3
//bit 4 = temporizador 4
//bit 5 = temporizador 5
int temporizador_1_ativado = 0;
int temporizador_2_ativado = 0;
int temporizador_3_ativado = 0;
int temporizador_4_ativado= 0;
int temporizador_5_ativado= 0;
int on1_minuto = 0;
int on1_hora = 0;
int on2_minuto = 0;
int on2_hora = 0;
int on3_minuto = 0;
int on3_hora = 0;
int on4_minuto = 0;
int on4_hora = 0;
int on5_minuto = 0;
int on5_hora = 0;
int off1_minuto = 0;
int off1_hora = 0;
int off2_minuto = 0;
int off2_hora = 0;
int off3_minuto = 0;
int off3_hora = 0;
int off4_minuto = 0;
int off4_hora = 0;
int off5_minuto = 0;
int off5_hora= 0;

//*****************************************************************************************
//************************** Variáveis temporárias dos timers *****************************
//*****************************************************************************************
int on1_minuto_temp2;
int on1_hora_temp2;
int on2_minuto_temp2;
int on2_hora_temp2;
int on3_minuto_temp2;
int on3_hora_temp2;
int on4_minuto_temp2;
int on4_hora_temp2;
int on5_minuto_temp2;
int on5_hora_temp2;
int off1_minuto_temp2;
int off1_hora_temp2;
int off2_minuto_temp2;
int off2_hora_temp2;
int off3_minuto_temp2;
int off3_hora_temp2;
int off4_minuto_temp2;
int off4_hora_temp2;
int off5_minuto_temp2;
int off5_hora_temp2;
int temporizador_1_ativado_temp2;
int temporizador_2_ativado_temp2;
int temporizador_3_ativado_temp2;
int temporizador_4_ativado_temp2;
int temporizador_5_ativado_temp2;

//*****************************************************************************************
//************************** Variáveis do PCF8575 *****************************************
//*****************************************************************************************
/*boolean PCF8575TS_S = false; // Altere para "false" caso não tenha um PCF8575
PCF8575 PCF8575TS;
byte endereco_PCF8575TS = 0x20; // Endereço em hexadecimal = 0x20
*/

//*****************************************************************************************
//************************** Comunicação RF ***********************************************
//*****************************************************************************************
/*boolean RFM12B = false; // Altere para "false" caso não tenha um RFM12B
#define myNodeID 30          // ID do emissor (intervalo 0-30) 
#define network     210      // Grupo (pode ser no intervalo de 1-250).
#define freq RF12_915MHZ     // Frequência de RF12B pode ser RF12_433MHZ, RF12_868MHZ ou RF12_915MHZ. Corresponde a frequência do módulo
typedef struct { int power1, power2, power3, battery; } PayloadTX;      // Cria uma estrutura
PayloadTX emontx;  
const int emonTx_NodeID = 10;            // ID do receptor*/

//*****************************************************************************************
//************************** Variáveis de controle da potência dos leds *******************
//*****************************************************************************************
byte bled[96] = {                       // Potência de saída dos leds azuis 255 = 100% da potência
  0, 0, 0, 0, 0, 0, 0, 0,       // 0 e 2
  0, 0, 0, 0, 0, 0, 0, 0,       // 2 e 4
  0, 0, 0, 0, 12, 21, 30, 39,       // 4 e 6
  48, 57, 66, 75, 84, 93, 102, 111,     // 6 e 8 
  120, 129, 138, 147, 156, 165, 174, 183, // 8 e 10
  192, 201, 210, 219, 228, 237, 246, 255, // 10 e 12
  255, 246, 237, 228, 219, 210, 201, 192, // 12 e 14
  183, 174, 165, 156, 147, 138, 129, 120,  // 14 e 16
  111, 102, 93, 84, 75, 66, 57, 48,       // 16 e 18
  39, 30, 21, 12, 0, 0, 0, 0,         // 18 a 20
  0, 0, 0, 0, 0, 0, 0, 0,         // 20 e 22
  0, 0, 0, 0, 0, 0, 0, 0          // 22 a 24
};  

byte wled[96] = {                         //Potência de saída dos leds brancos 255 = 100% da potência
  0, 0, 0, 0, 0, 0, 0, 0,       // 0 e 2
  0, 0, 0, 0, 0, 0, 0, 0,       // 2 e 4
  0, 0, 0, 0, 12, 21, 30, 39,       // 4 e 6
  48, 57, 66, 75, 84, 93, 102, 111,     // 6 e 8 
  120, 129, 138, 147, 156, 165, 174, 183, // 8 e 10
  192, 201, 210, 219, 228, 237, 246, 255, // 10 e 12
  255, 246, 237, 228, 219, 210, 201, 192, // 12 e 14
  183, 174, 165, 156, 147, 138, 129, 120,  // 14 e 16
  111, 102, 93, 84, 75, 66, 57, 48,       // 16 e 18
  39, 30, 21, 12, 0, 0, 0, 0,         // 18 a 20
  0, 0, 0, 0, 0, 0, 0, 0,         // 20 e 22
  0, 0, 0, 0, 0, 0, 0, 0          // 22 a 24
};
byte rbled[96] = {                         //Potência de saída dos leds brancos 255 = 100% da potência
  0, 0, 0, 0, 0, 0, 0, 0,       // 0 e 2
  0, 0, 0, 0, 0, 0, 0, 0,       // 2 e 4
  0, 0, 0, 0, 12, 21, 30, 39,       // 4 e 6
  48, 57, 66, 75, 84, 93, 102, 111,     // 6 e 8 
  120, 129, 138, 147, 156, 165, 174, 183, // 8 e 10
  192, 201, 210, 219, 228, 237, 246, 255, // 10 e 12
  255, 246, 237, 228, 219, 210, 201, 192, // 12 e 14
  183, 174, 165, 156, 147, 138, 129, 120,  // 14 e 16
  111, 102, 93, 84, 75, 66, 57, 48,       // 16 e 18
  39, 30, 21, 12, 0, 0, 0, 0,         // 18 a 20
  0, 0, 0, 0, 0, 0, 0, 0,         // 20 e 22
  0, 0, 0, 0, 0, 0, 0, 0          // 22 a 24
};
byte rled[96] = {                         //Potência de saída dos leds brancos 255 = 100% da potência
  0, 0, 0, 0, 0, 0, 0, 0,       // 0 e 2
  0, 0, 0, 0, 0, 0, 0, 0,       // 2 e 4
  0, 0, 0, 0, 12, 21, 30, 39,       // 4 e 6
  48, 57, 66, 75, 84, 93, 102, 111,     // 6 e 8 
  120, 129, 138, 147, 156, 165, 174, 183, // 8 e 10
  192, 201, 210, 219, 228, 237, 246, 255, // 10 e 12
  255, 246, 237, 228, 219, 210, 201, 192, // 12 e 14
  183, 174, 165, 156, 147, 138, 129, 120,  // 14 e 16
  111, 102, 93, 84, 75, 66, 57, 48,       // 16 e 18
  39, 30, 21, 12, 0, 0, 0, 0,         // 18 a 20
  0, 0, 0, 0, 0, 0, 0, 0,         // 20 e 22
  0, 0, 0, 0, 0, 0, 0, 0          // 22 a 24
};
byte uvled[96] = {                         //Potência de saída dos leds brancos 255 = 100% da potência
  0, 0, 0, 0, 0, 0, 0, 0,       // 0 e 2
  0, 0, 0, 0, 0, 0, 0, 0,       // 2 e 4
  0, 0, 0, 0, 12, 21, 30, 39,       // 4 e 6
  48, 57, 66, 75, 84, 93, 102, 111,     // 6 e 8 
  120, 129, 138, 147, 156, 165, 174, 183, // 8 e 10
  192, 201, 210, 219, 228, 237, 246, 255, // 10 e 12
  255, 246, 237, 228, 219, 210, 201, 192, // 12 e 14
  183, 174, 165, 156, 147, 138, 129, 120,  // 14 e 16
  111, 102, 93, 84, 75, 66, 57, 48,       // 16 e 18
  39, 30, 21, 12, 0, 0, 0, 0,         // 18 a 20
  0, 0, 0, 0, 0, 0, 0, 0,         // 20 e 22
  0, 0, 0, 0, 0, 0, 0, 0          // 22 a 24
};
byte tled[96];

