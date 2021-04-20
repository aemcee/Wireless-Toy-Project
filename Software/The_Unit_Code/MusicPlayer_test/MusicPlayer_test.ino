#include <SD.h>                      // need to include the SD library
//#define SD_ChipSelectPin 53  //example uses hardware SS pin 53 on Mega2560
#define SD_ChipSelectPin 10  //using digital pin 4 on arduino nano 328, can use other pins. Using pin 10 for unitduino
#include <TMRpcm.h>           //  also need to include this library...
#include <SPI.h>

/*
 * Need to uncomment the below in pcmConfig.h in arduino library before using pin 3 for speaker pin
 * #define DISABLE_SPEAKER2 (optional) extra precaution since using pin 10 as SD chip select
 * #define USE_TIMER2
 */

TMRpcm tmrpcm;   // create an object for use in this sketch


void setup(){

  tmrpcm.speakerPin = 3; //5,6,11 or 46 on Mega, 9 on Uno, Nano, etc. using pin 3 for unitduino

  Serial.begin(9600);
  if (!SD.begin(SD_ChipSelectPin)) {  // see if the card is present and can be initialized:
    Serial.println("SD fail");  
    return;   // don't do anything more if not
  }
  Serial.println("SD card ok");
  tmrpcm.setVolume(4); // optional, testing volume levels. 4 seems to be the max before sound quality degrades
  tmrpcm.play("DJ.wav"); //insert name of music file. will play each time the arduino powers up, or is reset
}



void loop(){  

  if(Serial.available()){    
    if(Serial.read() == 'p'){ //send the letter p over the serial monitor to start playback
      tmrpcm.play("DJ.wav");
    }
  }

}
