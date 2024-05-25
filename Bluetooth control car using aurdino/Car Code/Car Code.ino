//Arduino Bluetooth Controlled Car
//Before uploading the code you have to install the necessary library
//Note - Disconnect the Bluetooth Module before hiting the upload button otherwise you'll get compilation error message.
//AFMotor Library https://learn.adafruit.com/adafruit-motor-shield/library-install
//After downloading the library open Arduino IDE >> go to sketch >> Include Libray >> ADD. ZIP Libray >> Select the downloaded
//ZIP File >> Open it >> Done
//Now You Can Upload the Code without any problem but make sure the bt module isn't connected with Arduino while uploading code

#include <AFMotor.h>

//initial motors pin
AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

// Define LED and buzzer pins
#define frontLight A0
#define backLight A1
#define horn A2
#define parkingLight A3

char command;

void setup() {
  Serial.begin(9600);  //Set the baud rate to your Bluetooth module.

  // Set LED and buzzer pins as outputs
  pinMode(frontLight, OUTPUT);
  pinMode(backLight, OUTPUT);
  pinMode(horn, OUTPUT);
  pinMode(parkingLight, OUTPUT);
}





void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();
    Stop();  //initialize with motors stoped
    //Change pin mode only if new command is different from previous.
    //Serial.println(command);
    switch (command) {
      case 'F':
        forward();
        break;
      case 'B':
        back();
        break;
      case 'L':
        left();
        break;
      case 'R':
        right();
        break;

        //FrontLight testcase
      case 'W':
        frontlightOn();
        break;
      case 'w':
        frontlightOff();
        break;

        //FrontLight testcase
      case 'U':
        backlightOn();
        break;
      case 'u':
        backlightOff();
        break;

        //Horn testcase
      case 'V':
        hornOn();
        break;
      case 'v':
        hornOff();
        break;

        //ParkingLight testcase
      case 'X':
        parkinglightOn();
        break;
      case 'x':
        parkinglightOff();
        break;
    }
  }
}

void forward() {
  motor1.setSpeed(255);  //Define maximum velocity
  motor1.run(FORWARD);   //rotate the motor clockwise
  motor2.setSpeed(255);  //Define maximum velocity
  motor2.run(FORWARD);   //rotate the motor clockwise
  motor3.setSpeed(255);  //Define maximum velocity
  motor3.run(FORWARD);   //rotate the motor clockwise
  motor4.setSpeed(255);  //Define maximum velocity
  motor4.run(FORWARD);   //rotate the motor clockwise
}

void back() {
  motor1.setSpeed(255);  //Define maximum velocity
  motor1.run(BACKWARD);  //rotate the motor anti-clockwise
  motor2.setSpeed(255);  //Define maximum velocity
  motor2.run(BACKWARD);  //rotate the motor anti-clockwise
  motor3.setSpeed(255);  //Define maximum velocity
  motor3.run(BACKWARD);  //rotate the motor anti-clockwise
  motor4.setSpeed(255);  //Define maximum velocity
  motor4.run(BACKWARD);  //rotate the motor anti-clockwise
}

void left() {
  motor1.setSpeed(255);  //Define maximum velocity
  motor1.run(BACKWARD);  //rotate the motor anti-clockwise
  motor2.setSpeed(255);  //Define maximum velocity
  motor2.run(BACKWARD);  //rotate the motor anti-clockwise
  motor3.setSpeed(255);  //Define maximum velocity
  motor3.run(FORWARD);   //rotate the motor clockwise
  motor4.setSpeed(255);  //Define maximum velocity
  motor4.run(FORWARD);   //rotate the motor clockwise
}

void right() {
  motor1.setSpeed(255);  //Define maximum velocity
  motor1.run(FORWARD);   //rotate the motor clockwise
  motor2.setSpeed(255);  //Define maximum velocity
  motor2.run(FORWARD);   //rotate the motor clockwise
  motor3.setSpeed(255);  //Define maximum velocity
  motor3.run(BACKWARD);  //rotate the motor anti-clockwise
  motor4.setSpeed(255);  //Define maximum velocity
  motor4.run(BACKWARD);  //rotate the motor anti-clockwise
}


void frontlightOn() {  // Front light on
  digitalWrite(frontLight, HIGH);
}

void frontlightOff() {  // Front light off
  digitalWrite(frontLight, LOW);
}


void backlightOn() {  // Back light on
  digitalWrite(backLight, HIGH);
}

void backlightOff() {  // Back light off
  digitalWrite(backLight, LOW);
}


void hornOn() {  // Horn on
  digitalWrite(horn, HIGH);
}

void hornOff() {  // Horn off
  digitalWrite(horn, LOW);
}

void parkinglightOn() {  // Parking light on
  digitalWrite(parkingLight, HIGH);
}

void parkinglightOff() {  // Parking light off
  digitalWrite(parkingLight, LOW);
}



void Stop() {
  motor1.setSpeed(0);   //Define minimum velocity
  motor1.run(RELEASE);  //stop the motor when release the button
  motor2.setSpeed(0);   //Define minimum velocity
  motor2.run(RELEASE);  //rotate the motor clockwise
  motor3.setSpeed(0);   //Define minimum velocity
  motor3.run(RELEASE);  //stop the motor when release the button
  motor4.setSpeed(0);   //Define minimum velocity
  motor4.run(RELEASE);  //stop the motor when release the button
}