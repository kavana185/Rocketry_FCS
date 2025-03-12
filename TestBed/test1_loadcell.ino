#include "HX711.h"

// HX711 circuit wiring
#define LOADCELL_DOUT_PIN1  3
#define LOADCELL_SCK_PIN    13
// #define LOADCELL_DOUT_PIN2  5

HX711 scale1;
// HX711 scale2;

void setup() {
  Serial.begin(9600);
  
  // Initialize the first HX711 module
  scale1.begin(LOADCELL_DOUT_PIN1, LOADCELL_SCK_PIN);
  // Initialize the second HX711 module
  // scale2.begin(LOADCELL_DOUT_PIN2, LOADCELL_SCK_PIN);
}

void loop() {
  if (scale1.is_ready()) {
    long reading1 = scale1.read();
    Serial.print("Reading 1: ");
    //Gives readings in newtons
    Serial.println(((reading1+11830.91432490605)/-10.38429025)/1000-0.15);
    //Serial.println(reading1);
  } else {
    Serial.println("HX711 not found (scale 1).");
  }
  delay(1000); // Wait for a second
}
