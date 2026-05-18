#ifndef  __MATRIX2_H__
#define __MATRIX2_H__
#include <functional>
#include <iostream>
#include "matrix3.h"
#include "matrix4.h"

using namespace std;

template <typename T>
void Creatematrix2(T *&pMatrix, size_t n, size_t m) {
    pMatrix = new T[n*m];
}

template <typename T>
void Readmatrix2(T *pMatrix, size_t n,size_t m,  istream &isM) {
    for (size_t i = 0; i < n; ++i){
          for (size_t j=0; j<m; ++j){
                isM >> pMatrix[i*m + j];
          }
    }
       
}

template <typename T, typename Func>
void ApplyFunctionToAll2(T *pMatrix, size_t n, size_t m, Func func) {
    for (size_t i = 0; i < n; ++i)
        for (size_t j=0; j<m; ++j)
            func(pMatrix[i*m + j]);
}

template <typename T>
void Printmatrix2(T *pMatrix, size_t n,size_t m, ostream &osM) {
    osM << n << " " << m << "\n";
    for (size_t i = 0; i < n; ++i){
        for(size_t j=0 ; j<m; ++j){
             osM << pMatrix[i*m + j] << " ";
  
        }
          osM << endl;
    }
       
}

template <typename T>
void Deletematrix2(T *&pMatrix) {
    if (pMatrix != nullptr) {
        delete[] pMatrix;
        pMatrix = nullptr;
    }
}

#endif // __MATRIX2_H__