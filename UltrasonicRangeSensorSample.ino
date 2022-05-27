//超音波距離センサ
const int ECHO = 2; // 超音波受信用端子(エコー)が接続されているピン
const int TRIG = 3; // 超音波送信用端子(トリガー)が接続されているピン

void setup()
{
  Serial.begin(9600);    // シリアル通信の速度を設定
  pinMode(ECHO, INPUT);  // ピンを入力に設定
  pinMode(TRIG, OUTPUT); // ピンを出力に設定
}

void loop()
{
  float duration = 0;             // 受信した時間間隔
  float distance = 0;             // 距離(mm)
  digitalWrite(TRIG, LOW);        // 超音波出力をオフ
  delayMicroseconds(2);           // 2 マイクロ秒待機
  digitalWrite(TRIG, HIGH);       // 超音波出力をオン
  delayMicroseconds(20);          // 20 マイクロ秒待機
  digitalWrite(TRIG, LOW);        // 超音波出力をオフ
  duration = pulseIn(ECHO, HIGH); // パルス継続時間を計測
  distance = duration / 2 * 340.0 / 1000;
  // 音速(340 [m/s])から距離(mm)に換算
  Serial.print(distance); // シリアル通信で値を送信
  delay(100);             // 100 ミリ秒待機
}
