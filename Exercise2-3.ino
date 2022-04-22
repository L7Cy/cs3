const int SENSOR = 0; // 光センサが接続されているピン(アナログ)
const int LED = 9;    // LED が接続されているピン

void setup()
{
  Serial.begin(9600);   // シリアル通信の速度を設定
  pinMode(LED, OUTPUT); // ピンを出力に設定
}

void loop()
{
  int v1,v2;
  v1 = analogRead(SENSOR);  // センサの出力値を読み取る
  v2 = map(v1, 0, 1023, 0, 255); // 10 ビットから 8 ビットへ変換
  Serial.println(v2);       // シリアル通信で値を送信
  analogWrite(LED, v2); // LED を点灯
}
