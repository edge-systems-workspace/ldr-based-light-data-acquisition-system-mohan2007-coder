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
 // write your initialization code here
 Serial.begin(9600);
 pinMode(LDR_PIN,INPUT);
 Serial.println("LDR test");

}

/**
 * @brief Main Arduino loop that reads and reports light intensity.
 *
 * Reads the raw analog value from the LDR pin using analogRead(). The raw
 * reading (0..1023) is converted to a simple percentage (0..100) using
 * map(). The raw value and percentage are printed to the serial console.
 * The loop then waits 500 ms before repeating.
 *
 * @detail
 * - Raw range: 0 (dark) .. 1023 (bright) depending on wiring and divider.
 * - The map() call inverts the percentage so that 0 -> 100% (bright) and
 *   1023 -> 0% (dark) to provide an intuitive "Light: X%" readout.
 *
 * @note Adjust the map() parameters if your voltage divider produces a
 * different range or polarity.
 */
void loop() {
 // write your code here
 int ldrRaw = analogRead(LDR_PIN);
 int lightPerecentage = map(ldrRaw, 0, 1023, 0, 100);
 Serial.println("LDRRaw");
 Serial.println(ldrRaw);
 Serial.println(" | light: ");
 Serial.println(lightPerecentage);
 Serial.println("%");
 delay(500);
}