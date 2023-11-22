#include "serial.h"
#include <iostream>
#include "thread"

namespace motor{

    serial::Serial my_serial;
    

    void startMotor(void){
    
        unsigned long int message = 0;
        std::string s;
        size_t startBytes;

        std::string check = "Ok";

        my_serial.flushOutput();

        message |= (1 << 16);
        s = std::to_string(message)+"\n";
        startBytes = my_serial.write(s);
        
        std::this_thread::sleep_for(std::chrono::milliseconds(40));
        my_serial.flushInput();
        s = my_serial.read(2);

        if(!s.compare(check)){

        std::cout << s << std::endl;
        std::cout << "Motor on" << std::endl;

        }

        else{

            std::cout << "ERROR: message corrupted" << std::endl;

        }

    }

    void stopMotor(void){

        unsigned long int message = 0;
        std::string s;
        size_t startBytes;
        std::string check = "Ok";

        my_serial.flushOutput();

        message |= ((1 << 17) | (1 << 16));
        s = std::to_string(message)+"\n";
        startBytes = my_serial.write(s);

        std::this_thread::sleep_for(std::chrono::milliseconds(40));
        my_serial.flushInput();
        s = my_serial.read(2);
        
        if(!s.compare(check)){
        
        std::cout << s << std::endl;
        std::cout << "Motor off" << std::endl;

        }
        else{

            std::cout << "ERROR: message corrupted" << std::endl;
        }
    //my_serial.close();
    }

    void setDutyCycle(int dutyCycle, int option){

        unsigned long int message = 0;
        std::string s;
        size_t startBytes;
        std::string check = "Ok";

        my_serial.flushOutput();

        if(dutyCycle <= 100 && dutyCycle >= 0){

        if(option){

            message |= ((1 << 17) | (1 << 24));
            message += dutyCycle;
            s = std::to_string(message);
            startBytes = my_serial.write(s);

            //std::cout << "Duty cycle: " << dutyCycle << std::endl;
        }

        else if(!(option)){

            message |= (1 << 17);
            message += dutyCycle;
            s = std::to_string(message);
            startBytes = my_serial.write(s);

            std::cout << "Duty cycle: " << dutyCycle << std::endl;
        }
        else{

            //std::cout << "ERROR: requested task is not applicable" << std::endl;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(40));
        my_serial.flushInput();
        s = my_serial.read(2);

        if(!(s.compare(check))){

        //std::cout << s << std::endl;
        //std::cout << "Duty cycle set" << std::endl;

        }
        else{

            //std::cout << "ERROR: message corrupted" << std::endl;
        }

        

        }
        else{

            //std::cout << "ERROR: duty cycle is not applicable" << std::endl;
    
        }

    }

    void configPWM(int frequency, int resolution){

        unsigned long int message = 0;
        std::string s;
        size_t startBytes;
        std::string check = "Ok";

        my_serial.flushOutput();

        message |= (1 << 18) | resolution | ((frequency & 0x02FF) << 4);
        s = std::to_string(message);
        startBytes = my_serial.write(s);

        std::this_thread::sleep_for(std::chrono::milliseconds(40));
        my_serial.flushInput();
        s = my_serial.read(2);

        if(!(s.compare(check))){

        std::cout << s << std::endl;
        std::cout << "Frequency: " << frequency*1000 << " Hz" << std::endl;
        std::cout << "Resolution: " << resolution << std::endl;

        }
        else{

            std::cout << "ERROR: message corrupted" << std::endl;
        }
    }

    int getCurrent(void){

        int current;
        unsigned long int message = 0;
        std::string s;
        size_t startBytes;
        
        my_serial.flushOutput();

        message |= ((1 << 18) | (1 << 16)) ;
        s = std::to_string(message);
        startBytes = my_serial.write(s);

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        my_serial.flushInput();
        s = my_serial.read(4);
        current = std::stof(s);

        return current;
    }

    void InitMotor(std::string port, int baudrate, serial::Timeout timeout){

        my_serial.setPort(port);
        my_serial.setBaudrate(baudrate);
        my_serial.setTimeout(timeout);
        my_serial.open();

    }

}

