#include <Wire.h>
//defines the base address of the EEPROM
#define eeprom 0x50 
 
void setup()  {
  Wire.begin(); // Makes Wire Object
  Serial.begin(9600);
 
  unsigned int address = 0; // Starting Address for EEPROM
  Serial.println("serial zip");
  for(address = 0; address< 5; address++)
    writeEEPROM(eeprom, address, '2'); // Sets 22222 to EEPROM
 
  for(address = 0; address< 5; address++) {
    Serial.print(readEEPROM(eeprom, address), HEX);
    }
  }
 
void loop() {
  // There will be no loop() function here, through the loading, we do not want it to loop the same process.
}
 
// Write from the EEPROM
void writeEEPROM(int deviceaddress, unsigned int eeaddress, byte data ) {
  Wire.beginTransmission(deviceaddress);
  Wire.write((int)(eeaddress >> 8));      // Writes MSB
  Wire.write((int)(eeaddress & 0xFF));    // Writes LSB
  Wire.write(data);
  Wire.endTransmission();
  }
 
// Read from the EEPROM
byte readEEPROM(int deviceaddress, unsigned int eeaddress ) {
  byte rdata = 0xFF;
  Wire.beginTransmission(deviceaddress);
  Wire.write((int)(eeaddress >> 8)); // Writes MSB
  Wire.write((int)(eeaddress & 0xFF)); // Writes LSB
  Wire.endTransmission();
  Wire.requestFrom(deviceaddress,1);
  if (Wire.available())
    rdata = Wire.read();
  return rdata;
  }
