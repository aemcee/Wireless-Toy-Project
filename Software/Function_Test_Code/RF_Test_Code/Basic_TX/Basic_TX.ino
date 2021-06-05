/*

Demonstrates simple RX and TX operation.
Any of the Basic_RX examples can be used as a receiver.
Please read through 'NRFLite.h' for a description of all the methods available in the library.

Radio    Arduino
CE    -> 16
CSN   -> 15 (Hardware SPI SS)
MOSI  -> 11 (Hardware SPI MOSI)
MISO  -> 12 (Hardware SPI MISO)
SCK   -> 13 (Hardware SPI SCK)
IRQ   -> No connection
VCC   -> No more than 3.6 volts
GND   -> GND

*/

#include <SPI.h>
#include <NRFLite.h>
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns

//define the symbols on the buttons of the keypads. Note 'X' and 'Y' are don't cares since hardware does not support it
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'X','0','D','Y'}
};

byte rowPins[ROWS] = {8, 9, 10, 14}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {2, 3, 7, 5}; //connect to the column pinouts of the keypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 



const static uint8_t RADIO_ID = 1;             // Our radio's id.
const static uint8_t DESTINATION_RADIO_ID = 0; // Id of the radio we will transmit to.
const static uint8_t PIN_RADIO_CE = 16;
const static uint8_t PIN_RADIO_CSN = 15;

struct RadioPacket // Any packet up to 32 bytes can be sent.
{
    uint8_t LED0;
    uint8_t LED1;
    uint8_t LED2;
    uint8_t LED3;
    uint8_t FAN;
   
};
char red = 0x04, green = 0x02, blue = 0x01, yellow = 0x06, magenta = 0x05, cyan = 0x03, white = 0x07;
NRFLite _radio;
RadioPacket _radioData;

void setup()
{
    Serial.begin(115200);
    
    
    if (!_radio.init(RADIO_ID, PIN_RADIO_CE, PIN_RADIO_CSN))
    {
        Serial.println("Cannot communicate with radio");
        while (1); // Wait here forever.
    }
    
 
}

void loop()
{

  char customKey = customKeypad.getKey();
  if (customKey){
    char assign = customKey;
  _radioData.LED0 = assign-48;
  _radioData.LED1 = assign-48;
  _radioData.LED2 = assign-48;
  _radioData.LED3 = assign-48;
  //Serial.println(_radioData.FAN,HEX);
  }
  _radio.send(DESTINATION_RADIO_ID,&_radioData,sizeof(_radioData));
    delay(500);
for (char i = 0; i<8 ; i++){
  _radioData.LED0 = i;
  _radioData.LED1 = i;
  _radioData.LED2 = i;
  _radioData.LED3 = i;
  _radioData.FAN = i*30;
    _radio.send(DESTINATION_RADIO_ID,&_radioData,sizeof(_radioData));
    delay(500);
}
}
