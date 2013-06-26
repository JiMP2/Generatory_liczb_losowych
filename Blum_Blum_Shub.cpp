#include "aghInclude.h"

     BBS::BBS(unsigned int _p, unsigned int _q, unsigned int _MIN, unsigned int _SEED):Generator(_MIN,_MIN+_SEED,_SEED){
          if(!isPrime(_p)){
               _p = 11;
          }
          if(!isPrime(_q)){
               _q = 11;
          }
          p = _p;
          q = _q;
          this->setBaseMax(_p*_q);
          if(gcd(_SEED, this->getMax())!=1 || _SEED*_SEED > this->getMax()){
               this->findStart();
          }else{
               this->setBaseSeed(_SEED*_SEED);
          }
     }

     BBS::~BBS(){}
     
     void BBS::setSeed(int _SEED){
          if( gcd(_SEED, this->getMax()) != 1 ){
               throw aghException(6, "SEED value and MAX_V value should be coprime integers using Blum Blum Shub algorythm.", __FILE__, __LINE__);
          }else{
               this->setBaseSeed(_SEED);
          }
     }
     
     void BBS::setP(unsigned int _p){
          if(!isPrime(_p)){
               throw aghException(5, "Values of 'p' and 'q' parameter should be prime numbers.", __FILE__, __LINE__);
          }else{
               p = _p;
               this->setBaseMax(this->p*this->q);
               this->findStart();
          }
     }
     
     void BBS::setQ(unsigned int _q){
          if(!isPrime(_q)){
               throw aghException(5, "Values of 'p' and 'q' parameter should be prime numbers.", __FILE__, __LINE__);
          }else{
               q = _q;
               this->setBaseMax(this->p*this->q);
               this->findStart();
          }
     }
     
     unsigned int BBS::getP(){
          return this->p;
     }
     
     unsigned int BBS::getQ(){
          return this->q;
     }
     
     void BBS::findStart(){
          int start = -1;
          int s = this->getMin();
          int max = this->getMax();
          while(s*s<=max){
               if(gcd(s*s, max) == 1 && s!=1){
                    start = s*s;
                    break;
               }else{
                    s++;
               }
          }
          if(start!=-1){
               this->setBaseSeed(start);
          }else{
               cout << endl << "Incorrect parameters for Blum Blum Shub algorythm." << endl;
          }
     }
     
     int BBS::gcd(int a, int b){
          int c;
          while (b != 0){
               c = a%b;
               a = b;
               b = c;
          }
          return a;
     }
     
     bool BBS::isPrime(int x){	
          bool prime=true;	
	     for(int i=2;i<x;i++){
	    	     if(x%i==0){
	    	     	prime=false;
	    	     	break;			
	   	     }		
	     }			
        	return prime;
     }

     int BBS::operator() (){
          int randomNumber;
          randomNumber = (this->getSeed()*this->getSeed()) % this->getMax();
          randomNumber = this->getMin() + randomNumber % (this->getMax()-this->getMin()+1);               
          this->setBaseSeed(randomNumber);
          
          return randomNumber;
     }
