#include <AFMotor.h> // Importing the corresponding header file that is relevent for the bot

AF_DCMotor motorA(4); //this is the left motor
AF_DCMotor motorB(2); //this is the right motor

void setup()
{
    Serial.begin(9600); // set up Serial library at 9600 bps
    Serial.println("Line Follower Rover");
    delay(500);

    pinMode(A0, INPUT);   // declare A0 as input pin for left sensor
    pinMode(A1, INPUT);   // declare A1 as input pin for right sensor
    motorA.setSpeed(180); // turn on motor1
    motorA.run(RELEASE);
    motorB.setSpeed(180); // turn on motor2
    motorB.run(RELEASE);
}

void loop()
{
    int sensor1 = digitalRead(A1);
    int sensor2 = digitalRead(A0);

    //Reading the values of the sensors on the serial monitor
    Serial.print(sensor1);
    Serial.print("    ");
    Serial.println(sensor2);
    delay(50);
    //value of 0 means no black line, value of 1 means black line detected.

    //Move forward if both sensors zero (no black line).

    if ((sensor1 == 1) && (sensor2 == 1))
    {
        motorA.setSpeed(200); // turn on motor1
        motorB.setSpeed(200);
        motorA.run(FORWARD);
        motorB.run(FORWARD);
    }
    //Turn left if left sensor (sensor 1) detects black line
    else if ((sensor1 == 0) && (sensor2 == 1))
    //motor1 is left motor, motor 2 is right motor
    {
        motorA.setSpeed(200); // turn on motor1
        motorA.run(FORWARD);
        motorB.setSpeed(50);
        motorB.run(FORWARD);
    }
    //Turn right if right sensor detects black line
    else if ((sensor2 == 0) && (sensor1 == 1))
    //motor1 is left motor, motor 2 is right motor
    {
        motorA.setSpeed(50); // turn on motor1
        motorA.run(FORWARD);
        motorB.setSpeed(200);
        motorB.run(FORWARD);
    }
}