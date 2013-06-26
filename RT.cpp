#include "RT.h"
using namespace std;

Test::Test(Generator * _generator, int _sampleCount):sampleCount(_sampleCount), generator(_generator)
{
    samples = new int[_sampleCount];
}

Test::~Test()
{
    delete [] samples;
}

void Test::drawSamples()
{
    for (int i = 0; i < sampleCount; i++)
    {
        samples[i] = (*generator)();
    }
}

void Test::displaySamples(ostream & output)
{

    for (int i = 0; i < sampleCount; i++)
    {
        output << samples[i];
    }
}

void Test::setGenerator(int _minimum, int _maximum, int _seed)
{
    generator->setMin(_minimum);
    generator->setMax(_maximum);
    generator->setSeed(_seed);
}
