#include "aghInclude.h"

int main (void){
     ofstream plik1("TEST.txt", ios_base::out);
     ofstream plik2("file_ICG.txt", ios_base::out);
     ofstream plik3("file_BBS.txt", ios_base::out);
     
     InversiveGenerator inwersyjny(0, 17, 0, 5, 1);
     linearGenerator liniowy(0, 16, 0, 5, 1);
     BBS blum (0, 25, 11, 11);
     cout << "    ICG  |  LCG  |  BBS  " << endl;
     cout << "Min  " << inwersyjny.getMin() << "     " << liniowy.getMin() << "     " << blum.getMin() << endl;
     cout << "Max  " << inwersyjny.getMax() << "     " << liniowy.getMax() << "     " << blum.getMax() << endl;
     cout << "Seed " << inwersyjny.getSeed() << "     " << liniowy.getSeed() << "     " << blum.getSeed() << endl;
     cout << "I    " << inwersyjny.getA() << "     " << liniowy.getA() << "     " << blum.getP() << endl;
     cout << "II   " << inwersyjny.getB() << "     " << liniowy.getB() << "     " << blum.getQ() << endl;
     cout << endl << "Wylosowane liczby" << endl;
     
     for(int i=0;i<20;i++){
         //inwersyjny();
         liniowy.print();
         //blum();
     }
     plik1.close();
     plik2.close();
     plik3.close();
     return 0;
}
