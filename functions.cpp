     int modInverse(int value, int mod){
         value %= mod;
         for(int x = 1; x < mod; x++) {
             if((value*x) % mod == 1) return x;
         }
     }
     
     bool isPrime(int x){	
	     bool prime=true;	
	     for(int i=2;i<x;i++){
	     	if(x%i==0){
	     		prime=false;
	     		break;			
	     	}		
	     }			
	     return prime;
     }
