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
  if(wabun==false)
  {
    //a to z
    if (strcmp(code, ".-") == 0)
      printascii(65);
    if (strcmp(code, "-...") == 0)
      printascii(66);
    if (strcmp(code, "-.-.") == 0)
      printascii(67);
    if (strcmp(code, "-..") == 0)
      printascii(68);
    if (strcmp(code, ".") == 0)
      printascii(69);
    if (strcmp(code, "..-.") == 0)
      printascii(70);
    if (strcmp(code, "--.") == 0)
      printascii(71);
    if (strcmp(code, "....") == 0)
      printascii(72);
    if (strcmp(code, "..") == 0)
      printascii(73);
    if (strcmp(code, ".---") == 0)
      printascii(74);
    if (strcmp(code, "-.-") == 0)
      printascii(75);
    if (strcmp(code, ".-..") == 0)
      printascii(76);
    if (strcmp(code, "--") == 0)
      printascii(77);
    if (strcmp(code, "-.") == 0)
      printascii(78);
    if (strcmp(code, "---") == 0)
      printascii(79);
    if (strcmp(code, ".--.") == 0)
      printascii(80);
    if (strcmp(code, "--.-") == 0)
      printascii(81);
    if (strcmp(code, ".-.") == 0)
      printascii(82);
    if (strcmp(code, "...") == 0)
      printascii(83);
    if (strcmp(code, "-") == 0)
      printascii(84);
    if (strcmp(code, "..-") == 0)
      printascii(85);
    if (strcmp(code, "...-") == 0)
      printascii(86);
    if (strcmp(code, ".--") == 0)
      printascii(87);
    if (strcmp(code, "-..-") == 0)
      printascii(88);
    if (strcmp(code, "-.--") == 0)
      printascii(89);
    if (strcmp(code, "--..") == 0)
      printascii(90);

    //0 to 9
    if (strcmp(code, ".----") == 0)
      printascii(49);
    if (strcmp(code, "..---") == 0)
      printascii(50);
    if (strcmp(code, "...--") == 0)
      printascii(51);
    if (strcmp(code, "....-") == 0)
      printascii(52);
    if (strcmp(code, ".....") == 0)
      printascii(53);
    if (strcmp(code, "-....") == 0)
      printascii(54);
    if (strcmp(code, "--...") == 0)
      printascii(55);
    if (strcmp(code, "---..") == 0)
      printascii(56);
    if (strcmp(code, "----.") == 0)
      printascii(57);
    if (strcmp(code, "-----") == 0)
      printascii(48);

    if (strcmp(code, "..--..") == 0)//'?'
      printascii(63);
    if (strcmp(code, ".-.-.-") == 0)//'.'
      printascii(46);
    if (strcmp(code, "--..--") == 0)//','
      printascii(44);
    if (strcmp(code, "-.-.--") == 0)//''
      printascii(33);
    if (strcmp(code, ".--.-.") == 0)//'@'
      printascii(64);
    if (strcmp(code, "---...") == 0)//':'
      printascii(58);
    if (strcmp(code, "-....-") == 0)//'='
      printascii(45);
    if (strcmp(code, "-..-.") == 0)
      printascii(47);

    if (strcmp(code, "-.--.") == 0)//'('
      printascii(40);
    if (strcmp(code, "-.--.-") == 0)//')'
      Serial.write(")");
    if (strcmp(code, ".-..-.") == 0)//和文にもどるやつ
    {
      Serial.write(")");
      wabun=true;
    }
    if (strcmp(code, ".-...") == 0)
      printascii(95);
    if (strcmp(code, "...-..-") == 0)
      printascii(36);
    if (strcmp(code, "...-.-") == 0)
      printascii(62);
    if (strcmp(code, "...-.") == 0)
      printascii(126);
    if (strcmp(code, ".-.-.") == 0) // AR
    {
      printascii(32);
      printascii(65);
      printascii(82);
      Serial.println(wpm);
      Serial.println();
      charcount = 0;
    }

    if (strcmp(code, "........") == 0) // HH
    {
      printascii(72);
      printascii(72);
    }
    if (strcmp(code, "-...-") == 0) // BT
    {
      printascii(32);
      printascii(66);
      printascii(84);
      Serial.println(wpm);
      charcount = 0;
    }
  }
  else
  {
    //アからン
    if (strcmp(code, "--.--") == 0) //"ア"
      Serial.write("ア");
    if (strcmp(code, ".-") == 0) //"イ"
      Serial.write("イ");
    if (strcmp(code, "..-") == 0) //"ウ"
      Serial.write("ウ");
    if (strcmp(code, "-.---") == 0) //"エ"
      Serial.write("エ");
    if (strcmp(code, ".-...") == 0) //"オ"
      Serial.write("オ");
    if (strcmp(code, ".-..") == 0) //"カ"
      Serial.write("カ");
    if (strcmp(code, "-.-..") == 0) //"キ"
      Serial.write("キ");
    if (strcmp(code, "...-") == 0) //"ク"
      Serial.write("ク");
    if (strcmp(code, "-.--") == 0) //"ケ"
      Serial.write("ケ");
    if (strcmp(code, "----") == 0) //"コ"
      Serial.write("コ");
    if (strcmp(code, "-.-.-") == 0) //"サ"
      Serial.write("サ");
    if (strcmp(code, "--.-.") == 0) //"シ"
      Serial.write("シ");
    if (strcmp(code, "---.-") == 0) //"ス"
      Serial.write("ス");
    if (strcmp(code, ".---.") == 0) //"セ"
      Serial.write("セ");
    if (strcmp(code, "---.") == 0) //"ソ"
      Serial.write("ソ");
    if (strcmp(code, "-.") == 0) //"タ"
      Serial.write("タ");
    if (strcmp(code, "..-.") == 0) //"チ"
      Serial.write("チ");
    if (strcmp(code, ".--.") == 0) //"ツ"
      Serial.write("ツ");
    if (strcmp(code, ".-.--") == 0) //"テ"
      Serial.write("テ");
    if (strcmp(code, "..-..") == 0) //"ト"
      Serial.write("ト");
    if (strcmp(code, ".-.") == 0) //"ナ"
      Serial.write("ナ");
    if (strcmp(code, "-.-.") == 0) //"ニ"
      Serial.write("ニ");
    if (strcmp(code, "....") == 0) //"ヌ"
      Serial.write("ヌ");
    if (strcmp(code, "--.-") == 0) //"ネ"
      Serial.write("ネ");
    if (strcmp(code, "..--") == 0) //"ノ"
      Serial.write("ノ");
    if (strcmp(code, "-...") == 0) //"ハ"
      Serial.write("ハ");
    if (strcmp(code, "--..-") == 0) //"ヒ"
      Serial.write("ヒ");
    if (strcmp(code, "--..") == 0) //"フ"
      Serial.write("フ");
    if (strcmp(code, ".") == 0) //"ヘ"
      Serial.write("ヘ");
    if (strcmp(code, "-..") == 0) //"ホ"
      Serial.write("ホ");
    if (strcmp(code, "-..-") == 0) //"マ"
      Serial.write("マ");
    if (strcmp(code, "..-.-") == 0) //"ミ"
      Serial.write("ミ");
    if (strcmp(code, "-") == 0) //"ム"
      Serial.write("ム");
    if (strcmp(code, "-...-") == 0) //"メ"
      Serial.write("メ");
    if (strcmp(code, "-..-.") == 0) //"モ"
      Serial.write("モ");
    if (strcmp(code, ".--") == 0) //"ヤ"
      Serial.write("ヤ");
    if (strcmp(code, "-..--") == 0) //"ユ"
      Serial.write("ユ");
    if (strcmp(code, "--") == 0) //"ヨ"
      Serial.write("ヨ");
    if (strcmp(code, "...") == 0) //"ラ"
      Serial.write("ラ");
    if (strcmp(code, "--.") == 0) //"リ"
      Serial.write("リ");
    if (strcmp(code, "-.--.") == 0) //"ル"
      Serial.write("ル");
    if (strcmp(code, "---") == 0) //"レ"
      Serial.write("レ");
    if (strcmp(code, ".-.-") == 0) //"ロ"
      Serial.write("ロ");
    if (strcmp(code, "-.-") == 0) //"ワ"
      Serial.write("ワ");
    // if (strcmp(code, ".-..-") == 0) //"ヰ"
    //   printascii();
    if (strcmp(code, ".---") == 0) //"ヲ"
      Serial.write("ヲ");
    // if (strcmp(code, ".--..") == 0) //"ヱ"
    //   printascii();
    if (strcmp(code, ".-.-.") == 0) //"ン"
      Serial.write("ン");

    // 0 to 9
    if (strcmp(code, "-----") == 0)
      printascii(48);
    if (strcmp(code, ".----") == 0)
      printascii(49);
    if (strcmp(code, "..---") == 0)
      printascii(50);
    if (strcmp(code, "...--") == 0)
      printascii(51);
    if (strcmp(code, "....-") == 0)
      printascii(52);
    if (strcmp(code, ".....") == 0)
      printascii(53);
    if (strcmp(code, "-....") == 0)
      printascii(54);
    if (strcmp(code, "--...") == 0)
      printascii(55);
    if (strcmp(code, "---..") == 0)
      printascii(56);
    if (strcmp(code, "----.") == 0)
      printascii(57);

    if (strcmp(code, "..") == 0) //"濁点"
      Serial.write("゛");
    if (strcmp(code, "..--.") == 0) //"半濁点"
      Serial.write("゜");
    if (strcmp(code, "-.--.-") == 0) //"("
    {
      Serial.write("(");
      wabun = false;
    }
    // if (strcmp(code, ".-..-.") == 0) //")"
    // {
    //   Serial.write(")");
    //   wabun = true;
    // }
    if (strcmp(code, ".-.-.-") == 0) //"、"
      Serial.write("、");
    if (strcmp(code, "-..---") == 0) // AR
    {
      printascii(32);
      printascii(65);
      printascii(82);
      Serial.println(wpm);
      Serial.println();
      charcount = 0;
    }
    if (strcmp(code, "...-.") == 0) // HH
    {
      printascii(72);
      printascii(72);
    }
    if (strcmp(code, "..--..") == 0) // BT
    {
      printascii(32);
      printascii(66);
      printascii(84);
      Serial.println(wpm);
      charcount = 0;
    }
  }
  code[0] = '\0';
}

void printascii(int asciinumber)
{
  Serial.write(asciinumber);
}

// void checklacktime()
// {
//   if (wpm > 25)
//     lacktime = 1.0; ///  when high speeds we have to have a little more pause before new letter or new word
//   if (wpm > 30)
//     lacktime = 1.2;
//   if (wpm > 35)
//     lacktime = 1.5;
// }
