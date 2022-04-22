const int SENSOR = 0; // 光センサが接続されているピン(アナログ)
const int LED = 9;    // LED が接続されているピン
float rc =0;
int v=0;
#define a 0.8

void setup()
{
  Serial.begin(9600);   // シリアル通信の速度を設定
  pinMode(LED, OUTPUT); // ピンを出力に設定
}

void loop()
{
  v = analogRead(SENSOR); // センサの出力値を読み取る
  rc = a * rc + (1 - a) * (float)v;
  Serial.println(rc);      // シリアル通信で値を送信
  digitalWrite(LED, HIGH); // LED を点灯
  delay(rc);               // v ミリ秒待機
  digitalWrite(LED, LOW);  // LED を消灯
  delay(rc);               // v ミリ秒待機
}
