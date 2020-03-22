#include <NewPing.h>
#define PIN_TRIG0 22
#define PIN_ECHO0 23
#define PIN_TRIG1 24
#define PIN_ECHO1 25
#define PIN_TRIG2 26
#define PIN_ECHO2 27
#define PIN_TRIG3 28
#define PIN_ECHO3 29
#define PIN_TRIG4 30
#define PIN_ECHO4 31
#define PIN_TRIG5 32
#define PIN_ECHO5 33
#define PIN_TRIG6 34
#define PIN_ECHO6 35
#define PIN_TRIG 36
#define PIN_ECHO 37
#define MAX_DISTANCE 10
#define dir1 38
#define dir2 39
#define stp1 40
#define dir3 41
#define stp2 42
#define endstep 43
#define pump 44
#define Stop 45
float c;
float V = 0;
int n = 0;
int s= 0;
int standart = 2;
float x[13] = {2.5, 5, 7.5, 10, 12.5, 15, 17.5, 20, 22.5, 25, 27.5, 30, 32.5}; 
NewPing sonar0(PIN_TRIG0, PIN_ECHO0,MAX_DISTANCE);
NewPing sonar1(PIN_TRIG1, PIN_ECHO1,MAX_DISTANCE);
NewPing sonar2(PIN_TRIG2, PIN_ECHO2,MAX_DISTANCE);
NewPing sonar3(PIN_TRIG3, PIN_ECHO3,MAX_DISTANCE);
NewPing sonar4(PIN_TRIG4, PIN_ECHO4,MAX_DISTANCE);
NewPing sonar5(PIN_TRIG5, PIN_ECHO5,MAX_DISTANCE);
NewPing sonar6(PIN_TRIG6, PIN_ECHO6,MAX_DISTANCE);

void setup() {
  // Инициализируем взаимодействие по последовательному порту на скорости 9600
  Serial.begin(9600);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(dir3, OUTPUT);
  pinMode(stp1, OUTPUT);
  pinMode(stp2, OUTPUT);
  pinMode(Stop, INPUT);
  pinMode(pump, OUTPUT);
  while (endstep != LOW){
    digitalWrite(dir3, LOW);
    digitalWrite(stp2, HIGH);
    c = 0;
}
  digitalWrite(stp2,LOW);
}

void test(){
  n = 0;
  for ( int j = 0; j <= 6; j++){
    if (j == 0){
      if(unsigned range = sonar0.ping_cm() - standart >= 2){
        n++;
      }
    }  
    else if (j == 1) {
      if(unsigned range = sonar1.ping_cm() - standart >= 2){
        n++;
      }  
    }
   else if (j == 2) {
      if(unsigned range = sonar2.ping_cm() - standart >= 2){
        n++;
      }  
    }
     else if (j == 3) {
      if(unsigned range = sonar3.ping_cm() - standart >= 2){
        n++;
      }  
    }
     else if (j == 4) {
      if(unsigned range = sonar4.ping_cm() - standart >= 2){
        n++;
      }  
    }
     else if (j == 5) {
      if(unsigned range = sonar5.ping_cm() - standart >= 2){
        n++;
      }  
    }
     else if (j == 6) {
      if(unsigned range = sonar6.ping_cm() - standart >= 2){
        n++;
      }  
    }
    if (n >= 1) {
      return n;
      break; 
    }
    else{
      return n;
    }
  }  
}

void Move(){
  digitalWrite(dir1, HIGH);
  digitalWrite(dir2, HIGH);
  digitalWrite(stp1, HIGH);
}

void notMove(){
  digitalWrite(dir1, LOW);
  digitalWrite(dir2, LOW);
  digitalWrite(stp1, LOW);
}

void loop() {
  if( Stop == 1){
    Move();
    delay(500);
    notMove();
    test();
    if (n >=1){
      delay(50);
      NewPing sonarm(PIN_TRIG, PIN_ECHO,MAX_DISTANCE);
      for (int i = 0; i >= 12; i++){ 
        if ( int z = sonarm.ping_cm() - standart >= 2){
          V = V + x[i]*z* 0.5;
          for ( int m = 0; m <=62; m++){
            digitalWrite( stp2, HIGH);
            digitalWrite(dir3, HIGH);
            delay(10);
            digitalWrite(stp2, LOW);
            delay(10);  
          } 
          s++;
        } 
        if (s <= 11){
          break;
        }
      }
      digitalWrite(pump, HIGH);
      delay(V/5);
      digitalWrite(pump, LOW);
    }
  }
  else{
    notMove();
  }
  
}
