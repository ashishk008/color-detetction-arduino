#include <LiquidCrystal.h>
#include <Servo.h>
Servo myservo;

//Declaring global variables
int pos = 0;
int ldrValue1;
int ldrValue2;
int ldrValue3;
int i = 255;
int j = 255;
int k = 255;
int minim;
int i1;
int j1;
int k1;



void setup() 
{

  Serial.begin(9600);

}


void AutoCalibrate()
{

  //Auto calibrate the LED so that it gives out equal intensity glow for all the three colors. Make sure the potentiometer is at the extreme position
//Red pin - 9
//Blue pin - 10
//Green pin - 11

  for (int rr = 0; rr <= 5; rr++)
  {
    analogWrite(9, 255);
    delay(100);
    ldrValue1 = analogRead(A2);
    analogWrite(9, 0);

    analogWrite(10, 255);
    delay(100);
    ldrValue2 = analogRead(A2);
    analogWrite(10, 0);

    analogWrite(11, 255);
    delay(100);
    ldrValue3 = analogRead(A2);
    analogWrite(11, 0);

    Serial.print("R-");
    Serial.println(ldrValue1);
    Serial.print("G-");
    Serial.println(ldrValue2);
    Serial.print("B-");
    Serial.println(ldrValue3);
  }

  int minimum = compare(ldrValue1, ldrValue2, ldrValue3);

  while (abs(ldrValue1 - minimum) > 2)
  {
    analogWrite(9, i);
    delay(100);
    ldrValue1 = analogRead(A2);
    i--;
    Serial.println(ldrValue1);
    if (i == 0) {
      i = 255;
    }

    
  }
  Serial.println("RED CALIBRATED");
  Serial.println(ldrValue1);
  Serial.println(i);
  i1 = i;
  analogWrite(9, 0);


  while (abs(ldrValue2 - minimum) > 2)
  {

    analogWrite(10, j);

    delay(100);
    ldrValue2 = analogRead(A2);
    j--;
    Serial.println(ldrValue2);
    if (j == 0) {
      j = 255;
    }
  }

  Serial.println("GREEN CALIBRATED");
  Serial.println(ldrValue2);
  Serial.println(j);
  j1 = j;
  analogWrite(10, 0);

  while (abs(ldrValue3 - minimum) > 2)
  {
    analogWrite(11, k);
    delay(100);
    ldrValue3 = analogRead(A2);
    k--;
    Serial.println(ldrValue3);
    if (k == 0) {
      k = 255;
    }
    
  }

  Serial.println("BLUE CALIBRATED");
  Serial.println(ldrValue3);
  Serial.println(k);
  k1 = k;
  analogWrite(11, 0);





}

int compare(int a, int b, int c) {

  if (a > b) {
    if (a >= c) {
      minim = a;
    }
    else {
      minim = c;
    }
  }
  else if (b >= a)
  {
    if (b > c) {
      minim = b;
    }

    else {
      minim = c;
    }

  }

  Serial.println("minimum value is");
  Serial.println(minim);
  return minim;

}

void loop() {


  AutoCalibrate();
  Serial.println("calibration done");
  while (1) {
    analogWrite(9, i1);
    delay(100);
    ldrValue1 = analogRead(A2);

    analogWrite(9, 0);
    analogWrite(10, j1);
    delay(100);
    ldrValue2 = analogRead(A2);

    analogWrite(10, 0);
    analogWrite(11, k1);
    delay(100);
    ldrValue3 = analogRead(A2);

    analogWrite(11, 0);
    Serial.print("R-");
    Serial.print(ldrValue1);
    Serial.print(" G-");
    Serial.print(ldrValue2);
    Serial.print(" B-");
    Serial.println(ldrValue3);

  }
}
