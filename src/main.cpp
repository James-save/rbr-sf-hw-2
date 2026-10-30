/**
 * @file main.cpp
 * @author Planeson (carson.cpk@proton.me)
 * @brief Test and verify the AMS Slave board.
 * @version 1.0
 * @date 2026-10-05
 *
 * @copyright Copyright (c) 2026 Red Bird Racing
 *
 */

#include <Arduino.h>

void setup()
{
    // set LED pin as output
    pinMode(PIN_PD5, OUTPUT);
    digitalWrite(PIN_PD5, LOW);
}

void loop()
{
    // blink the LED
    digitalWrite(PIN_PD5, LOW);
    delay(1000);
    digitalWrite(PIN_PD5, HIGH);
    delay(1000);
}