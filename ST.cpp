#include "ST.h"

int compareElements(const void * _a, const void * _b)
{
    if (*(int *)_a > *(int *)_b)
        return 1;
    else if (*(int *)_a < *(int *)_b)
        return -1;
    else
        return 0;
}

runsTest::runsTest(Generator * _generator, int _sampleCount):Test(_generator, _sampleCount), setA(0), setB(0), runs(0), median(-1)
{
}

runsTest::~runsTest()
{
}

int runsTest::findMedian()
{
    int tempArray[sampleCount];
    
    for (int i = 0; i < sampleCount; i++)
        tempArray[i] = samples[i];
    
    qsort(tempArray, sampleCount, sizeof(int), compareElements);
    
    median = tempArray[(sampleCount + 1) / 2];
    return median;
}


void runsTest::countRuns()
{
    bool overMedian = false;
    setA = setB = runs = 0;
    
    for (int i = 0; i < sampleCount; i++)
    {
        if ((samples[i] > median) && overMedian)
        {
            setA++;
        }
        else if ((samples[i] < median) && !overMedian)
        {
            setB++;
        }
        else if ((samples[i] > median) && !overMedian)
        {
            setA++;
            runs++;
            overMedian = true;
        }
        else if ((samples[i] < median) && overMedian)
        {
            setB++;
            runs++;
            overMedian = false;
        }
    }
}

void runsTest::displayResult(ostream & output)
{
    output << "Runs test!" << endl << "Sample: " << endl;
    
    for (int i = 0; i < sampleCount; i++)
    {
        output << samples[i] << "\t";
        
        if ((i % 10 == 0) && (i > 0))
        {
            output << endl;
        }
    }
    
    output << endl << "Median:\t" << median << endl << "Set A:\t" << setA << endl << "Set B:\t" << setB << endl << "Runs:\t" << runs << endl << "Check critical value table for k1, k2." << endl << "If k1 < " << runs << " or " << runs << " > k2 - sequence is random." << endl << endl;
}

void runsTest::runTest(ostream & output)
{
    drawSamples();
    findMedian();
    countRuns();
    displayResult(output);
}
