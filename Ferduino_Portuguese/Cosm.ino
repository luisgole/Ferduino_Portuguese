
void cosm () //--------------- Envia dados para o cosm.com ------------------------------------
{

  if (millis() - previous_Millis > 65000)    //Envia dados a cada 65s
  {
    previous_Millis = millis();

    if(ether.dnsLookup(website))
    {
//      check_status(); // Atualiza os valores para envio ao cosm.com.
      byte sd = stash.create();
      stash.print("1,"); //Temp. da água
      stash.println(tempC,DEC);
      stash.print("2,"); //Temp. dissipador
      stash.println(tempH,DEC);
      stash.print("3,"); //PH do aquário
      stash.println(PHA, DEC);
      stash.print("4,"); //PH do reator de cálcio
      stash.println(PHR,DEC);
      stash.print("5,"); //Densidade
      stash.println(DEN);
      stash.print("6,"); //ORP
      stash.println(ORP);
      stash.print("7,"); //Status chiller 0 = desligado, 100 = ligado
      stash.println(bitRead(status_parametros,0));
      stash.print("8,"); //Status aquecedor 0 = desligado, 100 = ligado
      stash.println(bitRead(status_parametros,1));
      stash.print("9,"); //Status reator de cálcio 0 = desligado, 100 = ligado
      stash.println(bitRead(status_parametros,5));
      stash.print("10,"); // Status ozonizador 0 = desligado, 100 = ligado
      stash.println(bitRead(status_parametros,7));
      stash.print("11,"); //Status reposicao de agua doce 0 = desligado, 100 = ligado
      stash.println(bitRead(Status,1));
      stash.print("12,"); //Status niveis 0 = baixo, 100 = normal
      stash.println(bitRead(Status,2));
      stash.print("13,"); //Status TPA 0 = desligado, 100 = ligado
      stash.println(bitRead(Status,3));
      stash.print("14,"); //Potência dos leds azuis
      stash.println(LedToPercent(bled_out));
      stash.print("15,"); //Potência dos leds brancos
      stash.println(LedToPercent(wled_out));

      stash.save();
       // Gerar o cabeçalho com carga útil - note que o tamanho do "stash" é usado,
       // E que um "stash descriptor" é passado como argumento usando "$ H".
      Stash::prepare(PSTR("PUT http://$F/v2/feeds/$F.csv HTTP/1.0" "\r\n"
        "Host: $F" "\r\n"
        "X-PachubeApiKey: $F" "\r\n"
        "Content-Length: $D" "\r\n"
        "\r\n"
        "$H"),
      website, PSTR(FEED), website, PSTR(APIKEY), stash.size(), sd);

    // Envia o pacote - este também libera todos os "stash buffers", uma vez feito.
      ether.tcpSend();
    }
  }
}
