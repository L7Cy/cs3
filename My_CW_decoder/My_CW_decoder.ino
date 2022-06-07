#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int colums = 16;
const int rows = 2;

int lcdindex = 0;
int line1[colums];
int line2[colums];

int audioInPin = 0;
int audioOutPin = 10;
int ledPin = 13;

float magnitude;
int magnitudelimit = 100;
int magnitudelimit_low = 100;
int realstate = LOW;
int realstatebefore = LOW;
int filteredstate = LOW;
int filteredstatebefore = LOW;

float coeff;
float Q1 = 0;
float Q2 = 0;
float sine;
float cosine;
float sampling_freq = 8928.0;
float target_freq = 744.0;
float n = 48.0;
int testData[48];

int nbtime = 6;

long starttimehigh;
long highduration;
long lasthighduration;
long highdurationavg;
long lowtimesavg;
long startttimelow;
long lowduration;
long laststarttime = 0;

char code[20];
int stop = LOW;
int wpm;

void setup()
{
  int k;
  float omega;
  k = (int)(0.5 + ((n * target_freq) / sampling_freq));
  omega = (2.0 * PI * k) / n;
  sine = sin(omega);
  cosine = cos(omega);
  coeff = 2.0 * cosine;

  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  lcd.begin(colums, rows);
  for (int index = 0; index < colums; index++)
  {
    line1[index] = 32;
    line2[index] = 32;
  }
}

void loop()
{
  for (char index = 0; index < n; index++)
  {
    testData[index] = analogRead(audioInPin);
  }
  for (char index = 0; index < n; index++)
  {
    float Q0;
    Q0 = coeff * Q1 - Q2 + (float)testData[index];
    Q2 = Q1;
    Q1 = Q0;
  }
  float magnitudeSquared = (Q1 * Q1) + (Q2 * Q2) - Q1 * Q2 * coeff;
  magnitude = sqrt(magnitudeSquared);
  Q2 = 0;
  Q1 = 0;

  if (magnitude > magnitudelimit_low)
  {
    magnitudelimit = (magnitudelimit + ((magnitude - magnitudelimit) / 6)); /// moving average filter
  }

  if (magnitudelimit < magnitudelimit_low) // magnitudelimit_lowは常にmagnitudelimitよりも小さくする
    magnitudelimit = magnitudelimit_low;

  if (magnitude > magnitudelimit * 0.6)//信号があるかないかの判別
  // just to have some space up
    realstate = HIGH;
  else
    realstate = LOW;

  if (realstate != realstatebefore) //変化したら
  {
    laststarttime = millis(); // start-now
  }

  if ((millis() - laststarttime) > nbtime) //状態を同期させる,delay(nbtime)じゃだめなの？
  {
    if (realstate != filteredstate) //同じじゃなきゃ同じにする
    {
      filteredstate = realstate;
    }
  }

  if (filteredstate != filteredstatebefore) //変化したら時間を記録
  {
    stop = LOW;

    if (filteredstate == HIGH)
    {
      starttimehigh = millis();
      lowduration = (millis() - startttimelow);

      if (lowduration > (highdurationavg * 2) && lowduration < highdurationavg * 5) // letter space
      {
        decode_obun();
        code[0] = '\0';
        // Serial.print("/");
      }
      if (lowduration >= highdurationavg * 5) // word space
      {
        decode_obun();
        code[0] = '\0';
        printascii(32);
        // Serial.println();
      }
    }

    if (filteredstate == LOW)
    {
      startttimelow = millis();
      highduration = (millis() - starttimehigh);

      if (highduration < (2 * highdurationavg) || highdurationavg == 0)//hightimesavgの調整
      {
        highdurationavg = (highduration + highdurationavg + highdurationavg) / 3; // now we know avg dit time ( rolling 3 avg)
      }
      if (highduration > (5 * highdurationavg))
      {
        highdurationavg = highduration + highdurationavg; // if speed decrease fast ..
      }

      if (highduration < (highdurationavg * 2) && highduration > (highdurationavg * 0.6))
      { /// 0.6 filter out false dits
        strcat(code, ".");
        // Serial.print(".");
      }
      if (highduration > (highdurationavg * 2) && highduration < (highdurationavg * 6))
      {
        strcat(code, "-");
        // Serial.print("-");
        // wpm = (wpm + (1200 / ((highduration) / 3))) / 2;
      }
    }
  }

  if ((millis() - startttimelow) > (highduration * 6) && stop == LOW)//信号がなければストップ
  {
    decode_obun();
    code[0] = '\0';
    stop = HIGH;
  }

  // if (filteredstate == HIGH)
  // {
  //   digitalWrite(ledPin, HIGH);
  //   tone(audioOutPin, target_freq);
  // }
  // else
  // {
  //   digitalWrite(ledPin, LOW);
  //   noTone(audioOutPin);
  // }

  // updateinfolinelcd();
  realstatebefore = realstate;
  lasthighduration = highduration;
  filteredstatebefore = filteredstate;
}
