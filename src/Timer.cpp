#include "Timer.h"
#include <Arduino.h>

    Timer::Timer(long interval) {
        expiredTime = millis() + interval;
        timeInterval = interval;
    }

    bool Timer::isExpired() {
        if (millis() > expiredTime) {
            expiredTime = millis() + timeInterval;
            return true;
        }
        return false;
    }