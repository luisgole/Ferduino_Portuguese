
void check_temporizadores()
{

  if (temporizador_1_ativado == 1) 
  {  
   if(NumMins(off1_hora,off1_minuto) > NumMins(on1_hora,on1_minuto))
   {
    if((NumMins(t.hour,t.min) >= NumMins(on1_hora,on1_minuto)) && (NumMins(t.hour,t.min) <= NumMins(off1_hora,off1_minuto)))
    {
      digitalWrite(temporizador1, HIGH);
      //Serial.println("Timer 1 = on");
    }
    if (NumMins(t.hour,t.min) > NumMins(off1_hora,off1_minuto))
    {
      digitalWrite(temporizador1, LOW);
      //Serial.println("Timer 1 = off");
    }
   }
   if(NumMins(off1_hora,off1_minuto) < NumMins(on1_hora,on1_minuto))
   {                     
    if(NumMins(t.hour,t.min) >= NumMins(on1_hora,on1_minuto)) 
    {
      digitalWrite(temporizador1, HIGH);
      //Serial.println("Timer 1 = on");
    }
    
    if (NumMins(t.hour,t.min) < NumMins(off1_hora,off1_minuto)) 
    {
      digitalWrite(temporizador1, HIGH);
      //Serial.println("Timer 1 = on");
    }     
    if ((NumMins(t.hour,t.min) >= NumMins(off1_hora,off1_minuto)) && (NumMins(t.hour,t.min) < NumMins(on1_hora,on1_minuto)))
    {
      digitalWrite(temporizador1, LOW);
      //Serial.println("Timer 1 = off");
    } 
   }
  }
  else
  {
    digitalWrite(temporizador1, LOW);
  }
  if (temporizador_2_ativado == 1) 
  {
   if(NumMins(off2_hora,off2_minuto) > NumMins(on2_hora,on2_minuto))
   {
    if((NumMins(t.hour,t.min) >= NumMins(on2_hora,on2_minuto)) && (NumMins(t.hour,t.min) <= NumMins(off2_hora,off2_minuto)))
    {
      digitalWrite(temporizador2, HIGH);
      //Serial.println("Timer 2 = on");
    }
    if (NumMins(t.hour,t.min) > NumMins(off2_hora,off2_minuto))
    {
      digitalWrite(temporizador2, LOW);
      //Serial.println("Timer 2 = off");
    }
   }
   if(NumMins(off2_hora,off2_minuto) < NumMins(on2_hora,on2_minuto))
   {                     
    if(NumMins(t.hour,t.min) >= NumMins(on2_hora,on2_minuto)) 
    {
      digitalWrite(temporizador2, HIGH);
      //Serial.println("Timer 2 = on");
    }
    
    if (NumMins(t.hour,t.min) < NumMins(off2_hora,off2_minuto)) 
    {
      digitalWrite(temporizador2, HIGH);
      //Serial.println("Timer 2 = on");
    }     
    if ((NumMins(t.hour,t.min) >= NumMins(off2_hora,off2_minuto)) && (NumMins(t.hour,t.min) < NumMins(on2_hora,on2_minuto)))
    {
      digitalWrite(temporizador2, LOW);
      //Serial.println("Timer 2 = off");
    } 
   }
  }
  else
  {
    digitalWrite(temporizador2, LOW);
  }  
  if (temporizador_3_ativado == 1) 
  {  
   if(NumMins(off3_hora,off3_minuto) > NumMins(on3_hora,on3_minuto))
   {
    if((NumMins(t.hour,t.min) >= NumMins(on3_hora,on3_minuto)) && (NumMins(t.hour,t.min) <= NumMins(off3_hora,off3_minuto)))
    {
      digitalWrite(temporizador3, HIGH);
      //Serial.println("Timer 3 = on");
    }
    if (NumMins(t.hour,t.min) > NumMins(off3_hora,off3_minuto))
    {
      digitalWrite(temporizador3, LOW);
      //Serial.println("Timer 3 = off");
    }
   }
   if(NumMins(off3_hora,off3_minuto) < NumMins(on3_hora,on3_minuto))
   {                     
    if(NumMins(t.hour,t.min) >= NumMins(on3_hora,on3_minuto)) 
    {
      digitalWrite(temporizador3, HIGH);
      //Serial.println("Timer 3 = on");
    }
    
    if (NumMins(t.hour,t.min) < NumMins(off3_hora,off3_minuto)) 
    {
      digitalWrite(temporizador3, HIGH);
      //Serial.println("Timer 3 = on");
    }     
    if ((NumMins(t.hour,t.min) >= NumMins(off3_hora,off3_minuto)) && (NumMins(t.hour,t.min) < NumMins(on3_hora,on3_minuto)))
    {
      digitalWrite(temporizador3, LOW);
      //Serial.println("Timer 3 = off");
    } 
   }
  }
  else
  {
    digitalWrite(temporizador3, LOW);
  } 
  if (temporizador_4_ativado == 1) 
  {  
   if(NumMins(off4_hora,off4_minuto) > NumMins(on4_hora,on4_minuto))
   {
    if((NumMins(t.hour,t.min) >= NumMins(on4_hora,on4_minuto)) && (NumMins(t.hour,t.min) <= NumMins(off4_hora,off4_minuto)))
    {
      digitalWrite(temporizador4, HIGH);
      //Serial.println("Timer 4 = on");
    }
    if (NumMins(t.hour,t.min) > NumMins(off4_hora,off4_minuto))
    {
      digitalWrite(temporizador4, LOW);
      //Serial.println("Timer 4 = off");
    }
   }
   if(NumMins(off4_hora,off4_minuto) < NumMins(on4_hora,on4_minuto))
   {                     
    if(NumMins(t.hour,t.min) >= NumMins(on4_hora,on4_minuto)) 
    {
      digitalWrite(temporizador4, HIGH);
      //Serial.println("Timer 4 = on");
    }
    
    if (NumMins(t.hour,t.min) < NumMins(off4_hora,off4_minuto)) 
    {
      digitalWrite(temporizador4, HIGH);
      //Serial.println("Timer 4 = on");
    }     
    if ((NumMins(t.hour,t.min) >= NumMins(off4_hora,off4_minuto)) && (NumMins(t.hour,t.min) < NumMins(on4_hora,on4_minuto)))
    {
      digitalWrite(temporizador4, LOW);
      //Serial.println("Timer 4 = off");
    } 
   }
  }
  else
  {
    digitalWrite(temporizador4, LOW);
  }
  if (temporizador_5_ativado == 1) 
  {  
   if(NumMins(off5_hora,off5_minuto) > NumMins(on5_hora,on5_minuto))
   {
    if((NumMins(t.hour,t.min) >= NumMins(on5_hora,on5_minuto)) && (NumMins(t.hour,t.min) <= NumMins(off5_hora,off5_minuto)))
    {
      digitalWrite(temporizador5, HIGH);
      //Serial.println("Timer 5 = on");
    }
    if (NumMins(t.hour,t.min) > NumMins(off5_hora,off5_minuto))
    {
      digitalWrite(temporizador5, LOW);
      //Serial.println("Timer 5 = off");
    }
   }
   if(NumMins(off5_hora,off5_minuto) < NumMins(on5_hora,on5_minuto))
   {                     
    if(NumMins(t.hour,t.min) >= NumMins(on5_hora,on5_minuto)) 
    {
      digitalWrite(temporizador5, HIGH);
      //Serial.println("Timer 5 = on");
    }
    
    if (NumMins(t.hour,t.min) < NumMins(off5_hora,off5_minuto)) 
    {
      digitalWrite(temporizador5, HIGH);
      //Serial.println("Timer 5 = on");
    }     
    if ((NumMins(t.hour,t.min) >= NumMins(off5_hora,off5_minuto)) && (NumMins(t.hour,t.min) < NumMins(on5_hora,on5_minuto)))
    {
      digitalWrite(temporizador5, LOW);
      //Serial.println("Timer 5 = off");
    } 
   }
  }
  else
  {
    digitalWrite(temporizador5, LOW);
  }  
}

