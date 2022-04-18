const int LED = 9; // LED が接続されているピン

void setup()
{
  pinMode(LED, OUTPUT); // ピンを出力に設定
}

void loop()
{
  int i;
  for (i = 0; i < 255; i++)
  {                      // 繰り返し
    analogWrite(LED, i); // LED の明るさを設定
    delay(10);           // 10 ミリ秒待機
  }
  for (i = 255; i > 0; i--)
  {                      // 繰り返し
    analogWrite(LED, i); // LED の明るさを設定
    delay(10);           // 10 ミリ秒待機
  }
}
