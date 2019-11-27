const int DATA = 12;
const int CLOCK = 10;
const int LATCH = 11;
int row[] = {1, 2, 4, 8, 16, 32, 64, 128};
int column[] = {128, 64, 32, 16, 8, 4, 2, 1};
//int mask[]={0x3c,0x42,0xa5,0xa5,0x81,0xbd,0x42,0x3c};
int mask[][8]={
    //{0x3c},{0x42},{0xa5},{0xa5},{0x81},{0xbd},{0x42},{0x3c},
    {0x18,0x3C,0x66,0x66,0x7E,0x66,0x66,0x66},//A
    {0x78,0x64,0x68,0x78,0x64,0x66,0x66,0x7C},//B
    {0x3C,0x62,0x60,0x60,0x60,0x62,0x62,0x3C},//C
  };  
int datadisplay[]={};
int khoangtrong[]={0,0,0,0,0,0,0,0};
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
  for(int r=0;r<3;r++){
  for(int j=8;j>0;--j)
  { 
    for(int i=0;i<50;++i)
    {
     for (int c = 0; c < 8; ++c) 
     {    
      digitalWrite(LATCH, LOW); 
      shiftOut(DATA, CLOCK, MSBFIRST, ~(mask[r][c]<<j)); 
      shiftOut(DATA, CLOCK, MSBFIRST, row[c]);
      digitalWrite(LATCH, HIGH); 
      delay(1); 
     }
   }
  }
  for(int j=0;j<8;++j)
  { 
    for(int i=0;i<50;++i)
    {
     for (int c = 0; c < 8; ++c) 
     {    
      digitalWrite(LATCH, LOW); 
      shiftOut(DATA, CLOCK, MSBFIRST, ~(mask[r][c]>>j)); 
      shiftOut(DATA, CLOCK, MSBFIRST, row[c]);
      digitalWrite(LATCH, HIGH); 
      delay(1); 
     }
   }
  }
  }
}//C:\Users\nho\AppData\Local\Temp\arduino_build_556600
