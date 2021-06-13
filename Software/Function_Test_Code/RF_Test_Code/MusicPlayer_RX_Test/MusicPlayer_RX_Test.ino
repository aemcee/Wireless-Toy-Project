/*

Demonstrates simple RX and TX operation.
Any of the Basic_TX examples can be used as a transmitter.
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
#include <SD.h>                      // need to include the SD library
//#define SD_ChipSelectPin 53  //example uses hardware SS pin 53 on Mega2560
#define SD_ChipSelectPin 10  //using digital pin 4 on arduino nano 328, can use other pins. Using pin 10 for unitduino
#include <TMRpcm.h>           //  also need to include this library...
#include <SPI.h>
#include <NRFLite.h>

const static uint8_t RADIO_ID = 0;       // Our radio's id.  The transmitter will send to this id.
const static uint8_t PIN_RADIO_CE = 16;
const static uint8_t PIN_RADIO_CSN = 15;

struct RadioPacket // Any packet up to 32 bytes can be sent.
{
    uint8_t FromRadioId;
    uint32_t OnTimeMillis;
    uint32_t FailedTxCount;
    uint8_t PlaySong;
};

NRFLite _radio;
RadioPacket _radioData;


TMRpcm tmrpcm;   // create an object for use in this sketch

void setup()
{
    tmrpcm.speakerPin = 3;
    
    Serial.begin(115200);

    if (!SD.begin(SD_ChipSelectPin)) {  // see if the card is present and can be initialized:
    Serial.println("SD fail");  
    //return;   // don't do anything more if not
    }
    else{
      Serial.println("SD card ok");
    }

    // By default, 'init' configures the radio to use a 2MBPS bitrate on channel 100 (channels 0-125 are valid).
    // Both the RX and TX radios must have the same bitrate and channel to communicate with each other.
    // You can run the 'ChannelScanner' example to help select the best channel for your environment.
    // You can assign a different bitrate and channel as shown below.
    //   _radio.init(RADIO_ID, PIN_RADIO_CE, PIN_RADIO_CSN, NRFLite::BITRATE2MBPS, 100) // THE DEFAULT
    //   _radio.init(RADIO_ID, PIN_RADIO_CE, PIN_RADIO_CSN, NRFLite::BITRATE1MBPS, 75)
    //   _radio.init(RADIO_ID, PIN_RADIO_CE, PIN_RADIO_CSN, NRFLite::BITRATE250KBPS, 0)

    //digitalWrite(10, HIGH);
    if (!_radio.init(RADIO_ID, PIN_RADIO_CE, PIN_RADIO_CSN))
    {
        Serial.println("Cannot communicate with radio");
        while (1); // Wait here forever.
    }else{
      Serial.println("Radio COM OK");
    }
    //tmrpcm.play("DJ.wav");
}

void loop()
{

    while (_radio.hasData())
    {
        _radio.readData(&_radioData); // Note how '&' must be placed in front of the variable name.

        String msg = "Radio ";
        msg += _radioData.FromRadioId;
        msg += ", ";
        msg += _radioData.OnTimeMillis;
        msg += " ms, ";                                                                                                    
        msg += _radioData.FailedTxCount;
        msg += " Failed TX";
        msg += " Play Song is";
        msg += _radioData.PlaySong;

        if(_radioData.PlaySong){
          tmrpcm.play("DJ.wav");
          msg += "I play muh song"; 
        }

        Serial.println(msg);
    }
    delay(1000);
}
