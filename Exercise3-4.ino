const int VARIABLE_RESISTOR1 = 0; // 可変抵抗 1 が接続されているピン(アナログ)
const int VARIABLE_RESISTOR2 = 1; // 可変抵抗 2 が接続されているピン(アナログ)

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int value = analogRead(VARIABLE_RESISTOR1);

  Serial.write('H');             // ヘッダの送信
  Serial.write(highByte(value)); // 上位バイトの送信
  Serial.write(lowByte(value));  // 下位バイトの送信
  delay(100);                    // 100 ミリ秒待機
}
