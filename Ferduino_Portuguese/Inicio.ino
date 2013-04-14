//---------------------------------------Tela inicial ----------------------------------------------tela =0
void mainScreen(boolean refreshAll=false)
{
  int ledLevel, s, u;
  String oldval, rtc1, rtcm;
  oldval = day;
  day = String(t.date);                             //Atualiza se a data for diferente
  int offset = 0;

  setFont(SMALL, 255, 255, 0, 0, 0, 0);
  myGLCD.print(rtc.getTimeStr(FORMAT_LONG), 315, 227);  

  if ((oldval != day) || refreshAll)
  {
    setFont(SMALL, 255, 255, 0, 0, 0, 0);
    myGLCD.print(rtc.getDOWStr(FORMAT_LONG), 10, 227);
    myGLCD.printNumI(t.date, 75, 227);
    myGLCD.print("DE", 95, 227);
    myGLCD.print(rtc.getMonthStr(FORMAT_LONG), 125, 227);
    myGLCD.print("DE", 205, 227);
    myGLCD.printNumI(t.year, 225, 227);

    char bufferLP[16];
    LP.toCharArray(bufferLP, 16);

    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRect(98, 213, 235, 226); //Apaga descrição da fase lunar.

    myGLCD.setColor(255, 255, 255);
    myGLCD.print(bufferLP, 98, 213); //Escreve descrição da fase lunar

    float lunarCycle = moonPhase(t.year,t.mon, t.date); //get a value for the lunar cycle

      if ((lunarCycle*100) < 0) //Print % of Full to LCD
    { 
      myGLCD.print(" 0.00", 240, 213); 
    }
    else 
    { 
      myGLCD.printNumF(lunarCycle*100, 1, 240, 213);
    }

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[181])));
    myGLCD.print(buffer, 280, 213); // tabela_textos[181] = "% ILUMINADA"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[182])));
    myGLCD.print(buffer, 10, 213); // tabela_textos[182] = "FASE LUNAR:"
  }

  if ( refreshAll == true)                                  //Desenha elementos fixos
  {
    myGLCD.setColor(196, 136, 17);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[30])));
    myGLCD.print(buffer, 50, 10); // tabela_textos[30] = "POTENCIA DOS LEDS"

    myGLCD.setColor(192, 236, 255);

    myGLCD.print("100", 24, 17);  

    for (int i = 0; i < 90; i += 10)
    {
      myGLCD.printNumI(90-i, 32, 28 + offset);   // 90 até 10
      offset += 11;
    }

    myGLCD.print("0", 40, 127);

    myGLCD.setColor(255, 255, 255);

    myGLCD.drawRect(50, 138, 187, 138);       // Eixo X
    myGLCD.drawRect(50, 28, 50, 138);         // Eixo Y

    for (int i=0; i<10; i++)
    {
      myGLCD.drawLine(51,(i*11)+28,55,(i*11)+28);
    } // Marcador grande 
    myGLCD.setColor(190, 190, 190);  

    for (int i=0; i<10; i++)
    {
      myGLCD.drawLine(51,(i*11)+34,53,(i*11)+34);
    } // Marcador pequeno

    for (int i=0; i<10; i++)
    {
      myGLCD.drawLine(79,(i*11)+28,187,(i*11)+28);
    }// Grade
    
    myGLCD.setColor(255, 255, 255);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[183])));
    myGLCD.print(buffer, 212, 14);  // tabela_textos[183] = "T.DISSIPADOR:"  

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[184])));
    myGLCD.print(buffer, 212, 28); // tabela_textos[184] = "TEMP. AGUA:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[185])));
    myGLCD.print(buffer, 212, 42); // tabela_textos[185] = "PH DO AQUARIO:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[186])));
    myGLCD.print(buffer, 212, 56); // tabela_textos[186] =  "PH DO REATOR:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[187])));
    myGLCD.print(buffer, 212, 70); // tabela_textos[187] = "DENSIDADE:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[188])));
    myGLCD.print(buffer, 212, 84); // tabela_textos[188] = "ORP:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[189])));
    myGLCD.print(buffer, 212, 98); // tabela_textos[189] = "CHILLER:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[190])));
    myGLCD.print(buffer, 212, 112); // tabela_textos[190] = "AQUECEDOR:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[191])));
    myGLCD.print(buffer, 212, 126); // tabela_textos[191] = "REATOR:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[192])));
    myGLCD.print(buffer, 212, 140); // tabela_textos[192] = "OZONIO:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[193])));
    myGLCD.print(buffer, 212, 154); // tabela_textos[193] = "REPOSICAO:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[194])));
    myGLCD.print(buffer, 212, 168); // tabela_textos[194] = "NIVEL:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[195])));
    myGLCD.print(buffer, 212, 182); // tabela_textos[195] = "TPA:" // Troca de Água Parcial
    
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[89])));
    myGLCD.print(buffer, 212, 195); // tabela_textos[89] = "CONSUMO:"    

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[31])));
    myGLCD.print(buffer, 12, 144); // tabela_textos[31] = "TIMER 1:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[77])));
    myGLCD.print(buffer, 12, 156); // tabela_textos[77] = "TIMER 2:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[78])));
    myGLCD.print(buffer, 12, 168); // tabela_textos[78] = "TIMER 3:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[79])));
    myGLCD.print(buffer, 12, 180); // tabela_textos[79] = "TIMER 4:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[80])));
    myGLCD.print(buffer, 12, 192); // tabela_textos[80] = "TIMER 5:"

    myGLCD.setColor(0, 255, 0);

    myGLCD.drawCircle(359, 11, 2);                  // Unidade t. dissipador
    myGLCD.print("C", 362, 14);

    myGLCD.drawCircle(357, 25, 2);                  // Unidade t. água
    myGLCD.print("C", 360, 28);                     // Unidade t. água

    myGLCD.print("G/L", 332, 70);                   // Unidade densidade
    myGLCD.print("MV", 280, 84);                    // Unidade ORP
    myGLCD.print("KWH", 310, 195);                    // Unidade Consumo de energia


    myGLCD.setColor(161, 127, 73);                  
    myGLCD.drawRect(7, 5, 199, 208);                // Desenhar retângulos
    myGLCD.drawRect(206, 5, 392, 208);
  } // Fim do refreshAll

  if ((whiteLed != wled_out) || refreshAll)  // Atualiza gráfico led branco    
  {
    whiteLed = wled_out;
    ledLevel = LedToPercent(wled_out);

    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRect(128, 144, 185, 156);   // Apaga potência anterior

    myGLCD.setColor(cor_canal1[0], cor_canal1[1], cor_canal1[2]);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[1])));
    myGLCD.print(buffer, 128, 144); // nome_canal[1] = "BRA"

    offset = map(ledLevel, 100, 0, 28, 137);

    myGLCD.print(":", 152, 144);
    myGLCD.fillRect(59, offset, 79, 137);
    myGLCD.print(String(ledLevel), 160, 144);
    myGLCD.print("%", 186, 144); 

    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRect(59, offset, 79, 28);      // Apaga barra anterior
  }
  if ((blueLed != bled_out) || refreshAll)       // Atualiza gráfico led azul
  {
    blueLed = bled_out;
    ledLevel = LedToPercent(bled_out);

    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRect(128, 156, 185, 168);     // Apaga potência anterior

    myGLCD.setColor(cor_canal2[0], cor_canal2[1], cor_canal2[2]);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[2])));
    myGLCD.print(buffer, 128, 156); // nome_canal[2] = "AZU"

    offset = map(ledLevel, 100, 0, 28, 137);
    myGLCD.print(":", 152, 156);
    myGLCD.fillRect(85, offset, 105, 137);
    myGLCD.print(String(ledLevel), 160, 156); 
    myGLCD.print("%", 186, 156); 

    myGLCD.setColor(0, 0, 0);

    myGLCD.fillRect(85, offset, 105, 28);       // Apaga barra anterior
  }
  if ((azulroyalLed != rbled_out) || refreshAll)      // Atualiza gráfico led azul royal
  {
    azulroyalLed = rbled_out;
    ledLevel = LedToPercent(rbled_out);

    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRect(128, 168, 185, 180);     // Apaga potência anterior

    myGLCD.setColor(cor_canal3[0], cor_canal3[1], cor_canal3[2]);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[3])));
    myGLCD.print(buffer, 128, 168); // nome_canal[3] = "AZR"

    offset = map(ledLevel, 100, 0, 28, 137);
    myGLCD.print(":", 152, 168);
    myGLCD.fillRect(111, offset, 131, 137);
    myGLCD.print(String(ledLevel), 160, 168); 
    myGLCD.print("%", 186, 168); 

    myGLCD.setColor(0, 0, 0);

    myGLCD.fillRect(111, offset, 131, 28);      // Apaga barra anterior
  }
  if ((vermelhoLed != rled_out) || refreshAll)    // Atualiza gráfico led  vermelho 
  {
    vermelhoLed = rled_out;
    ledLevel = LedToPercent(rled_out);

    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRect(128, 180, 185, 192);     // Apaga potência anterior

    myGLCD.setColor(cor_canal4[0], cor_canal4[1], cor_canal4[2]);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[4])));
    myGLCD.print(buffer, 128, 180); // nome_canal[4] = "VER"

    offset = map(ledLevel, 100, 0, 28, 137);
    myGLCD.print(":", 152, 180);
    myGLCD.fillRect(137, offset, 157, 137);
    myGLCD.print(String(ledLevel), 160, 180); 
    myGLCD.print("%", 186, 180); 

    myGLCD.setColor(0, 0, 0);

    myGLCD.fillRect(137, offset, 157, 28);      // Apaga barra anterior
  }
  if ((violetaLed != uvled_out) || refreshAll)      // Atualiza gráfico led violeta
  {
    violetaLed = uvled_out;
    ledLevel = LedToPercent(uvled_out);

    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRect(128, 192, 185, 204);      // Apaga potência anterior
    
    myGLCD.setColor(cor_canal5[0], cor_canal5[1], cor_canal5[2]);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[5])));
    myGLCD.print(buffer, 128, 192); // nome_canal[5] = "VIO"

    offset = map(ledLevel, 100, 0, 28, 137);
    myGLCD.print(":", 152, 192);
    myGLCD.fillRect(163, offset, 183, 137);
    myGLCD.print(String(ledLevel), 160, 192); 
    myGLCD.print("%", 186, 192); 

    myGLCD.setColor(0, 0, 0);

    myGLCD.fillRect(163, offset, 183, 28);       // Apaga barra anterior
  }  

  myGLCD.setColor(0, 0, 0);                      
  myGLCD.fillRect(313, 14, 353, 26);                // Apagar temperatura dissipador
  myGLCD.fillRect(303, 32, 320, 40);                // Apagar temperatura agua
  myGLCD.fillRect(324, 42, 390, 54);                // Apagar PH do aquario
  myGLCD.fillRect(318, 56, 390, 68);                // Apagar PH do reator
  myGLCD.fillRect(288, 70, 330, 82);                // Apagar densidade
  myGLCD.fillRect(245, 84, 277, 96);                // Apagar ORP

  myGLCD.fillRect(279, 98, 330, 110);               // Apagar noticia de chiller ligado/desligado
  myGLCD.fillRect(289, 112, 350, 124);              // Apagar noticia de aquecedor ligado/desligado
  myGLCD.fillRect(270, 126, 320, 138);              // Apagar noticia de reator ligado/desligado
  myGLCD.fillRect(270, 140, 320, 152);              // Apagar noticia de ozonio ligado/desligado
  myGLCD.fillRect(289, 154, 350, 166);              // Apagar noticia de reposicao ligado/desligado
  myGLCD.fillRect(266, 168, 390, 180);              // Apagar noticia de nivel normal/anormal
  myGLCD.fillRect(250, 182, 365, 193);              // Apagar noticia de TPA ligado/desligado
  myGLCD.fillRect(280, 195, 309, 207);              // Apaga consumo de energia

  myGLCD.fillRect(80, 144, 110, 156);              // Apagar noticia de Timers 1 ligado/desligado
  myGLCD.fillRect(80, 156, 110, 168);              // Apagar noticia de Timers 2 ligado/desligado
  myGLCD.fillRect(80, 168, 110, 180);              // Apagar noticia de Timers 3 ligado/desligado
  myGLCD.fillRect(80, 180, 110, 192);              // Apagar noticia de Timers 4 ligado/desligado
  myGLCD.fillRect(80, 192, 110, 204);              // Apagar noticia de Timers 5 ligado/desligado

  myGLCD.setColor(0, 255, 0);  
  myGLCD.printNumF(tempH, 1, 316, 14);   // Temperatura dissipador
  myGLCD.printNumF(tempC, 1, 302, 28);   // Temperatura da agua
  myGLCD.printNumF(PHA, 2, 327, 42);     // PH aqua
  myGLCD.printNumF(PHR, 2, 316, 56);    // PH reator
  myGLCD.printNumI(DEN, 293, 70);        // Densidade
  myGLCD.printNumI(ORP, 245, 84);       // ORP 
  myGLCD.printNumI(consumo, 280, 195);  // Consumo de energia

  myGLCD.setColor(255, 0, 0);

  if (bitRead(status_parametros,2)==true) 
  {                               
    myGLCD.printNumF( tempC, 1, 302, 28);     // Temperatura em vermelho
  }  
  if (bitRead(status_parametros,3) == true) 
  {                               
    myGLCD.printNumF(PHA, 2, 327, 42);       // PH do aquario em vermelho
  }    
  if (bitRead(status_parametros,6) == true) 
  {                                
    myGLCD.printNumF(PHR, 2, 316, 56);       // PH do reator em vermelho
  }   
  if (bitRead(status_parametros,4) == true) 
  {                                
    myGLCD.printNumI(DEN, 293, 70);           // Densidade em vermelho
  }
  if (bitRead(status_parametros_1,0) == true) 
  {       
    myGLCD.printNumI(ORP, 245, 84);           // ORP em vermelho
  }  
  if (bitRead(status_parametros,0) == true) 
  {
    myGLCD.setColor(0, 130, 255);
    myGLCD.print("ON", 279, 98);           // Chiller ligado
  }
  else 
  {
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("OFF", 279, 98);          // Chiller desligado
  }
  if (bitRead(status_parametros,1) == true) 
  {
    myGLCD.setColor(0, 130, 255);
    myGLCD.print("ON", 294, 112);           // Aquecedor ligado
  } 
  else  
  {
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("OFF", 294, 112);          // Aquecedor desligado
  } 
  if (bitRead(status_parametros,5)== true) 
  {              
    myGLCD.setColor(0, 130, 255);
    myGLCD.print("ON", 270, 126);           // Reator ligado
  } 
  else  
  {              
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("OFF", 270, 126);          // Reator desligado
  }
  if (bitRead(status_parametros,7) == true) 
  {             
    myGLCD.setColor(0, 130, 255);
    myGLCD.print("ON", 270, 140);           // Ozonio ligado
  } 
  else
  {                
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("OFF", 270, 140);          // ozonio desligado
  }
  if (ato==true) 
  {             
    myGLCD.setColor(0, 130, 255);
    myGLCD.print("ON", 294, 154);           // Reposição ligada
  }
  else
  {             
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("OFF", 294, 154);          // Reposição desligada
  }
  if (nivel_status==true) 
  {             
    myGLCD.setColor(255, 0, 0);
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[196])));
    myGLCD.print(buffer, 265, 168);         // Nivel baixo em vermelho // tabela_textos[196] = "BAIXO!"
  }
  else 
  {             
    myGLCD.setColor(255, 0, 0);
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[197])));
    myGLCD.print(buffer, 265, 168);          // Nível nornal // tabela_textos[197] = "NORMAL"
  } 
  if ((bitRead(tpa_status,1)== true) && (bitRead(tpa_status,2)== false))
  {             
    myGLCD.setColor(0, 130, 255);
    myGLCD.print("ON", 250, 182);           // TPA em andamento
  }
  else if ((bitRead(tpa_status,1) == false) && (bitRead(tpa_status,2) == false))
  {             
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("OFF", 250, 182);           // TPA não esta em andamento
  }
  if (bitRead(tpa_status,2) == true)
  {             
    myGLCD.setColor(255, 0, 0);
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[86])));
    myGLCD.print(buffer, 250, 182);          // Sinaliza falha durante uma TPA // tabela_textos[86] = "FALHA!"
  }
  if (bitRead(temporizador_status,1) == true) 
  {             
    myGLCD.setColor(0, 130, 255);
    myGLCD.print("ON", 80, 144);           // Timer 1 ligado
  }
  else
  {             
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("OFF", 80, 144);          // Timer 1 desligado
  }

  if (bitRead(temporizador_status,2) == true) 
  {             
    myGLCD.setColor(0, 130, 255);
    myGLCD.print("ON", 80, 156);           // Timer 2 ligado
  }
  else
  {             
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("OFF", 80, 156);          // Timer 2 desligado
  }
  if (bitRead(temporizador_status,3) == true) 
  {             
    myGLCD.setColor(0, 130, 255);
    myGLCD.print("ON", 80, 168);           // Timer 3 ligado
  }
  else
  {             
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("OFF", 80, 168);          // Timer 3 desligado
  }
  if (bitRead(temporizador_status,4) == true) 
  {             
    myGLCD.setColor(0, 130, 255);
    myGLCD.print("ON", 80, 180);           // Timer 4 ligado
  }
  else
  {             
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("OFF", 80, 180);          // Timer 4 desligado
  }
  if (bitRead(temporizador_status,5) == true) 
  {             
    myGLCD.setColor(0, 130, 255);
    myGLCD.print("ON", 80, 192);           // Timer 5 ligado
  }
  else
  {             
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("OFF", 80, 192);          // Timer 5 desligado
  }  
}




