#pragma once


#include <iostream>
#include <string>
#include "serial.h"


namespace motorDriver{

    void startMotor(void);
    void stopMotor(void);
    void setDutyCycle(int dutycycle, int option);
    void configPWM(int frequency, int resolution);
    std::string getCurrent(void);
    void InitMotor(std::string port, int baudrate, serial::Timeout timeout);

}
