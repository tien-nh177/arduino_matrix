const int DATA = 12;
const int CLOCK = 10;
const int LATCH = 11;
int row[] = {1, 2, 4, 8, 16, 32, 64, 128};
int column[] = {128, 64, 32, 16, 8, 4, 2, 1};
int mask[]={0x3c,0x42,0xa5,0xa5,0x81,0xbd,0x42,0x3c};
/*int mask[][8]={
    {0x3c},{0x42},{0xa5},{0xa5},{0x81},{0xbd},{0x22},{0x3c}
  };
  //B00111100,B01000010,B10100101,B10100101,B10000001,B10111101,B01000010,B00111100
  
/*int mask[3][8][8] = {{  // 3 frames, 8 rows, 8 columns
  {0, 0, 1, 1, 1, 1, 0, 0}, //first frame
  {0, 1, 0, 0, 0, 0, 1, 0},
  {1, 0, 1, 0, 0, 1, 0, 1},
  {1, 0, 1, 0, 0, 1, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 1, 1, 1, 1, 0, 1},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 0, 1, 1, 1, 1, 0, 0}
},
{ // second frame
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {1, 0, 1, 0, 0, 1, 0, 1},
  {1, 0, 1, 0, 0, 1, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 1},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 0, 1, 1, 1, 1, 0, 0}
},
{ // third frame
  {0, 0, 1, 1, 1, 1, 0, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 1, 1, 1, 1, 0, 0},
  {0, 1, 0, 0, 0, 0, 0, 0},
  {0, 0, 1, 1, 1, 1, 0, 0}
}};
*/
void setup() {
    pinMode(DATA,OUTPUT);
    pinMode(CLOCK,OUTPUT);
    pinMode(LATCH,OUTPUT);
}
void loop()
{
    for (int c = 0; c < 8; ++c) 
    {    
      digitalWrite(LATCH, LOW); 
      shiftOut(DATA, CLOCK, MSBFIRST, ~mask[c]); 
      shiftOut(DATA, CLOCK, MSBFIRST, row[c]);
      digitalWrite(LATCH, HIGH); 
      delay(1); 
    }
}//C:\Users\nho\AppData\Local\Temp\arduino_build_974528
