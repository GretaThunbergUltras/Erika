// ERIKA  soundtrack for buzzer
// to compile: ./erika -lwiringPi

#include <wiringPi.h>
#include <stdio.h>

//Pin 11 on Raspberry Pi corresponds to BCM GPIO 17 and wiringPi pin 0
#define BeepPin 0

// NOTE // FREQUENCIES //
#define cL 129
#define cLS 139
#define dL 146
#define dLS 156
#define eL 163
#define fL 173
#define fLS 185
#define gL 194
#define gLS 207
#define aL 219
#define aLS 228
#define bL 232

#define c 261
#define cS 277
#define d 294
#define dS 311
#define e 329
#define f 349
#define fS 370
#define g 391
#define gS 415
#define a 440
#define aS 455
#define b 466

#define cH 523
#define cHS 554
#define dH 587
#define dHS 622
#define eH 659
#define fH 698
#define fHS 740
#define gH 784
#define gHS 830
#define aH 880
#define aHS 910
#define bH 933

//This function generates the square wave that makes the piezo speaker sound at a determinated frequency.
void beep(unsigned int note, unsigned int duration){
  //This is the semiperiod of each note.
  long beepDelay = (long)(1000000/note);
  //This is how much time we need to spend on the note.
  long time = (long)((duration*1000)/(beepDelay*2));
  for (int i=0;i<time;i++){
    //1st semiperiod
    digitalWrite(BeepPin, HIGH);
    delayMicroseconds(beepDelay);
    //2nd semiperiod
    digitalWrite(BeepPin, LOW);
    delayMicroseconds(beepDelay);
  }

  //Add a little delay to separate the single notes
  digitalWrite(BeepPin, LOW);
  delay(20);
}

void play()
{
      beep( c, 200);    // Auf
      beep( d, 250);    // der
      beep( e, 500);    // Hei-
      beep( e, 500);    // de

      beep( e, 500);    // blüht
      beep( a, 500);    // ein 
      beep( a, 500);    // klei-
      beep( cH, 500);   // nes

      beep( cH, 750);   // Blü-
      beep( b, 250);    // me-
      beep( a, 200);    // lein

      delay(1660);      // bum bum bum bum

      beep( g, 500);    // Und
      beep( a, 500);    // das
      beep( b, 500);    // heißt
      delay(1660);      // bum bum bum bum

      beep( cH, 750);   // EEEER
      beep( b, 250);    /// RRIIII
      beep( a, 200);    // KAAAAA


}

int main(void)
{
      //Check wiringPi setup
      if(-1 == wiringPiSetup())
      {
        printf("setup wiringPi failed!");
        return 1;
      }

      //Prepare GPIO0
      pinMode(BeepPin, OUTPUT);
      play();

      return 0;
}