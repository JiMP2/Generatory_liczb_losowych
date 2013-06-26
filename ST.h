/**
 * \file ST.h
 * \author Wojciech Kryscinski
 * \date 18.05.2013
 * \brief Definition of class runsTest. Class derived from abstract class "Test".
 */
// -------------------------------------------------------------------------

#ifndef __Liczby_Losowe__ST__
#define __Liczby_Losowe__ST__

#include <iostream>
#include <stdlib.h>
#include "RT.h"

class runsTest : public Test {
    int setA; // number of elements above median
    int setB; // number of elements below median
    int runs; // number of runs in dataset
    int median; // median of dataset
    
public:
    // \brief Class constructor.
    // \param _generator - Generator that will be tested.
    // \param _sampleCount - Size of sample dataset.
    runsTest(Generator * _generator, int _sampleCount = 10);
    
    // \brief Class destructor.
    ~runsTest();
    
    // \brief Method finds median of dataset.
    // \return Method returns median of dataset.
    int findMedian();
    
    // \brief Method counts runs in dataset.
    void countRuns();
    
    // \brief Method displays results of tests.
    // \param output - Sets output for displaying results. COUT by default.
    void displayResult(ostream & output = cout);
    
    // \brief Method method runs Wal-Wolfowitz runs test.
    // \param output - Sets output for displaying results. COUT by default.
    void runTest(ostream & output = cout);
};

#endif /* defined(__Liczby_Losowe__ST__) */
