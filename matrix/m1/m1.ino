
const int DATA = 12;
const int CLOCK = 10;
const int LATCH = 11;
byte row[] = {1, 2, 4, 8, 16, 32, 64, 128};
byte mask[]={0x00,0xFC,0xFE,0x13,0x13,0xFE,0xFC,0x00};


void setup() {
    pinMode(DATA,OUTPUT);
    pinMode(CLOCK,OUTPUT);
    pinMode(LATCH,OUTPUT);
}

void loop() {
   for(int a=0;a<8;a++)
    {
      digitalWrite(LATCH, LOW);
      shiftOut(DATA, CLOCK, MSBFIRST,~mask[a]);//column
      shiftOut(DATA, CLOCK, MSBFIRST,row[a]);//row
      digitalWrite(LATCH, HIGH);
      delay(1);
    }
  }
  //C:\Users\nho\AppData\Local\Temp\arduino_build_310131
