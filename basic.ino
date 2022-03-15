
// Einfacher Farbverlauf zwischen zwei Farben

#include <Adafruit_NeoPixel.h>

#define SENSOR_PIN 7 // Pin des Bewegungssensors
#define NUM_LED 150 //Anzahl der LEDs
#define LED_PIN 6 //Anschlusspin des LED-Streifens

#define ANIMATION_TIME 2000 //Dauer der Animation

Adafruit_NeoPixel led(NUM_LED, LED_PIN, NEO_GRB+NEO_KHZ800);

void setup() {
  led.begin(); //Einrichten des LED-Outputs
  led.setBrightness(64); //Maximale Helligkeit
  led.clear();
  led.show();
  turnOn();
  turnOff();
}

// Liefert Rotwert (0-255) für die LED an der jeweiligen Stelle zurück.
int getR(int index) {
  if(index < NUM_LED * 0.5) {
        return (index / (NUM_LED * 0.5)) * 255;
  } else {
    return 255 - ((index - (NUM_LED * 0.5)) / (NUM_LED * 0.5)) * 255;   
  }
}

// Liefert Grünwert (0-255) für die LED an der jeweiligen Stelle zurück.
int getG(int index) {
  if(index < NUM_LED * 0.5) {
        return 255 - ((index / (NUM_LED * 0.5)) * 255);
  } else {
      return 0;
  }
}

// Liefert Blauwert (0-255) für die LED an der jeweiligen Stele zurück.
int getB(int index) {
  if(index < NUM_LED * 0.5) {
    return 0;
  }  else {
    return ((index - (NUM_LED * 0.5)) / (NUM_LED * 0.5)) * 255;
  }
}

// Spielt die Aktivierungs-Animation ab.
void turnOn() {
  int delayTime = (ANIMATION_TIME / NUM_LED);
  for(int i = 0; i < NUM_LED; i++) {
    led.setPixelColor(i,getR(i), getG(i), getB(i));
    led.show();
    delay(delayTime);
  }
}

// Deaktiviert die LEDs mit Zeitverzögerung
void turnOff() {
  int delayTime = (ANIMATION_TIME / NUM_LED);
  for(int i = 0; i < NUM_LED; i++) {
    led.setPixelColor(i, 0,0,0);
    led.show();
    delay(delayTime);
  }
}

void loop() {
  if(digitalRead(SENSOR_PIN)) { // Signal vom Sensor auswerten
      turnOn();
      delay(5000);
      turnOff();
  }
  delay(100);
} 
