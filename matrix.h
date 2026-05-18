#ifndef __MATRIX_H__
#define __MATRIX_H__
#include <iostream>  // cout, cin, endl
#include <cstddef>   // size_t
#include "types.h"
#include "matrix2.h"
#include "matrix3.h"
#include "matrix4.h"

using namespace std;

void Creatematrix(TP *&pM, const size_t n,const size_t m);
void Readmatrix(TP *&pM, const size_t n,const size_t m);
void Printmatrix(TP *&pM, const size_t n,const size_t m);
void Deletematrix(TP *&pM);

void DemoPunteros2Matrix();

void DemoPointersMatrix2();
void DemoPointersMatrix3();
void DemoPointersMatrix4();
void DemoPointersMatrix5();

#endif // __MATRIX_H__