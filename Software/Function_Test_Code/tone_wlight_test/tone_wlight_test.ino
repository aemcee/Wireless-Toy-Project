#include "notes.h"
//#include "test.h"
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>




// int marioMelody[] 

// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        8 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 4 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels

    int marioMelody[] = { NOTE_E5,8, NOTE_E5,8, REST,8, NOTE_E5,8, REST,8, NOTE_C5,8, NOTE_E5,8, //1
        NOTE_G5,4, REST,4, NOTE_G4,8, REST,4, 
        NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, // 3
        NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
        NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
        REST,8, NOTE_E5,4,NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4,
        NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, // repeats from 3
        NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
        NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
        REST,8, NOTE_E5,4,NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4,
      
        
        REST,4, NOTE_G5,8, NOTE_FS5,8, NOTE_F5,8, NOTE_DS5,4, NOTE_E5,8,//7
        REST,8, NOTE_GS4,8, NOTE_A4,8, NOTE_C4,8, REST,8, NOTE_A4,8, NOTE_C5,8, NOTE_D5,8,
        REST,4, NOTE_DS5,4, REST,8, NOTE_D5,-4,
        NOTE_C5,2, REST,2,
      
        REST,4, NOTE_G5,8, NOTE_FS5,8, NOTE_F5,8, NOTE_DS5,4, NOTE_E5,8,//repeats from 7
        REST,8, NOTE_GS4,8, NOTE_A4,8, NOTE_C4,8, REST,8, NOTE_A4,8, NOTE_C5,8, NOTE_D5,8,
        REST,4, NOTE_DS5,4, REST,8, NOTE_D5,-4,
        NOTE_C5,2, REST,2,
      
        NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,4,//11
        NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2,
      
        NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,8, NOTE_E5,8,//13
        REST,1, 
        NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,4,
        NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2,
        NOTE_E5,8, NOTE_E5,8, REST,8, NOTE_E5,8, REST,8, NOTE_C5,8, NOTE_E5,4,
        NOTE_G5,4, REST,4, NOTE_G4,4, REST,4, 
        NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, // 19
        
        NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
        NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
        REST,8, NOTE_E5,4, NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4,
      
        NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, // repeats from 19
        NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
        NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
        REST,8, NOTE_E5,4, NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4,
      
        NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,//23
        NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
        NOTE_D5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_G5,-8, NOTE_F5,-8,
        
        NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2, //26
        NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,
        NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
        NOTE_B4,8, NOTE_F5,4, NOTE_F5,8, NOTE_F5,-8, NOTE_E5,-8, NOTE_D5,-8,
        NOTE_C5,8, NOTE_E4,4, NOTE_E4,8, NOTE_C4,2,
      
        NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,//repeats from 23
        NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
        NOTE_D5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_G5,-8, NOTE_F5,-8,
        
        NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2, //26
        NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,
        NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
        NOTE_B4,8, NOTE_F5,4, NOTE_F5,8, NOTE_F5,-8, NOTE_E5,-8, NOTE_D5,-8,
        NOTE_C5,8, NOTE_E4,4, NOTE_E4,8, NOTE_C4,2,
        NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,8, NOTE_E5,8,
        REST,1,
      
        NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,4, //33
        NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2,
        NOTE_E5,8, NOTE_E5,8, REST,8, NOTE_E5,8, REST,8, NOTE_C5,8, NOTE_E5,4,
        NOTE_G5,4, REST,4, NOTE_G4,4, REST,4, 
        NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,
        NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
        NOTE_D5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_G5,-8, NOTE_F5,-8,
        
        NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2, //40
        NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,
        NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
        NOTE_B4,8, NOTE_F5,4, NOTE_F5,8, NOTE_F5,-8, NOTE_E5,-8, NOTE_D5,-8,
        NOTE_C5,8, NOTE_E4,4, NOTE_E4,8, NOTE_C4,2,
        
        //game over sound
        NOTE_C5,-4, NOTE_G4,-4, NOTE_E4,4, //45
        NOTE_A4,-8, NOTE_B4,-8, NOTE_A4,-8, NOTE_GS4,-8, NOTE_AS4,-8, NOTE_GS4,-8,
        NOTE_G4,8, NOTE_D4,8, NOTE_E4,-2,  
    
      };

      int starwarsMelody[] = {
  
        // Dart Vader theme (Imperial March) - Star wars 
        // Score available at https://musescore.com/user/202909/scores/1141521
        // The tenor saxophone part was used
        
        NOTE_AS4,8, NOTE_AS4,8, NOTE_AS4,8,//1, 7 elem
        NOTE_F5,2, NOTE_C6,2, // 4 elem
        NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4,  // 10 elem
        NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4,  // 10 elem
        NOTE_AS5,8, NOTE_A5,8, NOTE_AS5,8, NOTE_G5,2, NOTE_C5,8, NOTE_C5,8, NOTE_C5,8, // 14 elem
        NOTE_F5,2, NOTE_C6,2, // 4 elem
        NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4,  // 10 elem
        
        NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4, //8  10 elem
        NOTE_AS5,8, NOTE_A5,8, NOTE_AS5,8, NOTE_G5,2, NOTE_C5,-8, NOTE_C5,16, // 12 elem
        NOTE_D5,-4, NOTE_D5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8, // 12 elem
        NOTE_F5,8, NOTE_G5,8, NOTE_A5,8, NOTE_G5,4, NOTE_D5,8, NOTE_E5,4,NOTE_C5,-8, NOTE_C5,16, // 16 elem
        NOTE_D5,-4, NOTE_D5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8, // 12 elem
        
        NOTE_C6,-8, NOTE_G5,16, NOTE_G5,2, REST,8, NOTE_C5,8,//13 5 elem
        NOTE_D5,-4, NOTE_D5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8, // 6 elem
        NOTE_F5,8, NOTE_G5,8, NOTE_A5,8, NOTE_G5,4, NOTE_D5,8, NOTE_E5,4,NOTE_C6,-8, NOTE_C6,16, // 8 elem
        NOTE_F6,4, NOTE_DS6,8, NOTE_CS6,4, NOTE_C6,8, NOTE_AS5,4, NOTE_GS5,8, NOTE_G5,4, NOTE_F5,8, // 8 elem
        NOTE_C6,1 // 2 elem

        // 7 + 4 + 10 + 10 + 14 + 4 + 10 + 10 + 12 + 12 + 16 + 12 + 5 + 6 + 8 + 8 + 2
        // 31 + 38 + 24 + 16 + 12 + 11 + 18 = 150
        // 
        
      };

      int starwars2Melody[] = {
  
        // Dart Vader theme (Imperial March) - Star wars 
        // Score available at https://musescore.com/user/202909/scores/1141521
        // The tenor saxophone part was used
        
        NOTE_AS4,8, NOTE_AS4,8, NOTE_AS4,8,//1, 7 elem
        NOTE_F5,2, NOTE_C6,2, // 4 elem
        NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4,  // 10 elem
        NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4,  // 10 elem
        NOTE_AS5,8, NOTE_A5,8, NOTE_AS5,8, NOTE_G5,2, NOTE_C5,8, NOTE_C5,8, NOTE_C5,8, // 14 elem
        NOTE_F5,2, NOTE_C6,2, // 4 elem
        NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4,  // 10 elem
        
        NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4, //8  10 elem
        NOTE_AS5,8, NOTE_A5,8, NOTE_AS5,8, NOTE_G5,2, NOTE_C5,-8, NOTE_C5,16, // 12 elem
        NOTE_D5,-4, NOTE_D5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8, // 12 elem
        NOTE_F5,8, NOTE_G5,8, NOTE_A5,8, NOTE_G5,4, NOTE_D5,8, NOTE_E5,4,NOTE_C5,-8, NOTE_C5,16, // 16 elem
        NOTE_D5,-4, NOTE_D5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8, // 12 elem
        
        NOTE_C6,-8, NOTE_G5,16, NOTE_G5,2, REST,8, NOTE_C5,8,//13 5 elem
        NOTE_D5,-4, NOTE_D5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8, // 6 elem
        NOTE_F5,8, NOTE_G5,8, NOTE_A5,8, NOTE_G5,4, NOTE_D5,8, NOTE_E5,4,NOTE_C6,-8, NOTE_C6,16, // 8 elem
        NOTE_F6,4, NOTE_DS6,8, NOTE_CS6,4, NOTE_C6,8, NOTE_AS5,4, NOTE_GS5,8, NOTE_G5,4, NOTE_F5,8, // 8 elem
        NOTE_C6,1 // 2 elem

        // 7 + 4 + 10 + 10 + 14 + 4 + 10 + 10 + 12 + 12 + 16 + 12 + 5 + 6 + 8 + 8 + 2
        // 31 + 38 + 24 + 16 + 12 + 11 + 18 = 150
        // 
        
      };

      int harrypotterMelody[] = {


        // Hedwig's theme fromn the Harry Potter Movies
        // Socre from https://musescore.com/user/3811306/scores/4906610
        
        REST, 2, NOTE_D4, 4, // 4 elem
        NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4, // 6 elem
        NOTE_G4, 2, NOTE_D5, 4, // 4 elem
        NOTE_C5, -2, // 2 elem
        NOTE_A4, -2, // 2 elem
        NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4, // 6 elem
        NOTE_F4, 2, NOTE_GS4, 4, // 4 elem
        NOTE_D4, -1, // 2 elem
        NOTE_D4, 4, // 2 elem

        // 32 elem
      
        NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4, //10 6 elem
        NOTE_G4, 2, NOTE_D5, 4, // 4 elem
        NOTE_F5, 2, NOTE_E5, 4, // 4 elem
        NOTE_DS5, 2, NOTE_B4, 4, // 4 elem
        NOTE_DS5, -4, NOTE_D5, 8, NOTE_CS5, 4, // 6 elem
        NOTE_CS4, 2, NOTE_B4, 4, // 4 elem
        NOTE_G4, -1, // 2 elem
        NOTE_AS4, 4, // 2 elem

        // 32 elem
           
        NOTE_D5, 2, NOTE_AS4, 4,//18  4 elem
        NOTE_D5, 2, NOTE_AS4, 4, // 4 elem
        NOTE_DS5, 2, NOTE_D5, 4, // 4 elem
        NOTE_CS5, 2, NOTE_A4, 4, // 4 elem
        NOTE_AS4, -4, NOTE_D5, 8, NOTE_CS5, 4, // 6 elem
        NOTE_CS4, 2, NOTE_D4, 4, // 4 elem
        NOTE_D5, -1, // 2 elem
        REST,4, NOTE_AS4,4,  // 4 elem

        // 32 elem
      
        NOTE_D5, 2, NOTE_AS4, 4,//26 4 elem
        NOTE_D5, 2, NOTE_AS4, 4,// 4 elem
        NOTE_F5, 2, NOTE_E5, 4, // 4 elem
        NOTE_DS5, 2, NOTE_B4, 4, // 4 elem
        NOTE_DS5, -4, NOTE_D5, 8, NOTE_CS5, 4, // 6 elem
        NOTE_CS4, 2, NOTE_AS4, 4, // 4 elem
        NOTE_G4, -1,  // 2 elem

        // 30 elem

        // (32 * 3) + 30 = 126
        
      };


void lightSetup(){

    // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.setBrightness(50);

}


//void playNow.playMusicLightShow(int melody[]);
// void playMusicLightShow(int ptr, int tempo, into size);
/*
// void playMusicLightShow(struct song * songptr){
      
    }
*/
void playMusicLightShow(int melody[], int tempo, int num){
//      int arraySize = *(&melodi + 1) - melodi;
//      int a = arraySize;
//      int melody[arraySize];

//      for(int i=0; i<(arraySize); i++){
//        melody[i] = melodi[i];
//      };
      //int tempo = 200; 
   
      // Pin to use for output 
      int buzzer = 3; // put into main ino

      // sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
      // there are two values per note (pitch and duration), so for each note there are four bytes
      // int notes = sizeof(melody) / sizeof(melody[0]) / 2;
      int notes = num / 2; 
    
      // this calculates the duration of a whole note in ms
      int wholenote = (60000 * 4) / tempo;
      
      int divider = 0, noteDuration = 0;
      
      // iterate over the notes of the melody.
      // Remember, the array is twice the number of notes (notes + durations)
      
      for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
         
        int randColor1 = random(256);
        int randColor2 = random(256);
        int randColor3 = random(256);
        int z = random(4);
    
        // t++;
        
        pixels.clear();
        // calculates the duration of each note
        divider = melody[thisNote + 1];
        if (divider > 0) {
          // regular note, just proceed
          noteDuration = (wholenote) / divider;
        } else if (divider < 0) {
          // dotted notes are represented with negative durations!!
          noteDuration = (wholenote) / abs(divider);
          noteDuration *= 1.5; // increases the duration in half for dotted notes
        }
    
        // we only play the note for 90% of the duration, leaving 10% as a pause
        tone(buzzer, melody[thisNote], noteDuration * 0.9);
        // colorWipe(strip.Color(randColor1, randColor2, randColor3), 50);
    //    if (t=3){
    //      t = 0;
    //    }
        pixels.setPixelColor(z, pixels.Color(randColor1, randColor2, randColor3));
    
        pixels.show();
        delay(noteDuration);
    
        // Wait for the specief duration before playing the next note.
    
        // stop the waveform generation before the next note.
        noTone(buzzer);
      }
      return 0; 
};

void setup() {
  // put your setup code here, to run once:

  
  // light setup
   lightSetup();

  //int randomSong = random(3);

  // Music Function
//  switch (randomSong){
//    case 0:
//        int marioTempo = 200;
//        playMusicLightShow(marioMelody, marioTempo);
//      break;
//    case 1:
//        int starwarsTempo = 108;
//        playMusicLightShow(starwarsMelody, starwarsTempo); 
//      break;
//    case 2:
//        int harrypotterTempo = 144;
//        playMusicLightShow(harrypotterMelody, harrypotterTempo);
//    default:
//      break;
//  }

// playMusicLightShow(); 
playMusicLightShow(starwarsMelody, 108, 150);
//playMusicLightShow(starwars2Melody, 200, 150);
//playMusicLightShow(marioMelody, 200);
//playMusicLightShow(starwarsMelody, 108);
playMusicLightShow(harrypotterMelody, 144, 126);
  // playMusicLightShow();

}

void loop() {
  // put your main code here, to run repeatedly:

}
