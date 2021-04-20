// #include <Arduino.h>
// #include "notes.h"
//#include "test.h"
// #include <Adafruit_NeoPixel.h>




// int marioMelody[] 

// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

//#ifdef __AVR__
// #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
//#endif
//
//// Which pin on the Arduino is connected to the NeoPixels?
//#define PIN        8 // On Trinket or Gemma, suggest changing this to 1
//
//// How many NeoPixels are attached to the Arduino?
//#define NUMPIXELS 4 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
// Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// #define DELAYVAL 500 // Time (in milliseconds) to pause between pixels



//void lightSetup(){
//
//    // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
//  // Any other board, you can remove this part (but no harm leaving it):
//#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
//  clock_prescale_set(clock_div_1);
//#endif
//  // END of Trinket-specific code.
//
//  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
//  pixels.setBrightness(50);
//
//}

// Declare music parameters
// Make song slower or faster
// int tempo = 200;
//// Pin to use for output 
//int buzzer = 3; // put into main ino

// notes of the moledy followed by the duration.
// a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
// !!negative numbers are used to represent dotted notes,
// so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!


//void playMusicLightShow(int melody[]){
//
//
//  // sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
//  // there are two values per note (pitch and duration), so for each note there are four bytes
//  int notes = sizeof(melody) / sizeof(melody[0]) / 2;
//
//  // this calculates the duration of a whole note in ms
//  int wholenote = (60000 * 4) / tempo;
//  
//  int divider = 0, noteDuration = 0;
//  
//  // iterate over the notes of the melody.
//  // Remember, the array is twice the number of notes (notes + durations)
//  
//  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
//     
//    int randColor1 = random(256);
//    int randColor2 = random(256);
//    int randColor3 = random(256);
//    int z = random(4);
//
//    // t++;
//    
//    pixels.clear();
//    // calculates the duration of each note
//    divider = melody[thisNote + 1];
//    if (divider > 0) {
//      // regular note, just proceed
//      noteDuration = (wholenote) / divider;
//    } else if (divider < 0) {
//      // dotted notes are represented with negative durations!!
//      noteDuration = (wholenote) / abs(divider);
//      noteDuration *= 1.5; // increases the duration in half for dotted notes
//    }
//
//    // we only play the note for 90% of the duration, leaving 10% as a pause
//    tone(buzzer, melody[thisNote], noteDuration * 0.9);
//    // colorWipe(strip.Color(randColor1, randColor2, randColor3), 50);
////    if (t=3){
////      t = 0;
////    }
//    pixels.setPixelColor(z, pixels.Color(randColor1, randColor2, randColor3));
//
//    pixels.show();
//    delay(noteDuration);
//
//    // Wait for the specief duration before playing the next note.
//
//    // stop the waveform generation before the next note.
//    noTone(buzzer);
//  }
//  return 0; 
//}
