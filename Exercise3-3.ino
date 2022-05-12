const int SENSOR = 0; // 光センサが接続されているピン(アナログ)

void setup()
{
  Serial.begin(9600); // シリアル通信の速度を設定
  // pinMode(LED, OUTPUT); // ピンを出力に設定
}

void loop()
{
  int v;
  v = analogRead(SENSOR); // センサの出力値を読み取る
  v = map(v, 0, 1023, 0, 255);
  Serial.write(v);
  delay(100);
  // Serial.print("\n");
}
