#include "aghInclude.h"
     LinearGenerator::LinearGenerator(unsigned int _MIN, unsigned int _MAX, unsigned int _SEED, unsigned int _a, unsigned int _b):Generator(_MIN, _MAX, _SEED){
          this->setA(_a);
          this->setB(_b);
     }

     LinearGenerator::~LinearGenerator(){}
     
     void LinearGenerator::setA(unsigned int _a){
          if(_a < 1 || _a > this->getMax()){
               _a = 1;
          }
          a = _a;
     }
     
     int LinearGenerator::getA(){
          return a;
     }
     
     void LinearGenerator::setB(unsigned int _b){
          if(_b < 1 || _b > this->getMax()){
               _b = 1;
          }
          b = _b;
     }
     
     int LinearGenerator::getB(){
          return b;
     }
     
     int LinearGenerator::operator() (){
          int randomNumber = ((a * (this->getSeed())+b) % this->getMax());
          randomNumber = this->getMin() + randomNumber % (this->getMax()-this->getMin()+1);        
          this->setSeed(randomNumber);
          return randomNumber;
     }

