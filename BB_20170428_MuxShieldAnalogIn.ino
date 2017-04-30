//This example shows how to use the Mux Shield for analog inputs

#include <MuxShield.h>

//Initialize the Mux Shield
MuxShield muxShield;

// global References
int reference = 700;

void setup()
{
    //Set I/O 1, I/O 2, and I/O 3 as analog inputs
    muxShield.setMode(1,ANALOG_IN);
    muxShield.setMode(2,DIGITAL_OUT);
  //  muxShield.setMode(3,ANALOG_IN);
    
    Serial.begin(19200);
}

//Arrays to store analog values after recieving them
int IO1AnalogVals[16];
//int IO2AnalogVals[16];
//int IO3AnalogVals[16];

void loop()
{
  for (int i=8; i<16; i++)
  {
    //Analog read on all 16 inputs on IO1, IO2, and IO3
    IO1AnalogVals[i] = muxShield.analogReadMS(1,i);
//    IO2AnalogVals[i] = muxShield.analogReadMS(2,i);
//    IO3AnalogVals[i] = muxShield.analogReadMS(3,i);
  }

  for (int i=8; i<16; i++)
  {
    //Compare IO1AnalogVals with Reference and set Pins
     int j = i-8;
     if (IO1AnalogVals[i] < reference) {
      muxShield.digitalWriteMS(2,j,1);
     }

     else {
      muxShield.digitalWriteMS(2,j,0);
     }

  }
  //Print IO1 values for inspection
  Serial.print("IO1 analog values: ");
  for (int i=8; i<16; i++)
  {
    Serial.print(IO1AnalogVals[i]);
    Serial.print('\t');
  }
  Serial.println();
}
