#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN 6

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags
Adafruit_NeoPixel strip = Adafruit_NeoPixel(107, PIN, NEO_GRB + NEO_KHZ800);

//button pin
const int buttonPin = 4;
int buttonState = 0;
int lightMode = 0;
int lightSubMode = 0;

void setup() {
  pinMode(buttonPin,INPUT);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
   lightMode++; 
  }
  if(lightMode == 4){
    lightMode = 0;
  }
  
  
  if(lightMode == 0){
   colorWipe(strip.Color(255, 100, 0), 50); // yellow
  }
  else if(lightMode == 1){
    colorWipe(strip.Color(255, 60, 0), 50); // orange
  }
  else if(lightMode == 2){
    colorWipe(strip.Color(255, 0, 0), 50); // red
  }
  else if(lightMode == 3){
      if(lightSubMode == 0){
        colorWipe(strip.Color(255, 100, 0), 50); // yellow
      }
      else if(lightSubMode == 1){
        colorWipe(strip.Color(255, 60, 0), 50); // orange
      }
      lightSubMode++;
      if(lightSubMode==2){
        lightSubMode = 0;
      }
  }
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}
