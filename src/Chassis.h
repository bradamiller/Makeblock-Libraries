#pragma once

#include <MeAuriga.h>

class Chassis {
 public:
  Chassis();
  /**
   * Set the effort value for the left and right motors
   */
  void setEffort(float leftEffort, float rightEffort);

  /**
   * Set the speed value for the left and right motors in RPM
   */
  void setSpeed(float leftRPM, float rightRPM);

  /**
   * This method sets up the registers so the chassis motors will operate
   * and needs to be called from the main program setup() function.
   */
  void setup();

  /**
   * This method should be called from the main program loop() function
   * and ensures that the encoders operate properly. It needs to get
   * moved somewhere else later.
   */
  void loop();

  /**
   * Get the left and right positions from the encoders. The units are
   * in degrees of rotation.
   */
  long getLeftPos();
  long getRightPos();

  /**
   * Stop the motors
   */
  void stop();

 private:
  static void isrLeft();
  static void isrRight();
};
