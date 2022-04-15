const int SWITCH = 2; // タクトスイッチが接続されているピン
const int LED = 9;    // LED が接続されているピン
int state = 0;        // 現在の状態(0 または 1)
int count = 0;

void setup()
{
  pinMode(SWITCH, INPUT); // ピンを入力に設定
  pinMode(LED, OUTPUT);   // ピンを出力に設定
}

void loop()
{
  int v;
  v = digitalRead(SWITCH); // 入力を読み取る
  if (v == HIGH)
  {                    // タクトスイッチが押されたとき
    if(count<=100)
      count++; 
  }else{
    count=0;
  }
  if(count==100){
    state = 1 -state;
  }
  if (state == 1)
  {                          // 状態が 1 のとき
    digitalWrite(LED, HIGH); // LED を点灯
  }
  else
  {                         // 状態が 0 のとき
    digitalWrite(LED, LOW); // LED を消灯
  }
}
