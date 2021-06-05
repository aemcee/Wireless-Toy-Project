/*

Demonstrates simple RX and TX operation.
Any of the Basic_TX examples can be used as a transmitter.
Please read through 'NRFLite.h' for a description of all the methods available in the library.

Radio    Arduino
CE    -> 9
CSN   -> 10 (Hardware SPI SS)
MOSI  -> 11 (Hardware SPI MOSI)
MISO  -> 12 (Hardware SPI MISO)
SCK   -> 13 (Hardware SPI SCK)
IRQ   -> No connection
VCC   -> No more than 3.6 volts
GND   -> GND

*/

#include <SPI.h>
#include <NRFLite.h>


#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif


#define PIN   8
#define NUMPIXELS 4 // Popular NeoPixel ring size


Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels
#define intensity 50
const static uint8_t RADIO_ID = 0;       // Our radio's id.  The transmitter will send to this id.
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
char LED0,LED1,LED2,LED3;

NRFLite _radio;
RadioPacket _radioData;

void setup()
{

  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
    Serial.begin(9600);

    // By default, 'init' configures the radio to use a 2MBPS bitrate on channel 100 (channels 0-125 are valid).
    // Both the RX and TX radios must have the same bitrate and channel to communicate with each other.
    // You can run the 'ChannelScanner' example to help select the best channel for your environment.
    // You can assign a different bitrate and channel as shown below.
    //   _radio.init(RADIO_ID, PIN_RADIO_CE, PIN_RADIO_CSN, NRFLite::BITRATE2MBPS, 100) // THE DEFAULT
    //   _radio.init(RADIO_ID, PIN_RADIO_CE, PIN_RADIO_CSN, NRFLite::BITRATE1MBPS, 75)
    //   _radio.init(RADIO_ID, PIN_RADIO_CE, PIN_RADIO_CSN, NRFLite::BITRATE250KBPS, 0)
    
    if (!_radio.init(RADIO_ID, PIN_RADIO_CE, PIN_RADIO_CSN))
    {
     //   Serial.println("Cannot communicate with radio");
        while (1); // Wait here forever.
    }
  pinMode(5, OUTPUT);
    
}

void loop()
{
    while (_radio.hasData())
    {
        _radio.readData(&_radioData); // Note how '&' must be placed in front of the variable name.

      String msg = "Recieved: ";
        msg += _radioData.LED0;
        //msg +=  _radioData.LED1;
        //msg +=  _radioData.LED2;
        //msg +=  _radioData.LED3;
      //int LED0 = _radioData.LED0;
      Serial.print("A");
       Serial.print(_radioData.LED0);
       Serial.print(_radioData.LED1);
       Serial.print(_radioData.LED2);
       Serial.print(_radioData.FAN);
pixels.clear(); // Set all pixel colors to 'off'


LED_CTRL(_radioData.LED0,0);
LED_CTRL(_radioData.LED1,1);
LED_CTRL(_radioData.LED2,2);
LED_CTRL(_radioData.LED3,3);

 analogWrite(5,100);   // turn the LED on (HIGH is the voltage level)
                     // wait for a second

    }
}
    uint8_t LED_CTRL (uint8_t LEDX, char num){
        switch (LEDX){
          case 1:
           pixels.setPixelColor(num, pixels.Color(0, 0, intensity));
           pixels.show();   // Send the updated pixel colors to the hardware.
           break;
          case 2:
           pixels.setPixelColor(num, pixels.Color(0, intensity, 0));
           pixels.show();   // Send the updated pixel colors to the hardware.
           break;
          case 3:
           pixels.setPixelColor(num, pixels.Color(0, intensity, intensity));
           pixels.show();   // Send the updated pixel colors to the hardware.
           break;
          case 4:
           pixels.setPixelColor(num, pixels.Color(intensity, 0, 0));
           pixels.show();   // Send the updated pixel colors to the hardware.
           break;
          case 5:
           pixels.setPixelColor(num, pixels.Color(intensity, 0, intensity));
           pixels.show();   // Send the updated pixel colors to the hardware.
           break;
          case 6:
           pixels.setPixelColor(num, pixels.Color(intensity, intensity, 0));
           pixels.show();   // Send the updated pixel colors to the hardware.
           break;
          case 7:
           pixels.setPixelColor(num, pixels.Color(intensity, intensity, intensity));
           pixels.show();   // Send the updated pixel colors to the hardware.
           break;
          default:
           pixels.clear();
           break;
        }
      
    }
