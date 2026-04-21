#ifndef __MATRIX_H__
#define __MATRIX_H__
#include <iostream>
#include "types.h"
using namespace std;
     void CreateMatrix(TP **&pMat, size_t rows, size_t cols);
     void ReadMatrix(TP **pMat, size_t rows, size_t cols);
     void PrintMatrix(TP **pMat, size_t rows, size_t cols);
     void DeleteMatrix(TP **&pMat, size_t rows);

void DemoMatrix1();

#endif // __MATRIX_H__