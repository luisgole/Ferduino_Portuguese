//---------------------------------------------------------------------------------------------
void checkTempC()
{ 
  contador_temp ++;

  sensors.requestTemperatures();   // call sensors.requestTemperatures() to issue a global 
  // temperature request to all devices on the bus
  temperatura_agua_temp += (sensors.getTempC(sensor_agua));  //read water temperature
  temperatura_dissipador_temp += (sensors.getTempC(sensor_dissipador));   //read heatsink temperature

  if(contador_temp == 12)
  {
    tempC = temperatura_agua_temp / 12;
    tempH = temperatura_dissipador_temp / 12;
    contador_temp = 0;
    temperatura_agua_temp = 0;
    temperatura_dissipador_temp = 0;
  }

  if (tempC < (setTempC + offTempC + alarmTempC) && tempC > (setTempC - offTempC - alarmTempC)) 
  {
    bitWrite(status_parametros,2,0);
   // tempAflag = false;
  }

  if (alarmTempC > 0)                        //turn on alarm
  {
    if ((tempC >= (setTempC + offTempC + alarmTempC)) || (tempC <= (setTempC - offTempC - alarmTempC)))
    {
      bitWrite(status_parametros,2,1);
     // tempAflag=true;
    }
  }

  if ((tempC < (setTempC + offTempC)) && (tempC > (setTempC - offTempC)))          //turn off cooler/heater
  {
    bitWrite(status_parametros,0,0);
    bitWrite(status_parametros,1,0);
    //tempCflag = false;
    //tempHflag = false;
    digitalWrite(aquecedorPin, LOW);
    digitalWrite(chillerPin, LOW);   
  }

  if (offTempC > 0)
  {
    if ((tempC > (setTempC + offTempC)))            //liga o chiller
    {
      bitWrite(status_parametros,0,1);
    //  tempCflag = true;
      digitalWrite(chillerPin, HIGH);
    }
    if ((tempC < (setTempC - offTempC)))             //liga o aquecedor
    {
      bitWrite(status_parametros,1,1);
    //  tempHflag=true;
      digitalWrite(aquecedorPin, HIGH);
    }
  }

  if ((tempC > 50) || (tempC <10))
  {
    bitWrite(status_parametros,0,0);
    bitWrite(status_parametros,1,0);
   // tempCflag = false;
   // tempHflag = false;
    digitalWrite(aquecedorPin, LOW);
    digitalWrite(chillerPin, LOW);
  }


  int tempval = int(tempH * 10);
  int fanSpeed = map(tempval, (HtempMin * 10), (HtempMax * 10), 0, 255);       //---------Controle de velocidade das ventoinhas do dissipador
  if (fanSpeed <= 0)                                                          //30°c = 0 volts -- 40°c = 5 volts
    fanSpeed = 0;                                                          
  if (fanSpeed > 255)
    fanSpeed = 255;
  analogWrite(fanPin, fanSpeed);
}

void check_nivel() //verifica o nivel do reef e fish only.
{
  if((analogRead(sensor5) > 400) ||(analogRead(sensor6) > 400) || (analogRead(sensor2) < 100) && (bitRead(tpa_status,1) == false))
  {
    nivel_status =true; //sinaliza nivel baixo em um dos aquários ou sump
  }
  else 
  {
    nivel_status =false; //sinaliza nivel normal dos aquários e sump
  }
}

void check_PH_reator()
{ 
  if (PHR < (setPHR + offPHR + alarmPHR) && PHR > (setPHR - offPHR - alarmPHR)) 
  {
    bitWrite(status_parametros,6,0);
   // PHRAflag = false;
  }
  if (alarmPHR > 0)           // liga o alarme
  {
    if ((PHR > (setPHR + offPHR + alarmPHR)) || (PHR <= (setPHR - offPHR - alarmPHR)))
    {
      bitWrite(status_parametros,6,1);
    //  PHRAflag=true;
    }
  }
  if (PHR < setPHR)       
  {
      bitWrite(status_parametros,5,0);
  //  PHRflag = false;
    digitalWrite(reatorPin, LOW);  // Desliga co2 do reator de calcio
  }
  if (offPHR > 0)
  {
    if (PHR > setPHR)    
    {
      bitWrite(status_parametros,5,1);
//      PHRflag = true;
      digitalWrite(reatorPin, HIGH); // Liga co2 do reator de calcio
    }
  }
  if ((PHR < 4) || (PHR > 10))
  {
    bitWrite(status_parametros,5,0);
//    PHRflag = false;
    digitalWrite(reatorPin, LOW);  // Desliga co2 do reator de calcio
  }     
}

void check_PH_aquario()
{ 
  if (PHA < (setPHA + offPHA + alarmPHA) && PHA > (setPHA - offPHA - alarmPHA)) 
  {
    bitWrite(status_parametros,3,0);
   // PHAAflag = false;
  }
  if (alarmPHA > 0)           // liga o alarme
  {
    if ((PHA >= (setPHA + offPHR + alarmPHA)) || (PHA <= (setPHA - offPHA - alarmPHA)))
    {
    bitWrite(status_parametros,3,1);
    //  PHAAflag=true;
    }
  }
  if (PHA < (setPHA - offPHA)) // Se PH do aquario menor que o desejado menos a variacao permitida. 
  {
    bitWrite(status_parametros,5,0);
   // PHRflag = false;
    digitalWrite(reatorPin, LOW);  // Desliga co2 do reator de calcio
  }  
}

void check_densidade()
{ 
  if (DEN < (setDEN + offDEN + alarmDEN) && DEN > (setDEN - offDEN - alarmDEN)) 
  {
   bitWrite(status_parametros,4,0);
  //  DENAflag = false;
  }
  if (alarmDEN > 0)           // liga o alarme
  {
    if ((DEN >= (setDEN + offPHR + alarmDEN)) || (DEN <= (setDEN - offDEN - alarmDEN)))
    {
      bitWrite(status_parametros,4,1);
    //  DENAflag=true;
    }
  }   
}

void check_ORP()
{ 
  if (ORP < (setORP + offORP + alarmORP) && ORP > (setORP - offORP - alarmORP)) 
  {
    bitWrite(status_parametros_1,0,0);
   // ORPAflag = false;
  }
  if (alarmORP > 0)            // liga o alarme
  {
    if ((ORP >= (setORP + offORP + alarmORP)) || (ORP <= (setORP - offORP - alarmORP)))
    {
     bitWrite(status_parametros_1,0,1);
   //   ORPAflag=true;
    }
  }
  if (ORP > setORP)    
  {
    bitWrite(status_parametros,7,0);    
 //   ORPflag = false;
    digitalWrite(ozonizadorPin, LOW);  // Desliga ozonizador
  }
  if (offORP > 0)
  {
    if (ORP < setORP)    
    {
    bitWrite(status_parametros,7,1);
  //    ORPflag = true;
      digitalWrite(ozonizadorPin, HIGH); // Liga ozonizador
    }
    if ((ORP < 100) || (ORP > 500))
    {
    bitWrite(status_parametros,7,0);
 //     ORPflag = false;
      digitalWrite(ozonizadorPin, LOW); // Desliga ozonizador
    }
  }
}
void check_alarme()
{
  if ((bitRead(status_parametros,2) == true) || (bitRead(status_parametros,3) == true) || (bitRead(status_parametros,4) == true) || 
      (bitRead(status_parametros,6) == true) || (bitRead(status_parametros_1,1)==true) || (bitRead(tpa_status,2) == true))
  {
    digitalWrite (alarmPin, HIGH);
  }
  else
  {
    digitalWrite (alarmPin, LOW);
  }
}

void reposicao_agua_doce () // abre a solenoide 1 se o nível estiver baixo e se a tpa não estiver em andamento
//e se o chiller estiver desligado e se o nível do sump não estiver anormal e se não houve falha durante uma tpa.
{
  if((analogRead(sensor3) > 400) && (analogRead(sensor2) > 400) && (bitRead(tpa_status,1) == false) && (bitRead(status_parametros,0) == false) && (bitRead(tpa_status,2) == false))
  {
    digitalWrite(solenoide1Pin,HIGH);
    ato = true; //sinaliza reposição em andamento
  }
  else
  {
    ato = false;
    digitalWrite(solenoide1Pin,LOW);
  }
}


