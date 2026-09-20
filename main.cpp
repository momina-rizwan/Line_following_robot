#include <iostream>
#include <thread>
#include <chrono>

// Pin & Port Assignments
#define MOTOR_LEFT_PORT   'A'
#define MOTOR_RIGHT_PORT  'D'
#define SENSOR_LEFT_PORT   1
#define SENSOR_RIGHT_PORT  4

// Threshold Values (Calibrated)
#define WHITE_THRESHOLD   20
#define BLACK_THRESHOLD   15
#define BASE_SPEED        75
#define TURN_SPEED        50

// Hardware Interface Functions
void setMotorSpeed(char port, int speed) {
    // Hardware abstraction for motor control
}

int readIRReflectance(int sensorPort) {
    // Hardware abstraction for IR sensor reading
    return 0; 
}

void stopAllMotors() {
    setMotorSpeed(MOTOR_LEFT_PORT, 0);
    setMotorSpeed(MOTOR_RIGHT_PORT, 0);
}

// Line Following Algorithm
void followLine() {
    while (true) {
        int leftValue  = readIRReflectance(SENSOR_LEFT_PORT);
        int rightValue = readIRReflectance(SENSOR_RIGHT_PORT);

        // Case 1: Both sensors see white -> Move straight forward
        if (leftValue > WHITE_THRESHOLD && rightValue > WHITE_THRESHOLD) {
            setMotorSpeed(MOTOR_LEFT_PORT, BASE_SPEED);
            setMotorSpeed(MOTOR_RIGHT_PORT, BASE_SPEED);
        }
        // Case 2: Left sensor detects black line -> Steer left
        else if (leftValue < BLACK_THRESHOLD && rightValue > WHITE_THRESHOLD) {
            setMotorSpeed(MOTOR_LEFT_PORT, -TURN_SPEED);
            setMotorSpeed(MOTOR_RIGHT_PORT, TURN_SPEED);
        }
        // Case 3: Right sensor detects black line -> Steer right
        else if (leftValue > WHITE_THRESHOLD && rightValue < BLACK_THRESHOLD) {
            setMotorSpeed(MOTOR_LEFT_PORT, TURN_SPEED);
            setMotorSpeed(MOTOR_RIGHT_PORT, -TURN_SPEED);
        }
        // Case 4: Both sensors detect black line / Stop condition
        else if (leftValue < BLACK_THRESHOLD && rightValue < BLACK_THRESHOLD) {
            stopAllMotors();
            break;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

int main() {
    // System Initialization
    setMotorSpeed(MOTOR_LEFT_PORT, BASE_SPEED);
    setMotorSpeed(MOTOR_RIGHT_PORT, BASE_SPEED);
    
    // Execute line tracking loop
    followLine();

    return 0;
}
