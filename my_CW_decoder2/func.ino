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
      if (strcmp(code, ".-..-.") == 0) //????????????????????????
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
    //????????????
    if (strcmp(code, "--.--") == 0)
      Serial.write("???");
    if (strcmp(code, ".-") == 0)
      Serial.write("???");
    if (strcmp(code, "..-") == 0)
      Serial.write("???");
    if (strcmp(code, "-.---") == 0)
      Serial.write("???");
    if (strcmp(code, ".-...") == 0)
      Serial.write("???");
    if (strcmp(code, ".-..") == 0)
      Serial.write("???");
    if (strcmp(code, "-.-..") == 0)
      Serial.write("???");
    if (strcmp(code, "...-") == 0)
      Serial.write("???");
    if (strcmp(code, "-.--") == 0)
      Serial.write("???");
    if (strcmp(code, "----") == 0)
      Serial.write("???");
    if (strcmp(code, "-.-.-") == 0)
      Serial.write("???");
    if (strcmp(code, "--.-.") == 0)
      Serial.write("???");
    if (strcmp(code, "---.-") == 0)
      Serial.write("???");
    if (strcmp(code, ".---.") == 0)
      Serial.write("???");
    if (strcmp(code, "---.") == 0)
      Serial.write("???");
    if (strcmp(code, "-.") == 0)
      Serial.write("???");
    if (strcmp(code, "..-.") == 0)
      Serial.write("???");
    if (strcmp(code, ".--.") == 0)
      Serial.write("???");
    if (strcmp(code, ".-.--") == 0)
      Serial.write("???");
    if (strcmp(code, "..-..") == 0)
      Serial.write("???");
    if (strcmp(code, ".-.") == 0)
      Serial.write("???");
    if (strcmp(code, "-.-.") == 0)
      Serial.write("???");
    if (strcmp(code, "....") == 0)
      Serial.write("???");
    if (strcmp(code, "--.-") == 0)
      Serial.write("???");
    if (strcmp(code, "..--") == 0)
      Serial.write("???");
    if (strcmp(code, "-...") == 0)
      Serial.write("???");
    if (strcmp(code, "--..-") == 0)
      Serial.write("???");
    if (strcmp(code, "--..") == 0)
      Serial.write("???");
    if (strcmp(code, ".") == 0)
      Serial.write("???");
    if (strcmp(code, "-..") == 0)
      Serial.write("???");
    if (strcmp(code, "-..-") == 0)
      Serial.write("???");
    if (strcmp(code, "..-.-") == 0)
      Serial.write("???");
    if (strcmp(code, "-") == 0)
      Serial.write("???");
    if (strcmp(code, "-...-") == 0)
      Serial.write("???");
    if (strcmp(code, "-..-.") == 0)
      Serial.write("???");
    if (strcmp(code, ".--") == 0)
      Serial.write("???");
    if (strcmp(code, "-..--") == 0)
      Serial.write("???");
    if (strcmp(code, "--") == 0)
      Serial.write("???");
    if (strcmp(code, "...") == 0)
      Serial.write("???");
    if (strcmp(code, "--.") == 0)
      Serial.write("???");
    if (strcmp(code, "-.--.") == 0)
      Serial.write("???");
    if (strcmp(code, "---") == 0)
      Serial.write("???");
    if (strcmp(code, ".-.-") == 0)
      Serial.write("???");
    if (strcmp(code, "-.-") == 0)
      Serial.write("???");
    if (strcmp(code, ".---") == 0)
      Serial.write("???");
    if (strcmp(code, ".-.-.") == 0)
      Serial.write("???");

    if (strcmp(code, "..") == 0)
      Serial.write("???");
    if (strcmp(code, "..--.") == 0)
      Serial.write("???");
    if (strcmp(code, ".--.-") == 0)
      Serial.write("???");
    if (strcmp(code, ".-.-.-") == 0)
      Serial.write("???");
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

  if (strcmp(code, "-..---") == 0) // ??????
  {
    wabun = true;
    hore = true;
  }
  if (strcmp(code, "...-.") == 0) // ??????
  {
    wabun = false;
    hore = false;
  }

  code[0] = '\0';
}
