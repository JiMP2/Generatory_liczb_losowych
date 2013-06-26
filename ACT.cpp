#include "ACT.h"

autoTest::autoTest(Generator * _generator, int _sampleCount, int _lag): Test(_generator, _sampleCount), lag(_lag), autoCorrel(0.0)
{
    if (lag > sampleCount)
        lag = 1;
}

autoTest::~autoTest()
{
}

double autoTest::countMean()
{
    double mean = 0.0;
    
    for (int i = 0; i < sampleCount; i++)
        mean += samples[i];
    
    mean /= sampleCount;
    
    return mean;
}

double autoTest::countAutocorr()
{
    double mean = countMean();
    double sum1 = 0.0, sum2 = 0.0;
    
    for (int i = lag; i < sampleCount; i++)
    {
        sum1 += ((samples[i] - mean) * samples[i - lag]);
        sum2 += pow((samples[i] - mean), 2);
    }
    
    autoCorrel = sum1 / sum2;
    return autoCorrel;
}

void autoTest::displayResult(ostream & output)
{
    output << "Autocorrelation test!" << endl << "Sample: " << endl;
    
    for (int i = 0; i < sampleCount; i++)
    {
        output << samples[i] << "\t";
        
        if ((i % 10 == 0) && (i > 0))
        {
            output << endl;
        }
    }
    
    output << endl << "Autocorrelation:\t" << autoCorrel << endl << "Lag:\t" << lag << endl << endl;
}

void autoTest::runTest(ostream & output)
{
    drawSamples();
    countAutocorr();
    displayResult(output);
}