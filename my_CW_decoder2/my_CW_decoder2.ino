int audioInPin = 0;

float magnitude;
int magnitudelimit = 100;
int magnitudelimit_low = 100; //固定
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

int nbtime = 6; /// ms noise blanker

long starttimehigh;
long highduration;
long highdurationsavg = 60;
long startttimelow;
long lowduration;
long laststarttime = 0;

char code[20];

int charcount = 0;

boolean wabun = false;
boolean hore = false;

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
  float magnitudeSquared = (Q1 * Q1) + (Q2 * Q2) - Q1 * Q2 * coeff; // we do only need the real part //
  magnitude = sqrt(magnitudeSquared);
  Q2 = 0;
  Q1 = 0;

  if (magnitudelimit_low < magnitude)
  {
    magnitudelimit = (magnitudelimit + ((magnitude - magnitudelimit) / 6)); /// moving average filter
    if (magnitudelimit < magnitudelimit_low)
      magnitudelimit = magnitudelimit_low;
  }

  if ((magnitudelimit * 0.6) < magnitude)
    realstate = HIGH;
  else
    realstate = LOW;

  if (realstate != realstatebefore)
  {
    laststarttime = millis();
  }

  if (nbtime < (millis() - laststarttime))
  {
    if (realstate != filteredstate)
    {
      filteredstate = realstate;
    }
  }

  if (filteredstate != filteredstatebefore)
  {
    if (filteredstate == HIGH)
    {
      starttimehigh = millis();
      lowduration = (millis() - startttimelow);

      if ((highdurationsavg * 2) < lowduration)
      {
        decode();
        charcount++;
        if (highdurationsavg * 5 <= lowduration)
        {
          Serial.write(" ");
          if (40 < charcount)
          {
            Serial.println();
            charcount = 0;
          }
        }
      }
    }
    else
    {
      startttimelow = millis();
      highduration = (millis() - starttimehigh);

      if (highduration < (2 * highdurationsavg))
      {
        highdurationsavg = (highduration + highdurationsavg + highdurationsavg) / 3;
      }

      if ((highdurationsavg * 0.6) < highduration && highduration < (highdurationsavg * 2))
      {
        strcat(code, ".");
      }
      if ((highdurationsavg * 2) <= highduration && highduration < (highdurationsavg * 6))
      {
        strcat(code, "-");
      }
    }
  }

  if ((highduration * 6) < (millis() - startttimelow))
  {
    decode();
    if ((highduration * 12) < (millis() - startttimelow))
    {
      highdurationsavg = 60;
    }
  }

  realstatebefore = realstate;
  filteredstatebefore = filteredstate;
}
