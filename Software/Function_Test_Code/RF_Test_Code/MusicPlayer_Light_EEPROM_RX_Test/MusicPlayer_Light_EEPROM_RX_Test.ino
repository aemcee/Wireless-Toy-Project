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
#include <Wire.h>
#include "SparkFun_External_EEPROM.h"
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1:
#define LED_PIN    8

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 4

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

struct eepromPacket
{
    char value1[5];
    uint8_t value2;
    float value3;
};

NRFLite _radio; // for RF RX
RadioPacket _radioData; // for RF RX packet
TMRpcm tmrpcm;   // create an object for use in this sketch for music player
ExternalEEPROM myMem; // for EEPROM
eepromPacket eePkt1 = {"amc", 25, 3.14}; // for EEPROM 
eepromPacket eePkt2;
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

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

    //EEPROM Setup
    Wire.begin();
    Wire.setClock(400000); // Based on AT24C256C - Datasheet
    
    // Sparkfun EEPROM function from library to check if memory detected
    if (myMem.begin() == false){
      Serial.println("No EEPROM detected :'(");
      while (1); 
    }
    Serial.println("EEPROM detected!");

    // Set settings for the EEPROM

    myMem.setMemorySize(256000/8); // 256kbit in bytes = 32kbyte
    myMem.setPageSize(64); // EEPROM has 64 bytes per page
    myMem.enablePollForWriteComplete(); // Supports I2C polling of write completion?
    myMem.setPageWriteTime(5); // 5 ms max write time

    Serial.print("EEPROM mem size in bytes: ");
    Serial.println(myMem.length());

    // Sample write and read. Will modify with struct data if this works
//    float myValue3 = -7.35;
    myMem.put(20, eePkt1); //(location, data), ex used myValue3
//    float myRead3;
    myMem.get(20, eePkt2); //location to read, thing to put data into. ex used myRead3
    Serial.println("I read: ");
    Serial.println(eePkt2.value1); // ex used myRead3
    Serial.println(eePkt2.value2); // ex used myRead3
    Serial.println(eePkt2.value3); // ex used myRead3

    // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
    // Any other board, you can remove this part (but no harm leaving it):
    #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
      clock_prescale_set(clock_div_1);
    #endif
    // END of Trinket-specific code.

    strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
    strip.show();            // Turn OFF all pixels ASAP
    strip.setBrightness(25); // Set BRIGHTNESS to about 1/5 (max = 255)
    
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
          rainbow(10);             // Flowing rainbow cycle along the whole strip
        }

        Serial.println(msg);
    }
    delay(1000);
}

// Rainbow cycle along whole strip. Pass delay time (in ms) between frames.
void rainbow(int wait) {
  // Hue of first pixel runs 5 complete loops through the color wheel.
  // Color wheel has a range of 65536 but it's OK if we roll over, so
  // just count from 0 to 5*65536. Adding 256 to firstPixelHue each time
  // means we'll make 5*65536/256 = 1280 passes through this outer loop:
  for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256) {
    for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
      // Offset pixel hue by an amount to make one full revolution of the
      // color wheel (range of 65536) along the length of the strip
      // (strip.numPixels() steps):
      int pixelHue = firstPixelHue + (i * 65536L / strip.numPixels());
      // strip.ColorHSV() can take 1 or 3 arguments: a hue (0 to 65535) or
      // optionally add saturation and value (brightness) (each 0 to 255).
      // Here we're using just the single-argument hue variant. The result
      // is passed through strip.gamma32() to provide 'truer' colors
      // before assigning to each pixel:
      strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
    }
    strip.show(); // Update strip with new contents
    delay(wait);  // Pause for a moment
  }
}
