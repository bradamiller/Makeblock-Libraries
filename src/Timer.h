#pragma once

class Timer {
    public:
    Timer(long interval);
    bool isExpired();
private:
    long expiredTime;
    long timeInterval;
};