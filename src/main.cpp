#include <Arduino.h>
#include <DHT.h>


/**
 * @file `src/main.cpp`
 * @brief DHT11 sensor example for Arduino — reads temperature and humidity and prints to Serial.
 *
 * @details
 * This sketch demonstrates basic use of the DHT sensor (DHT11).
 * - Initializes serial at 9600 baud and the DHT sensor in `setup()`.
 * - Periodically reads humidity and temperature in `loop()` and prints values.
 * - On read failure, a message is printed and the loop waits before retrying.
 *
 * Dependencies:
 * - DHT sensor library (ensure `DHT.h` is available in your project's include path).
 *
 * @note Ensure the sensor's data pin is connected to the pin defined by `DHTPIN`.
 */

/** @brief Pin the DHT sensor is connected to. */
#define DHTPIN 2

/** @brief DHT sensor model/type used by the library. */
#define DHTTYPE DHT11

/** @brief Global DHT object used to access sensor readings. */
DHT dht(DHTPIN, DHTTYPE);

/**
 * @brief Arduino setup function.
 *
 * Initializes the Serial port and the DHT sensor.
 *
 * @return void
 */
void setup() {
    Serial.begin(9600);
    dht.begin();
    Serial.println("Initializing DHT sensor!");
}

/**
 * @brief Arduino main loop.
 *
 * Reads humidity and temperature from the DHT sensor and prints values to Serial.
 * If the readings are NaN, prints an error message and waits before the next attempt.
 *
 * @return void
 */
void loop() {
    // read sensor values
    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();

    // check if any reads failed and exit early (to try again)
    if (isnan(humidity) || isnan(temperature)) {
        Serial.println("Failed to read from DHT sensor!");
        delay(2000);
        return;
    }

    Serial.println("Humidity: ");
    Serial.println(humidity);
    Serial.println("Temperature: ");
    Serial.println(temperature);
    delay(2000);
}