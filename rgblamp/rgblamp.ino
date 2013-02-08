// define output LEDs
// using pins 9, 10 and 11 because they are PWM pins
#define rLED 9
#define gLED 10
#define bLED 11

// Init variables
// Counter
int i=0;
// Brightness values
int rBrightNew=0;
int gBrightNew=0;
int bBrightNew=0;
int rBrightOld=0;
int gBrightOld=0;
int bBrightOld=0;
// Brightness compensation values, to even out differing LEDs
int rMax=256;
int gMax=256;
int bMax=256;
// Fade rate control
int fadeDelay=10;

void setup()
{
  // Set up pins
  pinMode(rLED, OUTPUT);
  pinMode(gLED, OUTPUT);
  pinMode(bLED, OUTPUT);
  // Set up serial output for debugging
  Serial.begin(9600);
}

void loop()
{
  // Decide on brightness values
  rBrightNew = random(rMax);
  gBrightNew = random(gMax);
  bBrightNew = random(bMax);
  // Output RGB values for debugging
  Serial.println("R:");
  Serial.println(rBright);
  Serial.println("G:");
  Serial.println(gBright);
  Serial.println("B:");
  Serial.println(bBright);
  Serial.println("---");
  // Fade in red
  for (i=0; i<rBright; i++)
  {
    analogWrite(rLED, i);
    delay(fadeDelay);
  }
  // Fade in green
  for (i=0; i<gBright; i++)
  {
    analogWrite(gLED, i);
    delay(fadeDelay);
  }
  // Fade in blue
  for (i=0; i<bBright; i++)
  {
    analogWrite(bLED, i);
    delay(fadeDelay);
  }
  // Fade out red
  for (i=rBright; i>0; i--)
  {
    analogWrite(rLED, i);
    delay(fadeDelay);
  }
  // Fade out green
  for (i=gBright; i>0; i--)
  {
    analogWrite(gLED, i);
    delay(fadeDelay);
  }
  // Fade out blue
  for (i=bBright; i>0; i--)
  {
    analogWrite(bLED, i);
    delay(fadeDelay);
  }
}
