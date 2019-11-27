//tốc độ chạy chữ, càng lớn chạy càng lâu
const byte SPEED = 4;
 
//kéo lên HIGH để cháy đèn LED, xài chung cho ROW và COL
const byte LATCH = 2;
 
const byte CLOCK_ROW = 3;
const byte DATA_ROW = 4;
 
const byte CLOCK_COL = 5;
const byte DATA_COL = 6;
 
//Dùng cho ROW, ứng với {00000001, 00000010, 00000100, 00001000, 00010000, 00100000, 01000000, 10000000};
const byte ROWS[8] = {1, 2, 4, 8, 16, 32, 64, 128};
 
//Ma trận gồm 8 dòng và 24 cột
//Mỗi byte trong 8 byte của một phần tử trong mảng sau ứng với 1 cột của ma trận. Vậy tại sao có 8 byte trong khi chỉ cần 5 cột là đủ biểu diễn một kí tự?
//Đó là vì dư ra cho tiện cho làm thêm các hình khác, trái tim chẳng hạn
 
//Mình chỉ làm kí tự hoa, số và vài kí tự đặt biệt
//Chữ thường làm hơi xấu nên sẽ tính sau
 
//Mình cũng sẽ đăng một phần mềm nhỏ nhỏ do mình viết dùng để tạo các kí tự
byte up[26][8] = {
  ​{B00111111, B01010000, B10010000, B01010000, B00111111, B00000000, B00000000, B00000000},
  ​{B11111111, B10010001, B10010001, B10010001, B01101110, B00000000, B00000000, B00000000},
  ​{B01111110, B10000001, B10000001, B10000001, B10000001, B00000000, B00000000, B00000000},
  ​{B11111111, B10000001, B10000001, B10000001, B01111110, B00000000, B00000000, B00000000},
  ​{B11111111, B10010001, B10010001, B10010001, B10010001, B00000000, B00000000, B00000000},//
  ​{B11111111, B10010000, B10010000, B10010000, B10010000, B00000000, B00000000, B00000000},//
  ​{B01111110, B10000001, B10000001, B10001001, B01001110, B00001000, B00000000, B00000000},//
  ​{B11111111, B00010000, B00010000, B00010000, B11111111, B00000000, B00000000, B00000000},//
  ​{B10000001, B10000001, B11111111, B10000001, B10000001, B00000000, B00000000, B00000000},//
  ​{B10000011, B10000001, B11111111, B10000000, B10000000, B00000000, B00000000, B00000000},//
  ​{B11111111, B00011000, B00100100, B01000010, B10000001, B00000000, B00000000, B00000000},//
  ​{B11111111, B00000001, B00000001, B00000001, B00000001, B00000000, B00000000, B00000000},//
  ​{B11111111, B01000000, B00100000, B01000000, B11111111, B00000000, B00000000, B00000000},//
  ​{B11111111, B01000000, B00100000, B00010000, B11111111, B00000000, B00000000, B00000000},//
  ​{B01111110, B10000001, B10000001, B10000001, B01111110, B00000000, B00000000, B00000000},//
  ​{B11111111, B10010000, B10010000, B10010000, B01100000, B00000000, B00000000, B00000000},//
  ​{B01111110, B10000001, B10000001, B10000101, B01111110, B00000001, B00000000, B00000000},//
  ​{B11111111, B10011000, B10010100, B10010010, B01100001, B00000000, B00000000, B00000000},//
  ​{B01100001, B10010001, B10010001, B10010001, B01001110, B00000000, B00000000, B00000000},//
  ​{B10000000, B10000000, B11111111, B10000000, B10000000, B00000000, B00000000, B00000000},//
  ​{B11111110, B00000001, B00000001, B00000001, B11111110, B00000000, B00000000, B00000000},//
  ​{B11111100, B00000010, B00000001, B00000010, B11111100, B00000000, B00000000, B00000000},//
  ​{B11111111, B00000010, B00000100, B00000010, B11111111, B00000000, B00000000, B00000000},//
  ​{B11000011, B00100100, B00011000, B00100100, B11000011, B00000000, B00000000, B00000000},//
  ​{B11100000, B00010000, B00001111, B00010000, B11100000, B00000000, B00000000, B00000000},//
  ​{B10000111, B10001001, B10010001, B10100001, B11000001, B00000000, B00000000, B00000000}//
};

byte num[10][8] = {
  ​{B01111110, B10000001, B10000001, B10000001, B01111110, B00000000, B00000000, B00000000},//
  ​{B00100001, B01000001, B11111111, B00000001, B00000001, B00000000, B00000000, B00000000},//
  ​{B01000011, B10000101, B10001001, B10010001, B01100001, B00000000, B00000000, B00000000},//
  ​{B01000001, B10010001, B10010001, B10010001, B01101110, B00000000, B00000000, B00000000},//
  ​{B11110000, B00010000, B00010000, B11111111, B00000000, B00000000, B00000000, B00000000},//
  ​{B11110001, B10010001, B10010001, B10010001, B10001110, B00000000, B00000000, B00000000},//
  ​{B01111110, B10010001, B10010001, B10010001, B10001110, B00000000, B00000000, B00000000},//
  ​{B10000000, B10000000, B10011111, B10100000, B11000000, B00000000, B00000000, B00000000},//
  ​{B01101110, B10010001, B10010001, B10010001, B01101110, B00000000, B00000000, B00000000},//
  ​{B01100000, B10010001, B10010001, B10010001, B01111110, B00000000, B00000000, B00000000}//
};
 
byte specials[5][8] = {
  ​{B00011000, B00100100, B01000010, B00100001, B01000010, B00100100, B00011000, B00000000},//HEAR
  ​{B00000001, B00000110, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000},//
  ​{B00000001, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000},//
  ​{B11111101, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000}//
};
 
//Lưu trữ giá trị để biểu diễn ma trận, 24 byte là 24 cột
//1 byte = 8 bit ứng mỗi điểm trên cột
byte leds[24];
 
void copyArr(byte target[8], byte source[8]) {
  for (byte i = 0; i < 8; i++) {
    ​target[i] = source[i];
  ​
}
}
//Tìm xem một kí tự ứng với đâu trong các mảng UP, NUM, SPECIALS)
void getArrFromChar(char ch, byte arr[8]) {
  byte ind = (byte) ch; //Lấy mã ASCII của kí tu
  
  if((ind >= 48) && (ind <= 57)){
    copyArr(arr, num[ind - 48]);
    return;
  
  }
  if ((ind >= 65) && (ind <= 90)){ 
    ​copyArr(arr, up[ind - 65]);
    return;
  ​
  }
  switch (ch) {
    case '$': {
        ​copyArr(arr, specials[0]);
        break;
    }​
    case ',': {
        ​copyArr(arr, specials[1]);
        break;
    }
    case '.': {
        ​copyArr(arr, specials[2]);
        break;
    }    ​
    case '!':{ 
        ​copyArr(arr, specials[3])
        break;
    }
  ​}
}
 
//Thêm một kí tự, sau đó gọi hàm addCol để hiển thị từng phần của kí tự
void addChar(char chr) {
  byte arr[8];
  ​getArrFromChar(chr, arr);
  for (byte i = 0; i < 8; i++) {
    if (arr[i] != 0) {
      ​addCol(arr[i]);
    ​
  ​   }
  }
  ​addCol(0);
}
 
//Thêm vào một cột vào mảng leds để hiển thị
void addCol(byte col) {
  ​moveLeft();
  ​leds[23] = col;
  ​show(leds, SPEED);
}
 
void moveLeft() {
  for (byte i = 0; i < 23; i++) {
    ​leds[i] = leds[i + 1];
  ​}
}
 
 
void parseString(String s) {
  ​s += "      ";
  for (byte i = 0; i < s.length(); i++){
    if (s.charAt(i) == ' ') {
      ​addCol(0);
      ​addCol(0);
    ​} else {
      ​addChar(s.charAt(i));
    ​}
  ​}
}
 
//Hiển thị mảng leds ra ma trận
void show(byte leds[24], byte hold) {
  for (byte k = 0; k < hold; k++){ 
    for (byte i = 0; i < 8; i++){ 
      byte d[3] = {0, 0, 0};
 
      for (byte j = 0; j < 24; j++) {
        ​d[  j / 8] = d[j / 8] | ((leds[j] >> i & 1) * ROWS[7 - j % 8]);
      ​}
 
      digitalWrite(LATCH, LOW);
      shiftOut(DATA_ROW, CLOCK_ROW, LSBFIRST, ROWS[i]);
      shiftOut(DATA_COL, CLOCK_COL, MSBFIRST, d[0]);
      shiftOut(DATA_COL, CLOCK_COL, MSBFIRST, d[1]);
      shiftOut(DATA_COL, CLOCK_COL, MSBFIRST, d[2]);
      digitalWrite(LATCH, HIGH);
//      delay(10); bỏ comment nếu bạn muốn tìm hiểu kĩ thuật quét LED
    ​}
  ​}
}
 
void initPin() {
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK_COL, OUTPUT);
  pinMode(DATA_COL, OUTPUT);
  pinMode(CLOCK_ROW, OUTPUT);
 ​ pinMode(DATA_ROW, OUTPUT);
}
 
void setup() {
  Serial.begin(9600);
  ​initPin();
}
 
void loop() {
  ​parseString("HAPPY NEW YEAR 2016");
}
