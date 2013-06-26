#include "aghInclude.h"

int main (void){
    ofstream plik("wyniki.txt", ios_base::out);
    //InversiveGenerator (_MIN, _MAX, _SEED, _a, _b)
    //LinearGenerator (_MIN, _MAX, _SEED, _a, _b)
    //BBS (_p, _q, _MIN, _SEED)
    
    InversiveGenerator inwersyjny(0, 17, 0, 5, 1);
    LinearGenerator liniowy(0, 16, 0, 5, 1);
    BBS blum (11,11,0,5);
    
    
    cout << "\tICG\tLCG\tBBS" << endl;
    cout << "Min\t" << inwersyjny.getMin() << "\t" << liniowy.getMin() << "\t" << blum.getMin() << endl;
    cout << "Max\t" << inwersyjny.getMax() << "\t" << liniowy.getMax() << "\t" << blum.getMax() << endl;
    cout << "Seed\t" << inwersyjny.getSeed() << "\t" << liniowy.getSeed() << "\t" << blum.getSeed() << endl;
    cout << "I\t" << inwersyjny.getA() << "\t" << liniowy.getA() << "\t" << blum.getP() << endl;
    cout << "II\t" << inwersyjny.getB() << "\t" << liniowy.getB() << "\t" << blum.getQ() << endl;
    cout << endl << "Wylosowane liczby:" << endl;

    
    cout << "Generator liniowy:\t";
    for (int i = 0; i < 10; i++)
        liniowy.print();
    cout << endl;
    
    cout << "Generator inwersyjny:\t";
    for (int i = 0; i < 10; i++)
        inwersyjny.print();
    cout << endl;
    
    cout << "Generator Blum Blum Shub:\t";
    for (int i = 0; i < 10; i++)
        blum.print();
    cout << endl;

    cout << "Testy:" << endl;
 
    liniowy.setSeed(0);
    inwersyjny.setSeed(0);
    blum.setSeed(5);
    

    Test * array [] = {
        new statTest(&inwersyjny), new statTest(&liniowy), new statTest(&blum),
        new autoTest(&inwersyjny), new autoTest(&liniowy), new autoTest(&blum),
        new runsTest(&inwersyjny), new runsTest(&liniowy), new runsTest(&blum)};
    
    for (int i = 0; i < 9; i++)
    {
        array[i]->runTest();
        array[i]->displayResult(plik);
    }

    plik.close();
    return 0;
}
