/**
 * \file SS.h
 * \author Wojciech Kryscinski
 * \date 18.05.2013
 * \brief Definition of class statTest. Class derived from abstract class "Test".
 */
// -------------------------------------------------------------------------

#ifndef __Liczby_Losowe__SS__
#define __Liczby_Losowe__SS__

#include "RT.h"

#include <iostream>
#include <cmath>


class statTest : public Test {
    double mean; // mean of dataset
    double variance; // variance of dataset
    double stdDeviation; // standard deviation of dataset
    double coefVariation; // coefficient of variation of dataset
    
public:
    // \brief Class constructor.
    // \param _generator - Generator that will be tested.
    // \param _sampleCount - Size of sample dataset.
    statTest(Generator * _generator, int _sampleCount = 10);
    
    // \brief Class destructor.
    ~statTest();
    
    // \brief Method counts  mean of test dataset.
    double countMean();
    
    // \brief Method counts  variance of test dataset.
    double countVariance();
    
    // \brief Method counts  standard deviation of test dataset.
    double countDeviation();
    
    // \brief Method counts  coefficient of variation of test dataset.
    double countVariation();
    
    // \brief Method displays results of tests.
    // \param output - Sets output for displaying results. COUT by default
    virtual void displayResult(ostream & output = cout);
    
    // \brief Method method runs Wal-Wolfowitz runs test.
    // \param output - Sets output for displaying results. COUT by default.
    virtual void runTest(ostream & output = cout);
};

#endif /* defined(__Liczby_Losowe__SS__) */
