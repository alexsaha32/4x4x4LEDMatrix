/*
created by: Alex Sahakian
github:AlexSaha32

positive_power (each layer)
A0
A1
A2
A3

//ground pins (each column)
13
12
11
10
9
8
7
6
5
4
3
2
1
0
A4
A5
*/

//initializing the rows
int posArray[4] = { A0, A1, A2, A3 };
//initializing the columns
int groundArray[16] = { A5, A4, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };  //negative

const int snake_speed = 550;

void setup() {
  // put your setup code here, to run once:

  // pinMode(A0, OUTPUT);  //activates A0 lane (positive)
  // pinMode(A1, OUTPUT);  //activates A1 lane (positive)
  // pinMode(7, OUTPUT);   //activates 7 lane (negative)
  // pinmode(6, OUTPUT);  //activates 6 lane (negative)

  //setting columns to output
  for (int j = 0; j < 16; j++) {
    pinMode(groundArray[j], OUTPUT);
  }

  //setting rows to output
  for (int i = 0; i < 4; i++) {
    pinMode(posArray[i], OUTPUT);
  }

  //flashing to start animation
  all_off();

  all_on();
  delay(2000);  //delay to 2 seconds

  //scan sequence
  scan_up();
  scan_up();
  scan_up();

  scan_down();
  scan_down();
  scan_down();

  scan_up();
  scan_down();
  scan_up();
  scan_down();

  scan_left();
  scan_right();
  scan_left();
  scan_right();

  //test_code();

  //loads
  reload();
  deload();

  snake();
  swirl();

  //disable_all_rows();
  all_off();

}

void loop() {
  // put your main code here, to run repeatedly:
  
}

/////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////FUNCTIONS////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
void test_code(void){
  enable_all_rows();
  //delay(1000);
  //disable_all_columns();
  delay(5000);
  //digitalWrite(0, HIGH);
  //enable_all_columns();
  all_off();
  //digitalWrite(groundArray[5],HIGH);  
}

void all_on() {
  //digitalWrite(A0, HIGH) ; //turns on positive lane; can use 1 in place of HIGH
  //digitalWrite(7,LOW);
  
  //enable positive leads
  for (int i = 0; i < 4; i++) {
    digitalWrite(posArray[i], HIGH);
  }

  //disable negative leads
  for (int j = 0; j < 16; j++) {
    digitalWrite(groundArray[j], LOW);
  }
}

void all_off() {
  //digitalWrite(A0, LOW);  //turns off positive lane; can use 0 in place of LOW

  for (int i = 0; i < 4; i++) {
    digitalWrite(posArray[i], LOW);
  }

  for (int j = 0; j < 16; j++) {
    digitalWrite(groundArray[j], HIGH);
  }
}

void disable_all_rows(){
  for (int i = 0; i < 4; i++) {
    digitalWrite(posArray[i], LOW);
  }
}

void enable_all_rows(){
  for (int i = 0; i < 4; i++) {
    digitalWrite(posArray[i], HIGH);
  }
}

void enable_all_columns(){
  for(int i=0;  i<16; i++){
    digitalWrite( groundArray[i],LOW);
  }
}

void disable_all_columns(){
  for(int i=0;  i<16; i++){
    digitalWrite( groundArray[i],HIGH);
  }
}

void dance() {//////////////////////////////////////////////////////////UNUSED
  all_off();

  //
  digitalWrite(A4,HIGH);  //enable row
  for(int i=0; i<16; i++){

  }
  digitalWrite(10,LOW); //enable column index 4
  digitalWrite(1,LOW);  //enable column index 13
  delay(2000);
  all_off();
}
///////////////////////////////////////////////////////////////////////////////////////

void finshing() {
  all_off();

  for (int a = 0; a < 4; a++) {
    digitalWrite(posArray[a], HIGH);  // actives leads to pass power
  }

  //done (finishing animation)
  all_on();
  delay(300);
  all_off();
  delay(300);
  all_on();
  delay(300);
  all_off();
  delay(300);
  all_on();
  delay(300);
  all_off();
}

void scan_up(){
  enable_all_columns();
  disable_all_rows();
  delay(150);
  for(int i=0; i<4; i++){
    digitalWrite(posArray[i],HIGH);
    delay(200);
    digitalWrite(posArray[i],LOW);
  }
}

void scan_down(){
  enable_all_columns();
  disable_all_rows();
  delay(150);
  for(int i=4; i>=0; i--){
    digitalWrite(posArray[i],HIGH);
    delay(200);
    digitalWrite(posArray[i],LOW);
  }
}

void scan_left(){
  all_off();
  enable_all_rows();
  delay(150);

  for(int i=3; i>=0; i--){
    //turn on LEDSs
    digitalWrite(groundArray[i], LOW);
    digitalWrite(groundArray[i+4], LOW);
    digitalWrite(groundArray[i+8], LOW);
    digitalWrite(groundArray[i+12], LOW);

    if(i != 4){
      int j=i+1;
      //turns off LEDs
      digitalWrite(groundArray[j], HIGH);
      digitalWrite(groundArray[j+4], HIGH);
      digitalWrite(groundArray[j+8], HIGH);
      digitalWrite(groundArray[j+12], HIGH);
    }

    if(i == 0){
      delay(200);
      //turns off remaining LEDs
      digitalWrite(groundArray[0], HIGH);
      digitalWrite(groundArray[4], HIGH);
      digitalWrite(groundArray[8], HIGH);
      digitalWrite(groundArray[12], HIGH);
    }
    delay(200);
  }

  all_off();
}

void scan_right(){
  all_off();
  enable_all_rows();
  delay(150);

  for(int i=0; i<4; i++){
    digitalWrite(groundArray[i], LOW);
    digitalWrite(groundArray[i+4], LOW);
    digitalWrite(groundArray[i+8], LOW);
    digitalWrite(groundArray[i+12], LOW);

    if(i != 0){
      int j=i-1;
      digitalWrite(groundArray[j], HIGH);
      digitalWrite(groundArray[j+4], HIGH);
      digitalWrite(groundArray[j+8], HIGH);
      digitalWrite(groundArray[j+12], HIGH);
    }

    delay(250);
  }

  //turns off remaining LEDs
  digitalWrite(groundArray[4], HIGH);
  digitalWrite(groundArray[8], HIGH);
  digitalWrite(groundArray[12], HIGH);
  digitalWrite(groundArray[16], HIGH);

  all_off();
}

void deload(){
  all_on();
  delay(100);
  for(int i=16; i>=0; i--){
    digitalWrite(groundArray[i],HIGH);
    delay(250);
  }
}

void reload(){
  //enable 
  all_off();
  enable_all_rows();
  delay(500);
  for(int i=0; i<16; i++){
    digitalWrite(groundArray[i],LOW);
    delay(250);
  }

  all_off();
}

void swirl(){
  all_off();
  enable_all_rows();

  //outer layer
  for(int i=0; i<4; i++){
    digitalWrite(groundArray[i], LOW);
    delay(250);
  }

  for(int i=3; i<=16; i+=4){
    digitalWrite(groundArray[i],LOW);
    delay(250);
  }

  for(int i=15; i>11; i--){
    digitalWrite(groundArray[i], LOW);
    delay(250);
  }

  for(int i=12; i>=4; i-=4){
    digitalWrite(groundArray[i], LOW);
    delay(250);
  }

  //inner portion
  digitalWrite(groundArray[5], LOW);
  delay(250);
  digitalWrite(groundArray[6], LOW);
  delay(250);
  digitalWrite(groundArray[10], LOW);
  delay(250);
  digitalWrite(groundArray[9], LOW);
  delay(500);

  //reverse order (inner portion)
  digitalWrite(groundArray[9], HIGH);
  delay(250);
  digitalWrite(groundArray[10], HIGH);
  delay(250);
  digitalWrite(groundArray[6], HIGH);
  delay(250);
  digitalWrite(groundArray[5], HIGH);
  delay(250);

  //reverse order(outter layer)
  for(int i=4; i<=11; i+=4){
    digitalWrite(groundArray[i], HIGH);
    delay(250);
  }

  for(int i=12; i<=14; i++){
    digitalWrite(groundArray[i], HIGH);
    delay(250);
  }

  for(int i=15; i>=3; i-=4){
    digitalWrite(groundArray[i], HIGH);
    delay(250);
  }

  for(int i=3; i>=0; i--){
    digitalWrite(groundArray[i], HIGH);
    delay(250);
  }

}


void snake(){
  enable_all_rows();
  disable_all_columns();

  for(int i=0; i<4; i++){
    digitalWrite(groundArray[i], LOW);
    delay(snake_speed);
  }

  digitalWrite(groundArray[0], HIGH); //off
  digitalWrite(groundArray[7], LOW);  //on
  delay(snake_speed);

  digitalWrite(groundArray[1], HIGH);
  digitalWrite(groundArray[6], LOW);
  delay(snake_speed);

  digitalWrite(groundArray[2], HIGH);
  digitalWrite(groundArray[5], LOW);  
  delay(snake_speed);

  digitalWrite(groundArray[3], HIGH);
  digitalWrite(groundArray[4], LOW);
  delay(snake_speed);
  
  digitalWrite(groundArray[7], HIGH);
  digitalWrite(groundArray[8], LOW);
  delay(snake_speed);
  
  digitalWrite(groundArray[6], HIGH);
  digitalWrite(groundArray[9], LOW);
  delay(snake_speed);

  digitalWrite(groundArray[5], HIGH);
  digitalWrite(groundArray[10], LOW);
  delay(snake_speed);
  
  digitalWrite(groundArray[4], HIGH);
  digitalWrite(groundArray[11], LOW);
  delay(snake_speed);
  
  digitalWrite(groundArray[8], HIGH);
  digitalWrite(groundArray[15], LOW);
  delay(snake_speed);

  digitalWrite(groundArray[9], HIGH);
  digitalWrite(groundArray[14], LOW);
  delay(snake_speed);

  digitalWrite(groundArray[10], HIGH);
  digitalWrite(groundArray[13], LOW);
  delay(snake_speed);

  digitalWrite(groundArray[11], HIGH);
  digitalWrite(groundArray[12], LOW);

  for(int i=15; i>=12; i--){
    delay(snake_speed);
    digitalWrite(groundArray[i], HIGH);
  }


}

void fan(){}
