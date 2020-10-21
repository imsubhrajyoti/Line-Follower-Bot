int mSpeed = 100;    // MAX 255
int tSpeed = 100;    // MAX 255 
int bStatus=0;
int late=10;
int dly = 30;
//int turn_delay = 10;

// motor R
int in1 = 4;
int in2 = 3;
int enR = 5;  //PWM Pin

// motor L
int enL = 6;  //PWM Pin
int in3 = 8;
int in4 = 7;

//sensors
int lir = A0;  // Analog input pin that the sensor is attached to
int mir = A1;  // Analog input pin that the sensor is attached to
int rir = A2;  // Analog input pin that the sensor is attached to

//state of sensors
int lir_state=1;
int mir_state=0;
int rir_state=1;
int path=0;

int sensor[3];
char p[30] = {};
int pLength;
int readLength;

void setup() {
  // set all IR input pins to inputs
  pinMode(lir, INPUT); // initialize Left sensor as an inut
  pinMode(mir, INPUT); // initialize Middle sensor as as input
  pinMode(rir, INPUT); // initialize Right sensor as as input
  
  // set all the motor control pins to outputs
  pinMode(enL, OUTPUT);
  pinMode(enR, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin(57600);
  delay(700);
}
void Run();
void Forward();
void turnRight();
void turnLeft();
void Stop();
void readSensor();
void turnAround();
void Backward();
void leftHandWall();

void loop() {  
  path=1;
  Run();
}
void Run(){
  readSensor();
  if(lir_state!=path && rir_state!=path && mir_state==path){
    delay(late);
    Forward();
    readSensor();
  }else if(lir_state==path && mir_state!= path && rir_state!=path){
    delay(late);
    turnLeft();
    readSensor();
  }else if(lir_state!=path && mir_state!= path && rir_state==path){
    delay(late);
    turnRight();
    readSensor();
  }else if(lir_state==path && mir_state==path && rir_state!=path){
    while(lir_state!=path){
      turnLeft;
      readSensor();
    }
  }else if(lir_state!=path && mir_state==path && rir_state==path){
    Forward();
    delay(late);
    readSensor();
    if(lir_state!=path && mir_state!=path){
      turnRight();
      readSensor();
    }
  }else if(lir_state==path && mir_state==path && rir_state==path){
    turnLeft();
    readSensor();
  }/*****
  else if(lir_state!=path && mir_state!=path && rir_state!=path){
      turnAround();
      readSensor(); 
  }****/
  else if(lir_state==path && mir_state!=path && rir_state==path){
    turnLeft();
    readSensor();
  }
  else if(lir_state!=path && mir_state!=path && rir_state!=path){
    Backward();
    delay(dly);
    Stop();
    delay(late);
    readSensor();
    if(lir_state!=path && mir_state==path && rir_state!=path){
      turnAround();
      readSensor();
    }else if(lir_state!=path && mir_state==path && rir_state==path){
      while(rir_state!=path){
        turnRight;
        readSensor();
      }
    }else if(lir_state==path && mir_state==path && rir_state!=path){
      while(lir_state!=path){
        turnLeft;
        readSensor();
      }
    }
  }
}
void Forward(){
  //turn on motor R
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);// move forward
  analogWrite(enR, mSpeed);// set speed to 200 out of possible range 0~255
  // turn on motor L
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);// move forward
  analogWrite(enL, mSpeed);// set speed to 200 out of possible range 0~255
}

void turnRight(){
  //turn off motor R
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);// Stop
  analogWrite(enR, 0);// set speed to 0 out of possible range 0~255
  // turn on motor L
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);// move forward
  analogWrite(enL, tSpeed);// set speed to 200 out of possible range 0~255

  //delay(turn_delay);
}

void turnLeft(){
  //turn on motor R
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);// move forward
  analogWrite(enR, tSpeed);// set speed to 200 out of possible range 0~255
  // turn off motor L
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);// stop
  analogWrite(enL, 0);// set speed to 0 out of possible range 0~255

  //delay(turn_delay);
}
void Backward(){
   //turn back motor R
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);// move backward
  analogWrite(enR, mSpeed);// set speed to 200 out of possible range 0~255
  // turn back motor L
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);// move backward
  analogWrite(enL, mSpeed);// set speed to 200 out of possible range 0~255
}
void Stop(){
  //turn off motor L
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);// Stop
  analogWrite(enL, 0);// set speed to 0 out of possible range 0~255
  // turn off motor R
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);// move forward
  analogWrite(enR, 0);// set speed to 0 out of possible range 0~255
}
void turnAround(){
  while(mir_state!=path){
    //turn motor L Backward
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);// Stop
    analogWrite(enL, 90);// set speed to 0 out of possible range 0~255
    // turn motor R Forward
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);// move forward
    analogWrite(enR, 90);// set speed to 0 out of possible range 0~255
  }
}
void readSensor(){
  lir_state=digitalRead(lir); //Read the digital value of Left sensor
  mir_state=digitalRead(mir); //Read the digital value of Middle sensor
  rir_state=digitalRead(rir); //Read the digital value of Right sensor 
}
