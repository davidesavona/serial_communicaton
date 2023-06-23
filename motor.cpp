#include "serial.h"
#include <iostream>
#include "thread"

namespace motor{

    serial::Serial my_serial;
    
    void startMotor(void){
    
        unsigned long int message = 0;
        std::string s = "";
        size_t startBytes;
        char startMarker = '<';
        char endMarker = '>';

        message |= (1 << 16);
        s.push_back(startMarker);
        s += std::to_string(message);
        s.push_back(endMarker);
            
        startBytes = my_serial.write(s);

    }

    void stopMotor(void){

        unsigned long int message = 0;
        std::string s = "";
        size_t startBytes;
        char startMarker = '<';
        char endMarker = '>';

        message |= ((1 << 17) | (1 << 16));
        s.push_back(startMarker);
        s += std::to_string(message);
        s.push_back(endMarker);

        startBytes = my_serial.write(s);

    }

    void setDutyCycle(int dutyCycle, int option){

        unsigned long int message = 0;
        std::string s = "";
        size_t startBytes;
        char startMarker = '<';
        char endMarker = '>';

        if(dutyCycle <= 100 && dutyCycle >= 0){

            if(option){

                message |= ((1 << 17) | (1 << 24));
                message = message + dutyCycle;

                s.push_back(startMarker);
                s += std::to_string(message);
                s.push_back(endMarker);

                startBytes = my_serial.write(s);

                std::cout << "Duty cycle: " << dutyCycle << std::endl;

            }
            else if(!(option)){
                
                message |= (1 << 17);
                message += dutyCycle;

                s.push_back(startMarker);
                s += std::to_string(message);
                s.push_back(endMarker);

                startBytes = my_serial.write(s);

                std::cout << "Duty cycle: " << dutyCycle << std::endl;
            }
            else{

                std::cout << "ERROR: requested task is not applicable" << std::endl;
            }
        }
        else{

            std::cout << "ERROR: duty cycle is not applicable" << std::endl;
    
        }

    }

    void configPWM(int frequency, int resolution){

        unsigned long int message = 0;
        std::string s = "";
        size_t startBytes;
        char startMarker = '<';
        char endMarker = '>';

        message |= (1 << 18) | resolution | ((frequency & 0x02FF) << 4);
        s.push_back(startMarker);
        s += std::to_string(message);
        s.push_back(endMarker);
        
        startBytes = my_serial.write(s);

        std::cout << "Frequency: " << frequency*1000 << " Hz" << std::endl;
        std::cout << "Resolution: " << resolution << std::endl;

    }

    float getCurrent(void){

        float current;
        unsigned long int message = 0;
        std::string s = "";
        size_t startBytes;
        char startMarker = '<';
        char endMarker = '>';

        char rc;
        int dim = 32;
        char arr[dim];
        bool newData = false;
        int ndx = 0;
        char endLine = '\n';

        message |= ((1 << 18) | (1 << 16));

        s += startMarker;
        s += std::to_string(message);
        s += endMarker;
        startBytes = my_serial.write(s);

        std::this_thread::sleep_for(std::chrono::milliseconds(20));
        
        while((my_serial.available() > 2) || (newData == false)){

        s = my_serial.read(1);
        arr[ndx] = s.at(0);

        if(arr[ndx] != endLine){

            ndx++;

            if(ndx >= dim){

                ndx = dim - 1;
            }
        }
        else{

            arr[ndx] = '\0';
            ndx = 0;
            newData = true;

        }
        }
        
        current = atof(arr);
        newData = false;

        return current;
    }

    void InitMotor(std::string port, int baudrate, serial::Timeout timeout){

        my_serial.setPort(port);
        my_serial.setBaudrate(baudrate);
        my_serial.setTimeout(timeout);
        my_serial.open();

        std::this_thread::sleep_for(std::chrono::milliseconds(200));

    }

}

