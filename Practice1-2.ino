const int LED = 2; // LED が接続されているピン
void setup()
{
  pinMode(LED, OUTPUT); // ピンを出力に設定
}

void loop()
{
  digitalWrite(LED, HIGH); // LED を点灯
  delay(1000);             // 1,000 ミリ秒待機
  digitalWrite(LED, LOW);  // LED を消灯
  delay(1000);             // 1,000 ミリ秒待機
}
