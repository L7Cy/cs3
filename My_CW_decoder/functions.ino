void docode()
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
  if (strcmp(code, ".-.-.") == 0)
    printascii(60);
  if (strcmp(code, "...-.") == 0)
    printascii(126);
}

void printascii(int asciinumber)
{

  int fail = 0;

  if (lcdindex > colums - 1) //端までいったら
  {
    lcdindex = 0;

    for (int i = 0; i <= colums - 1; i++)
    {
      lcd.setCursor(i + fail, rows - 2);
      lcd.write(line1[i]);
      lcd.setCursor(i + fail, rows - 1);
      lcd.write(32);
    }
  }
  line1[lcdindex] = asciinumber;
  lcd.setCursor(lcdindex + fail, rows - 1);
  lcd.write(asciinumber);
  lcdindex += 1;
}

void updateinfolinelcd()
{
  int place = 2;

  if (wpm < 10)
  { // 0xWPM
    lcd.setCursor((place)-2, 0);
    lcd.print("0");
    lcd.setCursor((place)-1, 0);
    lcd.print(wpm);
    lcd.setCursor((place), 0);
    lcd.print(" WPM");
  }
  else
  { // xxWPM
    lcd.setCursor((place)-2, 0);
    lcd.print(wpm);
    lcd.setCursor((place), 0);
    lcd.print(" WPM ");
  }
}
