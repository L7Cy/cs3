const int LED = 13; // LED が接続されているピン
                    // #define LED 13 でも可(以後同様)
void setup()
{
  pinMode(LED, OUTPUT);
}

void loop()
{
  digitalWrite(LED, HIGH); // LED を点灯(出力ピンの電圧を HIGH にする)
  delay(1000);             // 1,000 ミリ秒待機
  digitalWrite(LED, LOW);  // LED を消灯(出力ピンの電圧を LOW にする)
  delay(10);               // 1,000 ミリ秒待機
}
