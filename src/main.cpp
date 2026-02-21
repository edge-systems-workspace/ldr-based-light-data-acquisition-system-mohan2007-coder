/**
 * @file main.cpp
 * @brief Automatic light intensity monitoring - Arduino sketch using an LDR
 *
 * This sketch reads an analog value from an LDR (light-dependent resistor)
 * connected to the analog pin defined by LDR_PIN, converts it into a
 * percentage representing light intensity, and prints the raw and
 * percentage values to the serial console at 500 ms intervals.
 *
 * The code is intentionally small and clear for educational and prototyping
 * use. It demonstrates analogRead, basic mapping, and serial output.
 *
 * @author Mohan Sharma
 * @date 2026-02-17
 * @version 1.0
 */

#include <Arduino.h>

/**
 * @def LDR_PIN
 * @brief Analog pin to which the LDR (voltage divider) is connected.
 *
 * The LDR should be connected as part of a voltage divider so that the
 * analog input reads a voltage between 0 and Vcc. Use A0 (LDR_PIN) by default.
 */
#define LDR_PIN A0
/**
 * @brief Arduino initialization routine.
 *
 * Sets up the serial port and configures the LDR pin as an input. Prints a
 * single banner line to the serial console to indicate the sketch has started.
 *
 * @note This function is called once by the Arduino framework during startup.
 */
void setup() {
  // Initialize serial communication at 9600 baud rate
  Serial.begin(9600);
  // Configure the LDR pin as an input (optional, as analogRead does this)
  pinMode(LDR_PIN, INPUT);
  // Print a banner to indicate the sketch has started
  Serial.println("LDR Light Intensity Monitor Started");
}

/**
 * @brief Main loop function.
 *
 * Continuously reads the analog value from the LDR, converts it to a
 * percentage, and prints both the raw and percentage values to the serial
 * console every 500 milliseconds.
 *
 * The raw value is read using analogRead, which returns a value between 0
 * (0V) and 1023 (Vcc). The percentage is calculated by mapping this range
 * to 0-100%
 */
void loop() {
  //Read the raw analog value from the LDR
  int rawValue = analogRead(LDR_PIN);
  // Convert the raw value to a percentage (0-100%)
  int percentage = map(rawValue, 0, 1023, 0, 100);
  // Print the raw value and percentage to the serial console
  Serial.print("Raw Value: ");
  Serial.print(rawValue);
  Serial.print(" | Light Intensity: ");
  Serial.print(percentage);
  Serial.println("%");
  // Wait for 500 milliseconds before the next reading
  delay(500);
}