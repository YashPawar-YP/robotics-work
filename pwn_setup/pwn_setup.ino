#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>
#include <ESP32Servo.h>

// --- PIN DEFINITIONS ---
#define in1 32
#define in2 33
#define en1 25

#define in3 26
#define in4 27
#define en2 13

Servo myservo;
#define an1 14

// --- HELPER FUNCTION ---
void setMotors(int inA, int inB, int pwm, int speed) {
  if (speed > 0) {
    digitalWrite(inA, HIGH);
    digitalWrite(inB, LOW);
    analogWrite(pwm, speed);
  } else if (speed < 0) {
    digitalWrite(inA, LOW);
    digitalWrite(inB, HIGH);
    analogWrite(pwm, -speed);
  } else {
    digitalWrite(inA, LOW);
    digitalWrite(inB, LOW);
    analogWrite(pwm, 0);
  }
}

void setup() {
  Serial.begin(115200);
  Dabble.begin("1234");
  Serial.println("Dabble ready!");

  pinMode(in1, OUTPUT); pinMode(in2, OUTPUT); pinMode(en1, OUTPUT);
  pinMode(in3, OUTPUT); pinMode(in4, OUTPUT); pinMode(en2, OUTPUT);

  myservo.attach(an1);
  myservo.write(45); // Start position
}

void loop() {
  Dabble.processInput();

  int x_value = GamePad.getXaxisData(); // -7 to 7
  int y_value = GamePad.getYaxisData(); // -7 to 7

  // --- TANK MIXING ---
  // Left motor  = Forward/Back + Turn
  // Right motor = Forward/Back - Turn
  int leftSpeed  = constrain((y_value + x_value) * 255 / 7, -255, 255);
  int rightSpeed = constrain((y_value - x_value) * 255 / 7, -255, 255);

  // Dead zone — ignore tiny joystick drift
  if (abs(x_value) <= 1 && abs(y_value) <= 1) {
    leftSpeed  = 0;
    rightSpeed = 0;
    Serial.println("STOP");
  } else {
    Serial.printf("L: %d  R: %d\n", leftSpeed, rightSpeed);
  }

  setMotors(in1, in2, en1, -leftSpeed);  // Flip sign if motor is wired reversed
  setMotors(in3, in4, en2, -rightSpeed);

  // --- SERVO CONTROL ---
  if (GamePad.isCirclePressed()) {
    Serial.println("Servo UP");
    for (int i = 45; i <= 95; i++) {
      myservo.write(i);
      delay(15); // 15ms per step = ~0.75s total, not 50s
    }
  }

  if (GamePad.isTrianglePressed()) {
    Serial.println("Servo DOWN");
    for (int i = 95; i >= 45; i--) {
      myservo.write(i);
      delay(15);
    }
  }
}