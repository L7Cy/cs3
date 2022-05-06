const int SWITCH = 2; // タクトスイッチが接続されているピン

void setup()
{
  Serial.begin(9600);     // シリアル通信の速度を設定
  pinMode(SWITCH, INPUT); // ピンを入力に設定
}

void loop()
{
  int v;
  v = digitalRead(SWITCH); // 入力を読み取る
  if (v == HIGH)
  {                    // タクトスイッチが押されたとき
    Serial.write('r'); // シリアル通信で文字を送信
  }
  else
  {                    // タクトスイッチが押されていないとき
    Serial.write('w'); // シリアル通信で文字を送信
  }
  delay(100); // 100 ミリ秒待機
}
