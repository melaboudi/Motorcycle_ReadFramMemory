#include <Arduino.h>

#include <Wire.h>
#include "Adafruit_FRAM_I2C.h"
Adafruit_FRAM_I2C fram     = Adafruit_FRAM_I2C();
uint16_t          framAddr = 0;
int getCounter(uint16_t initPos,uint8_t length) ;
void setup(void) {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }

  if (fram.begin()) {  // you can stick the new i2c addr in here, e.g. begin(0x51);
    Serial.println("Found I2C FRAM");
  } else {
    Serial.println("I2C{} FRAM not identified ... check your connections?\r\n");
    Serial.println("Will continue in case this processor doesn't support repeated start\r\n");
  }

  uint16_t i=0;
  // for (uint16_t a =0; a < 2080; a++)
  // {
  //   // if(a%49==0){Serial.print(i);i++;Serial.print(":");}
  //   uint8_t test = fram.read8(a);
  //   char Buffer[10] = {0};
  //   sprintf(Buffer, "%c", test);
  //   Serial.print(Buffer);
  //   // if(a%49==48){Serial.println();}
  // }
  for (uint16_t a =0; a < 32600; a++)
  {
    // if(a%49==0){Serial.print(i);i++;Serial.print(":");}
    // Serial.print("pos");
    // Serial.print(a);
    // Serial.print(": ");
    uint8_t test = fram.read8(a);
    char Buffer[10] = {0};
    sprintf(Buffer, "%c", test);
    Serial.print(Buffer);
    // if(a%49==48){Serial.println();}
  }
  // Serial.println();
  // Serial.print("32080 to 32180: ");
  // for (uint16_t a =32080; a < 32180; a++)
  // {
  //   // if(a%49==0){Serial.print(i);i++;Serial.print(":");}
  //   uint8_t test = fram.read8(a);
  //   char Buffer[10] = {0};
  //   sprintf(Buffer, "%c", test);
  //   Serial.print(Buffer);
  //   // if(a%49==48){Serial.println();}
  // }
  // Serial.println();
 
  Serial.println(" ");
  Serial.println("getCounter 32000 =");Serial.println(getCounter(32000,3));

  Serial.println("Finished");
}

void loop(void) {}

int getCounter(uint16_t initPos,uint8_t length) {
  String retour = " ";
  for (uint16_t i = initPos; i < (initPos+length); i++) {
    char Buffer[5] = {0};
    uint8_t test = fram.read8(i);
    sprintf(Buffer, "%c", test);
    retour += Buffer;
  }
  return retour.toInt();
}