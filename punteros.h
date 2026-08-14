#ifndef __PUNTEROS_H__
#define __PUNTEROS_H__

#include "types.h"

void Print(TP n);
void f1(TP n);
void f2(TP &rn);
void f3(const TP &n);
void f4(TP *pi);
void f5(TP *&rp);
void f6(TP **ppx);
void f7(TP **&rpp);
void DemoPunteros1 ();

#endif // __PUNTEROS_H__