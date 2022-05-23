/************************************** THƯ VIỆN THỜI GIAN TIMER **************************************/

#ifndef TIMER_H
#define TIMER_H

#include <SDL2/SDL.h>

const int FRAME_RATE = 60; // tỉ lệ khung hình fps

class Timer {
private: 

    static Timer* Instance;
    unsigned StartTicks;    // thời gian từ khi bắt đầu chạy timer
    unsigned ElapsedTicks;  // thời gian đã trôi qua (ms)
    float DeltaTime;        // thời gian trôi qua tính (s)

public:

    static Timer* getInstance(); 
    static void Release();

    void Reset(); // reset lại timer
    float getDeltaTime(); // lấy ra khoảng thời gian cần tính

    void Update(); // update lại các giá trị thời gian

private:
    
    Timer();

};

#endif