#include "serial.h"
#include <iostream>
#include <bitset>
#include <string>
#include "thread"
#include "motor.h"



int main()
{   
    motor::InitMotor("/dev/cu.usbserial-0001", 115200, serial::Timeout::simpleTimeout(3000));

    // TEST LETTURA CORRENTE
    //motor::startMotor();
    //std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    // motor::setDutyCycle(50,0);

    // current = motor::getCurrent();
    // std::cout << current << std::endl;
    
    // current = motor::getCurrent();
    // std::cout << current << std::endl;
    
    // current = motor::getCurrent();
    // std::cout << current << std::endl;
    
    // current = motor::getCurrent();
    // std::cout << current << std::endl;
    
    // current = motor::getCurrent();
    // std::cout << current << std::endl;
    
    
    // motor::stopMotor();

    // TEST PER AFFIDABILITÀ

    // float count = 0;
    // float score;

    // for(int i = 0; i < 1000; i++){

    //     count = count + motor::startMotor();
    //     std::this_thread::sleep_for(std::chrono::milliseconds(20));

    // }

    // score = count/1000;

    // std::cout << score*100 << " %" << std::endl;
    float current;

    motor::startMotor();

    for(int i = 5; i < 10; i++){


        std::this_thread::sleep_for(std::chrono::milliseconds(20));
        motor::setDutyCycle(i*10, 0);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        current = motor::getCurrent();
        std::cout << current << std::endl;
    }

    // current = motor::getCurrent();
    // std::cout << current << std::endl;
    motor::stopMotor();
    
    return 0;

}

