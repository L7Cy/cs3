//スピーカ
const int SPEAKER = 9; // スピーカが接続されているピン

void setup()
{
  pinMode(SPEAKER, OUTPUT); // ピンを出力に設定
}

void loop()
{
  int i;
  for (i = 0; i < 20; i++)
  {
    digitalWrite(SPEAKER, HIGH); // 出力ピンの電圧を HIGH にする
    delay(5);                    // 5 ミリ秒待機
    digitalWrite(SPEAKER, LOW);  // 出力ピンの電圧を LOW にする
    delay(5);                    // 5 ミリ秒待機
    }
  delay(500); // 500 ミリ秒待機
}
