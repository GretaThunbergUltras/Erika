#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Pin 11 on Raspberry Pi corresponds to BCM GPIO 17 and wiringPi pin 0
#define BeepPin 0
#define PI 3.14159265
#define STEPS 100

//This function generates the square wave that makes the piezo speaker sound at a determinated frequency.
void beep(unsigned int note, unsigned int duration){
    printf("%d\n", note);
  //This is the semiperiod of each note.
  long beepDelay = (long)(1000000/note);

  //This is how much time we need to spend on the note.
  long time = (long)((duration*1000)/(beepDelay*2));

  for (int i=0; i<time; i++)
  {
    //1st semiperiod
    digitalWrite(BeepPin, HIGH);
    delayMicroseconds(beepDelay);
    //2nd semiperiod
    digitalWrite(BeepPin, LOW);
    delayMicroseconds(beepDelay);
  }

  //Add a little delay to separate the single notes
  digitalWrite(BeepPin, LOW);
  delay(5);
}

void play()
{
    double progress = 1.0;
    double step = 0.03;
    int freq = 0;
    for (;;)
    {
        progress += step;
        freq = 600 + abs(400 * sin(progress));
        if (freq == 0)
        {
            continue;
        }
        beep(freq, 10);
    }
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
