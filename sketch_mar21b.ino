int stp1 = 13; //подключите 13 пин к step

int dir1 = 12; //подключите 12 пин к dir
int stp2 = 10;

int dir2 = 11; 
#define st 5

int a = 0;
int barrier;
void setup()

{
pinMode(st, INPUT);
pinMode(stp1, OUTPUT);

pinMode(dir1, OUTPUT);

pinMode(stp2, OUTPUT);

pinMode(dir2, OUTPUT);
}

void loop(){
barrier = digitalRead(st);
if (barrier == 1){


if (a < 200) // вращение на 200 шагов в направлении 1

{

a++;

digitalWrite(stp1, HIGH);
digitalWrite(stp2, HIGH);

delay(10);

digitalWrite(stp1, LOW);
digitalWrite(stp2, LOW);

delay(10);

}

else { digitalWrite(dir1, HIGH);
digitalWrite(dir2, HIGH);

a++;

digitalWrite(stp1, HIGH);
digitalWrite(stp2, HIGH);

delay(10);

digitalWrite(stp1, LOW);
digitalWrite(stp2, LOW);

delay(10);

if (a>400) // вращение на 200 шагов в направлении 2

{

a = 0;

digitalWrite(dir1, LOW);
digitalWrite(dir2, LOW);

}

}

}
}
