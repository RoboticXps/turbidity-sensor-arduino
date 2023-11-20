/*
Example for Water Turbidity Sensor and LCD Screen with Arduino Uno.
By: RoboticX Team
*/

#include <LiquidCrystal_I2C.h>

const int sensorPin = A0; // Define the analog pin connected to the sensor
const float conversionFactor = 5.0 / 1024.0; // Conversion factor to convert analog value to voltage
const float turbidityThreshold = 3.4; // Threshold for water turbidity

LiquidCrystal_I2C lcd(0x27, 16, 2); // Set the I2C address of the LCD

void setup() {
  // Initialize the LCD
  lcd.init();
  // Turn on the backlight
  lcd.backlight();
  // Initialize serial communication
  Serial.begin(9600); //Baud rate: 9600
}

void loop() {
  // Read sensor value from analog pin A0
  int sensorValue = analogRead(sensorPin);
  float voltage = sensorValue * conversionFactor;

  // Display sensor value and turbidity status on the LCD
  lcd.setCursor(0, 0);
  lcd.print("Cleanliness: ");
  lcd.print(voltage);

  lcd.setCursor(0, 1);
  lcd.print("Result: ");

  if (voltage < turbidityThreshold) {
    lcd.print("Dirty Water");
  } else {
    lcd.print("Clean Water");
  }

  lcd.setCursor(0, 2);
  lcd.println("RoboticX");

  // Print sensor value to the serial monitor
  Serial.println(voltage);

  delay(500); // Delay for 500 milliseconds

}
