// #include <LiquidCrystal.h>

// LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// const int colums = 20; /// have to be 16 or 20
// const int rows = 4;    /// have to be 2 or 4

// int lcdindex = 0;
// int line1[colums];
// int line2[colums];

int audioInPin = 0;
int audioOutPin = 10;
int ledPin = 13;

float magnitude;
int magnitudelimit = 100;
int magnitudelimit_low = 100; //固定
int realstate = LOW;
int realstatebefore = LOW;
int filteredstate = LOW;
int filteredstatebefore = LOW;

///////////////////////////////////////////////////////////
// The sampling frq will be 8928 on a 16 mhz             //
// without any prescaler etc                             //
// because we need the tone in the center of the bins    //
// you can set the tone to 496, 558, 744 or 992          //
// then n the number of samples which give the bandwidth //
// can be (8928 / tone) * 1 or 2 or 3 or 4 etc           //
// init is 8928/558 = 16 *4 = 64 samples                 //
// try to take n = 96 or 128 ;o)                         //
// 48 will give you a bandwidth around 186 hz            //
// 64 will give you a bandwidth around 140 hz            //
// 96 will give you a bandwidth around 94 hz             //
// 128 will give you a bandwidth around 70 hz            //
// BUT remember that high n take a lot of time           //
// so you have to find the compromice - i use 48         //
///////////////////////////////////////////////////////////

float coeff;
float Q1 = 0;
float Q2 = 0;
float sine;
float cosine;
float sampling_freq = 8928.0;
float target_freq = 744.0; /// adjust for your needs see above
float n = 48.0;
int testData[48];

int nbtime = 6; /// ms noise blanker

long starttimehigh;
long highduration;
long lasthighduration;
long highdurationsvg;
long lowtimesavg;
long startttimelow;
long lowduration;
long laststarttime = 0;

char code[20];

int wpm;

int count = 0;

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

  // lcd.clear();
  // lcd.begin(colums, rows);
  // for (int index = 0; index < colums; index++)
  // {
  //   line1[index] = 32;
  //   line2[index] = 32;
  // }
}

void loop()
{
  for (char index = 0; index < n; index++)
  {
    testData[index] = analogRead(audioInPin);
  }
  goertzel();

  if (magnitudelimit_low < magnitude)
  {
    magnitudelimit = (magnitudelimit + ((magnitude - magnitudelimit) / 6)); /// moving average filter
    if (magnitudelimit < magnitudelimit_low)                                // magnitudelimit_lowは常にmagnitudelimitよりも小さい
      magnitudelimit = magnitudelimit_low;
  }

  if ((magnitudelimit * 0.6) < magnitude)
    realstate = HIGH;
  else
    realstate = LOW;

  if (realstate != realstatebefore) //変化したら
  {
    laststarttime = millis();
  }

  if (nbtime < (millis() - laststarttime)) //状態を同期させる
  {
    if (realstate != filteredstate) //同じじゃなきゃ同じにする
    {
      filteredstate = realstate;
    }
  }

  if (filteredstate != filteredstatebefore) //変化したら
  {
    if (filteredstate == HIGH)
    {
      starttimehigh = millis();
      lowduration = (millis() - startttimelow);

      float lacktime = 1;
      // checklacktime();

      if ((highdurationsvg * (2 * lacktime)) < lowduration)
      {
        docode();
        count++;
        if (highdurationsvg * (5 * lacktime) <= lowduration)
        { // word space
          printascii(32);
          if (50 < count)
          {
            Serial.println(wpm);
            count = 0;
          }
        }
      }
    }

    if (filteredstate == LOW)
    {
      startttimelow = millis();
      highduration = (millis() - starttimehigh);
      calcavg();

      if ((highdurationsvg * 0.6) < highduration && highduration < (highdurationsvg * 2))
      { /// 0.6 filter out false dits
        strcat(code, ".");
      }
      if ((highdurationsvg * 2) <= highduration && highduration < (highdurationsvg * 6))
      {
        strcat(code, "-");
        wpm = (wpm + (1200 / ((highduration) / 3))) / 2;
      }
    }
  }

  if (filteredstate == HIGH)
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }

  // updateinfolinelcd();
  realstatebefore = realstate;
  lasthighduration = highduration;
  filteredstatebefore = filteredstate;
}
