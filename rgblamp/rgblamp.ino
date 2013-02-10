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
int totalBrightness=0;
int minBrightness=461;
// Brightness compensation values, to even out differing LEDs
int rMax=256;
int gMax=256;
int bMax=256;
// Fade rate control
int fadeDelay=25;

void setup() {
  // Set up pins
  pinMode(rLED, OUTPUT);
  pinMode(gLED, OUTPUT);
  pinMode(bLED, OUTPUT);
  // Seed random number generator by reading value from unconnected pin
  randomSeed(analogRead(0));
  // Set up serial output for debugging
  Serial.begin(9600);
}

void loop() {
  // Create random brightness values and check if lamp is going to be too dim
  do {
    rBrightNew = random(rMax);
    gBrightNew = random(gMax);
    bBrightNew = random(bMax);
    totalBrightness = rBrightNew + gBrightNew + bBrightNew;
  } 
  while (totalBrightness <= minBrightness);
  // Begin colour-cycling
  // Compare current and new brightness of red LED
  if (rBrightNew <= rBrightOld) {
    // Decrease brightness if new brightness < old brightness
    for (i=rBrightOld; i>=rBrightNew; i--) {
      analogWrite(rLED, i);
      delay(fadeDelay);
    }
    // Store current brightness as old brightness
    rBrightOld = rBrightNew;
  }
  else {
    // Increase brightness if new brightness > old brightness
    for (i=rBrightOld; i<=rBrightNew; i++) {
      analogWrite(rLED, i);
      delay(fadeDelay);
    }
    // Store current brightness as old brightness
    rBrightOld = rBrightNew;
  }
  // Compare current and new brightness of green LED
  if (gBrightNew <= gBrightOld) {
    // Decrease brightness if new brightness < old brightness
    for (i=gBrightOld; i>=gBrightNew; i--) {
      analogWrite(gLED, i);
      delay(fadeDelay);
    }
    // Store current brightness as old brightness
    gBrightOld = gBrightNew;
  }
  else {
    // Increase brightness if new brightness > old brightness
    for (i=gBrightOld; i<=gBrightNew; i++) {
      analogWrite(gLED, i);
      delay(fadeDelay);
    }
    // Store current brightness as old brightness
    gBrightOld = gBrightNew;
  }
  // Compare current and new brightness of red LED
  if (bBrightNew <= bBrightOld) {
    // Decrease brightness if new brightness < old brightness
    for (i=bBrightOld; i>=bBrightNew; i--) {
      analogWrite(bLED, i);
      delay(fadeDelay);
    }
    // Store current brightness as old brightness
    bBrightOld = bBrightNew;
  }
  else {
    // Increase brightness if new brightness > old brightness
    for (i=bBrightOld; i<=bBrightNew; i++) {
      analogWrite(bLED, i);
      delay(fadeDelay);
    }
    // Store current brightness as old brightness
    bBrightOld = bBrightNew;
  }
  // Debugging output
  // Serial.println("Cycle ended.");
}

