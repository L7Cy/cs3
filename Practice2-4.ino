const int VARIABLE_RESISTOR = 0; // 可変抵抗が接続されているピン(アナログ)
const int LED = 9;               // LED が接続されているピン

void setup()
{
  pinMode(LED, OUTPUT); // ピンを出力に設定
}

void loop()
{
  int v1, v2;
  v1 = analogRead(VARIABLE_RESISTOR); // ピンから値を読み取る
  v2 = map(v1, 0, 1023, 0, 255);      // 10 ビットから 8 ビットへ変換
  analogWrite(LED, v2);               // LED の明るさを設定
}
