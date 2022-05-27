//照度センサ
const int SENSOR = 0; // 光センサが接続されているピン(アナログ)
const int LED = 9;  // LED が接続されているピン

void setup()
{
  Serial.begin(9600);     // シリアル通信の速度を設定
  pinMode(LED, OUTPUT); // ピンを出力に設定
}

void loop()
{
  int v;
  v = analogRead(SENSOR);  // センサの出力値を読み取る
  Serial.println(v);       // シリアル通信で値を送信
  digitalWrite(LED, HIGH); // LED を点灯
  delay(v);                // v ミリ秒待機
  digitalWrite(LED, LOW);  // LED を消灯
  delay(v);                // v ミリ秒待機
}
