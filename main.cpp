#include <iostream>
#include "Matrix.h"
using namespace std;

int main() {

    Matrix<float> A(4, 3);
    A.setValue(0, 0, 2.17);
    A.setValue(0, 1, 1.62);
    A.setValue(0, 2, 4.16);
    A.setValue(1, 0, 1.50);
    A.setValue(1, 1, 3.32);
    A.setValue(1, 2, 8.41);
    A.setValue(2, 0, 4.02);
    A.setValue(2, 1, 2.19);
    A.setValue(2, 2, 5.34);
    A.setValue(3, 0, 3.12);
    A.setValue(3, 1, 5.82);
    A.setValue(3, 2, 6.27);
    cout << "Matrice A:" << endl;
    A.print();

    cout << "Seleziona la  terza riga della matrice A:" << endl;
    A.selectRow(2).print();
    cout << "Seleziona la prima colonna della matrice A:" << endl;
    A.selectColumn(0).print();

    Matrix<float> B(3, 4);
    B.setValue(0, 0, 2.12);
    B.setValue(0, 1, 0.98);
    B.setValue(0, 2, 6.47);
    B.setValue(0, 3, 8.24);
    B.setValue(1, 0, 1.19);
    B.setValue(1, 1, 1.53);
    B.setValue(1, 2, 2.47);
    B.setValue(1, 3, 1.80);
    B.setValue(2, 0, 1.41);
    B.setValue(2, 1, 6.37);
    B.setValue(2, 2, 9.23);
    B.setValue(2, 3, 4.14);
    cout << "Matrice B:" << endl;
    B.print();


    Matrix<float> D = B.transpose();
    cout << "Trasposta della matrice B:" << endl;
    D.print();

    cout << "Seleziona il valore in posizione (2,1) della matrice B:" << endl;
    cout << B.getValue(1,0) << endl << endl;

    Matrix<float> C = A*B;
    cout << "Prodotto A*B:" << endl;
    C.print();

    return 0;
}
