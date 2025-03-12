# HX711 Load Cell Test Code

This folder contains a test codes for interfacing the HX711 load cell amplifier with an Arduino, for test bed. The code reads data from a single load cell and converts the raw readings into Newtons.

## Hardware Requirements
- Arduino board
- HX711 load cell amplifier module
- Load cell sensor
- Connecting wires

## Circuit Connections
| Component  | Arduino Pin |
|------------|-------------|
| HX711 DT   | 3           |
| HX711 SCK  | 13          |

## Installation
1. Install the [HX711 library](https://github.com/bogde/HX711) in the Arduino IDE.
2. Clone this repository or copy the `HX711_test.ino` file into your Arduino project directory.
3. Connect the HX711 module to the Arduino as per the circuit connections.

## Usage
1. Open the Arduino IDE and upload the `HX711_test.ino` sketch to your Arduino board.
2. Open the Serial Monitor (9600 baud) to view the weight readings.
3. The caliberation is done by linear regression. Following formula is the best possible value obtained so far.
4. The readings are converted into Newtons using the formula:
   ```cpp
   ((reading1 + 11830.91432490605) / -10.38429025) / 1000 - 0.15
   ```
5. If the HX711 module is not detected, an error message will be displayed in the Serial Monitor.

## Future Improvements
- Implement further calibration to improve accuracy.
- Connect LoRa for wireless transmission of data to ground station.
- Soldering all the connections & doing final tests.
