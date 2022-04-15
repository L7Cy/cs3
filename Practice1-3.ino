const int SWITCH = 2; // タクトスイッチが接続されているピン
const int LED = 9;    // LED が接続されているピン

void setup()
{
  pinMode(SWITCH, INPUT); // ピンを入力に設定
  pinMode(LED, OUTPUT);   // ピンを出力に設定
}

void loop()
{
  int v;
  v = digitalRead(SWITCH); // 入力を読み取る
  if (v == LOW)
  {                          // タクトスイッチが押されたとき
    digitalWrite(LED, HIGH); // LED を点灯
  }
  else
  {                         // タクトスイッチが押されていないとき
    digitalWrite(LED, LOW); // LED を消灯
  }
}
