#include "matrix.h"
#include <iostream>



using namespace std;
     void CreateMatrix(TP **&pMat, size_t rows, size_t    cols){
    pMat = new TP*[rows];
    for (size_t i = 0; i < rows; ++i){
        pMat[i] = new TP[cols];
    }
     }

     

     void ReadMatrix(TP **pMat, size_t rows, size_t cols){
    for (size_t i = 0; i < rows; ++i){
        for (size_t  j = 0; j < cols; ++j)
            cin >> pMat[i][j];
    }
}
     

     // PrintMatrix(pMat, rows, cols);
     void PrintMatrix(TP **pMat, size_t rows, size_t cols){
        for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j){
            cout << pMat[i][j] << " ";  
         
             }
    cout << endl;
            }     

     }  
     
     void DeleteMatrix(TP **&pMat, size_t rows){
    for (size_t i = 0; i < rows; ++i){
        delete[] pMat[i];
    delete[] pMat;
    pMat = nullptr;
    }
     }
void DemoMatrix1(){
    TP **pMat = nullptr;
    size_t rows=0, cols=0;
    // TP **pMat = nullptr;

   
    cout << "Ingrese el numero de filas : ";
    cin >> rows ;
    cout << "Ingrese el numero de columnas: ";    
    cin >> cols;
   CreateMatrix(pMat, rows, cols);
  cout << "Ingrese los elementos de la matriz: " << endl;
   ReadMatrix(pMat, rows, cols);   
 cout << "La matriz ingresada es: " << endl;
    PrintMatrix(pMat, rows, cols);
  cout << endl;
    DeleteMatrix(pMat, rows);
}
