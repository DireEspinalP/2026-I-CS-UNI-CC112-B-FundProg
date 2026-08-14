#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <iostream>
#include "types.h"

using namespace std;

void CreateVector(TP *&pv, const size_t n);
void ReadVector  (TP *pv, const size_t n);
void PrintVector (TP *pv, const size_t n);
void DeleteVector(TP *&pv);

void DemoPunteros2Vector();

void DemoPointersVector2();
void DemoPointersVector3();
void DemoPointersVector4();
void DemoPointersVector5();

#endif // __VECTOR_H__