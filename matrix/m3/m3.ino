const int DATA = 12;
const int CLOCK = 10;
const int LATCH = 11;
byte row[] = {1, 2, 4, 8, 16, 32, 64, 128};
int column[] = {128, 64, 32, 16, 8, 4, 2, 1};
byte mask[]={0x3C,0x42,0x8D,0xA1,0xA1,0x8D,0x42,0x3C};
byte d[8];

void show(byte d[],byte n){
    for(byte hold=0;hold<n;hold++)
    {
        for (byte i = 0; i < 8; i++) 
        {
          digitalWrite(LATCH, LOW); 
          shiftOut(DATA, CLOCK, MSBFIRST, ~(d[i])); 
          shiftOut(DATA, CLOCK, MSBFIRST, row[i]);
          digitalWrite(LATCH, HIGH); 
          delay(1); 
        }
    }
}
void moveled(){
  for(int j=0;j<8;j++)
    {
        d[j]=d[j+1];
    }
}
void setup() {
    pinMode(DATA,OUTPUT);
    pinMode(CLOCK,OUTPUT);
    pinMode(LATCH,OUTPUT);
}
void loop()
{ 
  for (int k=0;k<8;k++)
  {
    moveled();
    d[7]=mask[k];
    show(d,50);
  }
}

//C:\Users\nho\AppData\Local\Temp\arduino_build_880012
