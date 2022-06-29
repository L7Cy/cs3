void goertzel()
{
  for (char index = 0; index < n; index++)
  {
    float Q0;
    Q0 = coeff * Q1 - Q2 + (float)testData[index];
    Q2 = Q1;
    Q1 = Q0;
  }
  float magnitudeSquared = (Q1 * Q1) + (Q2 * Q2) - Q1 * Q2 * coeff; // we do only need the real part //
  magnitude = sqrt(magnitudeSquared);
  Q2 = 0;
  Q1 = 0;
}

void calcavg()
{
  if (highduration < (1.2 * highdurationsavg))
  {
    highdurationsavg = (highduration + highdurationsavg + highdurationsavg) / 3; // now we know avg dit time ( rolling 3 avg)
  }
  if ((5 * highdurationsavg) < highduration)
  {
    highdurationsavg = highduration; // if speed decrease fast ..
  }
}

void decode()
{
  // 0 to 9
  if (strcmp(code, "-----") == 0)
    Serial.write("0");
  if (strcmp(code, ".----") == 0)
    Serial.write("1");
  if (strcmp(code, "..---") == 0)
    Serial.write("2");
  if (strcmp(code, "...--") == 0)
    Serial.write("3");
  if (strcmp(code, "....-") == 0)
    Serial.write("4");
  if (strcmp(code, ".....") == 0)
    Serial.write("5");
  if (strcmp(code, "-....") == 0)
    Serial.write("6");
  if (strcmp(code, "--...") == 0)
    Serial.write("7");
  if (strcmp(code, "---..") == 0)
    Serial.write("8");
  if (strcmp(code, "----.") == 0)
    Serial.write("9");

  if (wabun == false)
  {
    // a to z
    if (strcmp(code, ".-") == 0)
      Serial.write("A");
    if (strcmp(code, "-...") == 0)
      Serial.write("B");
    if (strcmp(code, "-.-.") == 0)
      Serial.write("C");
    if (strcmp(code, "-..") == 0)
      Serial.write("D");
    if (strcmp(code, ".") == 0)
      Serial.write("E");
    if (strcmp(code, "..-.") == 0)
      Serial.write("F");
    if (strcmp(code, "--.") == 0)
      Serial.write("G");
    if (strcmp(code, "....") == 0)
      Serial.write("H");
    if (strcmp(code, "..") == 0)
      Serial.write("I");
    if (strcmp(code, ".---") == 0)
      Serial.write("J");
    if (strcmp(code, "-.-") == 0)
      Serial.write("K");
    if (strcmp(code, ".-..") == 0)
      Serial.write("L");
    if (strcmp(code, "--") == 0)
      Serial.write("M");
    if (strcmp(code, "-.") == 0)
      Serial.write("N");
    if (strcmp(code, "---") == 0)
      Serial.write("O");
    if (strcmp(code, ".--.") == 0)
      Serial.write("P");
    if (strcmp(code, "--.-") == 0)
      Serial.write("Q");
    if (strcmp(code, ".-.") == 0)
      Serial.write("R");
    if (strcmp(code, "...") == 0)
      Serial.write("S");
    if (strcmp(code, "-") == 0)
      Serial.write("T");
    if (strcmp(code, "..-") == 0)
      Serial.write("U");
    if (strcmp(code, "...-") == 0)
      Serial.write("V");
    if (strcmp(code, ".--") == 0)
      Serial.write("W");
    if (strcmp(code, "-..-") == 0)
      Serial.write("X");
    if (strcmp(code, "-.--") == 0)
      Serial.write("y");
    if (strcmp(code, "--..") == 0)
      Serial.write("Z");

    if (strcmp(code, ".-.-.-") == 0)
      Serial.write(".");
    if (strcmp(code, "--..--") == 0)
      Serial.write(",");
    if (strcmp(code, "---...") == 0)
      Serial.write(":");
    if (strcmp(code, "..--..") == 0)
      Serial.write("?");
    if (strcmp(code, ".----.") == 0)
      Serial.write("'");
    if (strcmp(code, "-....-") == 0)
      Serial.write("-");
    if (strcmp(code, "-.--.") == 0)
      Serial.write("(");
    if (strcmp(code, "-.--.-") == 0)
      Serial.write(")");
    if (strcmp(code, "-..-.") == 0)
      Serial.write("/");
    if (strcmp(code, "-...-") == 0)
      Serial.write("=");
    if (strcmp(code, ".-.-.") == 0)
      Serial.write("+");
    if (hore == true)
    {
      if (strcmp(code, ".-..-.") == 0) //和文にもどるやつ
      {
        Serial.write(")");
        wabun = true;
      }
    }
    else
    {
      if (strcmp(code, ".-..-.") == 0)
      {
        Serial.write('"');
      }
    }

    if (strcmp(code, ".--.-.") == 0)
      Serial.write("@");


    if (strcmp(code, "-.---") == 0)
    {
      Serial.write("エ");
      wabun = true;
      hore = true;
    }
    if (strcmp(code, ".-...") == 0)
    {
      Serial.write("オ");
      wabun = true;
      hore = true;
    }
    if (strcmp(code, "-.-..") == 0)
    {
      Serial.write("キ");
      wabun = true;
      hore = true;
    }
    if (strcmp(code, "----") == 0)
    {
      Serial.write("コ");
      wabun = true;
      hore = true;
    }
    if (strcmp(code, "-.-.-") == 0)
    {
      Serial.write("サ");
      wabun = true;
      hore = true;
    }
    if (strcmp(code, "--.-.") == 0)
    {
      Serial.write("シ");
      wabun = true;
      hore = true;
    }
    if (strcmp(code, "---.-") == 0)
    {
      Serial.write("ス");
      wabun = true;
      hore = true;
    }
    if (strcmp(code, ".---.") == 0)
    {
      Serial.write("セ");
      wabun = true;
      hore = true;
    }
    if (strcmp(code, "---.") == 0)
    {
      Serial.write("ソ");
      wabun = true;
      hore = true;
    }
    if (strcmp(code, ".-.--") == 0)
    {
      Serial.write("テ");
      wabun = true;
      hore = true;
    }
    if (strcmp(code, "..-..") == 0)
    {
      Serial.write("ト");
      wabun = true;
      hore = true;
    }
    if (strcmp(code, "..--") == 0)
    {
      Serial.write("ノ");
      wabun = true;
      hore = true;
    }
    if (strcmp(code, "--..-") == 0)
    {
      Serial.write("ヒ");
      wabun = true;
      hore = true;
    }
    if (strcmp(code, "..-.-") == 0)
    {
      Serial.write("ミ");
      wabun = true;
      hore = true;
    }
    if (strcmp(code, "-..--") == 0)
    {
      Serial.write("ユ");
      wabun = true;
      hore = true;
    }
    if (strcmp(code, ".-.-") == 0)
    {
      Serial.write("ロ");
      wabun = true;
      hore = true;
    }
    if (strcmp(code, "-.-") == 0)
    {
      Serial.write("ワ");
      wabun = true;
      hore = true;
    }
    if (strcmp(code, "..--.") == 0)
    {
      Serial.write("゜");
      wabun = true;
      hore = true;
    }
    if (strcmp(code, ".--.-") == 0)
    {
      Serial.write("ー");
      wabun = true;
      hore = true;
    }
  }
  else
  {
    //アからン
    if (strcmp(code, "--.--") == 0)
      Serial.write("ア");
    if (strcmp(code, ".-") == 0)
      Serial.write("イ");
    if (strcmp(code, "..-") == 0)
      Serial.write("ウ");
    if (strcmp(code, "-.---") == 0)
      Serial.write("エ");
    if (strcmp(code, ".-...") == 0)
      Serial.write("オ");
    if (strcmp(code, ".-..") == 0)
      Serial.write("カ");
    if (strcmp(code, "-.-..") == 0)
      Serial.write("キ");
    if (strcmp(code, "...-") == 0)
      Serial.write("ク");
    if (strcmp(code, "-.--") == 0)
      Serial.write("ケ");
    if (strcmp(code, "----") == 0)
      Serial.write("コ");
    if (strcmp(code, "-.-.-") == 0)
      Serial.write("サ");
    if (strcmp(code, "--.-.") == 0)
      Serial.write("シ");
    if (strcmp(code, "---.-") == 0)
      Serial.write("ス");
    if (strcmp(code, ".---.") == 0)
      Serial.write("セ");
    if (strcmp(code, "---.") == 0)
      Serial.write("ソ");
    if (strcmp(code, "-.") == 0)
      Serial.write("タ");
    if (strcmp(code, "..-.") == 0)
      Serial.write("チ");
    if (strcmp(code, ".--.") == 0)
      Serial.write("ツ");
    if (strcmp(code, ".-.--") == 0)
      Serial.write("テ");
    if (strcmp(code, "..-..") == 0)
      Serial.write("ト");
    if (strcmp(code, ".-.") == 0)
      Serial.write("ナ");
    if (strcmp(code, "-.-.") == 0)
      Serial.write("ニ");
    if (strcmp(code, "....") == 0)
      Serial.write("ヌ");
    if (strcmp(code, "--.-") == 0)
      Serial.write("ネ");
    if (strcmp(code, "..--") == 0)
      Serial.write("ノ");
    if (strcmp(code, "-...") == 0)
      Serial.write("ハ");
    if (strcmp(code, "--..-") == 0)
      Serial.write("ヒ");
    if (strcmp(code, "--..") == 0)
      Serial.write("フ");
    if (strcmp(code, ".") == 0)
      Serial.write("ヘ");
    if (strcmp(code, "-..") == 0)
      Serial.write("ホ");
    if (strcmp(code, "-..-") == 0)
      Serial.write("マ");
    if (strcmp(code, "..-.-") == 0)
      Serial.write("ミ");
    if (strcmp(code, "-") == 0)
      Serial.write("ム");
    if (strcmp(code, "-...-") == 0)
      Serial.write("メ");
    if (strcmp(code, "-..-.") == 0)
      Serial.write("モ");
    if (strcmp(code, ".--") == 0)
      Serial.write("ヤ");
    if (strcmp(code, "-..--") == 0)
      Serial.write("ユ");
    if (strcmp(code, "--") == 0)
      Serial.write("ヨ");
    if (strcmp(code, "...") == 0)
      Serial.write("ラ");
    if (strcmp(code, "--.") == 0)
      Serial.write("リ");
    if (strcmp(code, "-.--.") == 0)
      Serial.write("ル");
    if (strcmp(code, "---") == 0)
      Serial.write("レ");
    if (strcmp(code, ".-.-") == 0)
      Serial.write("ロ");
    if (strcmp(code, "-.-") == 0)
      Serial.write("ワ");
    if (strcmp(code, ".---") == 0)
      Serial.write("ヲ");
    if (strcmp(code, ".-.-.") == 0)
      Serial.write("ン");

    if (strcmp(code, "..") == 0)
      Serial.write("゛");
    if (strcmp(code, "..--.") == 0)
      Serial.write("゜");
    if (strcmp(code, ".--.-") == 0)
      Serial.write("ー");
    if (strcmp(code, ".-.-.-") == 0)
      Serial.write("、");
    if (strcmp(code, "-.--.-") == 0)
    {
      Serial.write("(");
      wabun = false;
    }


    if (strcmp(code, "--..--") == 0)
    {
      Serial.write(",");
      wabun = false;
      hore = false;
    }
    if (strcmp(code, "---...") == 0)
    {
      Serial.write(":");
      wabun = false;
      hore = false;
    }
    if (strcmp(code, "..--..") == 0)
    {
      Serial.write("?");
      wabun = false;
      hore = false;
    }
    if (strcmp(code, ".----.") == 0)
    {
      Serial.write("'");
      wabun = false;
      hore = false;
    }
    if (strcmp(code, "-....-") == 0)
    {
      Serial.write("-");
      wabun = false;
      hore = false;
    }
    if (strcmp(code, ".--.-.") == 0)
    {
      Serial.write("@");
      wabun = false;
      hore = false;
    }
  }

  if (strcmp(code, "-..---") == 0) // ホレ
  {
    wabun = true;
    hore = true;
  }
  if (strcmp(code, "...-.") == 0) // ラタ
  {
    wabun = false;
    hore = false;
  }

  code[0] = '\0';
}
