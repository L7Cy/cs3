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

    if (strcmp(code, "-.---") == 0 ||
        strcmp(code, ".-...") == 0 ||
        strcmp(code, "-.-..") == 0 ||
        strcmp(code, "----") == 0 ||
        strcmp(code, "-.-.-") == 0 ||
        strcmp(code, "--.-.") == 0 ||
        strcmp(code, "---.-") == 0 ||
        strcmp(code, ".---.") == 0 ||
        strcmp(code, "---.") == 0 ||
        strcmp(code, ".-.--") == 0 ||
        strcmp(code, "..-..") == 0 ||
        strcmp(code, "..--") == 0 ||
        strcmp(code, "--..-") == 0 ||
        strcmp(code, "..-.-") == 0 ||
        strcmp(code, "-..--") == 0 ||
        strcmp(code, ".-.-") == 0 ||
        strcmp(code, "-.-") == 0 ||
        strcmp(code, "..--.") == 0 ||
        strcmp(code, ".--.-") == 0)
    {
      wabun = true;
      hore = true;
      decode();
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

    if (strcmp(code, "--..--") == 0 ||
        strcmp(code, "---...") == 0 ||
        strcmp(code, "..--..") == 0 ||
        strcmp(code, ".----.") == 0 ||
        strcmp(code, "-....-") == 0 ||
        strcmp(code, ".--.-.") == 0)
    {
      wabun = false;
      hore = false;
      decode();
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
