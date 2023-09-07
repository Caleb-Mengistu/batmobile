int bruceLCD = 0;
int batLCD = 0;
int rightSensor = 6;
int leftSensor = 7;
int LDR = 8;
int LED = 11;
int piezo = 12;
int pos;
int fast;
int times = 0;

void driveRight() {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
}

void stopRight() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
}

void backRight() {
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
}

void driveLeft() {
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
}

void stopLeft() {
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
}

void backLeft() {
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
}

void setup() {
  // put your setup code here, to run once:
  pinMode (2, OUTPUT);
  pinMode (3, OUTPUT);
  pinMode (4, OUTPUT);
  pinMode (5, OUTPUT);
  pinMode (leftSensor, INPUT);
  pinMode (rightSensor, INPUT);
}

void drive() {
  if (digitalRead(rightSensor) == 0 and digitalRead (leftSensor) == 1) {
    if (times >= 500) {
      stopLeft();
      driveRight();
    }
    else if (times < 500) {
      backLeft();
      driveRight();
    }

  }
  else if (digitalRead(leftSensor) == 0 and digitalRead(rightSensor) == 1) {
    if (times >= 500) {
      backRight();
      driveLeft();
    }

    else if (times < 500) {
      stopRight();
      driveLeft();
    }
    times += 1;
  }
  else if (digitalRead (leftSensor) == 0 and digitalRead(rightSensor) == 0) {
    backRight();
    backLeft();
    times = 500;  
  }
  else if (digitalRead (leftSensor) == 1 and digitalRead(rightSensor) == 1) {
    driveRight();
    driveLeft();
    times = 0;
  }
}



void loop() {
  // put your main code here, to run repeatedly:

  drive();
  delay(1);


}
