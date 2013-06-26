/**
* \file Linear_Congruential_Generator.h
* \author Filip Pasternak
* \date 15.05.2013
* \brief Definition of Linear_Congruential_Generator class.
*/
// -------------------------------------------------------------------------
#ifndef LINEAR_CONGRUENTIAL_GENERATOR_H
#define LINEAR_CONGRUENTIAL_GENERATOR_H

#include <iostream>
#include <cmath>
using namespace std;

/**
* \class LinearGenerator
* \author Filip Pasternak
* \date 15.05.2013
* \brief The definition of LinearGenerator class.
* \brief X_(n+1) = (a * X_n + b) mod MAX_V
*/
// -------------------------------------------------------------------------
class LinearGenerator : public Generator{
     private:
          unsigned int a; ///< 'a' parameter for LCG [1, MAX_V-1]
          unsigned int b; ///< 'b' parameter for LCG [1, MAX_V-1]
     public:       
          //\brief The class constructor.
          //
          //\param minimum - Lower limit to set.
          //\param maximum - Upper limit to set.          
          //\param _seed - Seed value to set.    
          //\param _a - 'a' parameter value to set.      
          //\param _b - 'b' parameter value to set.
          LinearGenerator(unsigned int _MIN = 0, unsigned int _MAX = 16, unsigned int _SEED = 0, unsigned int _a = 5, unsigned int _b = 1);
          
          //\brief The class destructor.
          ~LinearGenerator();
          
          //\brief Setter of 'a' parameter value.
          //
          //\param _a - 'a' parameter value to set.
          void setA(unsigned int _a);
          
          //\brief Getter of 'a' parameter value.
          //
          //\return 'a' parameter value
          int getA();
          
          //\brief Setter of 'b' parameter value.
          //
          //\param _b - 'b' parameter value to set.
          void setB(unsigned int _b);
          
          //\brief Getter of 'b' parameter value.
          //
          //\return 'b' parameter value
          int getB();
          
          //\brief Virtual function to draw a random number.
          //
          //\return random number
          //virtual int operator() (ofstream * output = NULL);
          virtual int operator() ();
          
          
};
#endif
