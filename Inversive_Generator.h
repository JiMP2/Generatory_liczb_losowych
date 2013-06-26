/**
* \file Inversive_Generator.h
* \author Filip Pasternak
* \date 16.05.2013
* \brief Definition of InversiveGenerator class.
*/
// -------------------------------------------------------------------------

#include "Random_Number_Generator.h"
#include <iostream>
#include "aghException.h"
using namespace std;
/**
* \class Random_Number_Generator.h
* \author Filip Pasternak
* \date 16.05.2013
* \brief Definition of InversiveGenerator class.
*/
class InversiveGenerator : public Generator{
     private:
          unsigned int a; ///< Stores the 'a' parameter value
          unsigned int b; ///< Stores the 'b' parameter value
     public:
     //\brief The class constructor.
     //
     //\param _MIN - The lower limit to set.
     //\param _MAX - The upper limit to set.             
     //\param _SEED - The seed value to set.
     //\param _a - The 'a' parameter value to set.
     //\param _b - The 'b' parameter value to set.            
     InversiveGenerator(unsigned int _MIN = 0, unsigned int _MAX = 17, unsigned int _SEED = 0, unsigned int _a = 5, unsigned int _b = 1);
     
     //\brief The class destructor.
     ~InversiveGenerator();
     
     /*friend */int modInverse(int value, int mod);
     /*friend */bool isPrime(int x);
     
     //\brief Setter of the 'a' parameter.
     //
     //\param _a - The 'a' parameter value to set.
     void setA(unsigned int _a);

     //\brief Setter of the 'b' parameter.
     //
     //\param _b - The 'b' parameter value to set.
     void setB(unsigned int _b);

     //\brief Setter of the 'm' parameter.
     //
     //\param _MAX - The 'm' parameter value to set.
     virtual void setMax(unsigned int _MAX);    
     
     //\brief Getter of the 'a' parameter value.
     //
     //\return the 'a' parameter value
     unsigned int getA();

     //\brief Getter of the 'b' parameter value.
     //
     //\return the 'b' parameter value
     unsigned int getB();
      
     //\brief Virtual function to draw a random number using ICG algorythm.
     //virtual int operator() (ofstream * output = NULL);
     virtual int operator() ();
};
