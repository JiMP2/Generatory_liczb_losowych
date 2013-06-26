/**
 * \file ACT.h
 * \author Wojciech Kryscinski
 * \date 18.05.2013
 * \brief Definition of class autoTest. Class derived from abstract class "Test".
 */
// -------------------------------------------------------------------------

#ifndef __Liczby_Losowe__ACT__
#define __Liczby_Losowe__ACT__

#include "RT.h"
#include <iostream>
#include <cmath>



class autoTest : public Test {
    int lag; // lag of autocorrelation
    double autoCorrel; // autocorrelation of test dataset
    
public:
    // \brief Class constructor.
    // \param _generator - Generator that will be tested.
    // \param _sampleCount - Size of sample dataset.
    autoTest(Generator * _generator, int _sampleCount = 10, int _lag = 1);
    
    // \brief Class destructor.
    ~autoTest();
    
    // \brief Method counts  mean of test dataset.
    // \return Method returns mean of test dataset.
    double countMean();
    
    // \brief Method counts  autocorrelation of test dataset.
    // \return Method returns autocorrelation of test dataset.
    double countAutocorr();
    
    // \brief Method displays results of tests.
    // \param output - Sets output for displaying results. COUT by default
    void displayResult(ostream & output = cout);
    
    // \brief Method method runs autocorrelation test.
    // \param output - Sets output for displaying results. COUT by default.
    void runTest(ostream & output = cout);
};

#endif /* defined(__Liczby_Losowe__ACT__) */
