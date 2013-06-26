/**
* \file Random_Number_Generator.h
* \author Filip Pasternak
* \date 15.05.2013
* \brief Definition of abstract class as a base of random number generator.
*/
// -------------------------------------------------------------------------

#ifndef RANDOM_NUMBER_GENERATOR_H
#define RANDOM_NUMBER_GENERATOR_H

// -------------------------------------------------------------------------
#include <iostream>
#include "aghException.h"
// -------------------------------------------------------------------------
/**
* \class Generator
* \author Filip Pasternak
* \date 15.05.2013
* \brief Definition of abstract class as a base of random number generator.
*/
class Generator{
     private:
          unsigned int MIN_V;   ///< Stores the lower limit of drawing.
          unsigned int MAX_V;   ///< Stores the upper limit of drawing.
          unsigned int SEED;    ///< Stores the seed value.

// -------------------------------------------------------------------------
       
     public:
          //\brief The default constructor.
          Generator();
          
          //\brief The class constructor.
          //
          //\param minimum - The lower limit to set.
          //\param maximum - The upper limit to set.
          Generator(unsigned int _MIN, unsigned int _MAX);
          
          //\brief The class constructor.
          //
          //\param _MIN - The lower limit to set.
          //\param _MAX - The upper limit to set.
          //\param _SEED - The seed value to set.          
          Generator(unsigned int _MIN, unsigned int _MAX, unsigned int _SEED);
          
          //\brief The class destructor
          virtual ~Generator();
//--------------------------------------------------------------------------
          //\brief Setter of the lower limit value for the base class.
          //
          //\param _MIN - The lower limit to set.
          void setBaseMin(unsigned int _MIN);
          
          //\brief Setter of the upper limit value for the base class.
          //
          //\param _MAX - The upper limit to set.          
          void setBaseMax(unsigned int _MAX);

          //\brief Setter of seed value for the base class.
          //
          //\param _SEED - The seed value to set.
          void setBaseSeed(unsigned int _SEED);
// -------------------------------------------------------------------------        

          //\brief Setter of the lower limit value.
          //
          //\param _MIN - The lower limit to set.
          virtual void setMin(unsigned int _MIN);
          
          //\brief Setter of the upper limit value.
          //
          //\param _MAX - The upper limit to set.          
          virtual void setMax(unsigned int _MAX);

          //\brief Setter of seed value.
          //
          //\param _SEED - The seed value to set.
          virtual void setSeed(unsigned int _SEED);

          //\brief Getter of the lower limit value.
          //
          //\return a value of the MIN_V field
          unsigned int getMin();

          //\brief Getter of the upper limit value.
          //
          //\return a value of the MAX_V field
          unsigned int getMax();

          //\brief Getter of the seed value.
          //
          //\return a value of the SEED field
          unsigned int getSeed();
          
// -------------------------------------------------------------------------
          //\brief Virtual function to draw a random number.
          //
          //\return random number
          //virtual int operator() (ofstream * output = NULL) = 0;
          virtual int operator() () = 0;    
          
          //\brief Function to draw and put random number to the given stream.
          //
          //\param output - output stream
          void print(ostream & output = cout);      
};
#endif
