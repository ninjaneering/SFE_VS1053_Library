#include <SoftwareSerial.h>
#include <SFMusicalShield.h>

SoftwareSerial mySerial(2,3); //Create software serial communcation object with arduino rx on pin 2 and tx on pin 3
SFMusicalShield music; //Create SFMusicalShield object

void setup() {
  mySerial.begin(31250); //Start software serial with 31250 baud rate as required for shield
  
  music.begin(mySerial); //Start musical instrument shield object and pass in software serial object for communications
  
  music.setBank(0, BASIC_INSTRUMENTS); //Select basic instrument bank for channel 0
  music.setInstrument(0, ACOUSTIC_GRAND_PIANO); //Set acoustic grand piano for channel 0 instrument

  music.setVolume(0, 127); //Set volume of channel 0 at 100

}

void loop() {
  
  //Play some notes
  for(int i = 60; i < 68; i++) {
    music.noteOn(0, i, 60); //On channel 0, play note i with a velocity of 60
    delay(100);
    music.noteOff(0, i, 60); //On channel 0, turn off note i, with a velocity of 60
    delay(50);
  }
  
  delay(200);
  
}
