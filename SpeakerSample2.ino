//スピーカ
const int SPEAKER = 9; // スピーカが接続されているピン

void setup()
{
  pinMode(SPEAKER, OUTPUT); // ピンを出力に設定
}

void loop()
{
  tone(SPEAKER, 262, 500);    // 262Hz の音(ド)を 500 ミリ秒鳴らす
  delay(700);              // 700 ミリ秒待機
  tone(SPEAKER, 294, 500); // 294Hz の音(レ)を 500 ミリ秒鳴らす
  delay(700);              // 700 ミリ秒待機
  tone(SPEAKER, 330, 500); // 330Hz の音(ミ)を 500 ミリ秒鳴らす
  delay(700);              // 700 ミリ秒待機
  tone(SPEAKER, 349, 500); // 349Hz の音(ファ)を 500 ミリ秒鳴らす
  delay(700);              // 700 ミリ秒待機
  tone(SPEAKER, 392, 500); // 392Hz の音(ソ)を 500 ミリ秒鳴らす
  delay(700);              // 700 ミリ秒待機
  tone(SPEAKER, 440, 500); // 440Hz の音(ラ)を 500 ミリ秒鳴らす
  delay(700);              // 700 ミリ秒待機
  tone(SPEAKER, 494, 500); // 494Hz の音(シ)を 500 ミリ秒鳴らす
  delay(700);              // 700 ミリ秒待機
  tone(SPEAKER, 523, 500); // 523Hz の音(ド)を 500 ミリ秒鳴らす
  delay(700);              // 700 ミリ秒待機
}
