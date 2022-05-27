//マイク・アンプ
const int MIC = 0; // マイクが接続されているピン(アナログ)

void setup()
{
  Serial.begin(9600); // シリアル通信の速度を設定
}

void loop()
{
  int v;
  v = analogRead(MIC); // センサの出力値を読み取る
  Serial.println(v);   // シリアル通信で値を送信
}
