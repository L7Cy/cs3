const int VARIABLE_RESISTOR = 0; // 可変抵抗が接続されているピン(アナログ)

void setup()
{
  Serial.begin(9600); // シリアル通信の速度を設定
}

void loop()
{
  int v1, v2;
  v1 = analogRead(VARIABLE_RESISTOR); // ピンから値を読み取る
  v2 = map(v1, 0, 1023, 0, 255);      // 10 ビットから 8 ビットへ変換
  Serial.write(v2);                   // シリアル通信で値を送信
  delay(100);                         // 100 ミリ秒待機
}
