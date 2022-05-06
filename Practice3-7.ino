const int VARIABLE_RESISTOR1 = 0;   // 可変抵抗 1 が接続されているピン(アナログ)
const int VARIABLE_RESISTOR2 = 1; // 可変抵抗 2 が接続されているピン(アナログ)

void setup()
{
  Serial.begin(9600); // シリアル通信の速度を設定
}

void loop()
{
  int v[2];
  byte b[2];
  Serial.write('a');                     // シリアル通信で開始合図の文字を送信
  v[0] = analogRead(VARIABLE_RESISTOR1); // 可変抵抗 1 の値を読み取る
  b[0] = map(v[0], 0, 1023, 0, 255);     // 10 ビットから 8 ビットへ変換
  v[1] = analogRead(VARIABLE_RESISTOR2); // 可変抵抗 2 の値を読み取る
  b[1] = map(v[1], 0, 1023, 0, 255);     // 10 ビットから 8 ビットへ変換
  Serial.write(b, 2);                    // シリアル通信で値を送信
  delay(100);                            // 100 ミリ秒待機
}

// Serial.write(b, 2); は
// Serial.write(b[0]); Serial.write(b[1]); と 2 回に分けて送信するのと同じ
