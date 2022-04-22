const int SENSOR = 0; // 赤外線距離センサが接続されているピン(アナログ)

void setup()
{
  Serial.begin(9600); // シリアル通信の速度を設定
}

void loop()
{
  int v;
  float v_out;
  double d;
  v = analogRead(SENSOR);           // センサの出力値を読み取る
  v_out = 5.0 * v / 1023;           // 電圧値に換算
  d = 26.549 * pow(v_out, -1.2091); // 距離に換算
  Serial.print(d);                  // シリアル通信で値を送信
  Serial.println(" [cm]");          // シリアル通信で文字列を送信
  delay(200);                       // 200 ミリ秒待機
}
