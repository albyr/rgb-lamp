// define output LEDs
// using pins 9, 10 and 11 because they are PWM pins
#define rLED 9
#define gLED 10
#define bLED 11

// Init variables
// Counter
int i=0;
// Brightness values
int rBrightNew=255;
int gBrightNew=255;
int bBrightNew=255;
int rBrightOld=255;
int gBrightOld=255;
int bBrightOld=255;
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
  // Begin colour-cycling
  // Compare current and new brightness of red LED
  if (rBrightNew <= rBrightOld)
  {
    // Decrease brightness if new brightness < old brightness
    for (i=rBrightOld; i>rBrightNew; i--)
    {
      analogWrite(rLED, i);
      delay(fadeDelay);
    }
    // Store current brightness as old brightness
    rBrightOld = rBrightNew;
  }
  else
  {
    // Increase brightness if new brightness > old brightness
    for (i=rBrightOld; i<rBrightNew; i++)
    {
      analogWrite(rLED, i);
      delay(fadeDelay);
    }
    // Store current brightness as old brightness
    gBrightOld = gBrightNew;
  }
  
  // Compare current and new brightness of green LED
  if (gBrightNew <= gBrightOld)
  {
    // Decrease brightness if new brightness < old brightness
    for (i=gBrightOld; i>gBrightNew; i--)
    {
      analogWrite(gLED, i);
      delay(fadeDelay);
    }
    // Store current brightness as old brightness
    gBrightOld = gBrightNew;
  }
  else
  {
    // Increase brightness if new brightness > old brightness
    for (i=gBrightOld; i<gBrightNew; i++)
    {
      analogWrite(gLED, i);
      delay(fadeDelay);
    }
    // Store current brightness as old brightness
    gBrightOld = gBrightNew;
  }
  
  // Compare current and new brightness of red LED
  if (bBrightNew <= bBrightOld)
  {
    // Decrease brightness if new brightness < old brightness
    for (i=bBrightOld; i>bBrightNew; i--)
    {
      analogWrite(bLED, i);
      delay(fadeDelay);
    }
    // Store current brightness as old brightness
    bBrightOld = bBrightNew;
  }
  else
  {
    // Increase brightness if new brightness > old brightness
    for (i=bBrightOld; i<bBrightNew; i++)
    {
      analogWrite(bLED, i);
      delay(fadeDelay);
    }
    // Store current brightness as old brightness
    bBrightOld = bBrightNew;
  }
}
