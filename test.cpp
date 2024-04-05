#include "serial.h"
#include <iostream>
#include <bitset>
#include <string>
#include "thread"
#include "motorDriver.h"


int main()
{
    
//*************************************** Current reading*************************************
    // std::string  current;
    // int dc;

    // motorDriver::InitMotor("/dev/ttyUSB0", 115200, serial::Timeout::simpleTimeout(3000));
    // motorDriver::startMotor();
    // while(1){
    // current = motorDriver::getCurrent();
    // //std::cout<<"Current: "<<current<<std::endl;
    // char arr[current.length() + 1]; 
    // char* arrEnd;

	// strcpy(arr, current.c_str()); 
    // if(current.empty()) std::cout<<"error"<<std::endl;

    // //std::cout  << std::strtof(arr,&arrEnd) << " A" << std::endl;
    // std::cout <<"Current:"<< std::stof(current) << " A" << std::endl;
    // std::this_thread::sleep_for(std::chrono::milliseconds(20));
    // }

    //**************************************************************************************************************
    
    
    // for(int i = 0; i < 5; i++){

    //     if(i%5 == 0){

    //         dc = 200;

    //     }
    //     else{ 

    //         dc = 50;
    //     }

    //     count = motor::setDutyCycle(dc, 0);
    //     total += count;
        
    // }

    // std::cout << "Score: " << (total/5)*100 << "%" << std::endl;

    // motor::stopMotor();

    // for(int i = 10; i <= 50; i++){

    //     if(i%5 == 0){

    //         motor::setDutyCycle(i, 0);
    //         //current = motor::getCurrent();
    //         std::cout << current << " A" << std::endl;
    //     }

    // }

   
    motorDriver::stopMotor();

    return 0;

}

