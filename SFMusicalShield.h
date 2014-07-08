/*

*/

#ifndef _SFMusicalShield_h_
#define _SFMusicalShield_h_

#if (ARDUINO >= 100)
    #include "Arduino.h"
#else
    #include "WProgram.h"
#endif

#include <SoftwareSerial.h>

// ***************************************** //
// Constants for musical instrument options

#define ACOUSTIC_GRAND_PIANO 1

#define HARMONICA 23
#define ACOUSTIC_GUITAR_NYLON 25
#define TRUMPET 57

#define BAG_PIPE 110

#define WOODBLOCK 116

// ***************************************** //
// Constants for bank options

#define BASIC_INSTRUMENTS 0x00
#define PERCUSSION1 0x78
#define PERCUSSION2 0x7f
#define MELODIC 0x79

// ***************************************** //

class SFMusicalShield
{
    public:
        void begin();
        void begin(int resetMIDIPin);
        void begin(Stream &s);
        void begin(int resetMIDIPin, Stream &s);
        
        void noteOn(byte channel, byte note, byte attack_velocity);
        void noteOff(byte channel, byte note, byte release_velocity);
	void allOff(byte channel);

        void setBank(byte channel, byte bank);
        void setInstrument(byte channel, byte bank);
        void setVolume(byte channel, byte volume);
        /*
        void setReverbLevel(byte channel, byte level);
        void setReverbDecay(byte channel, byte decay);
        */
        
        void talkMIDI(byte cmd, byte data1, byte data2);
        
    private:
        Stream* mySerial;
        void resetMIDI(int resetMIDIPin);
};

#endif
