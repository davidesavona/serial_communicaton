#include "serial.h"
#include <iostream>
#include <bitset>
#include <string>
#include "thread"
#include "motor.h"


int main()
{
    //serial::Serial my_serial("/dev/cu.usbserial-0001", 115200, serial::Timeout::simpleTimeout(3000));

    // // // // if (my_serial.isOpen())
    // // // // {
    // // // //     std::cout << "Port opened succesfully" << std::endl;
    // // // // }
    // // // // else
    // // // // {
    // // // //     std::cout << "Port failed to open" << std::endl;
    // // // // }
    // // // // my_serial.flushOutput();

    // // // //  std::string test_string = "hi\n";
    // // // //  for (int i = 0; i < 3; i++)
    // // // //  {
    // // // //      size_t bytesWritten = my_serial.write(test_string);

    // // // //      std::string result = my_serial.read(test_string.length() + 1);
    // // // //      std::cout << "Bytes sent: " << bytesWritten << std::endl;
    // // // //      std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    // // // //  }


    // // // // //std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    // // // // //my_serial.flushInput();
    // // // // // std::string response = my_serial.read(6);
    // // // // // std::cout << "Arduino: " << response << std::endl;

    // // // // int stato;
    // // // // unsigned long int dato = 0;
    // // // // int freq;
    // // // // int res;
    // // // // float input;
    // // // // int duty_cycle;
    // // // // while(1){

    // // // //     std::cout<< "selezionare impostazioni:"<<std::endl<<"MOTORE ON  ----> 0"<<std::endl<<"MOTORE OFF ----> 1"<<std::endl<<"VELOCITA   ----> 2"<<std::endl<<"PAUSA      ----> 3"<<std::endl;
    // // // //     std::cin>>stato;
    // // // //     dato |= (stato<<16);
    // // // //     if(stato==2) {
    // // // //         std::cout<<"selezionare una frequenza in kHz [MAX 63]:"<<std::endl;
    // // // //         std::cin>>freq;
    // // // //         dato |= (freq<<18);
    // // // //         std::cout<<"selezionare una risoluzione [MAX 255]:"<<std::endl;
    // // // //         std::cin>>res;
    // // // //         dato |= (res<<24);
    // // // //         std::cout<<"selezionare duty cycle [~ 0.01]:"<<std::endl;
    // // // //         std::cin>>input;
    // // // //         duty_cycle = input*100*65535/10000;
    // // // //         dato |= duty_cycle;
    // // // //         }
    // // // //     std::cout<< std::bitset<32>(dato)<< std::endl<<dato<<std::endl;
    // // // //     std::string s = std::to_string(dato);
    // // // //     std::cout<<"il dato ora è una stringa: "<<s<<std::endl;
    // // // //     dato = 0;
    // // // // }
    // // // // return 0;

    // int state = 0;
    // unsigned long int message;
    // int dutyCycle = 0;
    // std::string s; 
    // size_t startBytes;

    // while(1){

    //     std::cout << "Select state: " << std::endl;
    //     std::cin >> state;

    //     switch(state){

    //         case 0: 

    //         break;

    //         case 1: 

    //         message = 65536;
    //         s = std::to_string(message);
    //         startBytes = my_serial.write(s);
    //         state = 0;
    //         break;

    //         case 2:

    //         std::cout << "Insert duty cycle: " << std::endl;
    //         std::cin >> dutyCycle;

    //         message = 131072 + dutyCycle;
    //         s = std::to_string(message);
    //         startBytes = my_serial.write(s);
    //         state = 0; 
    //         break;

    //         case 3:

    //         message = 196608;
    //         s = std::to_string(message);
    //         startBytes = my_serial.write(s);
    //         state = 0;
    //         break;
    //     }

    //  }

    // int dc = 0;
    // float current;

    // motor::InitMotor("/dev/cu.usbserial-0001", 115200, serial::Timeout::simpleTimeout(3000));

    // for(int i = 0; i < 3; i++){

    // std::cout << "Inserire duty cycle: " << std::endl;
    // std::cin >> dc;

    // motor::startMotor();
    // motor::setDutyCycle(dc, 1);

    // }

    // motor::stopMotor();

    // for(int i = 0; i < 3; i++){

    // std::cout << "Duty cycle: " << std::endl;
    // std::cin >> dc;

    // motor::setDutyCycle(dc, 0);

    // }

    // motor::stopMotor();

    // for(int i = 0; i < 3; i++){

    //     std::cin >> dc;
    //     motor::startMotor();
    //     std::cout << "Current level: " << current << " mA" << std::endl;

    // }

    // std::string testString = "Test\n";
    // size_t bytes;
    // float result;

    // my_serial.flushInput();
    // std::string response = my_serial.read(6);
    // //result = std::stof(response);
    // std::cout << "Arduino: " << response << std::endl;
    // my_serial.flushInput();

    // //std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    // my_serial.flushInput();
    // response = my_serial.read(9);
    // //result = std::stof(response);
    // std::cout << "Arduino: " << response << std::endl;

   

    // // serial::Serial my_serial("/dev/cu.usbserial-0001", 115200, serial::Timeout::simpleTimeout(3000));
    // // motor::startMotor(&my_serial);
    // int variable_1;
    // int variable_1;
    // int variable_2;
    // int variable_3;
    // float value;

    // motor::InitMotor("/dev/cu.usbserial-0001", 115200, serial::Timeout::simpleTimeout(3000));

    // for(int i = 0; i < 10; i++){
        
    //     motor::startMotor();

    // }

    //  motor::startMotor();
    // // motor::setDutyCycle(50, 0);
    // // motor::setDutyCycle(150, 0);
    // // motor::setDutyCycle(-10, 0);
    // // motor::setDutyCycle('a', 0);



    // std::cout << "Inserire dc: " << std::endl;
    // std::cin >> variable_1;

    // motor::setDutyCycle(variable_1, 0);

    // int value;
    // // float current;

    // motor::InitMotor("/dev/cu.usbserial-0001", 115200, serial::Timeout::simpleTimeout(3000));
    

    // for(int i = 0; i < 5; i++){

    //     std::cout << "Inserire duty cycle: " << std::endl;
    //     std::cin >> dc;
    //     motor::setDutyCycle(dc, 0);
    //     current = motor::getCurrent();
    //     std::cout << current << " A" << std::endl;

    // }

    std::string  current;
    int dc;

    motor::InitMotor("/dev/ttyUSB0", 115200, serial::Timeout::simpleTimeout(3000));
    motor::startMotor();
    while(1){
    current = motor::getCurrent();
    std::cout<<current<<"-->"<<std::endl;
    if(current.empty()) std::cout<<"error"<<std::endl;
    std::cout << std::stof(current) << " A" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
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

   
    motor::stopMotor();

    return 0;

}

