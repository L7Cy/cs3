//サーボモータ
#include <Servo.h>       // サーボモータ関連ファイルのインクルード
const int SERVO = 9; // サーボモータが接続されているピン
Servo servo;         // サーボモータ

void setup()
{
  servo.attach(SERVO); // サーボモータをピンに割り当て
}

void loop()
{
  servo.write(0);      // サーボモータの回転角度を 0 度に指定
  delay(2000);      // 2,000 ミリ秒待機
  servo.write(180); // サーボモータの回転角度を 180 度に指定
  delay(2000);      // 2,000 ミリ秒待機
  servo.write(90);  // サーボモータの回転角度を 90 度に指定
  delay(2000);      // 2,000 ミリ秒待機
}
