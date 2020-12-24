#include <Adafruit_NeoPixel.h>
#include <SoftwareSerial.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#define PIN 5 // Hier wird angegeben, an welchem digitalen Pin die WS2812 LEDs bzw. NeoPixel angeschlossen sind
#define NUMPIXELS 12 // Hier wird die Anzahl der angeschlossenen WS2812 LEDs bzw. NeoPixel angegeben
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
SoftwareSerial sensor(10, 11); // RX, TX

int pause_time = 5000; // 100 Millisekunden Pause bis zur Ansteuerung der nächsten LED.
const long samplePeriod = 5000L;
const byte requestReading[] = {0xFF, 0x01, 0x86, 0x00, 0x00, 0x00, 0x00, 0x00, 0x79};
byte result[9];
long lastSampleTime = 0;

void setup()
{
  pixels.begin(); // Initialisierung der NeoPixel
  Serial.begin(9600);
  sensor.begin(9600);
}

void loop()
{
  long now = millis();
  if (now > lastSampleTime + samplePeriod) {
    lastSampleTime = now;
    int ppmS = readPPMSerial();
    Serial.println(ppmS);

    if (ppmS < 400 ) {
      pixels.setPixelColor(3, pixels.Color(0, 10, 0)); // Pixel1 leuchtet in der Farbe Grün
      pixels.setPixelColor(4, pixels.Color(0, 10, 0)); // Pixel1 leuchtet in der Farbe Grün
      pixels.setPixelColor(5, pixels.Color(0, 10, 0)); // Pixel1 leuchtet in der Farbe Grün
      pixels.setPixelColor(6, pixels.Color(0, 10, 0)); // Pixel1 leuchtet in der Farbe Grün
      pixels.setPixelColor(7, pixels.Color(0, 10, 0)); // Pixel1 leuchtet in der Farbe Grün
      pixels.setPixelColor(8, pixels.Color(0, 10, 0)); // Pixel1 leuchtet in der Farbe Grün
      pixels.setPixelColor(9, pixels.Color(0, 10, 0)); // Pixel1 leuchtet in der Farbe Grün
      pixels.setPixelColor(10, pixels.Color(0, 10, 0)); // Pixel1 leuchtet in der Farbe Grün
      pixels.setPixelColor(11, pixels.Color(0, 10, 0)); // Pixel1 leuchtet in der Farbe Grün
      pixels.show();
      delay(pause_time);
    }
    

    if (ppmS >= 400 && ppmS <500 ) {
      pixels.setPixelColor(3, pixels.Color(0, 10, 0)); // Pixel1 leuchtet in der Farbe Grün
      pixels.setPixelColor(4, pixels.Color(0, 0, 0)); // Pixel1 leuchtet in der Farbe Grün
      pixels.setPixelColor(5, pixels.Color(0, 0, 0)); // Pixel1 leuchtet in der Farbe Grün
      pixels.setPixelColor(6, pixels.Color(0, 0, 0)); // Pixel1 leuchtet in der Farbe Grün
      pixels.setPixelColor(7, pixels.Color(0, 0, 0)); // Pixel1 leuchtet in der Farbe Grün
      pixels.setPixelColor(8, pixels.Color(0, 0, 0)); // Pixel1 leuchtet in der Farbe Grün
      pixels.setPixelColor(9, pixels.Color(0, 0, 0)); // Pixel1 leuchtet in der Farbe Grün
      pixels.setPixelColor(10, pixels.Color(0, 0, 0)); // Pixel1 leuchtet in der Farbe Grün
      pixels.setPixelColor(11, pixels.Color(0, 0, 0)); // Pixel1 leuchtet in der Farbe Grün
      pixels.show();
      delay(pause_time);
    }
    
    if (ppmS >= 600 && ppmS < 700 ) {
      pixels.setPixelColor(3, pixels.Color(0, 10, 0)); // Pixel1 leuchtet in der Farbe Grün
      pixels.setPixelColor(4, pixels.Color(0, 20, 0)); // Pixel1 leuchtet in der Farbe Grün
      pixels.setPixelColor(5, pixels.Color(0, 0, 0)); // Pixel1 leuchtet in der Farbe Grün
      pixels.setPixelColor(6, pixels.Color(0, 0, 0)); // Pixel1 leuchtet in der Farbe Grün
      pixels.setPixelColor(7, pixels.Color(0, 0, 0)); // Pixel1 leuchtet in der Farbe Grün
      pixels.setPixelColor(8, pixels.Color(0, 0, 0)); // Pixel1 leuchtet in der Farbe Grün
      pixels.setPixelColor(9, pixels.Color(0, 0, 0)); // Pixel1 leuchtet in der Farbe Grün
      pixels.setPixelColor(10, pixels.Color(0, 0, 0)); // Pixel1 leuchtet in der Farbe Grün
      pixels.setPixelColor(11, pixels.Color(0, 0, 0)); // Pixel1 leuchtet in der Farbe Grün
      pixels.show();
      delay(pause_time);
    }

    if (ppmS >= 700 && ppmS < 800 ) {
      pixels.setPixelColor(3, pixels.Color(0, 10, 0)); // Pixel1 leuchtet in der Farbe Grün
      pixels.setPixelColor(4, pixels.Color(0, 20, 0)); // Pixel1 leuchtet in der Farbe Grün
      pixels.setPixelColor(5, pixels.Color(0, 30, 0)); // Pixel1 leuchtet in der Farbe Grün
      pixels.setPixelColor(6, pixels.Color(0, 0, 0)); // Pixel1 leuchtet in der Farbe Grün
      pixels.setPixelColor(7, pixels.Color(0, 0, 0)); // Pixel1 leuchtet in der Farbe Grün
      pixels.setPixelColor(8, pixels.Color(0, 0, 0)); // Pixel1 leuchtet in der Farbe Grün
      pixels.setPixelColor(9, pixels.Color(0, 0, 0)); // Pixel1 leuchtet in der Farbe Grün
      pixels.setPixelColor(10, pixels.Color(0, 0, 0)); // Pixel1 leuchtet in der Farbe Grün
      pixels.setPixelColor(11, pixels.Color(0, 0, 0)); // Pixel1 leuchtet in der Farbe Grün
      pixels.show();
      delay(pause_time);
    }

    if (ppmS >= 800 && ppmS < 900 ) {
      pixels.setPixelColor(3, pixels.Color(0, 10, 0)); // Pixel1 leuchtet in der Farbe Grün
      pixels.setPixelColor(4, pixels.Color(0, 20, 0)); // Pixel1 leuchtet in der Farbe Grün
      pixels.setPixelColor(5, pixels.Color(0, 30, 0)); // Pixel1 leuchtet in der Farbe Grün
      pixels.setPixelColor(6, pixels.Color(20, 30, 0)); // Pixel1 leuchtet in der Farbe Grün
      pixels.setPixelColor(7, pixels.Color(0, 0, 0)); // Pixel1 leuchtet in der Farbe Grün
      pixels.setPixelColor(8, pixels.Color(0, 0, 0)); // Pixel1 leuchtet in der Farbe Grün
      pixels.setPixelColor(9, pixels.Color(0, 0, 0)); // Pixel1 leuchtet in der Farbe Grün
      pixels.setPixelColor(10, pixels.Color(0, 0, 0)); // Pixel1 leuchtet in der Farbe Grün
      pixels.setPixelColor(11, pixels.Color(0, 0, 0)); // Pixel1 leuchtet in der Farbe Grün
      pixels.show();
      delay(pause_time);
    }

    if (ppmS >= 900 && ppmS < 1000 ) {
      pixels.setPixelColor(3, pixels.Color(0, 10, 0));
      pixels.setPixelColor(4, pixels.Color(0, 20, 0));
      pixels.setPixelColor(5, pixels.Color(0, 30, 0));
      pixels.setPixelColor(6, pixels.Color(5, 30, 0));
      pixels.setPixelColor(7, pixels.Color(10, 30, 0));
      pixels.setPixelColor(8, pixels.Color(0, 0, 0));
      pixels.setPixelColor(9, pixels.Color(0, 0, 0));
      pixels.setPixelColor(10, pixels.Color(0, 0, 0));
      pixels.setPixelColor(11, pixels.Color(0, 0, 0));
      pixels.show();
      delay(pause_time);
    }

    if (ppmS >= 1000 && ppmS < 1100 ) {
      pixels.setPixelColor(3, pixels.Color(0, 10, 0));
      pixels.setPixelColor(4, pixels.Color(0, 20, 0));
      pixels.setPixelColor(5, pixels.Color(0, 30, 0));
      pixels.setPixelColor(6, pixels.Color(5, 30, 0));
      pixels.setPixelColor(7, pixels.Color(10, 30, 0));
      pixels.setPixelColor(8, pixels.Color(20, 30, 0));
      pixels.setPixelColor(9, pixels.Color(0, 0, 0));
      pixels.setPixelColor(10, pixels.Color(0, 0, 0));
      pixels.setPixelColor(11, pixels.Color(0, 0, 0));
      pixels.show();
      delay(pause_time);
    }
    if (ppmS >= 1100 && ppmS < 1200 ) {
      pixels.setPixelColor(3, pixels.Color(0, 10, 0));
      pixels.setPixelColor(4, pixels.Color(0, 20, 0));
      pixels.setPixelColor(5, pixels.Color(0, 30, 0));
      pixels.setPixelColor(6, pixels.Color(5, 30, 0));
      pixels.setPixelColor(7, pixels.Color(10, 30, 0));
      pixels.setPixelColor(8, pixels.Color(20, 30, 0));
      pixels.setPixelColor(9, pixels.Color(50, 0, 0));
      pixels.setPixelColor(10, pixels.Color(0, 0, 0));
      pixels.setPixelColor(11, pixels.Color(0, 0, 0));
      pixels.show();
      delay(pause_time);
    }
    if (ppmS >= 1200 && ppmS < 1300 ) {
      pixels.setPixelColor(3, pixels.Color(0, 10, 0));
      pixels.setPixelColor(4, pixels.Color(0, 20, 0));
      pixels.setPixelColor(5, pixels.Color(0, 30, 0));
      pixels.setPixelColor(6, pixels.Color(5, 30, 0));
      pixels.setPixelColor(7, pixels.Color(10, 30, 0));
      pixels.setPixelColor(8, pixels.Color(20, 30, 0));
      pixels.setPixelColor(9, pixels.Color(50, 0, 0));
      pixels.setPixelColor(10, pixels.Color(70, 0, 0));
      pixels.setPixelColor(11, pixels.Color(0, 0, 0));
      pixels.show();
      delay(pause_time);
    }
    if (ppmS >= 1300 ) {
      pixels.setPixelColor(3, pixels.Color(50, 0, 0));
      pixels.setPixelColor(4, pixels.Color(50, 0, 0));
      pixels.setPixelColor(5, pixels.Color(50, 0, 0));
      pixels.setPixelColor(6, pixels.Color(50, 0, 0));
      pixels.setPixelColor(7, pixels.Color(50, 0, 0));
      pixels.setPixelColor(8, pixels.Color(50, 0, 0));
      pixels.setPixelColor(9, pixels.Color(50, 0, 0));
      pixels.setPixelColor(10, pixels.Color(50, 0, 0));
      pixels.setPixelColor(11, pixels.Color(50, 0, 0));
      pixels.show();
      delay(pause_time);
    }
  }
}

int readPPMSerial() {
  for (int i = 0; i < 9; i++) {
    sensor.write(requestReading[i]);
  }

  while (sensor.available() < 9) {};
  for (int i = 0; i < 9; i++) {
    result[i] = sensor.read();
  }
  int high = result[2];
  int low = result[3];

  return high * 256 + low;
}
