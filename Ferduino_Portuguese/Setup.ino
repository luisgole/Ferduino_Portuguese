//------------------------setup------------------------------
void setup()
{
  Serial.begin(38400); //Inicia a comunicação com a  porta serial 0 para obter mensagens de depuração.
  Serial2.begin(38400); //Inicia a comunicação com a  porta serial 2 onde estão conectados os "stamps".
  pinMode(ledPinBlue, OUTPUT);
  pinMode(ledPinWhite, OUTPUT);
  pinMode(ledPinMoon, OUTPUT); 
  pinMode(aquecedorPin, OUTPUT);
  pinMode(chillerPin, OUTPUT);
  pinMode(alarmPin, OUTPUT);
  pinMode(fanPin, OUTPUT);
  pinMode(bomba1Pin, OUTPUT);
  pinMode(bomba2Pin, OUTPUT);
  pinMode(bomba3Pin, OUTPUT);
  pinMode(reatorPin, OUTPUT);
  pinMode(ozonizadorPin, OUTPUT);
  pinMode(solenoide1Pin, OUTPUT);
  pinMode(multiplexadorS0Pin, OUTPUT);
  pinMode(multiplexadorS1Pin, OUTPUT);
  pinMode (4, OUTPUT);  //sd card
  digitalWrite (4, HIGH);
  pinMode (dosadora1, OUTPUT);
  pinMode (dosadora2, OUTPUT);
  pinMode (dosadora3, OUTPUT);
  pinMode (dosadora4, OUTPUT);
  pinMode (dosadora5, OUTPUT);
  pinMode (dosadora6, OUTPUT);
  pinMode (temporizador1, OUTPUT);
  pinMode (temporizador2, OUTPUT);
  pinMode (temporizador3, OUTPUT);
  pinMode (temporizador4, OUTPUT);
  pinMode (temporizador5, OUTPUT);

  myGLCD.InitLCD(LANDSCAPE); // Orientação da imagem no LCD.
  myGLCD.clrScr(); // Limpa o LCD.

  myTouch.InitTouch(LANDSCAPE); // Orientação do "touch screen".
  myTouch.setPrecision(PREC_MEDIUM); // Define a precisão do "touch screen".

  sensors.begin();     //Inicia as leituras das sondas de temperatura.
  sensors.setResolution(sensor_agua, 10); // Define a resolução em 10 bits.
  sensors.setResolution(sensor_dissipador, 10); // Define a resolução em 10 bits.

/*  if(PCF8575TS_S == true)
  {
    PCF8575TS.begin(endereco_PCF8575TS); // Inicia a comunicação com o PCF8575TS
    for(int i = 0; i < 16; i++)
    {
      PCF8575TS.pinMode(i, OUTPUT);
      delay(100);
      PCF8575TS.digitalWrite(i, LOW);
    }
  }*/

  if(Ethernet_Shield == true)
  {
    if (ether.begin(sizeof Ethernet::buffer, mymac) == 0) // Inicia a comunicação com o "ethernet shield".
    {
      Serial.println( "Failed to access Ethernet controller");
    }
    ether.staticSetup(myip,gwip); // Seta o IP e o "Gateway".
  }

  rtc.halt(false); // Inicia o funcionamento do RTC.

  //Lê a variáveis guardadas na EEPROM.
  ReadFromEEPROM();
  lertpaEEPROM();
  lerPHAEEPROM();
  lerPHREEPROM();
  lerORPEEPROM();
  lerDENEEPROM();
  ler_dosadora_EEPROM();
  ler_luz_noturna_EEPROM();
  ler_timers_EEPROM();

  card.init(SPI_QUARTER_SPEED,chipselect); // Inicia a comunicação com o cartão SD.
  volume.init(&card);
  root.openRoot(&volume);

  if(Stamps == true)
  {
    iniciar_stamps();
  }

/*  if(RFM12B == true)
  {
    rf12_initialize(myNodeID,freq,network);   //Initialize RFM12 with settings defined above  
  }*/
  
  mainScreen(true); // Exibe a tela inicial no LCD.
}


