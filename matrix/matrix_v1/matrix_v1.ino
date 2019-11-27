const int DATA = 12;
const int CLOCK = 10;
const int LATCH = 11;
byte row[] = {1, 2, 4, 8, 16, 32, 64, 128};
int column[] = {128, 64, 32, 16, 8, 4, 2, 1};
//byte mask[]={0x3C,0x42,0xAD,0xA1,0xA1,0xAD,0x42,0x3C};
//byte trong[]={0x18,0x3C,0x66,0x66,0x7E,0x66,0x66,0x66};
byte mask[]={0x3C,0x42,0xAD,0xA1,0xA1,0xAD,0x42,0x3C,0x00,0xFC,0xFE,0x13,0x13,0xFE,0xFC,0x00};
//B00111100,B01000010,B10100101,B10100101,B10000001,B10111101,B01000010,B00111100
  

void setup() {
    pinMode(DATA,OUTPUT);
    pinMode(CLOCK,OUTPUT);
    pinMode(LATCH,OUTPUT);
}
void loop()
{ 
  for(byte k=0;k<16;k++)
  {
    mask[k]=mask[k+1];
  
    for(byte hold=0;hold<50;hold++)
    {
      for (byte i = 0; i < 8; i++) 
     {
          byte d[]={0};
          for(byte j=8;j<16;j++){
            d[j/8]=d[j/8]|((mask[j]>>i&1)*row[7-j%8]);
          }
          
        digitalWrite(LATCH, LOW); 
        shiftOut(DATA, CLOCK, MSBFIRST, ~(d[0])); 
        shiftOut(DATA, CLOCK, MSBFIRST, row[i]);
        digitalWrite(LATCH, HIGH); 
        delay(1); 
      }
    }
  }
}//C:\Users\nho\AppData\Local\Temp\arduino_build_839046
