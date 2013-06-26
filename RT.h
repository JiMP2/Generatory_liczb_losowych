/**
 * \file RT.h
 * \author Wojciech Kryscinski
 * \date 18.05.2013
 * \brief Definition of abstract class "Test". "Test" is the base class for all tests.
 */
// -------------------------------------------------------------------------

#ifndef __Testy_generatorow__Randomness_Test__
#define __Testy_generatorow__Randomness_Test__

#include <iostream>
#include "Random_Number_Generator.h"

class Test {
protected:
    const int sampleCount; // size of test dataset
    Generator * generator; // pointer to generator that will be tested
    int * samples; // array with test dataset
    
public:
    // \brief Class constructor.
    // \param _generator - Generator that will be tested.
    // \param _sampleCount - Size of test dataset.
    Test(Generator * _generator, int _sampleCount = 10);
    
    // \brief Class destructor.
    virtual ~Test();
    
    // \brief Method that draws random test dataset.
    void drawSamples();
    
    // \brief Method displays test dataset.
    // \param output - Sets output for displaying results. COUT by default.
    void displaySamples(ostream & output  = cout);
    
    // \brief Method changes generator parameters.
    // \param _minimum - Lower end of number range.
    // \param _maximum - Upper end of number range.
    // \param _seed - Seed
    void setGenerator(int _minimum, int _maximum, int _seed);
    
    // \brief Abstract method - displays results of tests.
    // \param output - Sets output for displaying results. COUT by default.
    virtual void displayResult(ostream & output = cout) = 0;
    
    // \brief Abstract method - runs test.
    // \param output - Sets output for displaying results. COUT by default.
    virtual void runTest(ostream & output = cout) = 0;
};
#endif /* defined(__Testy_generatorow__Randomness_Test__) */
