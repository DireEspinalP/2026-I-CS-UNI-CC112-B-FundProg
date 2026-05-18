
#include "matrix.h"
#include "sorting.h"
#include "matrix2.h"
#include "matrix3.h"
#include "matrix4.h"
#include "types.h"
#include <cstddef>
#include <iostream>
#include <fstream>
using namespace std;

void CreateMatrix(TP *&pM, const size_t n, const size_t m) {
    pM = new TP[n*m];
}
void ReadMatrix(TP *pM, const size_t n, const size_t m ){
    cout << "Ingrese " << n<<"x"<<m<<" valores: ";
    for (size_t i = 0; i < n; ++i){
        for (size_t j=0; j<m; ++j){
             cin >> pM[i*m + j];
        }
    }
       
}

void PrintMatrix(TP *pM, const size_t n, const size_t m){
    for (size_t i = 0; i < n; ++i){
        for (size_t j=0; j<m; ++j){
             cout<< pM[i*m + j]<<" ";
        }
        cout << endl;
    }
      
}

void DeleteMatrix(TP *&pM){
    delete[] pM;
    pM = nullptr;
}

// Matrixes
void DemoPunteros2Matrix(){
    cout << "Nivel #1: cachimbo ingeniero\n";
     cout<<endl;
    TP *pMect = nullptr;
    const size_t n = 10;
    const size_t m = 10;

    // Crear un Matrix de tamano n
    CreateMatrix(pMect, n, m);
    
    // Leer el Matrix con valores
    ReadMatrix(pMect, n, m);
    
    BurbujaClasico(pMect, n*m, Mayor<TP>);
    PrintMatrix(pMect, n, m);
    cout << endl;
    
    BurbujaClasico(pMect, n*m, Menor<TP>);
    PrintMatrix(pMect, n, m);
    cout << endl;
    
    // Eliminar el Matrix
    DeleteMatrix(pMect);
}

template <typename T>
void Print(T n) { cout << "valor: " << n << endl; }

template <typename T>
void Print2(T &n) { cout << "valor: " << n << endl; }

template <typename T>
void AddX(T &n,  T val1, T val2) { n += val1 + val2; }

template <typename T>
void Square(T &n) { n *= n; }

void DemoPointersMatrix2(){
    TI *pMatrix2 = nullptr;
     cout<<endl;
    cout << "Nivel #2 (cachimbo mejor informado (templates))\n";
     cout<<endl;
    cout << "Problemas:\n";
    cout << "* No se puede crear el arreglo en cualquier lugar (solo en el heap)\n";
    cout << "* No tengo una clase para encapsular los datos\n";
    size_t n2;
    size_t m2;
    cout << "Ingrese el tamaño del Matrix: ";
    cin >> n2;
    cin >> m2;

    Creatematrix2(pMatrix2, n2, m2  );
    Readmatrix2(pMatrix2, n2, m2, cin);
    cout << "Matrix original: ";
    Printmatrix2(pMatrix2, n2, m2,  cout);
    
    cout << "Funcion #1 aplicada:\n";
    ApplyFunctionToAll2(pMatrix2, n2,m2, Print2<TI>);
    Printmatrix2(pMatrix2, n2, m2, cout);
    
    cout << "Funcion #2 aplicada: ";
    ApplyFunctionToAll2(pMatrix2, n2, m2, Square<TI>);
    cout << "Matrix transformado #3: ";
    Printmatrix2(pMatrix2, n2, m2, cout);

    ofstream ofs("outputM2.txt");
    Printmatrix2(pMatrix2, n2, m2, ofs);
    ofs.close();

    Deletematrix2(pMatrix2);
}

void DemoPointersMatrix3(){
     cout<<endl;
    cout << "Nivel #3 (cachimbo con clase)\n";
     cout<<endl;
    cout << "Ingrese el tamaño del Matrix: ";
    matrix3<TI> matrix3;
    matrix3.Read(cin);
    matrix3.Print(cout);
    matrix3.ApplyMFunctionToAll(Print2<TI>);
    matrix3.ApplyMFunctionToAll(Square<TI>);
    matrix3.Print(cout);
    ofstream ofs("outputM3.txt");
    matrix3.Print(ofs);
    ofs.close();
}

void DemoPointersMatrix4(){
     cout<<endl;
    cout << "Nivel #4 (cachimbo respetable)\n";
     cout<<endl;
    matrix4<TI> matrix4;
    ifstream ifs("outputM3.txt");
    matrix4.Read(ifs);
    cout << "Aplicando Square\n";
    matrix4.ApplyFunctionToAll(Square<TI>);

    cout << "Imprimiendo en el cout\n";
    matrix4.ApplyFunctionToAll(Print4<TI>, cout);
    cout << endl;

    cout << "Sumándole 2 valores extras\n";
    matrix4.ApplyFunctionToAll(AddX<TI>, 5, 10);

    matrix4.ApplyFunctionToAll(Print4<TI>, cout);
    cout << endl;
}

void DemoPointersMatrix5(){
 cout<<endl;
    cout << "Nivel #5 (cachimbo CS)\n";
    cout<<endl;
    matrix4<TI> matrix5;
    ifstream ifs("outputM3.txt");
    ifs >> matrix5;
    cout << "Aplicando Square\n";
    matrix5.ApplyFunctionToAll(Square<TI>);

    cout << "Imprimiendo en el cout\n";
    // Matrix5.ApplyFunctionToAll(Print4<T>, cout);
    cout << matrix5;
    cout << endl;

    cout << "Sumándole 2 valores extras\n";
    matrix5.ApplyFunctionToAll(AddX<TI>, 5, 10);

    cout << matrix5 << endl;
    ofstream ofs("outputM5.txt");
    ofs << matrix5 ;
}