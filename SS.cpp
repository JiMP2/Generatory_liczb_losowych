#include "SS.h"


statTest::statTest(Generator * _generator, int _sampleCount):Test(_generator, _sampleCount), mean(0.0), variance(0.0), stdDeviation(0.0), coefVariation(0.0)
{
}

statTest::~statTest()
{
}

double statTest::countMean()
{
    mean = 0.0;
    
    for (int i = 0; i < sampleCount; i++)
        mean += samples[i];
    
    mean /= sampleCount;
    
    return mean;
}

double statTest::countVariance()
{
    variance = 0.0;
    countMean();
    
    for (int i = 0; i < sampleCount; i++)
        variance += pow((samples[i] - mean), 2);
    
    variance /= (sampleCount - 1);
    
    return variance;
}

double statTest::countDeviation()
{
    countVariance();
    
    stdDeviation = sqrt(variance);
    
    return stdDeviation;
}

double statTest::countVariation()
{
    countDeviation();
    
    coefVariation = stdDeviation / mean;
    
    return coefVariation;
}

void statTest::displayResult(ostream & output)
{
    output << "Basic statistic measure test!" << endl << "Sample: " << endl;
    
    for (int i = 0; i < sampleCount; i++)
    {
        output << samples[i] << "\t";
        
        if ((i % 10 == 0) && (i > 0))
        {
            output << endl;
        }
    }
    
    output << endl << "Mean: \t" << mean << endl << "Variance: \t" << variance << endl << "Standard deviation:\t" << stdDeviation << endl << "Coefficient of variation: \t" << coefVariation << endl << endl;
}

void statTest::runTest(ostream & output)
{
    drawSamples();
    countVariation();
    displayResult(output);
}