const int LED_red = 9; // LED が接続されているピン
const int LED_blue = 10;

void setup()
{
  Serial.begin(9600);   // シリアル通信の速度を設定
  pinMode(LED_red, OUTPUT);
  pinMode(LED_blue, OUTPUT);
}

void loop()
{
  char c;
  Serial.println(Serial.available());
  if (Serial.available() > 0)
  {                    // データが送られてきたとき
    c = Serial.read(); // シリアル通信の入力を読み取る
    if (c == 'r')
    {                          // 入力が「a」の場合
      digitalWrite(LED_red, HIGH); // LED を点灯
      digitalWrite(LED_blue, LOW);      // LED を消灯
    }
    else if (c == 'b')
    {                         // 入力が「b」の場合
      digitalWrite(LED_red, LOW); // LED を消灯
      digitalWrite(LED_blue, HIGH); // LED を消灯
    }
    else if (c=='a')
    {
      digitalWrite(LED_red, HIGH);
      digitalWrite(LED_blue, HIGH);
    }
    else
    {
      digitalWrite(LED_red, LOW);  // LED を消灯
      digitalWrite(LED_blue, LOW); // LED を消灯
    }
  }
}
