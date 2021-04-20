
Creating audio file to play
Convert audio file to wav file using: https://audio.online-convert.com/convert-to-wav
Use wav file settings found here: https://circuitdigest.com/microcontroller-projects/arduino-audio-music-player

SD card setup
Setup using a class 10 4GB SD Card and formatted as FAT32 
Connect SD Card module to SPI pin header on unitduino

Tested with 
* 8 Ohm speaker connected directly to J11 Spkr_out
* earbuds connected to J13

Update pcmConfig.h file
uncomment the following 
#define DISABLE_SPEAKER2 (optional) extra precaution since using pin 10 as SD chip select
#define USE_TIMER2

Update sketch ino file
Set SD_ChipSelectPin to 10
Set speakerPin to 3 