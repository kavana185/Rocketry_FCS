#include "HX711.h"

// Define connections
#define DT 3  // HX711 DT (Data) pin connected to Arduino Pin 3
#define SCK 2 // HX711 SCK (Clock) pin connected to Arduino Pin 2

HX711 scale;

void setup() {
    Serial.begin(9600);
    scale.begin(DT, SCK);  // Initialize HX711
    Serial.println("HX711 Load Cell Initialized.");
    
    // Calibration factor (to be adjusted based on your load cell)
    scale.set_scale(2280.f);  // Change this value according to your sensor
    scale.tare();  // Reset the scale to 0
}

void loop() {
    Serial.print("Weight: ");
    Serial.print(-1*scale.get_units(), 4);
    Serial.print(" g"); // Change unit if needed (kg, lb, etc.)
    Serial.print("  Thrust: ");
    Serial.print(-0.00981*scale.get_units(), 4); // Get weight in calibrated units
    Serial.println(" N"); // Change unit if needed (kg, lb, etc.)
    
    delay(1000);
}
