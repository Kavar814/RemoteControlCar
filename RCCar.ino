// connect motor controller pins to Arduino digital pins
// motor one
int enA = 10;
int in1 = 9;
int in2 = 8;
// motor two
int enB = 5;
int in3 = 7;
int in4 = 6;
void setup()
{
  Serial.begin(9600);
  // set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop()
{
  if(Serial.available() > 0){
    char inputChar = Serial.read();
    switch(inputChar){
      case 'w':
          //running small motor
          digitalWrite(in1, HIGH);
          digitalWrite(in2, LOW);
          analogWrite(enA, 255);//range 0-255  /*helps control speed*/
          //running large motor
          digitalWrite(in3, HIGH);
          digitalWrite(in4, LOW);
          analogWrite(enB, 255);
        break;
      case 'a':
            digitalWrite(in1, HIGH);
            digitalWrite(in2, LOW);
            analogWrite(enA, 255);
            digitalWrite(in3, LOW);
            digitalWrite(in4, HIGH);
            analogWrite(enB, 255);
        break;
      case 's':
            //running small motor
            digitalWrite(in1, LOW);
            digitalWrite(in2, HIGH);
            analogWrite(enA, 255);//range 0-255  /*helps control speed*/
            //running large motor
            digitalWrite(in3, LOW);
            digitalWrite(in4, HIGH);
            analogWrite(enB, 255);
        break;
      case 'd':
            digitalWrite(in1, LOW);
            digitalWrite(in2, HIGH);
            analogWrite(enA, 255);
            digitalWrite(in3, HIGH);
            digitalWrite(in4, LOW);
            analogWrite(enB, 255);
        break;
      case ' ':
             digitalWrite(in1, LOW);
             digitalWrite(in2, LOW);
             digitalWrite(in3, LOW);
             digitalWrite(in4, LOW);
        break; 
    } 
  }
}

