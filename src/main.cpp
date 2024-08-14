#include "Arduino.h"

const unsigned long timeoutDuration = 1000; //
const int LED1PIN = 9;
const int LED2PIN = 11;

void setup()
{
  // initialize LED digital pin as an output.
  pinMode(LED1PIN, OUTPUT);
  pinMode(LED2PIN, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available() > 0)
  {
    unsigned long startTime = millis();
    int firstDigit = Serial.read();
    Serial.print("First Digit: ");
    Serial.println(firstDigit);

    while (Serial.available() == 0)
    {
      if (millis() - startTime > timeoutDuration)
      {
        return;
      }
    }
    int secondDigit = Serial.read();
    Serial.print("Second Digit: ");
    Serial.println(secondDigit);

    if (firstDigit == '0')
    {
      if (secondDigit == '0' || secondDigit == '1')
      {
        digitalWrite(LED1PIN, secondDigit - '0'); // Convert '0'/'1' to LOW/HIGH
        Serial.println("LED1 set");
      }
    }
    else if (firstDigit == '1')
    {
      if (secondDigit == '0' || secondDigit == '1')
      {
        digitalWrite(LED2PIN, secondDigit - '0'); // Convert '0'/'1' to LOW/HIGH
        Serial.println("LED2 set");
      }
    }
  }
}

// void loop() {
//   Serial.println("Hello world");
//   delay(1000);
// }

  // void loop()
  // {
  //   // turn the LED on (HIGH is the voltage level)
  // digitalWrite(LED_BUILTIN, HIGH);
  //   digitalWrite(PIN, HIGH);

  //   // wait for a second
  //   delay(100);

  //   // turn the LED off by making the voltage LOW
  //   digitalWrite(LED_BUILTIN, LOW);
  //   digitalWrite(PIN, LOW);

  //    // wait for a second
  //   delay(100);
  // }