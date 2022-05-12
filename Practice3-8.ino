const int SWITCH = 2; // タクトスイッチが接続されているピン
const int LED = 9;    // LED が接続されているピン
volatile int i;       // LED の明るさ

void setup()
{
  pinMode(SWITCH, INPUT);            // ピンを入力に設定
  pinMode(LED, OUTPUT);              // ピンを出力に設定
  attachInterrupt(0, reset, FALLING); // 割り込みの設定
  //LOW:押されていない時にリセット
  //CHANGE:押された＆離されたときにリセット
  //RISING:押された時にリセット
  //FALLING:離されたときにリセット
}

void loop()
{
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

void reset(){
  i = 255; // LED の明るさをリセット
}
