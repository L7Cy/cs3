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
  if (highdurationsavg == 0)
  {
    highdurationsavg = highduration;
  }
  if (highduration < (2 * highdurationsavg))
  {
    highdurationsavg = (highduration + highdurationsavg + highdurationsavg) / 3; // now we know avg dit time ( rolling 3 avg)
  }
  if ((5 * highdurationsavg) < highduration)
  {
    highdurationsavg = highduration + highdurationsavg; // if speed decrease fast ..
  }
}

void decode()
{
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

  if (strcmp(code, "..--..") == 0)
    printascii(63);
  if (strcmp(code, ".-.-.-") == 0)
    printascii(46);
  if (strcmp(code, "--..--") == 0)
    printascii(44);
  if (strcmp(code, "-.-.--") == 0)
    printascii(33);
  if (strcmp(code, ".--.-.") == 0)
    printascii(64);
  if (strcmp(code, "---...") == 0)
    printascii(58);
  if (strcmp(code, "-....-") == 0)
    printascii(45);
  if (strcmp(code, "-..-.") == 0)
    printascii(47);

  if (strcmp(code, "-.--.") == 0)
    printascii(40);
  if (strcmp(code, "-.--.-") == 0)
    printascii(41);
  if (strcmp(code, ".-...") == 0)
    printascii(95);
  if (strcmp(code, "...-..-") == 0)
    printascii(36);
  if (strcmp(code, "...-.-") == 0)
    printascii(62);
  if (strcmp(code, ".-.-.") == 0) // AR
  {
    printascii(32);
    printascii(65);
    printascii(82);
    Serial.println(wpm);
    Serial.println();
    charcount = 0;
  }
  if (strcmp(code, "...-.") == 0)
    printascii(126);

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
  code[0] = '\0';
}

void printascii(int asciinumber)
{
  Serial.write(asciinumber);

  // int fail = 0;
  // if (rows == 4 and colums == 16)
  //   fail = -4; /// to fix the library problem with 4*16 display http://forum.arduino.cc/index.php/topic,14604.0.html

  // if (lcdindex > colums - 1)//端までいったら
  // {
  //   lcdindex = 0;
  //   if (rows == 4)
  //   {
  //     for (int i = 0; i <= colums - 1; i++)
  //     {
  //       lcd.setCursor(i, rows - 3);
  //       lcd.write(line2[i]);
  //       line2[i] = line1[i];
  //     }
  //   }
  //   for (int i = 0; i <= colums - 1; i++)
  //   {
  //     lcd.setCursor(i + fail, rows - 2);
  //     lcd.write(line1[i]);
  //     lcd.setCursor(i + fail, rows - 1);
  //     lcd.write(32);
  //   }
  // }
  // line1[lcdindex] = asciinumber;
  // lcd.setCursor(lcdindex + fail, rows - 1);
  // lcd.write(asciinumber);
  // lcdindex += 1;
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

// void updateinfolinelcd()
// {
//   int place;
//   if (rows == 4)
//   {
//     place = colums / 2;
//   }
//   else
//   {
//     place = 2;
//   }
//   if (wpm < 10)
//   {
//     lcd.setCursor((place)-2, 0);
//     lcd.print("0");
//     lcd.setCursor((place)-1, 0);
//     lcd.print(wpm);
//     lcd.setCursor((place), 0);
//     lcd.print(" WPM");
//   }
//   else
//   {
//     lcd.setCursor((place)-2, 0);
//     lcd.print(wpm);
//     lcd.setCursor((place), 0);
//     lcd.print(" WPM ");
//   }
// }
