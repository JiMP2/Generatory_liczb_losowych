#include "Random_Number_Generator.h"

     Generator::Generator(){
          MIN_V = 0;
          MAX_V = 10;
          SEED = 0;
     }
     
     Generator::Generator(unsigned int _MIN, unsigned int _MAX){
          if(_MIN > _MAX){
               int temp = _MIN;
               _MIN = _MAX;
               _MIN = temp;
          }
          MIN_V = _MIN;
          MAX_V = _MAX;
     }
     
     Generator::Generator(unsigned int _MIN, unsigned int _MAX, unsigned int _SEED){
          if(_MIN > _MAX){
               unsigned int temp = _MIN;
               _MIN = _MAX;
               _MAX = temp;
          }else if(_SEED < _MIN || _SEED > _MAX){
               _SEED = _MIN;
          }
          MIN_V = _MIN;
          MAX_V = _MAX;
          SEED = _SEED;
     }
     
     Generator::~Generator(){}
     
     void Generator::setBaseMin(unsigned int _MIN){
          if(MAX_V < _MIN){
               throw aghException(1, "The lower limit can not be higher than upper limit.", __FILE__, __LINE__);
          }else{
               MIN_V = _MIN;
          }
     }
     
     void Generator::setBaseMax(unsigned int _MAX){
          if(MIN_V > _MAX){
               throw aghException(1, "The lower limit can not be higher than upper limit.", __FILE__, __LINE__);
          }else{
               MAX_V = _MAX;
          }
     }
     
     void Generator::setBaseSeed(unsigned int _SEED){
          if(_SEED < MIN_V || _SEED > MAX_V){
               throw aghException(2, "The seed value should be between lower and upper limit.", __FILE__, __LINE__);
          }else{
               SEED = _SEED;
          }
     }
     
     void Generator::setMin(unsigned int _MIN){
          setBaseMin(_MIN);
     }
     
     void Generator::setMax(unsigned int _MAX){
          setBaseMax(_MAX);
     }
     
     void Generator::setSeed(unsigned int _SEED){
          setBaseSeed(_SEED);
     }
     
     unsigned int Generator::getMin(void){
          return MIN_V;
     }
     
     unsigned int Generator::getMax(void){
          return MAX_V;
     }
     
     unsigned int Generator::getSeed(void){
          return SEED;
     }     
     
     void Generator::print (ostream & output){
          output << this->operator()() << "\t";
     }
