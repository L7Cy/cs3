const int LED = 9; // LED が接続されているピン

void setup()
{
  Serial.begin(9600);   // シリアル通信の速度を設定
  pinMode(LED, OUTPUT); // ピンを出力に設定
}

void loop()
{
  char c;
  if (Serial.available() > 0)
  {                    // データが送られてきたとき
    c = Serial.read(); // シリアル通信の入力を読み取る
    if (c == 'a')
    {                          // 入力が「a」の場合
      digitalWrite(LED, HIGH); // LED を点灯
    }
    else if (c == 'b')
    {                         // 入力が「b」の場合
      digitalWrite(LED, LOW); // LED を消灯
    }
  }
}
