int E1 = 10; // 1번(A) 모터 Enable
int E2 = 11; // 2번(B) 모터 Enable
int M1 = 12; // 1번(A) 모터 PWM
int M2 = 13; // 2번(B) 모터 PWM
int linesensor1 = A5;
int linesensor2 = A4;
int value;

void setup() { 
 pinMode(M1, OUTPUT); // 출력핀 설정
 pinMode(M2, OUTPUT); 
 Serial.begin(9600);
}

void loop()
{ 
  int value = 200; 
  int linetemp1 = digitalRead(A5); 
  int linetemp2 = digitalRead(A4);

if(linetemp1 == 0 && linetemp2 == 0)
{ 
    digitalWrite(M1, HIGH); 
    digitalWrite(M2, HIGH); 
    analogWrite(E1, value); 
    analogWrite(E2, value); 
    delay(10);
}
else if(linetemp1 == 1 && linetemp2 == 0)
{ 
    digitalWrite(M1, HIGH); 
    digitalWrite(M2, HIGH); 
    analogWrite(E1, 0); 
    analogWrite(E2, value); 
    delay(10);
}
else if(linetemp1 == 0 && linetemp2 == 1)
{ 
    digitalWrite(M1, HIGH); 
    digitalWrite(M2, HIGH); 
    analogWrite(E1, value);
    analogWrite(E2, 0); 
    delay(10);
}
else if(linetemp1 == 1 && linetemp2 == 1)
{ 
    digitalWrite(M1, LOW); 
    digitalWrite(M2, LOW); 
    analogWrite(E1, 200); 
    analogWrite(E2, 200); 
    delay(10);
}

}