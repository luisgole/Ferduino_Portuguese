//------------------------------------ Menu 1 ----------------------------------------------------------- tela =1
void menuScreen()
{
  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printHeader(buffer); // tabela_textos[1] = "MENU 1";

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[3])));
  printButton(buffer, tanD[0], tanD[1], tanD[2], tanD[3]); // "HORA E DATA"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[201])));
  printButton(buffer, tesT[0], tesT[1], tesT[2], tesT[3]); // "CONFIG. LEDS"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[5])));
  printButton(buffer, temC[0], temC[1], temC[2], temC[3]); // "CONTROLE PARAM."

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[6])));
  printButton(buffer, graF[0], graF[1], graF[2], graF[3]); // "GRAFICOS"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[160])));
  printButton(buffer, ledW[0], ledW[1], ledW[2], ledW[3]); // tabela_textos[160] = "TIMERS"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[8])));
  printButton(buffer, tpaA[0], tpaA[1], tpaA[2], tpaA[3]); // "TPA AUTOMATICA"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[9])));
  printButton(buffer, dosA[0], dosA[1], dosA[2], dosA[3]); // "DOSADORAS"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[10])));
  printButton(buffer, wavM[0], wavM[1], wavM[2], wavM[3]); //  "WAVEMAKER"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "INICIO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[2])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 2";
}

// -------------------------Relógio------------------------------------------------------ tela =2
void setClock()   
{
  t_temp = rtc.getTime();

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[12])));
  printHeader(buffer); // tabela_textos[12] = "ALTERAR HORA E DATA"

  printButton ("+", houU[0], houU[1], houU[2], houU[3], true);   //hour up
  printButton ("-", houD[0], houD[1], houD[2], houD[3], true);   //hour down

  printButton ("+", minU[0], minU[1], minU[2], minU[3], true);   //min up
  printButton ("-", minD[0], minD[1], minD[2], minD[3], true);   //min down 

  printButton ("+", segC[0], segC[1], segC[2], segC[3], true);   //segundo mais
  printButton ("-", segB[0], segB[1], segB[2], segB[3], true);   //segundo menos

  printButton ("+", yeaU[0], yeaU[1], yeaU[2], yeaU[3], true);    //year up
  printButton ("-", yeaD[0], yeaD[1], yeaD[2], yeaD[3], true);     //year down

  printButton ("-", dayD[0], dayD[1], dayD[2], dayD[3], true);     //day down
  printButton ("+", dayU[0], dayU[1], dayU[2], dayU[3], true);    //day up

  printButton ("+", monU[0], monU[1], monU[2], monU[3], true);    //month up
  printButton ("-", monD[0], monD[1], monD[2], monD[3], true);     //month down

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[13])));
  printButton(buffer, prOK[0], prOK[1], prOK[2], prOK[3]); // "SALVAR"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "INICIO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

  setFont(SMALL, 255, 255, 255, 0, 0, 0);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[14])));
  myGLCD.print(buffer, 10, 51); // "HORA:"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[15])));
  myGLCD.print(buffer, 10, 134); // "DATA:"

  setFont(LARGE, 255, 255, 255, 0, 0, 0);
  myGLCD.print(":", 120, 48);
  myGLCD.print(":", 210, 48);

  if (t_temp.hour<10)
  {
    myGLCD.printNumI(0, 70, 48);
    myGLCD.printNumI(t_temp.hour, 86, 48);
  }
  else
  {
    myGLCD.printNumI(t_temp.hour, 70, 48);
  } 
  if (t_temp.min<10)
  {
    myGLCD.printNumI(0, 160, 48);
    myGLCD.printNumI(t_temp.min, 176, 48);
  }
  else
  {
    myGLCD.printNumI(t_temp.min, 160, 48);
  } 
  if (t_temp.sec<10)
  {
    myGLCD.printNumI(0, 250, 48);
    myGLCD.printNumI(t_temp.sec, 266, 48);
  }
  else
  {
    myGLCD.printNumI(t_temp.sec, 250, 48);
  }
  if (t_temp.date<10)
  {
    myGLCD.printNumI(0, 70, 132);
    myGLCD.printNumI(t_temp.date, 86, 132);
  }
  else
  {
    myGLCD.printNumI(t_temp.date, 70, 132);
  }
  if (t_temp.mon<10)
  {
    myGLCD.printNumI(0, 160, 132);
    myGLCD.printNumI(t_temp.mon, 176, 132);
  }
  else
  {
    myGLCD.printNumI(t_temp.mon, 160, 132);
  }
  myGLCD.printNumI(t_temp.year, 230, 132);

}

void testScreen(boolean refreshAll=false)//-------------------------------- Teste do leds ------------------------------------- tela =3
{    
  char bufferL[9];
  String led;

  if (refreshAll == true) 
  {  
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[16])));
    printHeader(buffer); // tabela_textos[16] "TESTAR VARIACAO DE LUMINOSIDADE"
    myGLCD.fillRect (1, 15, 318, 37);      //clear 'Test in progress'
    printButton ("", stsT[0], stsT[1], stsT[2], stsT[3], true);   //start/stop
    printButton ("-10s", tenM[0], tenM[1], tenM[2], tenM[3], true);     //-10s
    printButton ("+10s", tenP[0], tenP[1], tenP[2], tenP[3], true);   //+10s

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[17])));
    myGLCD.print(buffer, stsT[0]+10, stsT[1]+15); // "INICIAR"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[18])));
    myGLCD.print(buffer, stsT[0]+25, stsT[1]+40);  // "TESTE"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));    
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);  // "INICIO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
    printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
    printButton(buffer, volT[0], volT[1], volT[2], volT[3]);  // tabela_textos[66] = "VOLTAR"
  } 
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[19])));
    printHeader(buffer); // tabela_textos[19] = "TESTAR VARIACAO DE LUMINOSIDADE"
    printButton ("", stsT[0], stsT[1], stsT[2], stsT[3], true);   //start/stop
    printButton ("-10s", tenM[0], tenM[1], tenM[2], tenM[3], true);     //-10s
    printButton ("+10s", tenP[0], tenP[1], tenP[2], tenP[3], true);   //+10s

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[17])));
    myGLCD.print(buffer, stsT[0]+10, stsT[1]+15); // "INICIAR"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[18])));
    myGLCD.print(buffer, stsT[0]+25, stsT[1]+40); // "TESTE"
    min_cnt=0;

    myGLCD.setColor(0, 0, 200);
    myGLCD.fillRect(stsT[0]+5, stsT[1]+5, stsT[2]-5, stsT[3]-40);   //clear 'start'
    setFont(LARGE, 255, 255, 255, 0, 0, 200);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[20])));
    myGLCD.print(buffer, stsT[0]+25, stsT[1]+15); // "PARAR"

    myGLCD.setColor(255, 0, 0);
    myGLCD.fillRect (1, 15, 318, 37);
    myGLCD.drawRoundRect (stsT[0], stsT[1], stsT[2], stsT[3]);       //red button during test
    setFont(LARGE, 255, 255, 255, 255, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[21])));
    myGLCD.print(buffer, 15, 16); // "TESTE EM ANDAMENTO"

    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[22])));
    myGLCD.print(buffer, 33, 40); // "TEMPO:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[23])));
    myGLCD.print(buffer, 30, 40); // "POTENCIA DE SAIDA (0-255):"

    while (LEDtestTick == true)               //test LED and speed up time
    {
      if (myTouch.dataAvailable())  
      { 
        processMyTouch(); 
      }
      if (millis() - previousMillis > 500)    //change time every 0.5s
      {
        previousMillis = millis();
        min_cnt++;
        int hour = min_cnt/60;
        int minut = min_cnt%60;

        setFont(LARGE, 255, 255, 255, 0, 0, 0);

        myGLCD.print(":", 52, 55);

        if(hour >= 10)
        {
          myGLCD.printNumI(hour, 24, 55);
        }
        else
        {
          myGLCD.print("0", 24, 55);
          myGLCD.printNumI(hour, 40, 55);
        }
        if(minut >= 10)
        {
          myGLCD.printNumI(minut, 64, 55);
        }
        else
        {
          myGLCD.print("0", 64, 55);
          myGLCD.printNumI(minut, 80, 55);
        }

        myGLCD.setColor(cor_canal1[0], cor_canal1[1], cor_canal1[2]);
        strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[1])));
        led = buffer + String(":") + String(wled_out) + "  ";   // Led Branco  
        led.toCharArray(bufferL, 9);
        myGLCD.print(bufferL, 180, 55);     

        myGLCD.setColor(cor_canal2[0], cor_canal2[1], cor_canal2[2]);
        strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[2])));
        led = buffer + String(":") + String(bled_out) + "  "; // Led Azul
        led.toCharArray(bufferL, 9);
        myGLCD.print(bufferL, 180, 75);

        myGLCD.setColor(cor_canal3[0], cor_canal3[1], cor_canal3[2]);
        strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[3])));
        led = buffer + String(":") + String(rbled_out) + "  ";   // Led Royal Blue   
        led.toCharArray(bufferL, 9);
        myGLCD.print(bufferL, 180, 95);      //Blue led graph

        myGLCD.setColor(cor_canal4[0], cor_canal4[1], cor_canal4[2]);
        strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[4])));
        led = buffer + String(":") + String(rled_out) + "  "; // Led Vermelho
        led.toCharArray(bufferL, 9);
        myGLCD.print(bufferL, 180, 115);

        myGLCD.setColor(cor_canal5[0], cor_canal5[1], cor_canal5[2]);
        strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[5])));
        led = buffer + String(":") + String(uvled_out) + "  "; // Led Violeta
        led.toCharArray(bufferL, 9);
        myGLCD.print(bufferL, 180, 135);

        LED_levels_output();

      }
    }
  } 
}

//--------------------------------------------- Temperatura -------------------------------- tela =4 
void tempScreen(boolean refreshAll=false)
{

  if (refreshAll)
  {
    if (setTempC==0) {
      setTempC = tempC;  
    }                  //change to current temp.
    temp2beS = setTempC;
    temp2beO = offTempC;
    temp2beA = alarmTempC;

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[24])));
    printHeader(buffer); //tabela_textos[24] "CONTROLE DE TEMPERATURA DA AGUA"

    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[74])));
    myGLCD.print(buffer, 85, 20); // "TEMPERATURA DESEJADA:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[75])));
    myGLCD.print(buffer, 90, 70); // "VARIACAO PERMITIDA:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[76])));
    myGLCD.print(buffer, 50, 120); // "VARIACAO PARA ACIONAR O ALARME:"

    printButton("-", temM[0], temM[1], temM[2], temM[3], true);      //temp minus
    printButton("+", temP[0], temP[1], temP[2], temP[3], true);      //temp plus
    printButton("-", offM[0], offM[1], offM[2], offM[3], true);      //offset minus
    printButton("+", offP[0], offP[1], offP[2], offP[3], true);      //offset plus
    printButton("-", almM[0], almM[1], almM[2], almM[3], true);      //alarm minus
    printButton("+", almP[0], almP[1], almP[2], almP[3], true);      //alarm plus

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[13])));
    printButton(buffer, prOK[0], prOK[1], prOK[2], prOK[3]); // "SALVAR"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);  // "INICIO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
    printButton(buffer, menU[0], menU[1], menU[2], menU[3]);
  }

  setFont(LARGE, 255, 255, 255, 0, 0, 0);
  myGLCD.printNumF(temp2beS, 1, 130, 40);
  myGLCD.printNumF(temp2beO, 1, 140, 90);
  myGLCD.printNumF(temp2beA, 1, 140, 140);
}
void ledSetScreen()   //-------------------------------- Alterar valores ----------------------------------- tela =5
{
  int a;

  if (bitRead(cor_selecionada,1) == true) 
  {
    for (int i = 0; i < 97; i++)
    {
      tled[i] = wled[i];
    }
    strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[17])));
    printHeader(buffer); // "POTENCIA DOS LEDS BRANCOS: 255 = 100%"
  }
  else if (bitRead(cor_selecionada,2) == true)  
  {
    for (int i = 0; i < 97; i++)
    {
      tled[i] = bled[i];
    }
    strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[18])));
    printHeader(buffer); // "POTENCIA LEDS AZUIS: 255 = 100%"
  }
  else if (bitRead(cor_selecionada,3) == true)  
  {
    for (int i = 0; i < 97; i++)
    {
      tled[i] = rbled[i];
    }
    strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[19])));
    printHeader(buffer); // "POTENCIA LEDS AZUIS ROYAL: 255 = 100%"
  }
  else if (bitRead(cor_selecionada,4) == true)  
  {
    for (int i = 0; i < 97; i++)
    {
      tled[i] = rled[i];
    }
    strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[20])));
    printHeader(buffer); // "POTENCIA LEDS VERMELHOS: 255 = 100%"
  }
  else if (bitRead(cor_selecionada,5) == true)  
  {
    for (int i = 0; i < 97; i++)
    {
      tled[i] = uvled[i];
    }
    strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[21])));
    printHeader(buffer); // "POTENCIA LEDS VIOLETAS: 255 = 100%"
  }

  setFont(SMALL, 255, 255, 255, 0, 0, 0);
  for (int i = 0; i < 12; i++) 
  {
    myGLCD.setColor(0, 255, 255);
    myGLCD.printNumI((i*2), (i*26)+13, 22); 
    if(i == 11)
    {
      myGLCD.print("0", (i*26)+17, 36);
    }
    else
    {
      myGLCD.printNumI(((i*2)+2), (i*26)+13, 36);
    }
    for (int j=0; j<8; j++) 
    {
      a = (i*8)+j;         
      myGLCD.setColor(255, 255, 255);
      myGLCD.printNumI(tled[a], (i*26)+7, (j*18)+54);
      myGLCD.setColor(100, 100, 100);
      myGLCD.drawRect((i*26)+4, (j*18)+50, (i*26)+30, (j*18)+68);
      myGLCD.drawRect((i*26)+4, 16, (i*26)+30, 50);//
    }
  }

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[81])));
  printButton(buffer, leST[0], leST[1], leST[2], leST[3], SMALL); // "ALTERAR"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[82])));
  printButton(buffer, savE[0], savE[1], savE[2], savE[3], SMALL); // "SALVAR EEPROM"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);  // "INICIO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[210])));
  printButton(buffer, leWB[0], leWB[1], leWB[2], leWB[3], SMALL); // tabela_textos[210] = "MAIS"
}

void ledChangeScreen(boolean refreshAll=false)    //--------------------------------------- Potência dos leds------------------------------ tela =6
{
  if(refreshAll == true)
  {
    mensagem = true;
    if (bitRead(cor_selecionada,1) == true)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[12])));
      printHeader(buffer); // nome_canal[12] = "ALTERAR POTENCIAS DOS LEDS BRANCOS"
    }
    else if (bitRead(cor_selecionada,2) == true)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[13])));
      printHeader(buffer); // nome_canal[13] = "ALTERAR POTENCIA DOS LEDS AZUIS"
    }
    else if (bitRead(cor_selecionada,3) == true)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[14])));
      printHeader(buffer); // nome_canal[14] = "ALTERAR POTENCIA DOS LEDS AZUL ROYAL"
    }
    else if (bitRead(cor_selecionada,4) == true)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[15])));
      printHeader(buffer); // nome_canal[15] = "ALTERAR POTENCIA DOS LEDS VERMELHOS"
    }
    else if (bitRead(cor_selecionada,5) == true)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[16])));
      printHeader(buffer); // nome_canal[16] = "ALTERAR POTENCIA DOS LEDS VIOLETA"
    }

    setFont(SMALL, 0, 255, 255, 0,0,0);
    for (int i=0; i<12; i++) 
    {
      myGLCD.setColor(0, 255, 255);
      myGLCD.printNumI(((i*2)), (i*26)+13, 22);
      if(i == 11)
      {
        myGLCD.print("0", (i*26)+17, 33);
      }
      else
      {
        myGLCD.printNumI(((i*2)+2), (i*26)+13, 33);
      }

      myGLCD.setColor(100, 100, 100);
      myGLCD.drawRect((i*26)+4, 20 , (i*26)+30, 45);
    }

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[13])));
    printButton(buffer, salV[0], salV[1], salV[2], salV[3]); // "SALVAR"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "INICIO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
    printButton(buffer, menU[0], menU[1], menU[2], menU[3]);  // "MENU 1";

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
    printButton(buffer, volT[0], volT[1], volT[2], volT[3]);  // tabela_textos[66] = "VOLTAR"

    setFont(SMALL, 255, 0, 0, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[203])));
    myGLCD.print(buffer,50, 105);  // tabela_textos[203] = "SELECIONE UM PERIODO."

  }

  if(periodo_selecionado == true)
  {
    for (int i=0; i<8; i++)
    { 
      printButton("+", (i*38)+5, 50, (i*38)+39, 75, LARGE);
      printButton("-", (i*38)+5, 214, (i*38)+39, 239, LARGE);
    }
  }
  if((mensagem == true) && (periodo_selecionado == true))
  {
    mensagem = false;
    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRect(45, 105, 300, 121); //Apaga mensagem.
  }
}
void tpaScreen(boolean refreshAll = false) //-------------------------------------------------------- tela =7
{
  if(refreshAll)
  {
    temp2hora = hora;
    temp2minuto = minuto;
    temp2duracaomaximatpa = duracaomaximatpa;
    temp2segunda = segunda;
    temp2terca = terca;
    temp2quarta = quarta;
    temp2quinta = quinta;
    temp2sexta = sexta;
    temp2sabado = sabado;
    temp2domingo = domingo;

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[32])));
    printHeader(buffer); // tabela_textos[32] = "CONF. DIAS E HORARIO PARA TPA AUTOMATICA"

    printButton("+", houU[0], houU[1], houU[2], houU[3], true); //hour up
    printButton("-", houD[0], houD[1], houD[2], houD[3], true); //hour down
    printButton("+", minUT[0], minUT[1], minUT[2], minUT[3], true); //min up
    printButton("-", minDT[0], minDT[1], minDT[2], minDT[3], true); //min down
    printButton("+", durC[0], durC[1], durC[2], durC[3], true); //min up
    printButton("-", durB[0], durB[1], durB[2], durB[3], true); //min down

    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.print(":", 105, 48);
    myGLCD.setFont(SmallFont);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[83])));
    myGLCD.print(buffer, 10, 51); // "HORA:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[84])));
    myGLCD.print(buffer, 157, 31); // "DURACAO MAXIMA"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[85])));
    myGLCD.print(buffer, 170, 46); // "POR ESTAGIO:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[13])));
    printButton(buffer, prOK[0], prOK[1], prOK[2], prOK[3]); // "SALVAR"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);  // "INICIO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
    printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";
  }
  if (temp2segunda == 1) 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[59])));
    printButton_verde(buffer, segU[0], segU[1], segU[2], segU[3]); //botao segunda
  } 
  else 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[59])));
    printButton(buffer, segU[0], segU[1], segU[2], segU[3]); //botao segunda
  }
  if (temp2terca == 2) 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[60])));
    printButton_verde(buffer, terC[0], terC[1], terC[2], terC[3]); //botao terca
  } 
  else 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[60])));
    printButton(buffer, terC[0], terC[1], terC[2], terC[3]); //botao terca
  }
  if (temp2quarta == 3) 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[61])));
    printButton_verde(buffer, quaR[0], quaR[1], quaR[2], quaR[3]); //botao quarta
  } 
  else 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[61])));
    printButton(buffer, quaR[0], quaR[1], quaR[2], quaR[3]); //botao quarta
  }
  if (temp2quinta == 4) 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[62])));
    printButton_verde(buffer, quiN[0], quiN[1], quiN[2], quiN[3]); //botao quinta
  } 
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[62])));
    printButton(buffer, quiN[0], quiN[1], quiN[2], quiN[3]); //botao quinta
  }
  if (temp2sexta == 5)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[63])));
    printButton_verde(buffer, sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
  } 
  else 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[63])));
    printButton(buffer, sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
  }
  if (temp2sabado == 6) 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[64])));
    printButton_verde(buffer, sabA[0], sabA[1], sabA[2], sabA[3]); //botao sabado
  }
  else 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[64])));
    printButton(buffer, sabA[0], sabA[1], sabA[2], sabA[3]); //botao sabado
  }
  if (temp2domingo == 7) 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[65])));
    printButton_verde(buffer, domI[0], domI[1], domI[2], domI[3]); //botao domingo
  }
  else 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[65])));
    printButton(buffer, domI[0], domI[1], domI[2], domI[3]); //botao domingo
  }
  if (falha_tpa == true) 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[86])));
    printButton_vermelho(buffer, proX[0], proX[1], proX[2], proX[3]); //Sinaliza que houve uma falha durante a TPA. // "FALHA!!"
  } 
  else 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[87])));
    printButton(buffer, proX[0], proX[1], proX[2], proX[3]); //Sinaliza que a TPA foi realizada normalmente ou não foi realizada. // "NORMAL"
  }

  setFont(LARGE, 255, 255, 255, 0, 0, 0);
  if (temp2hora < 10) 
  {
    myGLCD.printNumI(0, 70, 48);
    myGLCD.printNumI(temp2hora, 86, 48);
  } 
  else 
  {
    myGLCD.printNumI(temp2hora, 70, 48);
  }

  if (temp2minuto < 10) 
  {
    myGLCD.printNumI(0, 120, 48);
    myGLCD.printNumI(temp2minuto, 136, 48);
  } 
  else 
  {
    myGLCD.printNumI(temp2minuto, 120, 48);
  }
  if (temp2duracaomaximatpa < 10) 
  {
    myGLCD.printNumI(0, 275, 48);
    myGLCD.printNumI(temp2duracaomaximatpa, 291, 48);
  } 
  else 
  {
    myGLCD.printNumI(temp2duracaomaximatpa, 275, 48);
  }  
}
void menu_dosadoras()//---------------------------------------------tela =8
{
  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[33])));
  printHeader(buffer); // tabela_textos[33] = "ALTERAR CONFIGURACAO DAS DOSADORAS"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[88])));
  printButton(buffer, manU[0], manU[1], manU[2], manU[3]); // "MANUAL"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[90])));
  printButton(buffer, perS[0], perS[1], perS[2], perS[3]); // "PERSONALIZADO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[91])));
  printButton(buffer, reV[0], reV[1], reV[2], reV[3]); // "REVER CONFIG."

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[134])));
  printButton(buffer, atiV[0], atiV[1], atiV[2], atiV[3]); // "DESATIVAR MODOS"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[133])));
  printButton(buffer, orP[0], orP[1], orP[2], orP[3]); // "CALIBRAR"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);  // "INICIO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";
}

void graficoScreen()//------------------------------------------------------------tela =9
{

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[34])));  
  printHeader(buffer); // tabela_textos[34] = "ESCOLHA UM GRAFICO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);  // "INICIO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[93])));
  printButton(buffer, tempG[0], tempG[1], tempG[2],tempG[3]); // "TEMPERATURA"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[94])));
  printButton(buffer, phA[0], phA[1], phA[2], phA[3]); // "PH AQUARIO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[95])));
  printButton(buffer, phR[0], phR[1], phR[2], phR[3]); // "PH REATOR"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[96])));
  printButton(buffer, orP[0], orP[1], orP[2], orP[3]); // "ORP"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[97])));
  printButton(buffer, denS[0], denS[1], denS[2], denS[3]); // "DENSIDADE"

}

void waveScreen(boolean refreshAll=false)///------------------------------------------------------------------tela =10
{
  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[35])));
  printHeader(buffer); // tabela_textos[35] = "WAVEMAKER"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);  // "INICIO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

  setFont(SMALL, 255, 255, 255, 0, 0, 0);
  myGLCD.print("FUNCAO INCOMPLETA", 80, 30);
}


void parametroScreen()//-------------------------------------------------------------------tela =14
{  
  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[36])));
  printHeader(buffer); // tabela_textos[36] = "ESCOLHA UM PARAMETRO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3],false); // "INICIO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3],false); // "MENU 1";

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[93])));
  printButton(buffer, tempG[0], tempG[1], tempG[2],tempG[3]); // "TEMPERATURA"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[94])));
  printButton(buffer, phA[0], phA[1], phA[2], phA[3]); // "PH AQUARIO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[95])));
  printButton(buffer, phR[0], phR[1], phR[2], phR[3]); // "PH REATOR"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[96])));
  printButton(buffer, orP[0], orP[1], orP[2], orP[3]); // "ORP"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[97])));
  printButton(buffer, denS[0], denS[1], denS[2], denS[3]); // "DENSIDADE"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[98])));
  printButton(buffer, caliB[0], caliB[1], caliB[2], caliB[3]); // "CALIBRAR SONDAS"

}
//---------------------------------------------PH do reator--------------------------------tela =15 ----------
void config_phR_Screen(boolean refreshAll=false)
{

  if (refreshAll)
  {
    if (setPHR==0) {
      setPHR = PHR;  
    }                  //change to current temp.
    PHR2beS = setPHR;
    PHR2beO = offPHR;
    PHR2beA = alarmPHR;

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[37])));
    printHeader(buffer); // tabela_textos[37] = "CONTROLE DE PH DO REATOR DE CALCIO"

    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[99])));
    myGLCD.print(buffer, 110, 20); // "PH DESEJADO:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[75])));
    myGLCD.print(buffer, 90, 70); // "VARIACAO PERMITIDA:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[76])));
    myGLCD.print(buffer, 50, 120); // "VARIACAO PARA ACIONAR O ALARME:"

    printButton("-", temM[0], temM[1], temM[2], temM[3], true);      //temp minus
    printButton("+", temP[0], temP[1], temP[2], temP[3], true);      //temp plus
    printButton("-", offM[0], offM[1], offM[2], offM[3], true);      //offset minus
    printButton("+", offP[0], offP[1], offP[2], offP[3], true);      //offset plus
    printButton("-", almM[0], almM[1], almM[2], almM[3], true);      //alarm minus
    printButton("+", almP[0], almP[1], almP[2], almP[3], true);      //alarm plus


    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[13])));
    printButton(buffer, prOK[0], prOK[1], prOK[2], prOK[3]); // "SALVAR"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);  // "INICIO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
    printButton(buffer, menU[0], menU[1], menU[2], menU[3]);
  }

  setFont(LARGE, 255, 255, 255, 0, 0, 0);
  myGLCD.printNumF(PHR2beS, 1, 135, 40);
  myGLCD.printNumF(PHR2beO, 1, 140, 90);
  myGLCD.printNumF(PHR2beA, 1, 140, 140);
}

//---------------------------------------------ORP--------------------------------tela =16 ----------
void config_orp_Screen(boolean refreshAll=false)
{

  if (refreshAll)
  {
    ORP2beS = setORP;
    ORP2beO = offORP;
    ORP2beA = alarmORP;


    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[38])));
    printHeader(buffer); // tabela_textos[38] = "CONTROLE DE ORP"

    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[100])));
    myGLCD.print(buffer, 115, 20); // "ORP DESEJADA:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[75])));
    myGLCD.print(buffer, 90, 70); // "VARIACAO PERMITIDA:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[76])));
    myGLCD.print(buffer, 50, 120); // "VARIACAO PARA ACIONAR O ALARME:"

    printButton("-", temM[0], temM[1], temM[2], temM[3], true);      //temp minus
    printButton("+", temP[0], temP[1], temP[2], temP[3], true);      //temp plus
    printButton("-", offM[0], offM[1], offM[2], offM[3], true);      //offset minus
    printButton("+", offP[0], offP[1], offP[2], offP[3], true);      //offset plus
    printButton("-", almM[0], almM[1], almM[2], almM[3], true);      //alarm minus
    printButton("+", almP[0], almP[1], almP[2], almP[3], true);      //alarm plus


    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[13])));
    printButton(buffer, prOK[0], prOK[1], prOK[2], prOK[3]); // "SALVAR"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);  // "INICIO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
    printButton(buffer, menU[0], menU[1], menU[2], menU[3]);
  }

  setFont(LARGE, 255, 255, 255, 0, 0, 0);
  myGLCD.printNumI(ORP2beS,145, 40);
  myGLCD.printNumI(ORP2beO,150, 90);
  myGLCD.printNumI(ORP2beA, 150, 140);
}
//---------------------------------------------PH do aquario--------------------------------tela =18 ----------

void config_phA_Screen(boolean refreshAll=false)
{

  if (refreshAll)
  {
    if (setPHA==0) {
      setPHA = PHA;  
    }                  //change to current temp.
    PHA2beS = setPHA;
    PHA2beO = offPHA;
    PHA2beA = alarmPHA;

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[39])));
    printHeader(buffer); // tabela_textos[39] = "CONTROLE DE PH DO AQUARIO"

    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[99])));
    myGLCD.print(buffer, 110, 20); // "PH DESEJADO:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[75])));
    myGLCD.print(buffer, 90, 70); // "VARIACAO PERMITIDA:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[76])));
    myGLCD.print(buffer, 50, 120); // "VARIACAO PARA ACIONAR O ALARME:"

    printButton("-", temM[0], temM[1], temM[2], temM[3], true);      //temp minus
    printButton("+", temP[0], temP[1], temP[2], temP[3], true);      //temp plus
    printButton("-", offM[0], offM[1], offM[2], offM[3], true);      //offset minus
    printButton("+", offP[0], offP[1], offP[2], offP[3], true);      //offset plus
    printButton("-", almM[0], almM[1], almM[2], almM[3], true);      //alarm minus
    printButton("+", almP[0], almP[1], almP[2], almP[3], true);      //alarm plus

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[13])));
    printButton(buffer, prOK[0], prOK[1], prOK[2], prOK[3]); // "SALVAR"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);  // "INICIO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
    printButton(buffer, menU[0], menU[1], menU[2], menU[3]);
  }

  setFont(LARGE, 255, 255, 255, 0, 0, 0); 
  myGLCD.printNumF(PHA2beS, 1, 135, 40);
  myGLCD.printNumF(PHA2beO, 1, 140, 90);
  myGLCD.printNumF(PHA2beA, 1, 140, 140);
}
//---------------------------------------------configurar densidade--------------------------------tela =20 ----------
void config_dens_Screen(boolean refreshAll=false)
{

  if (refreshAll)
  {
    DEN2beS = setDEN;
    DEN2beO = offDEN;
    DEN2beA = alarmDEN;

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[40])));
    printHeader(buffer); // tabela_textos[40] = "CONTROLE DE DENSIDADE"

    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[101])));
    myGLCD.print(buffer, 90, 20); // "DENSIDADE DESEJADA:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[75])));
    myGLCD.print(buffer, 90, 70); // "VARIACAO PERMITIDA:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[76])));
    myGLCD.print(buffer, 50, 120); // "VARIACAO PARA ACIONAR O ALARME:"

    printButton("-", temM[0], temM[1], temM[2], temM[3], true);      //temp minus
    printButton("+", temP[0], temP[1], temP[2], temP[3], true);      //temp plus
    printButton("-", offM[0], offM[1], offM[2], offM[3], true);      //offset minus
    printButton("+", offP[0], offP[1], offP[2], offP[3], true);      //offset plus
    printButton("-", almM[0], almM[1], almM[2], almM[3], true);      //alarm minus
    printButton("+", almP[0], almP[1], almP[2], almP[3], true);      //alarm plus

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[13])));
    printButton(buffer, prOK[0], prOK[1], prOK[2], prOK[3]); // "SALVAR"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);  // "INICIO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
    printButton(buffer, menU[0], menU[1], menU[2], menU[3]);
  }

  setFont(LARGE, 255, 255, 255, 0, 0, 0); 
  myGLCD.printNumI(DEN2beS, 128, 40);
  myGLCD.printNumI(DEN2beO, 150, 90);
  myGLCD.printNumI(DEN2beA, 150, 140);
}

void selecionar_dosadora()//---------------------------------------------tela =21
{

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[41])));
  printHeader(buffer); // tabela_textos[41] = "ESCOLHA UMA DOSADORA"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[102])));
  printButton(buffer, dosa1[0], dosa1[1], dosa1[2], dosa1[3]); // tabela_textos[102] = "DOSADORA 1"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[103])));
  printButton(buffer, dosa2[0], dosa2[1], dosa2[2], dosa2[3]); // tabela_textos[103] = "DOSADORA 2"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[104])));
  printButton(buffer, dosa3[0], dosa3[1], dosa3[2], dosa3[3]); // tabela_textos[104] = "DOSADORA 3"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[204])));
  printButton(buffer, dosa4[0], dosa4[1], dosa4[2], dosa4[3]); // tabela_textos[204] = "DOSADORA 4"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[205])));
  printButton(buffer, dosa5[0], dosa5[1], dosa5[2], dosa5[3]); // tabela_textos[205] = "DOSADORA 5"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[206])));
  printButton(buffer, dosa6[0], dosa6[1], dosa6[2], dosa6[3]); // tabela_textos[206] = "DOSADORA 6"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);  // "INICIO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
  printButton(buffer, volT[0], volT[1], volT[2], volT[3]);  // "VOLTAR"
}
//--------------------------- teste manual dos leds ----------------------------------------------------- tela =22
void teste_individual_leds()
{
  bled_out_temp = bled_out;

  wled_out_temp = wled_out;
  rbled_out_temp = rbled_out;
  rled_out_temp = rled_out;
  uvled_out_temp = uvled_out;

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[16])));
  printHeader(buffer); // tabela_textos[16] "TESTAR VARIACAO DE LUMINOSIDADE"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);  // "INICIO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
  printButton(buffer, volT[0], volT[1], volT[2], volT[3]);  // "VOLTAR"

  printButton("+", 49, 18, 93, 41, true);    // "+"
  printButton("+", 101, 18, 145, 41, true);  // "+"
  printButton("+", 153, 18, 197, 41, true);  // "+"
  printButton("+", 205, 18, 249, 41, true);  // "+"
  printButton("+", 257, 18, 301, 41, true);  // "+"

  printButton("-", 49, 201, 93, 224, true);    // "-"
  printButton("-", 101, 201, 145, 224, true);  // "-"
  printButton("-", 153, 201, 197, 224, true);  // "-"
  printButton("-", 205, 201, 249, 224, true);  // "-"
  printButton("-", 257, 201, 301, 224, true);  // "-"

  myGLCD.setFont(SmallFont);
  myGLCD.setBackColor(0,0,0);

  myGLCD.setColor(cor_canal1[0], cor_canal1[1],cor_canal1[2]); 
  myGLCD.drawRect(49, 44, 93, 172);   // % bar place holder 

  strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[1])));
  myGLCD.print(buffer, 61, 176);   //  Branco

  myGLCD.printNumI(wled_out_temp, 61, 186);

  myGLCD.setColor(cor_canal2[0], cor_canal2[1],cor_canal2[2]); 
  myGLCD.drawRect(101, 44, 145, 172);  // % bar place holder

  strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[2])));
  myGLCD.print(buffer, 113, 176);    // Azul

  myGLCD.printNumI(bled_out_temp, 113, 186);

  myGLCD.setColor(cor_canal3[0], cor_canal3[1],cor_canal3[2]); 
  myGLCD.drawRect(153, 44, 197, 172); //  % bar place holder 

  strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[3])));
  myGLCD.print(buffer, 165, 176);   // Azul Royal

  myGLCD.printNumI(rbled_out_temp, 165, 186);

  myGLCD.setColor(cor_canal4[0], cor_canal4[1],cor_canal4[2]); 
  myGLCD.drawRect(205, 44, 249, 172); // % bar place holder;

  strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[4])));
  myGLCD.print(buffer, 217, 176);   // Vermelho

  myGLCD.printNumI(rled_out_temp, 217, 186);

  myGLCD.setColor(cor_canal5[0], cor_canal5[1],cor_canal5[2]);  
  myGLCD.drawRect(257, 44, 301, 172); // % bar place holder

  strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[5])));
  myGLCD.print(buffer, 269, 176);   // Violeta  

  myGLCD.printNumI(uvled_out_temp, 269, 186);   

  setFont(SMALL, 255, 255, 255, 0, 0, 0); 
  myGLCD.drawRect(30, 173, 315, 173);     // Eixo x
  myGLCD.drawRect(30, 173, 30, 44);       // eixo y  

  myGLCD.setColor(190, 190, 190);
  for (int i=0; i<10; i++){               // Escala % 
    myGLCD.drawLine(31, (i*13)+44, 38, (i*13)+44); 
  } 
  for (int i=0; i<10; i++){              
    myGLCD.drawLine(31, (i*13)+51, 34, (i*13)+51); 
  } 

  myGLCD.setFont(SmallFont);
  myGLCD.print("%", 20, 25);     // %
  myGLCD.print("100", 5, 41);   // 100
  myGLCD.print("90", 12, 54);   // 90
  myGLCD.print("80", 12, 67);   // 80
  myGLCD.print("70", 12, 80);   // 70
  myGLCD.print("60", 12, 93);   // 60
  myGLCD.print("50", 12, 106);  // 50
  myGLCD.print("40", 12, 119);  // 40
  myGLCD.print("30", 12, 132);  // 30
  myGLCD.print("20", 12, 145);  // 20
  myGLCD.print("10", 12, 158);  // 10
  myGLCD.print("0", 20, 171);   // 0

  myGLCD.setColor(180, 180, 180);                  
  for (int i=0; i<10; i++){                      // escalas de linhas pontilhadas horizontais 
    for(int k=46; k<311; k++){ 
      myGLCD.drawPixel(k,(i*13)+44); 
      k=k+2;
    } 
  } 

  //void desenhar_barras(int sbR, int sbG, int sbB, int sbX1, int sbY1, int sbX2, int sbY2)

  y_tocado = map(wled_out_temp, 255, 0, 44, 172);
  desenhar_barras(cor_canal1[0], cor_canal1[1],cor_canal1[2], 49, 44, 93, 172);

  y_tocado = map(bled_out_temp, 255, 0, 44, 172);
  desenhar_barras(cor_canal2[0], cor_canal2[1],cor_canal2[2], 101, 44, 145, 172);

  y_tocado = map(rbled_out_temp, 255, 0, 44, 172);
  desenhar_barras(cor_canal3[0], cor_canal3[1],cor_canal3[2], 153, 44, 197, 172);

  y_tocado = map(rled_out_temp, 255, 0, 44, 172);
  desenhar_barras(cor_canal4[0], cor_canal4[1],cor_canal4[2], 205, 44, 249, 172);

  y_tocado = map(uvled_out_temp, 255, 0, 44, 172);
  desenhar_barras(cor_canal5[0], cor_canal5[1],cor_canal5[2], 257, 44, 301, 172);                                                             
}
void rever_dosagem_personalizada_2() // ------------------------------------------------------------------ tela =23
{
  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[50])));
  printHeader(buffer); // tabela_textos[50] = "REVER CONF. DA DOSAGEM PERSONALIZADA"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);  // "INICIO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
  printButton(buffer, volT[0], volT[1], volT[2], volT[3]); // "VOLTAR"

  myGLCD.setColor(161, 127, 73);                    
  myGLCD.drawLine(1, 88, 319, 88);  
  myGLCD.drawLine(1, 158, 319, 158);
  myGLCD.drawLine(319, 15, 319, 239);

  setFont(SMALL, 255, 255, 255, 0, 0, 0);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[211])));
  myGLCD.print(buffer, 10, 30); // tabela_textos[129]  

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[118])));
  myGLCD.print(buffer, 10, 50);  

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[119])));
  myGLCD.print(buffer, 118, 50);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[128])));
  myGLCD.print(buffer, 10, 70);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[121])));
  myGLCD.print(buffer, 215, 50);    //Posição correta

  myGLCD.print(":", 90, 50);
  myGLCD.print(":", 180, 50);

  myGLCD.printNumF(dose_dosadora_4_personalizada, 1, 275, 50); //Posição correta
  myGLCD.printNumI(quantidade_dose_dosadora_4_personalizada, 170, 70);

  if(hora_inicial_dosagem_personalizada_4 < 10)
  {
    myGLCD.printNumI(0, 72, 50);
    myGLCD.printNumI(hora_inicial_dosagem_personalizada_4, 80, 50);
  }
  else
  {
    myGLCD.printNumI(hora_inicial_dosagem_personalizada_4, 72, 50);
  }
  if(minuto_inicial_dosagem_personalizada_4 < 10)
  {
    myGLCD.printNumI(0, 98, 50);
    myGLCD.printNumI(minuto_inicial_dosagem_personalizada_4, 106, 50);
  }
  else
  {
    myGLCD.printNumI(minuto_inicial_dosagem_personalizada_4, 98, 50);
  }
  if(hora_final_dosagem_personalizada_4 < 10)
  {
    myGLCD.printNumI(0, 165, 50);
    myGLCD.printNumI(hora_final_dosagem_personalizada_4, 173, 50); 
  }
  else
  {
    myGLCD.printNumI(hora_final_dosagem_personalizada_4, 165, 50);
  }
  if(minuto_final_dosagem_personalizada_4 < 10)
  {
    myGLCD.printNumI(0, 188, 50);
    myGLCD.printNumI(minuto_final_dosagem_personalizada_4, 196, 50);
  }
  else
  {
    myGLCD.printNumI(minuto_final_dosagem_personalizada_4, 188, 50);
  }
  if(segunda_dosagem_personalizada_4 == 1)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[70])));
    printButton_verde(buffer, 110, 23, 130, 43);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[70])));
    printButton(buffer, 110, 23, 130, 43);
  }
  if(terca_dosagem_personalizada_4 == 2)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[71])));
    printButton_verde(buffer, 140, 23, 160, 43);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[71])));
    printButton(buffer, 140, 23, 160, 43);
  }
  if(quarta_dosagem_personalizada_4 == 3)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[72])));
    printButton_verde(buffer, 170, 23, 190, 43);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[72])));
    printButton(buffer, 170, 23, 190, 43);
  }    
  if(quinta_dosagem_personalizada_4 == 4)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[198])));
    printButton_verde(buffer, 200, 23, 220, 43);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[198])));
    printButton(buffer, 200, 23, 220, 43);
  }    
  if(sexta_dosagem_personalizada_4 == 5)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[199])));
    printButton_verde(buffer, 230, 23, 250, 43);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[199])));
    printButton(buffer, 230, 23, 250, 43);
  }
  if(sabado_dosagem_personalizada_4 == 6)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[200])));
    printButton_verde(buffer, 260, 23, 280, 43);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[200])));
    printButton(buffer, 260, 23, 280, 43);
  }
  if(domingo_dosagem_personalizada_4 == 7)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[73])));
    printButton_verde(buffer, 290, 23, 310, 43);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[73])));
    printButton(buffer, 290, 23, 310, 43);
  } 
  if (modo_personalizado_on_4 == 1) 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
    printButton_verde(buffer, 200, 65, 245, 85); 
  } 
  else 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
    printButton(buffer, 200, 65, 245, 85); 
  }
  if (modo_personalizado_on_4 == 0) 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));
    printButton_verde(buffer, 250, 65, 295, 85); 
  } 
  else 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));
    printButton(buffer, 250, 65, 295, 85); 
  }
  setFont(SMALL, 255, 255, 255, 0, 0, 0);    

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[212])));
  myGLCD.print(buffer, 10, 100);   

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[118])));
  myGLCD.print(buffer, 10, 120);  

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[119])));
  myGLCD.print(buffer, 118, 120);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[128])));
  myGLCD.print(buffer, 10, 140);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[121])));
  myGLCD.print(buffer, 215, 120);    

  myGLCD.print(":", 90, 120);
  myGLCD.print(":", 180, 120);

  myGLCD.printNumF(dose_dosadora_5_personalizada, 1, 275, 120); 
  myGLCD.printNumI(quantidade_dose_dosadora_5_personalizada, 170, 140);

  if(hora_inicial_dosagem_personalizada_5 < 10)
  {
    myGLCD.printNumI(0, 72, 120);
    myGLCD.printNumI(hora_inicial_dosagem_personalizada_5, 80, 120);
  }
  else
  {
    myGLCD.printNumI(hora_inicial_dosagem_personalizada_5, 72, 120);
  }
  if(minuto_inicial_dosagem_personalizada_5 < 10)
  {
    myGLCD.printNumI(0, 98, 120);
    myGLCD.printNumI(minuto_inicial_dosagem_personalizada_5, 106, 120);
  }
  else
  {
    myGLCD.printNumI(minuto_inicial_dosagem_personalizada_5, 98, 120);
  }
  if(hora_final_dosagem_personalizada_5 < 10)
  {
    myGLCD.printNumI(0, 165, 120);
    myGLCD.printNumI(hora_final_dosagem_personalizada_5, 173, 120); 
  }
  else
  {
    myGLCD.printNumI(hora_final_dosagem_personalizada_5, 165, 120);
  }
  if(minuto_final_dosagem_personalizada_5 < 10)
  {
    myGLCD.printNumI(0, 188, 120);
    myGLCD.printNumI(minuto_final_dosagem_personalizada_5, 196, 120);
  }
  else
  {
    myGLCD.printNumI(minuto_final_dosagem_personalizada_5, 188, 120);
  }
  if(segunda_dosagem_personalizada_5 == 1)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[70])));
    printButton_verde(buffer, 110, 93, 130, 113);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[70])));
    printButton(buffer, 110, 93, 130, 113);
  }
  if(terca_dosagem_personalizada_5 == 2)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[71])));
    printButton_verde(buffer, 140, 93, 160, 113);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[71])));
    printButton(buffer, 140, 93, 160, 113);
  }
  if(quarta_dosagem_personalizada_5 == 3)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[72])));
    printButton_verde(buffer, 170, 93, 190, 113);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[72])));
    printButton(buffer, 170, 93, 190, 113);
  }    
  if(quinta_dosagem_personalizada_5 == 4)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[198])));
    printButton_verde(buffer, 200, 93, 220, 113);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[198])));
    printButton(buffer, 200, 93, 220, 113);
  }    
  if(sexta_dosagem_personalizada_5 == 5)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[199])));
    printButton_verde(buffer, 230, 93, 250, 113);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[199])));
    printButton(buffer, 230, 93, 250, 113);
  }
  if(sabado_dosagem_personalizada_5 == 6)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[200])));
    printButton_verde(buffer, 260, 93, 280, 113);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[200])));
    printButton(buffer, 260, 93, 280, 113);
  }
  if(domingo_dosagem_personalizada_5 == 7)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[73])));
    printButton_verde(buffer, 290, 93, 310, 113);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[73])));
    printButton(buffer, 290, 93, 310, 113);
  } 
  if (modo_personalizado_on_5 == 1) 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
    printButton_verde(buffer, 200, 135, 245, 155); 
  } 
  else 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
    printButton(buffer, 200, 135, 245, 155); 
  }
  if (modo_personalizado_on_5 == 0) 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));
    printButton_verde(buffer, 250, 135, 295, 155); 
  } 
  else 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));
    printButton(buffer, 250, 135, 295, 155); 
  } 
  setFont(SMALL, 255, 255, 255, 0, 0, 0);    

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[213])));
  myGLCD.print(buffer, 10, 170);   

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[118])));
  myGLCD.print(buffer, 10, 190);  

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[119])));
  myGLCD.print(buffer, 118, 190);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[128])));
  myGLCD.print(buffer, 10, 210); // tabela_textos[128] = "QUANTIDADE DE DOSES:"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[121])));
  myGLCD.print(buffer, 215, 190);    

  myGLCD.print(":", 90, 190);
  myGLCD.print(":", 180, 190);

  myGLCD.printNumF(dose_dosadora_6_personalizada, 1, 275, 190); 
  myGLCD.printNumI(quantidade_dose_dosadora_6_personalizada, 170, 210);

  if(hora_inicial_dosagem_personalizada_6 < 10)
  {
    myGLCD.printNumI(0, 72, 190);
    myGLCD.printNumI(hora_inicial_dosagem_personalizada_6, 80, 190);
  }
  else
  {
    myGLCD.printNumI(hora_inicial_dosagem_personalizada_6, 72, 190);
  }
  if(minuto_inicial_dosagem_personalizada_6 < 10)
  {
    myGLCD.printNumI(0, 98, 190);
    myGLCD.printNumI(minuto_inicial_dosagem_personalizada_6, 106, 190);
  }
  else
  {
    myGLCD.printNumI(minuto_inicial_dosagem_personalizada_6, 98, 190);
  }
  if(hora_final_dosagem_personalizada_6 < 10)
  {
    myGLCD.printNumI(0, 165, 190);
    myGLCD.printNumI(hora_final_dosagem_personalizada_6, 173, 190); 
  }
  else
  {
    myGLCD.printNumI(hora_final_dosagem_personalizada_6, 165, 190);
  }
  if(minuto_final_dosagem_personalizada_6 < 10)
  {
    myGLCD.printNumI(0, 188, 190);
    myGLCD.printNumI(minuto_final_dosagem_personalizada_6, 196, 190);
  }
  else
  {
    myGLCD.printNumI(minuto_final_dosagem_personalizada_6, 188, 190);
  }
  if(segunda_dosagem_personalizada_6 == 1)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[70])));
    printButton_verde(buffer, 110, 163, 130, 183);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[70])));
    printButton(buffer, 110, 163, 130, 183);
  }
  if(terca_dosagem_personalizada_6 == 2)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[71])));
    printButton_verde(buffer, 140, 163, 160, 183);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[71])));
    printButton(buffer, 140, 163, 160, 183);
  }
  if(quarta_dosagem_personalizada_6 == 3)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[72])));
    printButton_verde(buffer, 170, 163, 190, 183);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[72])));
    printButton(buffer, 170, 163, 190, 183);
  }    
  if(quinta_dosagem_personalizada_6 == 4)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[198])));
    printButton_verde(buffer, 200, 163, 220, 183);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[198])));
    printButton(buffer, 200, 163, 220, 183);
  }    
  if(sexta_dosagem_personalizada_6 == 5)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[199])));
    printButton_verde(buffer, 230, 163, 250, 183);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[199])));
    printButton(buffer, 230, 163, 250, 183);
  }
  if(sabado_dosagem_personalizada_6 == 6)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[200])));
    printButton_verde(buffer, 260, 163, 280, 183);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[200])));
    printButton(buffer, 260, 163, 280, 183);
  }
  if(domingo_dosagem_personalizada_6 == 7)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[73])));
    printButton_verde(buffer, 290, 163, 310, 183);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[73])));
    printButton(buffer, 290, 163, 310, 183);
  } 
  if (modo_personalizado_on_6 == 1) 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
    printButton_verde(buffer, 200, 205, 245, 225); 
  } 
  else 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
    printButton(buffer, 200, 205, 245, 225); 
  }
  if (modo_personalizado_on_6 == 0) 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));
    printButton_verde(buffer, 250, 205, 295, 225); 
  } 
  else 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));
    printButton(buffer, 250, 205, 295, 225); 
  }     
}
//---------------------------------------------Desativar dosadoras--------------------------------tela =24
void desativar_dosadoras_2(boolean refreshAll = false)
{
  if(refreshAll == true)
  {
    if((modo_personalizado_on_4 == 1))
    {
      ativar_desativar_4 = 1;
    }
    else
    {
      ativar_desativar_4 = 0;
    }
    if((modo_personalizado_on_5 == 1))
    {
      ativar_desativar_5 = 1;
    }
    else
    {
      ativar_desativar_5 = 0;
    }
    if((modo_personalizado_on_6 == 1))
    {
      ativar_desativar_6 = 1;
    }
    else
    {
      ativar_desativar_6 = 0;
    }
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[51])));
    printHeader(buffer); // tabela_textos[51] =  "DESATIVAR DOSADORAS"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);  // "INICIO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
    printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[13])));
    printButton(buffer, salV[0], salV[1], salV[2], salV[3]); // "SALVAR"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
    printButton(buffer, volT[0], volT[1], volT[2], volT[3]);

    setFont(SMALL, 255, 255, 255, 0, 0, 0); 

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[211])));
    myGLCD.print(buffer, 117, 30);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[212])));
    myGLCD.print(buffer, 120, 100);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[213])));
    myGLCD.print(buffer, 120, 170); 

    setFont(SMALL, 255, 0, 0, 0, 0, 0); 

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[141])));
    myGLCD.print(buffer, 230, 60); //tabela_textos[141] = "USE ESTA"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[142])));
    myGLCD.print(buffer, 230, 75); //tabela_textos[141] = "FUNCAO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[143])));
    myGLCD.print(buffer, 230, 90); // tabela_textos[143] = "APENAS PARA"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[144])));
    myGLCD.print(buffer, 230, 105); //tabela_textos[144] = "DESATIVAR"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[145])));
    myGLCD.print(buffer, 230, 120);  // tabela_textos[145] = "OS MODOS"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[146])));
    myGLCD.print(buffer, 230, 135); // tabela_textos[146] = "DE DOSAGEM."
  }
  if (ativar_desativar_4 == 1)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[147])));
    printButton_verde(buffer, 100, 45, 220, 85); // tabela_textos[147]

    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRect (3, 26, 117, 43);
    myGLCD.fillRect (3, 45, 95, 61);
    myGLCD.fillRect (3, 60, 95, 76);
    myGLCD.fillRect (3, 75, 95, 91);

    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[149])));
    myGLCD.print(buffer, 10, 30); // tabela_textos[149] = "UM DOS MODOS"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[150])));
    myGLCD.print(buffer, 10, 45); // tabela_textos[150] = "DE DOSAGEM  "

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[151])));
    myGLCD.print(buffer, 10, 60);  // tabela_textos[151] = "ESTA:"
  } 
  else 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[152])));
    printButton(buffer, 100, 45, 220, 85);

    setFont(SMALL, 255, 255, 0, 0, 0, 0); 

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[153])));
    myGLCD.print(buffer, 3, 30); 

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[150])));
    myGLCD.print(buffer, 3, 45);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[154])));
    myGLCD.print(buffer, 3, 60);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[155])));
    myGLCD.print(buffer, 3, 75); 
  }
  if (ativar_desativar_5 == 1)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[147])));
    printButton_verde(buffer, 100, 115, 220, 155);

    myGLCD.setColor(0, 0, 0); 
    myGLCD.fillRect (3, 96, 117, 113);
    myGLCD.fillRect (3, 115, 95, 131);
    myGLCD.fillRect (3, 130, 95, 146);
    myGLCD.fillRect (3, 145, 95, 161); 

    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[149])));
    myGLCD.print(buffer, 10, 100); // tabela_textos[149] = "UM DOS MODOS"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[150])));
    myGLCD.print(buffer, 10, 115); // tabela_textos[150] = "DE DOSAGEM  "

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[151])));
    myGLCD.print(buffer, 10, 130); // tabela_textos[151] = "ESTA:"
  } 
  else 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[152])));
    printButton(buffer, 100, 115, 220, 155);  // tabela_textos[152]

    setFont(SMALL, 255, 255, 0, 0, 0, 0); 

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[153])));
    myGLCD.print(buffer, 3, 100); // tabela_textos[153] = "AMBOS OS MODOS"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[150])));
    myGLCD.print(buffer, 3, 115); //tabela_textos[150] =  "DE DOSAGEM  "

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[154])));
    myGLCD.print(buffer, 3, 130); // tabela_textos[154] = "ESTAO OU"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[155])));
    myGLCD.print(buffer, 3, 145); // tabela_textos[155] = "SERAO:"
  }
  if (ativar_desativar_6 == 1)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[147])));
    printButton_verde(buffer, 100, 185, 220, 225); 

    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRect (3, 166, 120, 183);
    myGLCD.fillRect (3, 185, 95, 201);
    myGLCD.fillRect (3, 200, 95, 216);
    myGLCD.fillRect (3, 215, 95, 231);

    setFont(SMALL, 255, 255, 255, 0, 0, 0); 

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[149])));
    myGLCD.print(buffer, 10, 170);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[150])));
    myGLCD.print(buffer, 10, 185);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[151])));
    myGLCD.print(buffer, 10, 200); 
  } 
  else 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[152])));
    printButton(buffer, 100, 185, 220, 225);

    setFont(SMALL, 255, 255, 0, 0, 0, 0); 

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[153])));
    myGLCD.print(buffer, 3, 170); 

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[150])));
    myGLCD.print(buffer, 3, 185);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[154])));
    myGLCD.print(buffer, 3, 200);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[155])));
    myGLCD.print(buffer, 3, 215);
  }
}
//---------------------------------------- Opções de teste dos leds ---------------------- tela =25
void escolher_teste()
{
  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[49])));
  printHeader(buffer); //tabela_textos[49] = "ESCOLHA UM TIPO DE TESTE"; 

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);  // "INICIO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";  

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[67])));
  printButton(buffer, testI[0], testI[1], testI[2], testI[3]); // "TESTE INDIVIDUAL"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[68])));
  printButton(buffer, testT[0], testT[1], testT[2], testT[3]); // "TESTAR TODOS"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[69])));
  printButton(buffer, preD[0], preD[1], preD[2], preD[3]); // "PRE DEFINIDO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
  printButton(buffer, volT[0], volT[1], volT[2], volT[3]);// "VOLTAR
}
//---------------------------------------- Calibrar dosadoras ---------------------- tela =26 
void calibrar_dosadoras(boolean refreshAll=false)
{
  if(refreshAll)
  {
    fator_calib_dosadora_1_temp2 = fator_calib_dosadora_1;
    fator_calib_dosadora_2_temp2 = fator_calib_dosadora_2;
    fator_calib_dosadora_3_temp2 = fator_calib_dosadora_3;
    fator_calib_dosadora_4_temp2 = fator_calib_dosadora_4;
    fator_calib_dosadora_5_temp2 = fator_calib_dosadora_5;
    fator_calib_dosadora_6_temp2 = fator_calib_dosadora_6;

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[42])));
    printHeader(buffer); // tabela_textos[42] = "CALIBRAR DOSADORA"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[13])));
    printButton(buffer, salV[0], salV[1], salV[2], salV[3]); // "SALVAR"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);  // "INICIO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
    printButton(buffer, volT[0], volT[1], volT[2], volT[3]);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[17])));
    printButton(buffer, iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]); // "INICIAR"

    printButton("-", almM[0], almM[1], almM[2], almM[3], true);      //alarm minus
    printButton("+", almP[0], almP[1], almP[2], almP[3], true);      //alarm plus  

    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRect(20, 50, 310, 125);
    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[105])));
    myGLCD.print(buffer, 30, 55); // "COLOQUE O RECIPIENTE SOB O BICO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[106])));
    myGLCD.print(buffer, 30, 70);  // "DOSADOR E CLIQUE EM INICIAR."

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[107])));
    myGLCD.print(buffer, 30, 85); // "EM SEGUIDA INSIRA O VALOR OBTIDO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[108])));
    myGLCD.print(buffer, 30, 100); // "EM ML NO CAMPO ABAIXO."

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[109])));
    myGLCD.print(buffer, 5, 165); // "PARA MELHORES RESULTADOS REPITA O TESTE"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[110])));
    myGLCD.print(buffer, 35, 177); // "ALGUMAS VEZES E USE UMA MEDIA."
  }
  myGLCD.setColor(0, 0, 0);
  myGLCD.fillRect(117, 135, 203, 160);

  if((modo_calibrar == true) && (bitRead(dosadora_selecionada,1) == true))
  {
    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.printNumF(fator_calib_dosadora_1_temp2,1, 130, 140);
    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[111])));
    myGLCD.print(buffer, 80, 30); // tabela_textos[111] = "DOSADORA 1 SELECIONADA"
  }

  if((modo_calibrar == true) && (bitRead(dosadora_selecionada,2) == true))
  {
    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.printNumF(fator_calib_dosadora_2_temp2,1, 130, 140);  
    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[112])));
    myGLCD.print(buffer, 80, 30); // tabela_textos[112] = "DOSADORA 2 SELECIONADA"
  }

  if((modo_calibrar == true) && (bitRead(dosadora_selecionada,3) == true))
  {
    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.printNumF(fator_calib_dosadora_3_temp2,1, 130, 140);
    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[113])));
    myGLCD.print(buffer, 80, 30); // tabela_textos[113] = "DOSADORA 3 SELECIONADA"
  } 
  if((modo_calibrar == true) && (bitRead(dosadora_selecionada,4) == true))
  {
    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.printNumF(fator_calib_dosadora_4_temp2,1, 130, 140);
    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[207])));
    myGLCD.print(buffer, 80, 30); // tabela_textos[207] = "DOSADORA 4 SELECIONADA"
  }

  if((modo_calibrar == true) && (bitRead(dosadora_selecionada,5) == true))
  {
    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.printNumF(fator_calib_dosadora_5_temp2,1, 130, 140);  
    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[208])));
    myGLCD.print(buffer, 80, 30); // tabela_textos[208] = "DOSADORA 5 SELECIONADA"
  }

  if((modo_calibrar == true) && (bitRead(dosadora_selecionada,6) == true))
  {
    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.printNumF(fator_calib_dosadora_6_temp2,1, 130, 140);
    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[209])));
    myGLCD.print(buffer, 80, 30); // tabela_textos[209] = "DOSADORA 6 SELECIONADA"
  } 
}

void config_dosagem_manual(boolean refreshAll=false) // ----------tela =27
{
  if(refreshAll)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[43])));
    printHeader(buffer); // tabela_textos[43] = "DOSAGEM MANUAL"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);  // "INICIO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
    printButton(buffer, volT[0], volT[1], volT[2], volT[3]);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[17])));
    printButton(buffer, iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]); // "INICIAR"

    printButton("-", almM[0], almM[1], almM[2], almM[3], true);      //alarm minus
    printButton("+", almP[0], almP[1], almP[2], almP[3], true);      //alarm plus  

    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRect(20, 50, 310, 125);

    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[114])));
    myGLCD.print(buffer, 30, 55); // "SELECIONE O VOLUME A SER DOSADO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[115])));
    myGLCD.print(buffer, 30, 70); // "EM ML NO CAMPO ABAIXO  E"  

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[116])));
    myGLCD.print(buffer, 30, 85); // "EM SEGUIDA TOQUE EM INICIAR."

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[117])));
    myGLCD.print(buffer, 30, 100); // "A DOSAGEM INICIARA EM 10 SEGUNDOS"
  }
  myGLCD.setColor(0, 0, 0);
  myGLCD.fillRect(117, 135, 203, 160);

  if((modo_manual == true) && (bitRead(dosadora_selecionada,1) == true))
  {
    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.printNumF(dose_dosadora_1_manual,1, 130, 140);
    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[111])));
    myGLCD.print(buffer, 80, 30);
  }

  if((modo_manual == true) && (bitRead(dosadora_selecionada,2) == true))
  {
    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.printNumF(dose_dosadora_2_manual,1, 130, 140);  
    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[112])));
    myGLCD.print(buffer, 80, 30);
  }

  if((modo_manual == true) && (bitRead(dosadora_selecionada,3) == true))
  {
    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.printNumF(dose_dosadora_3_manual,1, 130, 140);
    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[113])));
    myGLCD.print(buffer, 80, 30);
  } 
  if((modo_manual == true) && (bitRead(dosadora_selecionada,4) == true))
  {
    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.printNumF(dose_dosadora_4_manual,1, 130, 140);
    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[207]))); // "DOSADORA 4 SELECIONADA"
    myGLCD.print(buffer, 80, 30); 
  }

  if((modo_manual == true) && (bitRead(dosadora_selecionada,5) == true))
  {
    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.printNumF(dose_dosadora_5_manual,1, 130, 140);  
    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[208]))); // "DOSADORA 5 SELECIONADA"
    myGLCD.print(buffer, 80, 30);
  }

  if((modo_manual == true) && (bitRead(dosadora_selecionada,6) == true))
  {
    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.printNumF(dose_dosadora_6_manual,1, 130, 140);
    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[209]))); // "DOSADORA 6 SELECIONADA"
    myGLCD.print(buffer, 80, 30);
  } 
}
void escolher_canal() //---------------------------------------------------------- tela =28
{
  strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[11])));
  printHeader(buffer); // nome_canal[11] = "ESCOLHA UMA COR"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3],false); // "INICIO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3],false); // "MENU 1";

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
  printButton(buffer, volT[0], volT[1], volT[2], volT[3]);// "VOLTAR"
    
  strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[6])));
  printButton(buffer, tempG[0], tempG[1], tempG[2],tempG[3]); // "BRANCO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[7])));
  printButton(buffer, phA[0], phA[1], phA[2], phA[3]); // "AZUL"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[8])));
  printButton(buffer, phR[0], phR[1], phR[2], phR[3]); // "AZUL ROYAL"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[9])));
  printButton(buffer, orP[0], orP[1], orP[2], orP[3]); // "VERMELHO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[10])));
  printButton(buffer, denS[0], denS[1], denS[2], denS[3]); // "VIOLETA"
}  

void config_dosagem_personalizada(boolean refreshAll=false) // -------------------tela =29
{
  if(refreshAll)
  {   
    temp2hora_inicial_dosagem_personalizada_1 = hora_inicial_dosagem_personalizada_1;
    temp2minuto_inicial_dosagem_personalizada_1 = minuto_inicial_dosagem_personalizada_1;
    temp2hora_final_dosagem_personalizada_1 = hora_final_dosagem_personalizada_1;
    temp2minuto_final_dosagem_personalizada_1 = minuto_final_dosagem_personalizada_1;
    temp2segunda_dosagem_personalizada_1 = segunda_dosagem_personalizada_1;
    temp2terca_dosagem_personalizada_1 = terca_dosagem_personalizada_1;
    temp2quarta_dosagem_personalizada_1 = quarta_dosagem_personalizada_1;
    temp2quinta_dosagem_personalizada_1 = quinta_dosagem_personalizada_1;
    temp2sexta_dosagem_personalizada_1 = sexta_dosagem_personalizada_1;
    temp2sabado_dosagem_personalizada_1 = sabado_dosagem_personalizada_1;
    temp2domingo_dosagem_personalizada_1 = domingo_dosagem_personalizada_1;
    temp2hora_inicial_dosagem_personalizada_2 = hora_inicial_dosagem_personalizada_2;
    temp2minuto_inicial_dosagem_personalizada_2 = minuto_inicial_dosagem_personalizada_2;
    temp2hora_final_dosagem_personalizada_2 = hora_final_dosagem_personalizada_2;
    temp2minuto_final_dosagem_personalizada_2 = minuto_final_dosagem_personalizada_2;
    temp2segunda_dosagem_personalizada_2 = segunda_dosagem_personalizada_2;
    temp2terca_dosagem_personalizada_2 = terca_dosagem_personalizada_2;
    temp2quarta_dosagem_personalizada_2 = quarta_dosagem_personalizada_2;
    temp2quinta_dosagem_personalizada_2 = quinta_dosagem_personalizada_2;
    temp2sexta_dosagem_personalizada_2 = sexta_dosagem_personalizada_2;
    temp2sabado_dosagem_personalizada_2 = sabado_dosagem_personalizada_2;
    temp2domingo_dosagem_personalizada_2 = domingo_dosagem_personalizada_2;
    temp2hora_inicial_dosagem_personalizada_3 = hora_inicial_dosagem_personalizada_3;
    temp2minuto_inicial_dosagem_personalizada_3 = minuto_inicial_dosagem_personalizada_3;
    temp2hora_final_dosagem_personalizada_3 = hora_final_dosagem_personalizada_3;
    temp2minuto_final_dosagem_personalizada_3 = minuto_final_dosagem_personalizada_3;
    temp2segunda_dosagem_personalizada_3 = segunda_dosagem_personalizada_3;
    temp2terca_dosagem_personalizada_3 = terca_dosagem_personalizada_3;
    temp2quarta_dosagem_personalizada_3 = quarta_dosagem_personalizada_3;
    temp2quinta_dosagem_personalizada_3 = quinta_dosagem_personalizada_3;
    temp2sexta_dosagem_personalizada_3 = sexta_dosagem_personalizada_3;
    temp2sabado_dosagem_personalizada_3 = sabado_dosagem_personalizada_3;
    temp2domingo_dosagem_personalizada_3 = domingo_dosagem_personalizada_3;
    temp2hora_inicial_dosagem_personalizada_4 = hora_inicial_dosagem_personalizada_4;
    temp2minuto_inicial_dosagem_personalizada_4 = minuto_inicial_dosagem_personalizada_4;
    temp2hora_final_dosagem_personalizada_4 = hora_final_dosagem_personalizada_4;
    temp2minuto_final_dosagem_personalizada_4 = minuto_final_dosagem_personalizada_4;
    temp2segunda_dosagem_personalizada_4 = segunda_dosagem_personalizada_4;
    temp2terca_dosagem_personalizada_4 = terca_dosagem_personalizada_4;
    temp2quarta_dosagem_personalizada_4 = quarta_dosagem_personalizada_4;
    temp2quinta_dosagem_personalizada_4 = quinta_dosagem_personalizada_4;
    temp2sexta_dosagem_personalizada_4 = sexta_dosagem_personalizada_4;
    temp2sabado_dosagem_personalizada_4 = sabado_dosagem_personalizada_4;
    temp2domingo_dosagem_personalizada_4 = domingo_dosagem_personalizada_4;
    temp2hora_inicial_dosagem_personalizada_5 = hora_inicial_dosagem_personalizada_5;
    temp2minuto_inicial_dosagem_personalizada_5 = minuto_inicial_dosagem_personalizada_5;
    temp2hora_final_dosagem_personalizada_5 = hora_final_dosagem_personalizada_5;
    temp2minuto_final_dosagem_personalizada_5 = minuto_final_dosagem_personalizada_5;
    temp2segunda_dosagem_personalizada_5 = segunda_dosagem_personalizada_5;
    temp2terca_dosagem_personalizada_5 = terca_dosagem_personalizada_5;
    temp2quarta_dosagem_personalizada_5 = quarta_dosagem_personalizada_5;
    temp2quinta_dosagem_personalizada_5 = quinta_dosagem_personalizada_5;
    temp2sexta_dosagem_personalizada_5 = sexta_dosagem_personalizada_5;
    temp2sabado_dosagem_personalizada_5 = sabado_dosagem_personalizada_5;
    temp2domingo_dosagem_personalizada_5 = domingo_dosagem_personalizada_5;
    temp2hora_inicial_dosagem_personalizada_6 = hora_inicial_dosagem_personalizada_6;
    temp2minuto_inicial_dosagem_personalizada_6 = minuto_inicial_dosagem_personalizada_6;
    temp2hora_final_dosagem_personalizada_6 = hora_final_dosagem_personalizada_6;
    temp2minuto_final_dosagem_personalizada_6 = minuto_final_dosagem_personalizada_6;
    temp2segunda_dosagem_personalizada_6 = segunda_dosagem_personalizada_6;
    temp2terca_dosagem_personalizada_6 = terca_dosagem_personalizada_6;
    temp2quarta_dosagem_personalizada_6 = quarta_dosagem_personalizada_6;
    temp2quinta_dosagem_personalizada_6 = quinta_dosagem_personalizada_6;
    temp2sexta_dosagem_personalizada_6 = sexta_dosagem_personalizada_6;
    temp2sabado_dosagem_personalizada_6 = sabado_dosagem_personalizada_6;
    temp2domingo_dosagem_personalizada_6 = domingo_dosagem_personalizada_6;

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[45])));
    printHeader(buffer); // tabela_textos[45] = "CONFIGURAR DOSAGEM PERSONALIZADA"

    printButton("+", houU[0], houU[1], houU[2], houU[3], true); //hour up
    printButton("-", houD[0], houD[1], houD[2], houD[3], true); //hour down
    printButton("+", minUT[0], minUT[1], minUT[2], minUT[3], true); //min up
    printButton("-", minDT[0], minDT[1], minDT[2], minDT[3], true); //min down
    printButton("+", houU[0]+155, houU[1], houU[2]+155, houU[3], true); //hora mais
    printButton("-", houD[0]+155, houD[1], houD[2]+155, houD[3], true); //hora menos
    printButton("+", minUT[0]+155, minUT[1], minUT[2]+155, minUT[3], true); //minuto mais
    printButton("-", minDT[0]+155, minDT[1], minDT[2]+155, minDT[3], true); //minuto menos

    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.print(":", 105, 48);
    myGLCD.print(":", 105 + 155, 48);
    myGLCD.setFont(SmallFont);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[118])));
    myGLCD.print(buffer, 5, 51);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[119])));
    myGLCD.print(buffer, 172, 51);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[135])));
    printButton(buffer, proX[0], proX[1], proX[2], proX[3]); // "PROXIMO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);  // "INICIO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
    printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
    printButton(buffer, volT[0], volT[1], volT[2], volT[3]);
  }
  if(bitRead(dosadora_selecionada,1) == true)
  {
    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[102])));
    myGLCD.print(buffer, 10, 198);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[125])));
    myGLCD.print(buffer, 10, 218);

    if (temp2segunda_dosagem_personalizada_1 == 1)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[59])));
      printButton_verde(buffer, segU[0], segU[1], segU[2], segU[3]); //botao segunda
    } 
    else 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[59])));      
      printButton(buffer, segU[0], segU[1], segU[2], segU[3]); //botao segunda
    }
    if (temp2terca_dosagem_personalizada_1 == 2)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[60])));
      printButton_verde(buffer, terC[0], terC[1], terC[2], terC[3]); //botao terca
    } 
    else 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[60])));
      printButton(buffer, terC[0], terC[1], terC[2], terC[3]); //botao terca
    }
    if (temp2quarta_dosagem_personalizada_1 == 3)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[61]))); 
      printButton_verde(buffer, quaR[0], quaR[1], quaR[2], quaR[3]); //botao quarta
    } 
    else
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[61])));
      printButton(buffer, quaR[0], quaR[1], quaR[2], quaR[3]); //botao quarta
    }
    if (temp2quinta_dosagem_personalizada_1 == 4) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[62])));
      printButton_verde(buffer, quiN[0], quiN[1], quiN[2], quiN[3]); //botao quinta
    } 
    else 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[62])));
      printButton(buffer, quiN[0], quiN[1], quiN[2], quiN[3]); //botao quinta
    }
    if (temp2sexta_dosagem_personalizada_1 == 5) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[63])));
      printButton_verde(buffer, sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
    } 
    else
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[63])));
      printButton(buffer, sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
    }
    if (temp2sabado_dosagem_personalizada_1 == 6) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[64])));
      printButton_verde(buffer, sabA[0], sabA[1], sabA[2], sabA[3]); //botao sabado
    }
    else 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[64])));
      printButton(buffer, sabA[0], sabA[1], sabA[2], sabA[3]); //botao sabado
    }
    if (temp2domingo_dosagem_personalizada_1 == 7) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[65])));
      printButton_verde(buffer, domI[0], domI[1], domI[2], domI[3]); //botao sabado
    }
    else 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[65])));
      printButton(buffer, domI[0], domI[1], domI[2], domI[3]); //botao sabado
    }

    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    if (temp2hora_inicial_dosagem_personalizada_1 < 10) 
    {
      myGLCD.printNumI(0, 70, 48);
      myGLCD.printNumI(temp2hora_inicial_dosagem_personalizada_1, 86, 48);
    } 
    else
    {
      myGLCD.printNumI(temp2hora_inicial_dosagem_personalizada_1, 70, 48);
    }

    if (temp2minuto_inicial_dosagem_personalizada_1 < 10)
    {
      myGLCD.printNumI(0, 120, 48);
      myGLCD.printNumI(temp2minuto_inicial_dosagem_personalizada_1, 136, 48);
    } 
    else 
    {
      myGLCD.printNumI(temp2minuto_inicial_dosagem_personalizada_1, 120, 48);
    }
    if (temp2hora_final_dosagem_personalizada_1 < 10)
    {
      myGLCD.printNumI(0, 70 + 155, 48);
      myGLCD.printNumI(temp2hora_final_dosagem_personalizada_1, 86 + 155, 48);
    } 
    else
    {
      myGLCD.printNumI(temp2hora_final_dosagem_personalizada_1, 70 + 155, 48);
    }

    if (temp2minuto_final_dosagem_personalizada_1 < 10)
    {
      myGLCD.printNumI(0, 120 + 155, 48);
      myGLCD.printNumI(temp2minuto_final_dosagem_personalizada_1, 136 + 155, 48);
    } 
    else
    {
      myGLCD.printNumI(temp2minuto_final_dosagem_personalizada_1, 120 + 155, 48);
    }
  }
  if(bitRead(dosadora_selecionada,2) == true)
  {
    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[103])));
    myGLCD.print(buffer, 10, 198);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[125])));
    myGLCD.print(buffer, 10, 218);

    if (temp2segunda_dosagem_personalizada_2 == 1) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[59])));
      printButton_verde(buffer, segU[0], segU[1], segU[2], segU[3]); //botao segunda
    } 
    else 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[59])));
      printButton(buffer, segU[0], segU[1], segU[2], segU[3]); //botao segunda
    }
    if (temp2terca_dosagem_personalizada_2 == 2)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[60])));
      printButton_verde(buffer, terC[0], terC[1], terC[2], terC[3]); //botao terca
    } 
    else
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[60])));
      printButton(buffer, terC[0], terC[1], terC[2], terC[3]); //botao terca
    }
    if (temp2quarta_dosagem_personalizada_2 == 3) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[61])));
      printButton_verde(buffer, quaR[0], quaR[1], quaR[2], quaR[3]); //botao quarta
    } 
    else 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[61])));
      printButton(buffer, quaR[0], quaR[1], quaR[2], quaR[3]); //botao quarta
    }
    if (temp2quinta_dosagem_personalizada_2 == 4) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[62])));
      printButton_verde(buffer, quiN[0], quiN[1], quiN[2], quiN[3]); //botao quinta
    } 
    else 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[62])));
      printButton(buffer, quiN[0], quiN[1], quiN[2], quiN[3]); //botao quinta
    }
    if (temp2sexta_dosagem_personalizada_2 == 5)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[63])));
      printButton_verde(buffer, sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
    } 
    else 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[63])));
      printButton(buffer, sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
    }
    if (temp2sabado_dosagem_personalizada_2 == 6) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[64])));
      printButton_verde(buffer, sabA[0], sabA[1], sabA[2], sabA[3]); //botao sabado
    }
    else 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[64])));
      printButton(buffer, sabA[0], sabA[1], sabA[2], sabA[3]); //botao sabado
    }
    if (temp2domingo_dosagem_personalizada_2 == 7) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[65])));
      printButton_verde(buffer, domI[0], domI[1], domI[2], domI[3]); //botao sabado
    }
    else 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[65])));
      printButton(buffer, domI[0], domI[1], domI[2], domI[3]); //botao sabado
    }

    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    if (temp2hora_inicial_dosagem_personalizada_2 < 10) 
    {
      myGLCD.printNumI(0, 70, 48);
      myGLCD.printNumI(temp2hora_inicial_dosagem_personalizada_2, 86, 48);
    } 
    else 
    {
      myGLCD.printNumI(temp2hora_inicial_dosagem_personalizada_2, 70, 48);
    }

    if (temp2minuto_inicial_dosagem_personalizada_2 < 10) 
    {
      myGLCD.printNumI(0, 120, 48);
      myGLCD.printNumI(temp2minuto_inicial_dosagem_personalizada_2, 136, 48);
    } 
    else 
    {
      myGLCD.printNumI(temp2minuto_inicial_dosagem_personalizada_2, 120, 48);
    }
    if (temp2hora_final_dosagem_personalizada_2 < 10) 
    {
      myGLCD.printNumI(0, 70 + 155, 48);
      myGLCD.printNumI(temp2hora_final_dosagem_personalizada_2, 86 + 155, 48);
    } 
    else 
    {
      myGLCD.printNumI(temp2hora_final_dosagem_personalizada_2, 70 + 155, 48);
    }

    if (temp2minuto_final_dosagem_personalizada_2 < 10) {
      myGLCD.printNumI(0, 120 + 155, 48);
      myGLCD.printNumI(temp2minuto_final_dosagem_personalizada_2, 136 + 155, 48);
    } 
    else 
    {
      myGLCD.printNumI(temp2minuto_final_dosagem_personalizada_2, 120 + 155, 48);
    }
  }
  if(bitRead(dosadora_selecionada,3) == true)
  {
    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[104])));
    myGLCD.print(buffer, 10, 198);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[125])));
    myGLCD.print(buffer, 10, 218);

    if (temp2segunda_dosagem_personalizada_3 == 1) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[59])));
      printButton_verde(buffer, segU[0], segU[1], segU[2], segU[3]); //botao segunda
    } 
    else
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[59])));
      printButton(buffer, segU[0], segU[1], segU[2], segU[3]); //botao segunda
    }
    if (temp2terca_dosagem_personalizada_3 == 2)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[60])));
      printButton_verde(buffer, terC[0], terC[1], terC[2], terC[3]); //botao terca
    } 
    else 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[60])));
      printButton(buffer, terC[0], terC[1], terC[2], terC[3]); //botao terca
    }
    if (temp2quarta_dosagem_personalizada_3 == 3)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[61])));
      printButton_verde(buffer, quaR[0], quaR[1], quaR[2], quaR[3]); //botao quarta
    } 
    else 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[61])));
      printButton(buffer, quaR[0], quaR[1], quaR[2], quaR[3]); //botao quarta
    }
    if (temp2quinta_dosagem_personalizada_3 == 4)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[62])));
      printButton_verde(buffer, quiN[0], quiN[1], quiN[2], quiN[3]); //botao quinta
    } 
    else 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[62])));
      printButton(buffer, quiN[0], quiN[1], quiN[2], quiN[3]); //botao quinta
    }
    if (temp2sexta_dosagem_personalizada_3 == 5)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[63])));
      printButton_verde(buffer, sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
    } 
    else
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[63])));
      printButton(buffer, sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
    }
    if (temp2sabado_dosagem_personalizada_3 == 6)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[64])));
      printButton_verde(buffer, sabA[0], sabA[1], sabA[2], sabA[3]); //botao sabado
    }
    else 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[64])));
      printButton(buffer, sabA[0], sabA[1], sabA[2], sabA[3]); //botao sabado
    }
    if (temp2domingo_dosagem_personalizada_3 == 7) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[65])));
      printButton_verde(buffer, domI[0], domI[1], domI[2], domI[3]); //botao sabado
    }
    else
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[65])));
      printButton(buffer, domI[0], domI[1], domI[2], domI[3]); //botao sabado
    }

    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    if (temp2hora_inicial_dosagem_personalizada_3 < 10) 
    {
      myGLCD.printNumI(0, 70, 48);
      myGLCD.printNumI(temp2hora_inicial_dosagem_personalizada_3, 86, 48);
    } 
    else 
    {
      myGLCD.printNumI(temp2hora_inicial_dosagem_personalizada_3, 70, 48);
    }

    if (temp2minuto_inicial_dosagem_personalizada_3 < 10) 
    {
      myGLCD.printNumI(0, 120, 48);
      myGLCD.printNumI(temp2minuto_inicial_dosagem_personalizada_3, 136, 48);
    } 
    else 
    {
      myGLCD.printNumI(temp2minuto_inicial_dosagem_personalizada_3, 120, 48);
    }
    if (temp2hora_final_dosagem_personalizada_3 < 10) 
    {
      myGLCD.printNumI(0, 70 + 155, 48);
      myGLCD.printNumI(temp2hora_final_dosagem_personalizada_3, 86 + 155, 48);
    } 
    else 
    {
      myGLCD.printNumI(temp2hora_final_dosagem_personalizada_3, 70 + 155, 48);
    }

    if (temp2minuto_final_dosagem_personalizada_3 < 10) 
    {
      myGLCD.printNumI(0, 120 + 155, 48);
      myGLCD.printNumI(temp2minuto_final_dosagem_personalizada_3, 136 + 155, 48);
    } 
    else 
    {
      myGLCD.printNumI(temp2minuto_final_dosagem_personalizada_3, 120 + 155, 48);
    }
  }
  if(bitRead(dosadora_selecionada,4) == true)
  {
    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[204])));
    myGLCD.print(buffer, 10, 198);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[125])));
    myGLCD.print(buffer, 10, 218);

    if (temp2segunda_dosagem_personalizada_4 == 1)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[59])));
      printButton_verde(buffer, segU[0], segU[1], segU[2], segU[3]); //botao segunda
    } 
    else 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[59])));      
      printButton(buffer, segU[0], segU[1], segU[2], segU[3]); //botao segunda
    }
    if (temp2terca_dosagem_personalizada_4 == 2)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[60])));
      printButton_verde(buffer, terC[0], terC[1], terC[2], terC[3]); //botao terca
    } 
    else 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[60])));
      printButton(buffer, terC[0], terC[1], terC[2], terC[3]); //botao terca
    }
    if (temp2quarta_dosagem_personalizada_4 == 3)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[61]))); 
      printButton_verde(buffer, quaR[0], quaR[1], quaR[2], quaR[3]); //botao quarta
    } 
    else
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[61])));
      printButton(buffer, quaR[0], quaR[1], quaR[2], quaR[3]); //botao quarta
    }
    if (temp2quinta_dosagem_personalizada_4 == 4) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[62])));
      printButton_verde(buffer, quiN[0], quiN[1], quiN[2], quiN[3]); //botao quinta
    } 
    else 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[62])));
      printButton(buffer, quiN[0], quiN[1], quiN[2], quiN[3]); //botao quinta
    }
    if (temp2sexta_dosagem_personalizada_4 == 5) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[63])));
      printButton_verde(buffer, sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
    } 
    else
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[63])));
      printButton(buffer, sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
    }
    if (temp2sabado_dosagem_personalizada_4 == 6) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[64])));
      printButton_verde(buffer, sabA[0], sabA[1], sabA[2], sabA[3]); //botao sabado
    }
    else 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[64])));
      printButton(buffer, sabA[0], sabA[1], sabA[2], sabA[3]); //botao sabado
    }
    if (temp2domingo_dosagem_personalizada_4 == 7) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[65])));
      printButton_verde(buffer, domI[0], domI[1], domI[2], domI[3]); //botao sabado
    }
    else 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[65])));
      printButton(buffer, domI[0], domI[1], domI[2], domI[3]); //botao sabado
    }

    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    if (temp2hora_inicial_dosagem_personalizada_4 < 10) 
    {
      myGLCD.printNumI(0, 70, 48);
      myGLCD.printNumI(temp2hora_inicial_dosagem_personalizada_4, 86, 48);
    } 
    else
    {
      myGLCD.printNumI(temp2hora_inicial_dosagem_personalizada_4, 70, 48);
    }

    if (temp2minuto_inicial_dosagem_personalizada_4 < 10)
    {
      myGLCD.printNumI(0, 120, 48);
      myGLCD.printNumI(temp2minuto_inicial_dosagem_personalizada_4, 136, 48);
    } 
    else 
    {
      myGLCD.printNumI(temp2minuto_inicial_dosagem_personalizada_4, 120, 48);
    }
    if (temp2hora_final_dosagem_personalizada_4 < 10)
    {
      myGLCD.printNumI(0, 70 + 155, 48);
      myGLCD.printNumI(temp2hora_final_dosagem_personalizada_4, 86 + 155, 48);
    } 
    else
    {
      myGLCD.printNumI(temp2hora_final_dosagem_personalizada_4, 70 + 155, 48);
    }

    if (temp2minuto_final_dosagem_personalizada_4 < 10)
    {
      myGLCD.printNumI(0, 120 + 155, 48);
      myGLCD.printNumI(temp2minuto_final_dosagem_personalizada_4, 136 + 155, 48);
    } 
    else
    {
      myGLCD.printNumI(temp2minuto_final_dosagem_personalizada_4, 120 + 155, 48);
    }
  }
  if(bitRead(dosadora_selecionada,5) == true)
  {
    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[205])));
    myGLCD.print(buffer, 10, 198);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[125])));
    myGLCD.print(buffer, 10, 218);

    if (temp2segunda_dosagem_personalizada_5 == 1) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[59])));
      printButton_verde(buffer, segU[0], segU[1], segU[2], segU[3]); //botao segunda
    } 
    else 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[59])));
      printButton(buffer, segU[0], segU[1], segU[2], segU[3]); //botao segunda
    }
    if (temp2terca_dosagem_personalizada_5 == 2)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[60])));
      printButton_verde(buffer, terC[0], terC[1], terC[2], terC[3]); //botao terca
    } 
    else
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[60])));
      printButton(buffer, terC[0], terC[1], terC[2], terC[3]); //botao terca
    }
    if (temp2quarta_dosagem_personalizada_5 == 3) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[61])));
      printButton_verde(buffer, quaR[0], quaR[1], quaR[2], quaR[3]); //botao quarta
    } 
    else 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[61])));
      printButton(buffer, quaR[0], quaR[1], quaR[2], quaR[3]); //botao quarta
    }
    if (temp2quinta_dosagem_personalizada_5 == 4) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[62])));
      printButton_verde(buffer, quiN[0], quiN[1], quiN[2], quiN[3]); //botao quinta
    } 
    else 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[62])));
      printButton(buffer, quiN[0], quiN[1], quiN[2], quiN[3]); //botao quinta
    }
    if (temp2sexta_dosagem_personalizada_5 == 5)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[63])));
      printButton_verde(buffer, sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
    } 
    else 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[63])));
      printButton(buffer, sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
    }
    if (temp2sabado_dosagem_personalizada_5 == 6) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[64])));
      printButton_verde(buffer, sabA[0], sabA[1], sabA[2], sabA[3]); //botao sabado
    }
    else 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[64])));
      printButton(buffer, sabA[0], sabA[1], sabA[2], sabA[3]); //botao sabado
    }
    if (temp2domingo_dosagem_personalizada_5 == 7) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[65])));
      printButton_verde(buffer, domI[0], domI[1], domI[2], domI[3]); //botao sabado
    }
    else 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[65])));
      printButton(buffer, domI[0], domI[1], domI[2], domI[3]); //botao sabado
    }

    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    if (temp2hora_inicial_dosagem_personalizada_5 < 10) 
    {
      myGLCD.printNumI(0, 70, 48);
      myGLCD.printNumI(temp2hora_inicial_dosagem_personalizada_5, 86, 48);
    } 
    else 
    {
      myGLCD.printNumI(temp2hora_inicial_dosagem_personalizada_5, 70, 48);
    }

    if (temp2minuto_inicial_dosagem_personalizada_5 < 10) 
    {
      myGLCD.printNumI(0, 120, 48);
      myGLCD.printNumI(temp2minuto_inicial_dosagem_personalizada_5, 136, 48);
    } 
    else 
    {
      myGLCD.printNumI(temp2minuto_inicial_dosagem_personalizada_5, 120, 48);
    }
    if (temp2hora_final_dosagem_personalizada_5 < 10) 
    {
      myGLCD.printNumI(0, 70 + 155, 48);
      myGLCD.printNumI(temp2hora_final_dosagem_personalizada_5, 86 + 155, 48);
    } 
    else 
    {
      myGLCD.printNumI(temp2hora_final_dosagem_personalizada_5, 70 + 155, 48);
    }

    if (temp2minuto_final_dosagem_personalizada_5 < 10) {
      myGLCD.printNumI(0, 120 + 155, 48);
      myGLCD.printNumI(temp2minuto_final_dosagem_personalizada_5, 136 + 155, 48);
    } 
    else 
    {
      myGLCD.printNumI(temp2minuto_final_dosagem_personalizada_5, 120 + 155, 48);
    }
  }
  if(bitRead(dosadora_selecionada,6) == true)
  {
    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[206])));
    myGLCD.print(buffer, 10, 198);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[125])));
    myGLCD.print(buffer, 10, 218);

    if (temp2segunda_dosagem_personalizada_6 == 1) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[59])));
      printButton_verde(buffer, segU[0], segU[1], segU[2], segU[3]); //botao segunda
    } 
    else
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[59])));
      printButton(buffer, segU[0], segU[1], segU[2], segU[3]); //botao segunda
    }
    if (temp2terca_dosagem_personalizada_6 == 2)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[60])));
      printButton_verde(buffer, terC[0], terC[1], terC[2], terC[3]); //botao terca
    } 
    else 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[60])));
      printButton(buffer, terC[0], terC[1], terC[2], terC[3]); //botao terca
    }
    if (temp2quarta_dosagem_personalizada_6 == 3)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[61])));
      printButton_verde(buffer, quaR[0], quaR[1], quaR[2], quaR[3]); //botao quarta
    } 
    else 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[61])));
      printButton(buffer, quaR[0], quaR[1], quaR[2], quaR[3]); //botao quarta
    }
    if (temp2quinta_dosagem_personalizada_6 == 4)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[62])));
      printButton_verde(buffer, quiN[0], quiN[1], quiN[2], quiN[3]); //botao quinta
    } 
    else 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[62])));
      printButton(buffer, quiN[0], quiN[1], quiN[2], quiN[3]); //botao quinta
    }
    if (temp2sexta_dosagem_personalizada_6 == 5)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[63])));
      printButton_verde(buffer, sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
    } 
    else
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[63])));
      printButton(buffer, sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
    }
    if (temp2sabado_dosagem_personalizada_6 == 6)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[64])));
      printButton_verde(buffer, sabA[0], sabA[1], sabA[2], sabA[3]); //botao sabado
    }
    else 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[64])));
      printButton(buffer, sabA[0], sabA[1], sabA[2], sabA[3]); //botao sabado
    }
    if (temp2domingo_dosagem_personalizada_6 == 7) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[65])));
      printButton_verde(buffer, domI[0], domI[1], domI[2], domI[3]); //botao sabado
    }
    else
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[65])));
      printButton(buffer, domI[0], domI[1], domI[2], domI[3]); //botao sabado
    }

    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    if (temp2hora_inicial_dosagem_personalizada_6 < 10) 
    {
      myGLCD.printNumI(0, 70, 48);
      myGLCD.printNumI(temp2hora_inicial_dosagem_personalizada_6, 86, 48);
    } 
    else 
    {
      myGLCD.printNumI(temp2hora_inicial_dosagem_personalizada_6, 70, 48);
    }

    if (temp2minuto_inicial_dosagem_personalizada_6 < 10) 
    {
      myGLCD.printNumI(0, 120, 48);
      myGLCD.printNumI(temp2minuto_inicial_dosagem_personalizada_6, 136, 48);
    } 
    else 
    {
      myGLCD.printNumI(temp2minuto_inicial_dosagem_personalizada_6, 120, 48);
    }
    if (temp2hora_final_dosagem_personalizada_6 < 10) 
    {
      myGLCD.printNumI(0, 70 + 155, 48);
      myGLCD.printNumI(temp2hora_final_dosagem_personalizada_6, 86 + 155, 48);
    } 
    else 
    {
      myGLCD.printNumI(temp2hora_final_dosagem_personalizada_6, 70 + 155, 48);
    }

    if (temp2minuto_final_dosagem_personalizada_6 < 10) 
    {
      myGLCD.printNumI(0, 120 + 155, 48);
      myGLCD.printNumI(temp2minuto_final_dosagem_personalizada_6, 136 + 155, 48);
    } 
    else 
    {
      myGLCD.printNumI(temp2minuto_final_dosagem_personalizada_6, 120 + 155, 48);
    }
  }
}

void solicitar_senha()  //---------------tela =30
{
  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[46])));
  printHeader(buffer); // tabela_textos[46] = "DIGITE A SENHA"

  printButton("1", boT1[0], boT1[1], boT1[2], boT1[3],true);
  printButton("2", boT2[0], boT2[1], boT2[2], boT2[3],true);
  printButton("3", boT3[0], boT3[1], boT3[2], boT3[3],true);
  printButton("4", boT4[0], boT4[1], boT4[2], boT4[3],true);
  printButton("5", boT5[0], boT5[1], boT5[2], boT5[3],true);
  printButton("6", boT6[0], boT6[1], boT6[2], boT6[3],true);
  printButton("7", boT7[0], boT7[1], boT7[2], boT7[3],true);
  printButton("8", boT8[0], boT8[1], boT8[2], boT8[3],true);
  printButton("9", boT9[0], boT9[1], boT9[2], boT9[3],true);
  printButton("0", boT0[0], boT0[1], boT0[2], boT0[3],true);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[136])));
  printButton(buffer, boTL[0], boTL[1], boTL[2], boTL[3],true); // tabela_textos[136] = "LIMPAR"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[137])));
  printButton(buffer, boTE[0], boTE[1], boTE[2], boTE[3],true); // tabela_textos[137] = "ENTRAR"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);  // tabela_textos[11] = "INICIO"

}

void config_dosagem_personalizada_2(boolean refreshAll=false) // ----------tela =31
{
  if(refreshAll)
  {
    dose_dosadora_1_personalizada_temp2 = dose_dosadora_1_personalizada;
    dose_dosadora_2_personalizada_temp2 = dose_dosadora_2_personalizada;
    dose_dosadora_3_personalizada_temp2 = dose_dosadora_3_personalizada;
    quantidade_dose_dosadora_1_personalizada_temp2 = quantidade_dose_dosadora_1_personalizada;
    quantidade_dose_dosadora_2_personalizada_temp2 = quantidade_dose_dosadora_2_personalizada;
    quantidade_dose_dosadora_3_personalizada_temp2 = quantidade_dose_dosadora_3_personalizada;
    modo_personalizado_on_1_temp2 = modo_personalizado_on_1;
    modo_personalizado_on_2_temp2 = modo_personalizado_on_2;
    modo_personalizado_on_3_temp2 = modo_personalizado_on_3;
    dose_dosadora_4_personalizada_temp2 = dose_dosadora_4_personalizada;
    dose_dosadora_5_personalizada_temp2 = dose_dosadora_5_personalizada;
    dose_dosadora_6_personalizada_temp2 = dose_dosadora_6_personalizada;
    quantidade_dose_dosadora_4_personalizada_temp2 = quantidade_dose_dosadora_4_personalizada;
    quantidade_dose_dosadora_5_personalizada_temp2 = quantidade_dose_dosadora_5_personalizada;
    quantidade_dose_dosadora_6_personalizada_temp2 = quantidade_dose_dosadora_6_personalizada;
    modo_personalizado_on_4_temp2 = modo_personalizado_on_4;
    modo_personalizado_on_5_temp2 = modo_personalizado_on_5;
    modo_personalizado_on_6_temp2 = modo_personalizado_on_6;

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[47])));
    printHeader(buffer); // tabela_textos[47] = "CONFIGURAR DOSAGEM PERSONALIZADA"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);  // "INICIO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
    printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[138])));
    printButton(buffer, anT[0],anT[1], anT[2], anT[3]); // tabela_textos[138] = "ANTERIOR"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[13])));
    printButton(buffer, prOK[0],prOK[1], prOK[2], prOK[3]); // "SALVAR"

    printButton("+", minUT[0], minUT[1], minUT[2], minUT[3], true); //min up
    printButton("-", minDT[0], minDT[1], minDT[2], minDT[3], true); //min down
    printButton("+", durC[0], durC[1], durC[2], durC[3], true); //minuto mais
    printButton("-", durB[0], durB[1], durB[2], durB[3], true); //minuto menos

    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.setFont(SmallFont);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[120])));
    myGLCD.print(buffer, 10, 31); // "SELECIONE O"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[121])));
    myGLCD.print(buffer, 10, 55); // "VOLUME "

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[122])));
    myGLCD.print(buffer, 10, 75); // "(ML/DIA):"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[123])));
    myGLCD.print(buffer, 190, 46); // "QUANTIDADE"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[124])));
    myGLCD.print(buffer, 190, 61); // "DE DOSES:"
  }

  if ((bitRead(dosadora_selecionada,1) == true) && (modo_personalizado == true ))
  { 
    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.printNumF(dose_dosadora_1_personalizada_temp2, 1, 100, 48);  
    if (quantidade_dose_dosadora_1_personalizada_temp2 < 10) 
    {
      myGLCD.printNumI(0, 275, 48);
      myGLCD.printNumI(quantidade_dose_dosadora_1_personalizada_temp2, 291, 48);
    } 
    else 
    {
      myGLCD.printNumI(quantidade_dose_dosadora_1_personalizada_temp2, 275, 48);
    }
    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[111])));
    myGLCD.print(buffer, 125, 213);

    if (modo_personalizado_on_1_temp2 == 1) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
      printButton_verde(buffer, sexT[0], sexT[1], sexT[2], sexT[3]); 
    } 
    else 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));
      printButton(buffer, sexT[0], sexT[1], sexT[2], sexT[3]); 
    }
  } 
  if ((bitRead(dosadora_selecionada,2) == true) && (modo_personalizado == true ))
  {
    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.printNumF(dose_dosadora_2_personalizada_temp2, 1, 100, 48);  
    if (quantidade_dose_dosadora_2_personalizada_temp2 < 10) 
    {
      myGLCD.printNumI(0, 275, 48);
      myGLCD.printNumI(quantidade_dose_dosadora_2_personalizada_temp2, 291, 48);
    } 
    else 
    {
      myGLCD.printNumI(quantidade_dose_dosadora_2_personalizada_temp2, 275, 48);
    }
    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[112])));
    myGLCD.print(buffer, 125, 213);

    if (modo_personalizado_on_2_temp2 == 1) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
      printButton_verde(buffer, sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
    } 
    else 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));      
      printButton(buffer, sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
    }
  }
  if ((bitRead(dosadora_selecionada,3) == true) && (modo_personalizado == true))
  {
    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.printNumF(dose_dosadora_3_personalizada_temp2, 1, 100, 48); 

    if (quantidade_dose_dosadora_3_personalizada_temp2 < 10) 
    {
      myGLCD.printNumI(0, 275, 48);
      myGLCD.printNumI(quantidade_dose_dosadora_3_personalizada_temp2, 291, 48);
    } 
    else 
    {
      myGLCD.printNumI(quantidade_dose_dosadora_3_personalizada_temp2, 275, 48);
    }
    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[113])));
    myGLCD.print(buffer, 125, 213);

    if (modo_personalizado_on_3_temp2 == 1) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
      printButton_verde(buffer, sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
    } 
    else 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));
      printButton(buffer, sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
    }
  }
  if ((bitRead(dosadora_selecionada,4) == true) && (modo_personalizado == true ))
  {
    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.printNumF(dose_dosadora_4_personalizada_temp2, 1, 100, 48);  
    if (quantidade_dose_dosadora_4_personalizada_temp2 < 10) 
    {
      myGLCD.printNumI(0, 275, 48);
      myGLCD.printNumI(quantidade_dose_dosadora_4_personalizada_temp2, 291, 48);
    } 
    else 
    {
      myGLCD.printNumI(quantidade_dose_dosadora_4_personalizada_temp2, 275, 48);
    }
    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[207])));
    myGLCD.print(buffer, 125, 213);

    if (modo_personalizado_on_4_temp2 == 1) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
      printButton_verde(buffer, sexT[0], sexT[1], sexT[2], sexT[3]); 
    } 
    else 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));
      printButton(buffer, sexT[0], sexT[1], sexT[2], sexT[3]); 
    }
  } 
  if ((bitRead(dosadora_selecionada,5) == true) && (modo_personalizado == true ))
  {
    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.printNumF(dose_dosadora_5_personalizada_temp2, 1, 100, 48);  
    if (quantidade_dose_dosadora_5_personalizada_temp2 < 10) 
    {
      myGLCD.printNumI(0, 275, 48);
      myGLCD.printNumI(quantidade_dose_dosadora_5_personalizada_temp2, 291, 48);
    } 
    else 
    {
      myGLCD.printNumI(quantidade_dose_dosadora_5_personalizada_temp2, 275, 48);
    }
    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[208])));
    myGLCD.print(buffer, 125, 213);

    if (modo_personalizado_on_5_temp2 == 1) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
      printButton_verde(buffer, sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
    } 
    else 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));      
      printButton(buffer, sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
    }
  }
  if ((bitRead(dosadora_selecionada,6) == true) && (modo_personalizado == true))
  {
    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.printNumF(dose_dosadora_6_personalizada_temp2, 1, 100, 48); 

    if (quantidade_dose_dosadora_6_personalizada_temp2 < 10) 
    {
      myGLCD.printNumI(0, 275, 48);
      myGLCD.printNumI(quantidade_dose_dosadora_6_personalizada_temp2, 291, 48);
    } 
    else 
    {
      myGLCD.printNumI(quantidade_dose_dosadora_6_personalizada_temp2, 275, 48);
    }
    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[209])));
    myGLCD.print(buffer, 125, 213);

    if (modo_personalizado_on_6_temp2 == 1) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
      printButton_verde(buffer, sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
    } 
    else 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));
      printButton(buffer, sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
    }
  }
}

void rever_configuracao_dosadoras()//---------------------------------------------tela =32
{
  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[44])));
  printHeader(buffer); // tabela_textos[44] = "REVER CONFIG. DOSADORAS" 

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[140])));
  printButton(buffer, manU[0], manU[1], manU[2], manU[3]); // tabela_textos[140] = "PERSONALIZADO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);  // "INICIO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
  printButton(buffer, volT[0], volT[1], volT[2], volT[3]); // tabela_textos[66]
} 
void rever_dosagem_personalizada() // ------------------------------------------------------------------tela =34
{
  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[50])));
  printHeader(buffer); // tabela_textos[50] = "REVER CONF. DA DOSAGEM PERSONALIZADA"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);  // "INICIO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[210])));
  printButton(buffer, salV[0], salV[1], salV[2], salV[3]); // "MAIS"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
  printButton(buffer, volT[0], volT[1], volT[2], volT[3]); // "VOLTAR"

  myGLCD.setColor(161, 127, 73);                    
  myGLCD.drawLine(1, 88, 319, 88);  
  myGLCD.drawLine(1, 158, 319, 158);
  myGLCD.drawLine(319, 15, 319, 239);

  setFont(SMALL, 255, 255, 255, 0, 0, 0);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[129])));
  myGLCD.print(buffer, 10, 30); // tabela_textos[129]  

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[118])));
  myGLCD.print(buffer, 10, 50);  

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[119])));
  myGLCD.print(buffer, 118, 50);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[128])));
  myGLCD.print(buffer, 10, 70);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[121])));
  myGLCD.print(buffer, 215, 50);    //Posição correta

  myGLCD.print(":", 90, 50);
  myGLCD.print(":", 180, 50);

  myGLCD.printNumF(dose_dosadora_1_personalizada, 1, 275, 50); //Posição correta
  myGLCD.printNumI(quantidade_dose_dosadora_1_personalizada, 170, 70);

  if(hora_inicial_dosagem_personalizada_1 < 10)
  {
    myGLCD.printNumI(0, 72, 50);
    myGLCD.printNumI(hora_inicial_dosagem_personalizada_1, 80, 50);
  }
  else
  {
    myGLCD.printNumI(hora_inicial_dosagem_personalizada_1, 72, 50);
  }
  if(minuto_inicial_dosagem_personalizada_1 < 10)
  {
    myGLCD.printNumI(0, 98, 50);
    myGLCD.printNumI(minuto_inicial_dosagem_personalizada_1, 106, 50);
  }
  else
  {
    myGLCD.printNumI(minuto_inicial_dosagem_personalizada_1, 98, 50);
  }
  if(hora_final_dosagem_personalizada_1 < 10)
  {
    myGLCD.printNumI(0, 165, 50);
    myGLCD.printNumI(hora_final_dosagem_personalizada_1, 173, 50); 
  }
  else
  {
    myGLCD.printNumI(hora_final_dosagem_personalizada_1, 165, 50);
  }
  if(minuto_final_dosagem_personalizada_1 < 10)
  {
    myGLCD.printNumI(0, 188, 50);
    myGLCD.printNumI(minuto_final_dosagem_personalizada_1, 196, 50);
  }
  else
  {
    myGLCD.printNumI(minuto_final_dosagem_personalizada_1, 188, 50);
  }
  if(segunda_dosagem_personalizada_1 == 1)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[70])));
    printButton_verde(buffer, 110, 23, 130, 43);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[70])));
    printButton(buffer, 110, 23, 130, 43);
  }
  if(terca_dosagem_personalizada_1 == 2)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[71])));
    printButton_verde(buffer, 140, 23, 160, 43);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[71])));
    printButton(buffer, 140, 23, 160, 43);
  }
  if(quarta_dosagem_personalizada_1 == 3)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[72])));
    printButton_verde(buffer, 170, 23, 190, 43);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[72])));
    printButton(buffer, 170, 23, 190, 43);
  }    
  if(quinta_dosagem_personalizada_1 == 4)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[198])));
    printButton_verde(buffer, 200, 23, 220, 43);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[198])));
    printButton(buffer, 200, 23, 220, 43);
  }    
  if(sexta_dosagem_personalizada_1 == 5)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[199])));
    printButton_verde(buffer, 230, 23, 250, 43);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[199])));
    printButton(buffer, 230, 23, 250, 43);
  }
  if(sabado_dosagem_personalizada_1 == 6)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[200])));
    printButton_verde(buffer, 260, 23, 280, 43);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[200])));
    printButton(buffer, 260, 23, 280, 43);
  }
  if(domingo_dosagem_personalizada_1 == 7)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[73])));
    printButton_verde(buffer, 290, 23, 310, 43);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[73])));
    printButton(buffer, 290, 23, 310, 43);
  } 
  if (modo_personalizado_on_1 == 1) 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
    printButton_verde(buffer, 200, 65, 245, 85); 
  } 
  else 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
    printButton(buffer, 200, 65, 245, 85); 
  }
  if (modo_personalizado_on_1 == 0) 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));
    printButton_verde(buffer, 250, 65, 295, 85); 
  } 
  else 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));
    printButton(buffer, 250, 65, 295, 85); 
  }
  setFont(SMALL, 255, 255, 255, 0, 0, 0);    

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[130])));
  myGLCD.print(buffer, 10, 100);   

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[118])));
  myGLCD.print(buffer, 10, 120);  

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[119])));
  myGLCD.print(buffer, 118, 120);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[128])));
  myGLCD.print(buffer, 10, 140);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[121])));
  myGLCD.print(buffer, 215, 120);    

  myGLCD.print(":", 90, 120);
  myGLCD.print(":", 180, 120);

  myGLCD.printNumF(dose_dosadora_2_personalizada, 1, 275, 120); 
  myGLCD.printNumI(quantidade_dose_dosadora_2_personalizada, 170, 140);

  if(hora_inicial_dosagem_personalizada_2 < 10)
  {
    myGLCD.printNumI(0, 72, 120);
    myGLCD.printNumI(hora_inicial_dosagem_personalizada_2, 80, 120);
  }
  else
  {
    myGLCD.printNumI(hora_inicial_dosagem_personalizada_2, 72, 120);
  }
  if(minuto_inicial_dosagem_personalizada_2 < 10)
  {
    myGLCD.printNumI(0, 98, 120);
    myGLCD.printNumI(minuto_inicial_dosagem_personalizada_2, 106, 120);
  }
  else
  {
    myGLCD.printNumI(minuto_inicial_dosagem_personalizada_2, 98, 120);
  }
  if(hora_final_dosagem_personalizada_2 < 10)
  {
    myGLCD.printNumI(0, 165, 120);
    myGLCD.printNumI(hora_final_dosagem_personalizada_2, 173, 120); 
  }
  else
  {
    myGLCD.printNumI(hora_final_dosagem_personalizada_2, 165, 120);
  }
  if(minuto_final_dosagem_personalizada_2 < 10)
  {
    myGLCD.printNumI(0, 188, 120);
    myGLCD.printNumI(minuto_final_dosagem_personalizada_2, 196, 120);
  }
  else
  {
    myGLCD.printNumI(minuto_final_dosagem_personalizada_2, 188, 120);
  }
  if(segunda_dosagem_personalizada_2 == 1)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[70])));
    printButton_verde(buffer, 110, 93, 130, 113);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[70])));
    printButton(buffer, 110, 93, 130, 113);
  }
  if(terca_dosagem_personalizada_2 == 2)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[71])));
    printButton_verde(buffer, 140, 93, 160, 113);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[71])));
    printButton(buffer, 140, 93, 160, 113);
  }
  if(quarta_dosagem_personalizada_2 == 3)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[72])));
    printButton_verde(buffer, 170, 93, 190, 113);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[72])));
    printButton(buffer, 170, 93, 190, 113);
  }    
  if(quinta_dosagem_personalizada_2 == 4)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[198])));
    printButton_verde(buffer, 200, 93, 220, 113);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[198])));
    printButton(buffer, 200, 93, 220, 113);
  }    
  if(sexta_dosagem_personalizada_2 == 5)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[199])));
    printButton_verde(buffer, 230, 93, 250, 113);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[199])));
    printButton(buffer, 230, 93, 250, 113);
  }
  if(sabado_dosagem_personalizada_2 == 6)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[200])));
    printButton_verde(buffer, 260, 93, 280, 113);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[200])));
    printButton(buffer, 260, 93, 280, 113);
  }
  if(domingo_dosagem_personalizada_2 == 7)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[73])));
    printButton_verde(buffer, 290, 93, 310, 113);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[73])));
    printButton(buffer, 290, 93, 310, 113);
  } 
  if (modo_personalizado_on_2 == 1) 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
    printButton_verde(buffer, 200, 135, 245, 155); 
  } 
  else 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
    printButton(buffer, 200, 135, 245, 155); 
  }
  if (modo_personalizado_on_2 == 0) 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));
    printButton_verde(buffer, 250, 135, 295, 155); 
  } 
  else 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));
    printButton(buffer, 250, 135, 295, 155); 
  } 
  setFont(SMALL, 255, 255, 255, 0, 0, 0);    

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[131])));
  myGLCD.print(buffer, 10, 170);   

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[118])));
  myGLCD.print(buffer, 10, 190);  

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[119])));
  myGLCD.print(buffer, 118, 190);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[128])));
  myGLCD.print(buffer, 10, 210); // tabela_textos[128] = "QUANTIDADE DE DOSES:"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[121])));
  myGLCD.print(buffer, 215, 190);    

  myGLCD.print(":", 90, 190);
  myGLCD.print(":", 180, 190);

  myGLCD.printNumF(dose_dosadora_3_personalizada, 1, 275, 190); 
  myGLCD.printNumI(quantidade_dose_dosadora_3_personalizada, 170, 210);

  if(hora_inicial_dosagem_personalizada_3 < 10)
  {
    myGLCD.printNumI(0, 72, 190);
    myGLCD.printNumI(hora_inicial_dosagem_personalizada_3, 80, 190);
  }
  else
  {
    myGLCD.printNumI(hora_inicial_dosagem_personalizada_3, 72, 190);
  }
  if(minuto_inicial_dosagem_personalizada_3 < 10)
  {
    myGLCD.printNumI(0, 98, 190);
    myGLCD.printNumI(minuto_inicial_dosagem_personalizada_3, 106, 190);
  }
  else
  {
    myGLCD.printNumI(minuto_inicial_dosagem_personalizada_3, 98, 190);
  }
  if(hora_final_dosagem_personalizada_3 < 10)
  {
    myGLCD.printNumI(0, 165, 190);
    myGLCD.printNumI(hora_final_dosagem_personalizada_3, 173, 190); 
  }
  else
  {
    myGLCD.printNumI(hora_final_dosagem_personalizada_3, 165, 190);
  }
  if(minuto_final_dosagem_personalizada_3 < 10)
  {
    myGLCD.printNumI(0, 188, 190);
    myGLCD.printNumI(minuto_final_dosagem_personalizada_3, 196, 190);
  }
  else
  {
    myGLCD.printNumI(minuto_final_dosagem_personalizada_3, 188, 190);
  }
  if(segunda_dosagem_personalizada_3 == 1)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[70])));
    printButton_verde(buffer, 110, 163, 130, 183);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[70])));
    printButton(buffer, 110, 163, 130, 183);
  }
  if(terca_dosagem_personalizada_3 == 2)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[71])));
    printButton_verde(buffer, 140, 163, 160, 183);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[71])));
    printButton(buffer, 140, 163, 160, 183);
  }
  if(quarta_dosagem_personalizada_3 == 3)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[72])));
    printButton_verde(buffer, 170, 163, 190, 183);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[72])));
    printButton(buffer, 170, 163, 190, 183);
  }    
  if(quinta_dosagem_personalizada_3 == 4)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[198])));
    printButton_verde(buffer, 200, 163, 220, 183);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[198])));
    printButton(buffer, 200, 163, 220, 183);
  }    
  if(sexta_dosagem_personalizada_3 == 5)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[199])));
    printButton_verde(buffer, 230, 163, 250, 183);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[199])));
    printButton(buffer, 230, 163, 250, 183);
  }
  if(sabado_dosagem_personalizada_3 == 6)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[200])));
    printButton_verde(buffer, 260, 163, 280, 183);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[200])));
    printButton(buffer, 260, 163, 280, 183);
  }
  if(domingo_dosagem_personalizada_3 == 7)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[73])));
    printButton_verde(buffer, 290, 163, 310, 183);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[73])));
    printButton(buffer, 290, 163, 310, 183);
  } 
  if (modo_personalizado_on_3 == 1) 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
    printButton_verde(buffer, 200, 205, 245, 225); 
  } 
  else 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
    printButton(buffer, 200, 205, 245, 225); 
  }
  if (modo_personalizado_on_3 == 0) 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));
    printButton_verde(buffer, 250, 205, 295, 225); 
  } 
  else 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));
    printButton(buffer, 250, 205, 295, 225); 
  }     
}

//---------------------------------------------Desativar dosadoras--------------------------------tela =35 ----------
void desativar_dosadoras(boolean refreshAll = false)
{
  if(refreshAll == true)
  {
    if((modo_personalizado_on_1 == 1))
    {
      ativar_desativar_1 = 1;
    }
    else
    {
      ativar_desativar_1 = 0;
    }
    if((modo_personalizado_on_2 == 1))
    {
      ativar_desativar_2 = 1;
    }
    else
    {
      ativar_desativar_2 = 0;
    }
    if((modo_personalizado_on_3 == 1))
    {
      ativar_desativar_3 = 1;
    }
    else
    {
      ativar_desativar_3 = 0;
    }
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[51])));
    printHeader(buffer); // tabela_textos[51] =  "DESATIVAR DOSADORAS"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);  // "INICIO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
    printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[13])));
    printButton(buffer, salV[0], salV[1], salV[2], salV[3]); // "SALVAR"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
    printButton(buffer, volT[0], volT[1], volT[2], volT[3]); // VOLTAR

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[210])));
    printButton(buffer, deS[0], deS[1], deS[2], deS[3]); //"MAIS"

    setFont(SMALL, 255, 255, 255, 0, 0, 0); 

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[129])));
    myGLCD.print(buffer, 117, 30);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[130])));
    myGLCD.print(buffer, 120, 100);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[131])));
    myGLCD.print(buffer, 120, 170); 

    setFont(SMALL, 255, 0, 0, 0, 0, 0); 

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[141])));
    myGLCD.print(buffer, 230, 60); //tabela_textos[141] = "USE ESTA"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[142])));
    myGLCD.print(buffer, 230, 75); //tabela_textos[141] = "FUNCAO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[143])));
    myGLCD.print(buffer, 230, 90); // tabela_textos[143] = "APENAS PARA"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[144])));
    myGLCD.print(buffer, 230, 105); //tabela_textos[144] = "DESATIVAR"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[145])));
    myGLCD.print(buffer, 230, 120);  // tabela_textos[145] = "OS MODOS"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[146])));
    myGLCD.print(buffer, 230, 135); // tabela_textos[146] = "DE DOSAGEM."
  }
  if (ativar_desativar_1 == 1)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[147])));
    printButton_verde(buffer, 100, 45, 220, 85); // tabela_textos[147]

    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRect (3, 26, 117, 43);
    myGLCD.fillRect (3, 45, 95, 61);
    myGLCD.fillRect (3, 60, 95, 76);
    myGLCD.fillRect (3, 75, 95, 91);

    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[149])));
    myGLCD.print(buffer, 10, 30); // tabela_textos[149] = "UM DOS MODOS"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[150])));
    myGLCD.print(buffer, 10, 45); // tabela_textos[150] = "DE DOSAGEM  "

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[151])));
    myGLCD.print(buffer, 10, 60);  // tabela_textos[151] = "ESTA:"
  } 
  else 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[152])));
    printButton(buffer, 100, 45, 220, 85);

    setFont(SMALL, 255, 255, 0, 0, 0, 0); 

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[153])));
    myGLCD.print(buffer, 3, 30); 

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[150])));
    myGLCD.print(buffer, 3, 45);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[154])));
    myGLCD.print(buffer, 3, 60);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[155])));
    myGLCD.print(buffer, 3, 75); 
  }
  if (ativar_desativar_2 == 1)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[147])));
    printButton_verde(buffer, 100, 115, 220, 155);

    myGLCD.setColor(0, 0, 0); 
    myGLCD.fillRect (3, 96, 117, 113);
    myGLCD.fillRect (3, 115, 95, 131);
    myGLCD.fillRect (3, 130, 95, 146);
    myGLCD.fillRect (3, 145, 95, 161); 

    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[149])));
    myGLCD.print(buffer, 10, 100); // tabela_textos[149] = "UM DOS MODOS"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[150])));
    myGLCD.print(buffer, 10, 115); // tabela_textos[150] = "DE DOSAGEM  "

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[151])));
    myGLCD.print(buffer, 10, 130); // tabela_textos[151] = "ESTA:"
  } 
  else 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[152])));
    printButton(buffer, 100, 115, 220, 155);  // tabela_textos[152]

    setFont(SMALL, 255, 255, 0, 0, 0, 0); 

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[153])));
    myGLCD.print(buffer, 3, 100); // tabela_textos[153] = "AMBOS OS MODOS"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[150])));
    myGLCD.print(buffer, 3, 115); //tabela_textos[150] =  "DE DOSAGEM  "

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[154])));
    myGLCD.print(buffer, 3, 130); // tabela_textos[154] = "ESTAO OU"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[155])));
    myGLCD.print(buffer, 3, 145); // tabela_textos[155] = "SERAO:"
  }
  if (ativar_desativar_3 == 1)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[147])));
    printButton_verde(buffer, 100, 185, 220, 225); 

    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRect (3, 166, 120, 183);
    myGLCD.fillRect (3, 185, 95, 201);
    myGLCD.fillRect (3, 200, 95, 216);
    myGLCD.fillRect (3, 215, 95, 231);

    setFont(SMALL, 255, 255, 255, 0, 0, 0); 

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[149])));
    myGLCD.print(buffer, 10, 170);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[150])));
    myGLCD.print(buffer, 10, 185);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[151])));
    myGLCD.print(buffer, 10, 200); 
  } 
  else 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[152])));
    printButton(buffer, 100, 185, 220, 225);

    setFont(SMALL, 255, 255, 0, 0, 0, 0); 

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[153])));
    myGLCD.print(buffer, 3, 170); 

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[150])));
    myGLCD.print(buffer, 3, 185);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[154])));
    myGLCD.print(buffer, 3, 200);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[155])));
    myGLCD.print(buffer, 3, 215);
  }
}

//--------------------------------------------- Potência mínima e máxima para a luz noturna -------------------------------- tela =36 
void luz_noturna(boolean refreshAll=false)
{

  if (refreshAll)
  {
    tMaxI = MaxI;
    tMinI = MinI;

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[52])));
    printHeader(buffer); // tabela_textos[52] = "LUZ NOTURNA   255 = 100 %"

    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[180])));
    myGLCD.print(buffer, 90, 70); // "ILUMINACAO MAXIMA:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[156])));
    myGLCD.print(buffer, 90, 170); // "ILUMINACAO MINIMA:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[157])));
    myGLCD.print(buffer, 120, 20); // "LUA CHEIA:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[158])));
    myGLCD.print(buffer, 125, 120); // "LUA NOVA:"

    printButton("-", temM[0], temM[1], temM[2], temM[3], true);      //Lua cheia menos
    printButton("+", temP[0], temP[1], temP[2], temP[3], true);      //Lua cheia mais
    printButton("-", almM[0], almM[1], almM[2], almM[3], true);      //Lua nova menos
    printButton("+", almP[0], almP[1], almP[2], almP[3], true);      //Lua nova mais

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[13])));
    printButton(buffer, salV[0], salV[1], salV[2], salV[3]); // "SALVAR"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "INICIO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
    printButton(buffer, menU[0], menU[1], menU[2], menU[3]);  // "MENU 1";

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
    printButton(buffer, volT[0], volT[1], volT[2], volT[3]);  // tabela_textos[66] = "VOLTAR";
  }

  setFont(LARGE, 255, 255, 255, 0, 0, 0); 
  myGLCD.printNumI(tMaxI, 135, 40);
  myGLCD.printNumI(tMinI, 135, 140);
}

//--------------------------------------------- Menu 2 -------------------------------- tela =37
void menuScreen_2()
{

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[2])));
  printHeader(buffer); // tabela_textos[2] = "MENU 2"
  // printButton("", tanD[0], tanD[1], tanD[2], tanD[3]); // 1º botaão, 1ª coluna
  //  printButton("", tesT[0], tesT[1], tesT[2], tesT[3]); // 2º botão, 1ª coluna 
  //  printButton("", temC[0], temC[1], temC[2], temC[3]); // 3º botão, 1ª coluna
  //  printButton("", graF[0], graF[1], graF[2], graF[3]); // 4º botão, 1ª coluna
  //  printButton("", ledW[0], ledW[1], ledW[2], ledW[3]); // 1º botão, 2ª coluna
  //  printButton("", tpaA[0], tpaA[1], tpaA[2], tpaA[3]); // 2º botão, 2ª coluna
  //  printButton("", dosA[0], dosA[1], dosA[2], dosA[3]); // 3º botão, 2ª coluna
  //  printButton("", wavM[0], wavM[1], wavM[2], wavM[3]); // 4º botão, 2ª coluna
  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "INICIO"
}

//--------------------------------------------- Timers -------------------------------- tela =38
void TimerScreen()
{ 
  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[53])));
  printHeader(buffer); // tabela_textos[53] = "SELECIONE O TIMER"

  if (temporizador_1_ativado == 1) 
  {
    printButton_verde("T 1",7, 22, 56, 50);     // Timer 1 
  }
  else 
  {
    printButton("T 1",7, 22, 56, 50);     // Timer 1 
  }      
  if (temporizador_2_ativado == 1) 
  {
    printButton_verde("T 2",71, 22, 120, 50);     // Timer 2 
  }
  else 
  {
    printButton("T 2",71, 22, 120, 50);     // Timer 2 
  }     
  if (temporizador_3_ativado == 1) 
  {
    printButton_verde("T 3",135, 22, 184, 50);     // Timer 3 
  }
  else 
  {
    printButton("T 3",135, 22, 184, 50);     // Timer 3 
  }    
  if (temporizador_4_ativado == 1) 
  {
    printButton_verde("T 4",199, 22, 248, 50);     // Timer 4 
  }
  else 
  {
    printButton("T 4",199, 22, 248, 50);     // Timer 4 
  }        
  if (temporizador_5_ativado == 1) 
  {
    printButton_verde("T 5",263, 22, 312, 50);     // Timer 5 
  }
  else 
  {
    printButton("T 5",263, 22, 312, 50);     // Timer 5
  } 

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
  printButton_verde(buffer,7, 55, 56, 97);      // Botão ON 1 

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
  printButton_verde(buffer,71, 55, 120, 97);    // Botão ON 2

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
  printButton_verde(buffer,135, 55, 184, 97);   // Botão ON 3

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
  printButton_verde(buffer,199, 55, 248, 97);   // Botão ON 4

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
  printButton_verde(buffer,263, 55, 312, 97);   // Botão ON 5

  myGLCD.setColor(255, 255, 255);  // Retângulos ao redor dos horários
  myGLCD.drawRoundRect(7, 102, 56, 144);      // Botão ON 1 
  myGLCD.drawRoundRect(71, 102, 120, 144);    // Botão ON 2 
  myGLCD.drawRoundRect(135, 102, 184, 144);   // Botão ON 3 
  myGLCD.drawRoundRect(199, 102, 248, 144);   // Botão ON 4 
  myGLCD.drawRoundRect(263, 102, 312, 144);   // Botão ON 5  

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));
  printButton_vermelho(buffer, 8, 149, 55, 191);      // Botão OFF 1 

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));
  printButton_vermelho(buffer, 72, 149, 119, 191);    // Botão OFF 2 

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));
  printButton_vermelho(buffer, 136, 149, 183, 191);   // Botão OFF 3 

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));
  printButton_vermelho(buffer, 200, 149, 247, 191);   // Botão OFF 4 

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));
  printButton_vermelho(buffer, 264, 149, 311, 191);   // Botão OFF 5 

  myGLCD.setColor(255, 255, 255);  // Retângulos ao redor dos horários
  myGLCD.drawRoundRect(7, 196, 56, 238);     // Botão OFF 1 
  myGLCD.drawRoundRect(71, 196, 120, 238);   // Botão OFF 2 
  myGLCD.drawRoundRect(135, 196, 184, 238);  // Botão OFF 3 
  myGLCD.drawRoundRect(199, 196, 248, 238);  // Botão OFF 4 
  myGLCD.drawRoundRect(263, 196, 312, 238);  // Botão OFF 5

  myGLCD.setBackColor(0, 0, 0);

  if (on1_hora < 10) // Timer 1
  { 
    myGLCD.print("0",12, 117); 
    myGLCD.printNumI(on1_hora,21,117);
  }
  else
  {
    myGLCD.printNumI(on1_hora, 12, 117);
  }
  myGLCD.print(":", 29, 117); 

  if (on1_minuto < 10)
  { 
    myGLCD.print("0", 37, 117);
    myGLCD.printNumI(on1_minuto, 46, 117);
  } 
  else 
  { 
    myGLCD.printNumI(on1_minuto, 37,117);
  }      

  if (on2_hora < 10) // Timer 2
  { 
    myGLCD.print("0", 76, 117);
    myGLCD.printNumI(on2_hora ,85, 117);
  }
  else
  {
    myGLCD.printNumI(on2_hora, 76, 117);
  }

  myGLCD.print(":", 93, 117);    

  if (on2_minuto < 10)
  { 
    myGLCD.print("0",101, 117);  
    myGLCD.printNumI(on2_minuto, 110, 117);
  } 
  else 
  { 
    myGLCD.printNumI(on2_minuto,101, 117);
  } 

  if (on3_hora <10) // Timer 3
  { 
    myGLCD.print("0",140, 117);   
    myGLCD.printNumI(on3_hora,149, 117);
  }
  else
  {
    myGLCD.printNumI(on3_hora, 140, 117);
  } 

  myGLCD.print(":",157, 117);          

  if (on3_minuto < 10)
  { 
    myGLCD.print("0",165, 117);  
    myGLCD.printNumI(on3_minuto, 174, 117);
  } 
  else { 
    myGLCD.printNumI(on3_minuto ,165, 117);
  } 

  if (on4_hora < 10) // Timer 4
  { 
    myGLCD.print("0",204, 117); 
    myGLCD.printNumI(on4_hora,213, 117);
  }
  else{
    myGLCD.printNumI(on4_hora,204, 117);
  }

  myGLCD.print(":",221, 117);         

  if (on4_minuto < 10)
  { 
    myGLCD.print("0",229, 117);  
    myGLCD.printNumI(on4_minuto, 238, 117);
  } 
  else 
  { 
    myGLCD.printNumI(on4_minuto, 229, 117);
  } 

  if (on5_hora < 10) // Timer 5
  { 
    myGLCD.print("0",268, 117);  
    myGLCD.printNumI(on5_hora, 277, 117);
  }
  else
  {
    myGLCD.printNumI(on5_hora, 268, 117);
  } 

  myGLCD.print(":",285, 117);          

  if (on5_minuto < 10)
  { 
    myGLCD.print("0", 293, 117); 
    myGLCD.printNumI(on5_minuto, 302, 117);
  } 
  else 
  { 
    myGLCD.printNumI(on5_minuto, 293, 117);
  } 

  if (off1_hora < 10) // Timer 1
  { 
    myGLCD.print("0",12, 211); 
    myGLCD.printNumI(off1_hora, 21, 211);
  }
  else
  {
    myGLCD.printNumI(off1_hora, 12, 211);
  }

  myGLCD.print(":", 29, 210); 

  if (off1_minuto < 10)
  { 
    myGLCD.print("0", 37, 211);
    myGLCD.printNumI(off1_minuto, 46, 211);
  } 
  else 
  { 
    myGLCD.printNumI(off1_minuto, 37,211);
  }      

  if (off2_hora < 10) // Timer 2
  { 
    myGLCD.print("0", 76, 211);
    myGLCD.printNumI(off2_hora , 85, 211);
  }
  else
  {
    myGLCD.printNumI(off2_hora, 76, 211);
  }

  myGLCD.print(":", 93, 211);    

  if (off2_minuto < 10)
  { 
    myGLCD.print("0",101, 211);  
    myGLCD.printNumI(off2_minuto, 110, 211);
  } 
  else 
  { 
    myGLCD.printNumI(off2_minuto,101, 211);
  } 

  if (off3_hora <10) // Timer 3
  { 
    myGLCD.print("0", 140, 211);   
    myGLCD.printNumI(off3_hora, 149, 211);
  }
  else
  {
    myGLCD.printNumI(off3_hora, 140, 211);
  } 

  myGLCD.print(":", 157, 211);          

  if (off3_minuto < 10)
  { 
    myGLCD.print("0", 165, 211);  
    myGLCD.printNumI(off3_minuto, 174, 211);
  } 
  else 
  { 
    myGLCD.printNumI(off3_minuto, 165, 211);
  } 

  if (off4_hora < 10) // Timer 4
  { 
    myGLCD.print("0", 204, 211); 
    myGLCD.printNumI(off4_hora, 213, 211);
  }
  else
  {
    myGLCD.printNumI(off4_hora, 204, 211);
  }

  myGLCD.print(":", 221, 211);         

  if (off4_minuto < 10)
  { 
    myGLCD.print("0", 229, 211);  
    myGLCD.printNumI(off4_minuto, 238, 211);
  } 
  else 
  { 
    myGLCD.printNumI(off4_minuto, 229, 211);
  } 

  if (off5_hora < 10) // Timer 5
  { 
    myGLCD.print("0", 268, 211);  
    myGLCD.printNumI(off5_hora, 277, 211);
  }
  else
  {
    myGLCD.printNumI(off5_hora, 268, 211);
  } 

  myGLCD.print(":", 285, 211);          

  if (off5_minuto < 10)
  { 
    myGLCD.print("0", 293, 211); 
    myGLCD.printNumI(off5_minuto, 302, 211);
  } 
  else { 
    myGLCD.printNumI(off5_minuto, 293, 211);
  }

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // Volta ao menu 1. // "MENU 1";

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // Volta ao início.  // "INICIO"
} 
//--------------------------------------------- Configurar timers -------------------------------- tela =39
void config_timer(boolean refreshAll=false)
{
  if( refreshAll == true)
  {
    on1_minuto_temp2 = on1_minuto;
    on1_hora_temp2 = on1_hora;
    on2_minuto_temp2 = on2_minuto;
    on2_hora_temp2 = on2_hora;
    on3_minuto_temp2 = on3_minuto;
    on3_hora_temp2 = on3_hora;
    on4_minuto_temp2 = on4_minuto;
    on4_hora_temp2 = on4_hora;
    on5_minuto_temp2 = on5_minuto;
    on5_hora_temp2 = on5_hora ;
    off1_minuto_temp2 = off1_minuto;
    off1_hora_temp2 = off1_hora;
    off2_minuto_temp2 = off2_minuto;
    off2_hora_temp2 = off2_hora;
    off3_minuto_temp2 = off3_minuto;
    off3_hora_temp2 = off3_hora;
    off4_minuto_temp2 = off4_minuto;
    off4_hora_temp2 = off4_hora;
    off5_minuto_temp2 = off5_minuto;
    off5_hora_temp2 = off5_hora;
    temporizador_1_ativado_temp2 = temporizador_1_ativado;
    temporizador_2_ativado_temp2 = temporizador_2_ativado;
    temporizador_3_ativado_temp2 = temporizador_3_ativado;
    temporizador_4_ativado_temp2 = temporizador_4_ativado;
    temporizador_5_ativado_temp2 = temporizador_5_ativado;

    if(bitRead(temporizador,1) == true)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[54])));
      printHeader(buffer); // tabela_textos[54] = "CONFIGURAR TIMER 1"
    }
    else if(bitRead(temporizador,2) == true)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[55])));
      printHeader(buffer); // tabela_textos[55] = "CONFIGURAR TIMER 2"
    }
    else  if(bitRead(temporizador,3) == true)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[56])));
      printHeader(buffer); // tabela_textos[56] = "CONFIGURAR TIMER 3"
    }
    else if(bitRead(temporizador,4) == true)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[57])));
      printHeader(buffer); // tabela_textos[57] = "CONFIGURAR TIMER 4"
    } 
    else if(bitRead(temporizador,5) == true)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[58])));
      printHeader(buffer); // tabela_textos[58] ="CONFIGURAR TIMER 5"
    }

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[161])));
    printButton_verde(buffer, 8, 17, 142, 34); // "LIGAR TIMER"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[162])));
    printButton_vermelho(buffer, 173, 17, 312, 34); // "DESLIGAR TIMER"

    printButton("+", 21, 45, 65, 88, true);    // Botão para cima
    printButton("+", 89, 45, 133, 88, true);    // Botão para cima
    printButton("-", 21, 135, 65, 178, true); // Botão para baixo
    printButton("-", 89, 135, 133, 178, true); // Botão para baixo

    printButton("+", 187, 45, 231, 88, true);    // Botão para cima
    printButton("+", 255, 45, 299, 88, true);    // Botão para cima
    printButton("-", 187, 135, 231, 178, true); // Botão para baixo
    printButton("-", 255, 135, 299, 178, true); // Botão para baixo

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
    printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // Volta ao menu 1.  // "MENU 1";

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // Volta ao início. // "INICIO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
    printButton(buffer, volT[0], volT[1], volT[2], volT[3]); // Volta ao menu selecionar timer. // "VOLTAR"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[13])));
    printButton(buffer, salV[0], salV[1], salV[2], salV[3]); // Salva as modificações. // "SALVAR"

    setFont(LARGE, 255, 255, 255, 0, 0, 0);          
    myGLCD.print(":",70, 103);
    myGLCD.print(":",236, 103);
  }
  setFont(LARGE, 255, 255, 255, 0, 0, 0);

  if(bitRead(temporizador,1) == true)
  {
    if (on1_hora_temp2 < 10)
    {
      myGLCD.print("0",27, 100);           
      myGLCD.printNumI(on1_hora_temp2, 44, 100);
    } 
    else 
    {
      myGLCD.printNumI(on1_hora_temp2, 27, 100);
    }

    if (on1_minuto_temp2 < 10)
    {                            
      myGLCD.print("0", 95, 100);
      myGLCD.printNumI(on1_minuto_temp2, 112, 100);
    } 
    else 
    {
      myGLCD.printNumI(on1_minuto_temp2, 95, 100);
    }

    if (off1_hora_temp2 < 10)
    {
      myGLCD.print("0",193, 100);            
      myGLCD.printNumI(off1_hora_temp2, 210, 100);
    } 
    else 
    {
      myGLCD.printNumI(off1_hora_temp2, 193, 100);
    }

    if (off1_minuto_temp2 < 10)
    {
      myGLCD.print("0",262, 100); 
      myGLCD.printNumI(off1_minuto_temp2, 279, 100);
    } 
    else 
    {
      myGLCD.printNumI(off1_minuto_temp2, 262, 100);
    }
    if (temporizador_1_ativado_temp2 == 1) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[147])));
      printButton_verde(buffer, domI[0]-20, domI[1], domI[2]+20, domI[3]); // Ativado 120, 193, 200, 233
    }
    else 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[148])));
      printButton(buffer, domI[0]-20, domI[1], domI[2]+20, domI[3]); // Desativado
    } 
  }
  else if(bitRead(temporizador,2) == true)
  {
    if (on2_hora_temp2 < 10)
    {
      myGLCD.print("0",27, 100);           
      myGLCD.printNumI(on2_hora_temp2, 44, 100);
    } 
    else 
    {
      myGLCD.printNumI(on2_hora_temp2, 27, 100);
    }

    if (on2_minuto_temp2 < 10)
    {                            
      myGLCD.print("0", 95, 100);
      myGLCD.printNumI(on2_minuto_temp2, 112, 100);
    } 
    else 
    {
      myGLCD.printNumI(on2_minuto_temp2, 95, 100);
    }

    if (off2_hora_temp2 < 10)
    {
      myGLCD.print("0",193, 100);            
      myGLCD.printNumI(off2_hora_temp2, 210, 100);
    } 
    else 
    {
      myGLCD.printNumI(off2_hora_temp2, 193, 100);
    }

    if (off2_minuto_temp2 < 10)
    {
      myGLCD.print("0",262, 100); 
      myGLCD.printNumI(off2_minuto_temp2, 279, 100);
    } 
    else 
    {
      myGLCD.printNumI(off2_minuto_temp2, 262, 100);
    } 
    if (temporizador_2_ativado_temp2 == 1) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[147])));
      printButton_verde(buffer, domI[0]-20, domI[1], domI[2]+20, domI[3]); // Ativado
    }
    else 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[148])));
      printButton(buffer, domI[0]-20, domI[1], domI[2]+20, domI[3]); // Desativado
    }
  }
  else  if(bitRead(temporizador,3) == true)
  {
    if (on3_hora_temp2 < 10)
    {
      myGLCD.print("0",27, 100);           
      myGLCD.printNumI(on3_hora_temp2, 44, 100);
    } 
    else 
    {
      myGLCD.printNumI(on3_hora_temp2, 27, 100);
    }

    if (on3_minuto_temp2 < 10)
    {                            
      myGLCD.print("0", 95, 100);
      myGLCD.printNumI(on3_minuto_temp2, 112, 100);
    } 
    else 
    {
      myGLCD.printNumI(on3_minuto_temp2, 95, 100);
    }

    if (off3_hora_temp2 < 10)
    {
      myGLCD.print("0",193, 100);            
      myGLCD.printNumI(off3_hora_temp2, 210, 100);
    } 
    else 
    {
      myGLCD.printNumI(off3_hora_temp2, 193, 100);
    }

    if (off3_minuto_temp2 < 10)
    {
      myGLCD.print("0",262, 100); 
      myGLCD.printNumI(off3_minuto_temp2, 279, 100);
    } 
    else 
    {
      myGLCD.printNumI(off3_minuto_temp2, 262, 100);
    } 
    if (temporizador_3_ativado_temp2 == 1) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[147])));
      printButton_verde(buffer, domI[0]-20, domI[1], domI[2]+20, domI[3]); // Ativado
    }
    else 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[148])));
      printButton(buffer, domI[0]-20, domI[1], domI[2]+20, domI[3]); // Desativado
    }
  }
  else if(bitRead(temporizador,4) == true)
  {
    if (on4_hora_temp2 < 10)
    {
      myGLCD.print("0",27, 100);           
      myGLCD.printNumI(on4_hora_temp2, 44, 100);
    } 
    else 
    {
      myGLCD.printNumI(on4_hora_temp2, 27, 100);
    }

    if (on4_minuto_temp2 < 10)
    {                            
      myGLCD.print("0", 95, 100);
      myGLCD.printNumI(on4_minuto_temp2, 112, 100);
    } 
    else 
    {
      myGLCD.printNumI(on4_minuto_temp2, 95, 100);
    }

    if (off4_hora_temp2 < 10)
    {
      myGLCD.print("0",193, 100);            
      myGLCD.printNumI(off4_hora_temp2, 210, 100);
    } 
    else 
    {
      myGLCD.printNumI(off4_hora_temp2, 193, 100);
    }

    if (off4_minuto_temp2 < 10)
    {
      myGLCD.print("0",262, 100); 
      myGLCD.printNumI(off4_minuto_temp2, 279, 100);
    } 
    else 
    {
      myGLCD.printNumI(off4_minuto_temp2, 262, 100);
    }
    if (temporizador_4_ativado_temp2 == 1) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[147])));
      printButton_verde(buffer, domI[0]-20, domI[1], domI[2]+20, domI[3]); // Ativado
    }
    else 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[148])));
      printButton(buffer, domI[0]-20, domI[1], domI[2]+20, domI[3]); // Desativado
    }
  } 
  if(bitRead(temporizador,5) == true)
  {
    if (on5_hora_temp2 < 10)
    {
      myGLCD.print("0",27, 100);           
      myGLCD.printNumI(on5_hora_temp2, 44, 100);
    } 
    else 
    {
      myGLCD.printNumI(on5_hora_temp2, 27, 100);
    }

    if (on5_minuto_temp2 < 10)
    {                            
      myGLCD.print("0", 95, 100);
      myGLCD.printNumI(on5_minuto_temp2, 112, 100);
    } 
    else 
    {
      myGLCD.printNumI(on5_minuto_temp2, 95, 100);
    }

    if (off5_hora_temp2 < 10)
    {
      myGLCD.print("0",193, 100);            
      myGLCD.printNumI(off5_hora_temp2, 210, 100);
    } 
    else 
    {
      myGLCD.printNumI(off5_hora_temp2, 193, 100);
    }

    if (off5_minuto_temp2 < 10)
    {
      myGLCD.print("0",262, 100); 
      myGLCD.printNumI(off5_minuto_temp2, 279, 100);
    } 
    else 
    {
      myGLCD.printNumI(off5_minuto_temp2, 262, 100);
    }  
    if (temporizador_5_ativado_temp2 == 1) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[147])));
      printButton_verde(buffer, domI[0]-20, domI[1], domI[2]+20, domI[3]); // Ativado
    }
    else 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[148])));
      printButton(buffer, domI[0]-20, domI[1], domI[2]+20, domI[3]); // Desativado
    }
  }
}

//--------------------------------------------- Configurar leds -------------------------------- tela =40
void config_leds()
{
  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[202])));
  printHeader(buffer); // tabela_textos[2] = "CONFIGURAR LEDS"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[4])));
  printButton(buffer, tanD[0], tanD[1], tanD[2], tanD[3]); // 1º botaão, 1ª coluna 

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[7])));
  printButton(buffer, tesT[0], tesT[1], tesT[2], tesT[3]); // 2º botão, 1ª coluna 

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[159])));
  printButton(buffer, temC[0], temC[1], temC[2], temC[3]); // 3º botão, 1ª coluna 

  //  printButton("", graF[0], graF[1], graF[2], graF[3]); // 4º botão, 1ª coluna
  //  printButton("", ledW[0], ledW[1], ledW[2], ledW[3]); // 1º botão, 2ª coluna
  //  printButton("", tpaA[0], tpaA[1], tpaA[2], tpaA[3]); // 2º botão, 2ª coluna
  //  printButton("", dosA[0], dosA[1], dosA[2], dosA[3]); // 3º botão, 2ª coluna
  //  printButton("", wavM[0], wavM[1], wavM[2], wavM[3]); // 4º botão, 2ª coluna
  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "INICIO"
}





