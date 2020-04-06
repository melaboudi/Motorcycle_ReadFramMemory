#include <Arduino.h>

#include <Wire.h>
#include "Adafruit_FRAM_I2C.h"
Adafruit_FRAM_I2C fram     = Adafruit_FRAM_I2C();
uint16_t          framAddr = 0;
//char data[800] = {0};

void setup(void) {
  Serial.begin(57600);
  while (!Serial) {
    ;
  }

  if (fram.begin()) {  // you can stick the new i2c addr in here, e.g. begin(0x51);
    Serial.println("Found I2C FRAM");
  } else {
    Serial.println("I2C FRAM not identified ... check your connections?\r\n");
    Serial.println("Will continue in case this processor doesn't support repeated start\r\n");
  }
  for (uint16_t a = 0; a < 32767; a++)
  {
    uint8_t test = fram.read8(a);
    char Buffer[10] = {0};
    sprintf(Buffer, "%c", test);

    Serial.print(Buffer);
  }
  Serial.println("Finished");
}




void loop(void) {

}