//モータドライバ
const int IN1 = 10; // IN1 が接続されているピン
const int IN2 = 9;  // IN2 が接続されているピン

void setup()
{
  Serial.begin(9600);   // シリアル通信の速度を設定
  pinMode(IN1, OUTPUT); // ピンを出力に設定
  pinMode(IN2, OUTPUT); // ピンを出力に設定
}

void loop()
{
  forward(255);                             // 順方向に回転
  Serial.println("Forward");                // シリアル通信で文字列を送信
  delay(500);                               // 500 ミリ秒待機
  despin(true);                             // ブレーキを使用して回転を停止
  Serial.println("Despin (with brake)");    // シリアル通信で文字列を送信
  delay(1000);                              // 1000 ミリ秒待機
  reverse(255);                             // 逆方向に回転
  Serial.println("Reverse");                // シリアル通信で文字列を送信
  delay(500);                               // 500 ミリ秒待機
  despin(false);                            // ブレーキを使用せず回転を停止
  Serial.println("Despin (without brake)"); // シリアル通信で文字列を送信
  delay(1000);                              // 1000 ミリ秒待機
}

void forward(int value) // 順方向に回転
{
  analogWrite(IN1, value);
  analogWrite(IN2, 0);
}

void reverse(int value) // 逆方向に回転
{
  analogWrite(IN1, 0);
  analogWrite(IN2, value);
}

void despin(boolean brake) // 回転を停止
{
  if (brake)
  { // ブレーキを使用するとき
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);
  }
  else
  { // ブレーキを使用しないとき
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
  }
}
