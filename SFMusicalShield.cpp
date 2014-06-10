

#include "SFMusicalShield.h"

void SFMusicalShield::begin(){
    SoftwareSerial s(2,3);
    s.begin(31250);
    mySerial = &s;
    
    resetMIDI(4);
}

//begin method for overriding default resetMIDIPin
void SFMusicalShield::begin(int resetMIDIPin){
    SoftwareSerial s(2,3);
    s.begin(31250);
    mySerial = &s;
    
    resetMIDI(resetMIDIPin);
}

// begin method for overriding default Stream
void SFMusicalShield::begin(Stream &s){
    mySerial = &s;
    
    resetMIDI(4);
}

// begin method for overriding default resetMIDIPin and default stream
void SFMusicalShield::begin(int resetMIDIPin, Stream &s){
    //Setup software serial for MIDI
    //SoftwareSerial softSerial(2,3);
    
    mySerial = &s;
      
    resetMIDI(resetMIDIPin);
}

void SFMusicalShield::resetMIDI(int resetMIDIPin){
    //Reset the VS1053
    pinMode(resetMIDIPin, HIGH);
    digitalWrite(resetMIDIPin, LOW);
    delay(100);
    digitalWrite(resetMIDIPin, HIGH);
    delay(100);
    
    setVolume(0, 125);
}

void SFMusicalShield::talkMIDI(byte cmd, byte data1, byte data2){
    mySerial->write(cmd);
    mySerial->write(data1);
    
    if( (cmd & 0xF0) <= 0xB0) {
        mySerial->write(data2);
    }
}

void SFMusicalShield::noteOn(byte channel, byte note, byte attack_velocity) {
    talkMIDI( (0x90 | channel), note, attack_velocity);
}

void SFMusicalShield::noteOff(byte channel, byte note, byte release_velocity) {
    talkMIDI( (0x80 | channel), note, release_velocity);
}

void SFMusicalShield::setBank(byte channel, byte bank) {
    talkMIDI(0xB0, channel, bank);
}

void SFMusicalShield::setInstrument(byte channel, byte instrument) {
    instrument--; //Instruments are listed from 1-128 instead of 0-127 in datasheet
    talkMIDI( (0xC0 | channel), instrument, 0);
}

void SFMusicalShield::setVolume(byte channel, byte volume) {
    talkMIDI( (0xB0 | channel), 0x07, volume);
}

/*
void SFMusicalShield::setReverbLevel(byte channel, byte level){
    talkMIDI( (0xB0 | channel), 0x5b, level);
}

void SFMusicalShield::setReverbDecay(byte channel, byte level){
    talkMIDI( (0xB0 | channel), 0xC0, level);
}
*/

SFMusicalShield Musical;

