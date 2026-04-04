#ifndef __SORTING_H__
#define __SORTING_H__
#include "types.h"
// #include "compareFunc.h"

using ContainerElemType1 = T1;
using ContainerElemType2 = double;

using ContainerRange    = int;

void DemoBurbuja();
void intercambiar(ContainerElemType1& a, ContainerElemType1& b);
void PrintArray(ContainerElemType1 arr[], ContainerRange n);

void BurbujaClasico(ContainerElemType1 arr[], ContainerRange n);
void BurbujaRecursivo(ContainerElemType1 arr[], ContainerRange n);

// void BurbujaClasico(ContainerElemType1* arr, ContainerRange n, CompFunc pComp);
// void BurbujaRecursivo(ContainerElemType1* arr, ContainerRange n, CompFunc pComp);


// ContainerRange  particionar(ContainerElemType1* arr, ContainerRange first, ContainerRange last, CompFunc pComp);
// void QuickSort  (ContainerElemType1* arr, ContainerRange first, ContainerRange last, CompFunc pComp);
// void DemoQuickSort();

// void Merge(ContainerElemType1* arr, const ContainerRange left, const ContainerRange mid, const ContainerRange right, CompFunc pComp); 
// void MergeSort(ContainerElemType1* arr, const ContainerRange begin, const ContainerRange end, CompFunc pComp);
// void DemoMergeSort();

void DemoSorting();

#endif // __SORTING_H__