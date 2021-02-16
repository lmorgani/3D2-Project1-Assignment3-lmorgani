// Goal with code:
// Neopixel: Have each LED light up as purple (can test different
// colours) as default. Set a timer to correspond with the motor 
// and silhouette "hitting" the gong, in which the LEDs will
// light up yellow (see above).
// Neopixel material: Will probably use the tinfoil bag to reflect
// the light better behind the gong.
// Motor: Have the silhouette rotate clockwise 10 degrees, counter
// clockwise 160 degrees quickly* and back clockwise to repeat.
// * the motor corrects itself when the code is played with (in
// sweep example, changing the degrees and pos >=/<= causes it
// to rotate faster.

#include <Adafruit_NeoPixel.h>
// Arduino pin connected to Neopixel
#define LED_PIN    6
// # of Neopixels
#define LED_COUNT 4

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position



void setup() {
  // put your setup code here, to run once:
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)

  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  // put your main code here, to run repeatedly:

// Code from sweep example
for (pos = 50; pos <= 120; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
// Code from sweep example


//    Code from strandtest example
        colorWipe(strip.Color(139,   0,   150), 50);
//    Code from strandtest example

    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 120; pos >= 50; pos -= 1) { // goes from 180 degrees to 0 degrees
        colorWipe(strip.Color(225,   225,   0), 50);

    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(25);                       // waits 15ms for the servo to reach the position
  }
 
}

//    Code from strandtest example
void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
//    delay(wait);                           //  Pause for a moment
  }
}
//    Code from strandtest example
