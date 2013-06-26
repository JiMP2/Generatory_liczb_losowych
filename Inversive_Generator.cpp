#include "aghInclude.h"    
     InversiveGenerator::InversiveGenerator(unsigned int _MIN, unsigned int _MAX, unsigned int _SEED, unsigned int _a, unsigned int _b):Generator(_MIN, _MAX, _SEED){
               this->setMax(_MAX);
               this->setA(_a);
               this->setB(_b);          
     }
     
     InversiveGenerator::~InversiveGenerator(){}
     
     void InversiveGenerator::setA(unsigned int _a){
          if(_a < 1 || _a > this->getMax()){
               _a = 1;
          }
          a = _a;
     }
     
     void InversiveGenerator::setB(unsigned int _b){
          if(_b < 1 || _b > this->getMax()){
               _b = 1;
          }
          b = _b;
     }
     
     void InversiveGenerator::setMax(unsigned int _MAX){
          if(!isPrime(_MAX)){
               _MAX++;
               while(!isPrime(_MAX)){
                    _MAX++;
               }
          }
          this->setBaseMax(_MAX);
          
          if(this->getA() > _MAX){
               this->setA(1);
          }
          if(this->getB() > _MAX){
               this->setB(1);
          }
     }
     
     unsigned int InversiveGenerator::getA(){
          return a;
     }
     
     unsigned int InversiveGenerator::getB(){
          return b;
     }  
     
     int InversiveGenerator::modInverse(int value, int mod){
         value %= mod;
         int x=1;
         while( x < mod && ((value*x)%mod)!=1 ){
              x++;
         }
         return x;
     }
     
     bool InversiveGenerator::isPrime(int x){	
	     bool prime=true;	
	     for(int i=2;i<x;i++){
		     if(x%i==0){
		     	prime=false;
		     	break;			
		     }		
	     }			
     	return prime;
     }

     int InversiveGenerator::operator() (){
          int randomNumber;
          if(this->getSeed() == 0){
               randomNumber = this->b;
          }else{
               randomNumber = (a*modInverse(this->getSeed(), this->getMax() )+b) % getMax();
          }
          randomNumber = this->getMin() + randomNumber % (this->getMax()-this->getMin()+1);          
          this->setSeed(randomNumber);
          
          return randomNumber;
     }
