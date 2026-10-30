/**
 * @file main.cpp
 * @author Planeson (carson.cpk@proton.me)
 * @brief Test and verify the AMS Slave board.
 * @version 1.1
 * @date 2026-10-05
 *
 * @copyright Copyright (c) 2026 Red Bird Racing
 *
 */

#include <Arduino.h>
#include <mcp2515.h>

MCP2515 can(PIN_PB2);

can_frame frame = {
    .can_id = 0x123,
    .can_dlc = 8,
    .data = {0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF}};

void setup()
{
    // set LED pin as output
    pinMode(PIN_PD5, OUTPUT);
    digitalWrite(PIN_PD5, LOW);

    can.reset();
    can.setBitrate(CAN_500KBPS, MCP_20MHZ);
    can.setNormalMode();
}

void loop()
{
    while (1)
    {
        can.sendMessage(&frame);
    }
    // blink the LED
    digitalWrite(PIN_PD5, LOW);
    delay(1000);
    digitalWrite(PIN_PD5, HIGH);
    delay(1000);
}