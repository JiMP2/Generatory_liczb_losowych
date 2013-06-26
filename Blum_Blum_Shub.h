/**
* \file Blum_Blum_Shub.h
* \author Filip Pasternak
* \date 17.05.2013
* \brief Definition of BBS class.
*/
// -------------------------------------------------------------------------
#ifndef BLUM_BLUM_SHUB_H
#define BLUM_BLUM_SHUB_H

#include <iostream>
#include "Random_Number_Generator.h"

class BBS : public Generator{
     private:
          unsigned int p; ///< Stores 'p' parameter value (should be a prime number).
          unsigned int q; ///< Stores 'q' parameter value (should be a prime number).
     public:
          //|brief The class constructor.
          //
          //\param _p - Value of 'p' parameter to set.
          //\param _q - Value of 'q' parameter to set.
          //\param _MIN - The lower limit to set.
          //\param _SEED - The seed value to set (its squareroot value should be coprime with MAX_V).
          BBS(unsigned int _p = 11, unsigned int _q = 11, unsigned int _MIN = 0, unsigned int _SEED = 5);
          
          //\brief The class destructor.
          ~BBS();
          
          virtual void setSeed(int _SEED);
          
          //brief Setter of the 'p' parameter.
          //
          //\param _p - 'p' parameter value to set.
          void setP(unsigned int _p);

          //brief Setter of the 'q' parameter.
          //
          //\param _q - 'q' parameter value to set.          
          void setQ(unsigned int _q);
          
          //brief Getter of the 'p' parameter.
          //
          //\return 'p' parameter value.
          unsigned int getP();

          //brief Getter of the 'q' parameter.
          //
          //\return 'q' parameter value.          
          unsigned int getQ();
          
          //\brief Function to check if the number is prime
          //
          //\param x - number to check
          //\return TRUE if x is a prime number
          bool isPrime(int x);
          
          //\brief Function to find correct seed using current parameters.
          void findStart();
          
          //\brief Greates common divisor
          //
          //\param a - first figure
          //\param b - second figure
          /*friend*/ int gcd(int a, int b);
          
          //virtual int operator() (ofstream * output = NULL);
          virtual int operator() ();
};
#endif
