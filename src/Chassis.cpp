#include "Chassis.h"

MeEncoderOnBoard left(SLOT2);
MeEncoderOnBoard right(SLOT1);

Chassis::Chassis() {}

void Chassis::isrLeft() {
  if (digitalRead(left.getPortB()) == 0) {
    left.pulsePosMinus();
  } else {
    left.pulsePosPlus();
  }
}

void Chassis::isrRight() {
  if (digitalRead(right.getPortB()) == 0) {
    right.pulsePosMinus();
  } else {
    right.pulsePosPlus();
  }
}

void Chassis::setup() {
  left.reset(SLOT2);
  right.reset(SLOT1);
  // Set Pwm 8KHz
  TCCR1A = _BV(WGM10);
  TCCR1B = _BV(CS11) | _BV(WGM12);
  TCCR2A = _BV(WGM21) | _BV(WGM20);
  TCCR2B = _BV(CS21);
  attachInterrupt(left.getIntNum(), isrLeft, RISING);
  left.setPulse(9);
  left.setRatio(39.267);
  left.setPosPid(1.8, 0, 1.2);
  left.setSpeedPid(0.18, 0, 0);
  attachInterrupt(right.getIntNum(), isrRight, RISING);
  right.setPulse(9);
  right.setRatio(39.267);
  right.setPosPid(1.8, 0, 1.2);
  right.setSpeedPid(0.18, 0, 0);
}

void Chassis::setEffort(float leftEffort, float rightEffort) {
  left.setMotorPwm(leftEffort);
  right.setMotorPwm(-rightEffort);
}

void Chassis::setSpeed(float leftRPM, float rightRPM) {
  left.runSpeed(leftRPM);
  right.runSpeed(-rightRPM);
}

void Chassis::stop() { setEffort(0, 0); }

void Chassis::loop() {
  left.loop();
  right.loop();
}

long Chassis::getLeftPos() { return left.getCurPos(); }

long Chassis::getRightPos() { return -right.getCurPos(); }
