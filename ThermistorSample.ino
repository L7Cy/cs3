//温度センサ
const int THERMISTOR = 0; // 温度センサが接続されているピン(アナログ)

void setup()
{
  Serial.begin(9600); // シリアル通信の速度を設定
}

void loop()
{
  int v;
  float temp;
  v = analogRead(THERMISTOR);                // センサの出力値を読み込む
  temp = (v * 5000.0 / 1024 - 500.0) / 10.0; // 温度に換算
  Serial.println(temp);                      // シリアル通信で値を送信
  delay(200);                                // 200 ミリ秒待機
}
