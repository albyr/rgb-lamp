// define output LEDs
#define rLED 9
#define gLED 10
#define bLED 11

// Init variables
// Counter
int i=0;
// Brightness values
int rBright=0;
int gBright=0;
int bBright=0;
// Brightness compensation values, to even out differing LEDs
int rMax=256;
int gMax=256;
int bMax=256;

void setup()
{
  pinMode(rLED, OUTPUT);
  pinMode(gLED, OUTPUT);
  pinMode(bLED, OUTPUT);
}

void loop()
{
  // Decide on brightness values
  rBright = random(rMax);
  gBright = random(gMax);
  bBright = random(bMax);
  // Fade in red
  for (i=0; i<255; i++)
  {
    analogWrite(rLED, i);
    delay(10);
  }
  // Fade out red
  for (i=255; i>0; i--)
  {
    analogWrite(rLED, i);
    delay(10);
  }
  // Fade in green
  for (i=0; i<255; i++)
  {
    analogWrite(gLED, i);
    delay(10);
  }
  // Fade out green
  for (i=255; i>0; i--)
  {
    analogWrite(gLED, i);
    delay(10);
  }
  // Fade in blue
  for (i=0; i<255; i++)
  {
    analogWrite(bLED, i);
    delay(10);
  }
  // Fade out blue
  for (i=255; i>0; i--)
  {
    analogWrite(bLED, i);
    delay(10);
  }
}
