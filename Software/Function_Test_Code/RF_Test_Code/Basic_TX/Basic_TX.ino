<<<<<<< HEAD
/*

Demonstrates simple RX and TX operation.
Any of the Basic_RX examples can be used as a receiver.
Please read through 'NRFLite.h' for a description of all the methods available in the library.

Radio    Arduino
CE    -> 9 (for uno), 16 (for unit)
CSN   -> 10 (Hardware SPI SS) (for uno), 15 (for unit)
MOSI  -> 11 (Hardware SPI MOSI)
MISO  -> 12 (Hardware SPI MISO)
SCK   -> 13 (Hardware SPI SCK)
IRQ   -> No connection
VCC   -> No more than 3.6 volts
GND   -> GND

*/

#include <SPI.h>
#include <NRFLite.h>

const static uint8_t RADIO_ID = 1;             // Our radio's id.
const static uint8_t DESTINATION_RADIO_ID = 0; // Id of the radio we will transmit to.
const static uint8_t PIN_RADIO_CE = 9;
const static uint8_t PIN_RADIO_CSN = 10;

struct RadioPacket // Any packet up to 32 bytes can be sent.
{
    uint8_t FromRadioId;
    uint32_t OnTimeMillis;
    uint32_t FailedTxCount;
    uint8_t PlaySong;
};

int dummy = 0; 

NRFLite _radio;
RadioPacket _radioData;

void setup()
{
    Serial.begin(115200);
    
    // By default, 'init' configures the radio to use a 2MBPS bitrate on channel 100 (channels 0-125 are valid).
    // Both the RX and TX radios must have the same bitrate and channel to communicate with each other.
    // You can run the 'ChannelScanner' example to help select the best channel for your environment.
    // You can assign a different bitrate and channel as shown below.
    //   _radio.init(RADIO_ID, PIN_RADIO_CE, PIN_RADIO_CSN, NRFLite::BITRATE2MBPS, 100) // THE DEFAULT
    //   _radio.init(RADIO_ID, PIN_RADIO_CE, PIN_RADIO_CSN, NRFLite::BITRATE1MBPS, 75)
    //   _radio.init(RADIO_ID, PIN_RADIO_CE, PIN_RADIO_CSN, NRFLite::BITRATE250KBPS, 0)
    
    if (!_radio.init(RADIO_ID, PIN_RADIO_CE, PIN_RADIO_CSN))
    {
        Serial.println("Cannot communicate with radio");
        while (1); // Wait here forever.
    }
    
    _radioData.FromRadioId = RADIO_ID;
}

void loop()
{
    _radioData.OnTimeMillis = millis();

//    Serial.print("Sending ");
//    Serial.print(_radioData.OnTimeMillis);
//    Serial.print(" ms");

    // By default, 'send' transmits data and waits for an acknowledgement.  If no acknowledgement is received,
    // it will try again up to 16 times.  This retry logic is built into the radio hardware itself, so it is very fast.
    // You can also perform a NO_ACK send that does not request an acknowledgement.  In this situation, the data packet
    // will only be transmitted a single time and there is no verification of delivery.  So NO_ACK sends are suited for
    // situations where performance is more important than reliability.
    //   _radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData), NRFLite::REQUIRE_ACK) // THE DEFAULT
    //   _radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData), NRFLite::NO_ACK)

     dummy = Serial.read(); 
      Serial.print("dummy is ..."); 
      Serial.print(dummy);
  
      if(dummy == 116){ //send the letter t over the serial monitor to start playback
          Serial.print("sending start cmd"); 
          _radioData.PlaySong = 1; 

          if (_radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData))) // Note how '&' must be placed in front of the variable name.
          {
            Serial.print("...Success");
          }
      else
          {
            Serial.print("...Failed");
            _radioData.FailedTxCount++;
          }
        }
//      if(dummy == 112){ //send the letter p over the serial monitor to start playback
//          Serial.print("sending stop cmd"); 
//          _radioData.PlaySong = 0; 
//        }
      _radioData.PlaySong = 0; 
      dummy = 0;
      Serial.print("dummy is ..."); 
      Serial.println(dummy);
      delay(1000);
}
=======
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
>>>>>>> ce5a902053183234d1600abe7bf83e4eb2666f43
