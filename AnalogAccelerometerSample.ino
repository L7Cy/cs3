//３軸加速度センサ
const int SENSOR_X = 2; // 加速度センサが接続されているピン(X 軸)(アナログ)
const int SENSOR_Y = 1; // 加速度センサが接続されているピン(Y 軸)(アナログ)
const int SENSOR_Z = 0; // 加速度センサが接続されているピン(Z 軸)(アナログ)

void setup()
{
  Serial.begin(9600); // シリアル通信の速度を設定
}

void loop()
{
  int vx, vy, vz;
  double ax, ay, az;
  vx = analogRead(SENSOR_X);             // 加速度センサの X 軸の出力値を読み取る
  ax = -(3.3 * vx / 1023 - 1.65) / 0.66; // X 軸の加速度に換算
  vy = analogRead(SENSOR_Y);             // 加速度センサの Y 軸の出力値を読み取る
  ay = -(3.3 * vy / 1023 - 1.65) / 0.66; // Y 軸の加速度に換算
  vz = analogRead(SENSOR_Z);             // 加速度センサの Z 軸の出力値を読み取る
  az = -(3.3 * vz / 1023 - 1.65) / 0.66; // Z 軸の加速度に換算
  Serial.print(ax);                      // シリアル通信で値を送信
  Serial.print(",");
  Serial.print(ay);
  Serial.print(",");
  Serial.println(az);
  delay(200); // 200 ミリ秒待機
}
