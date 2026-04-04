#include <iostream> // cout
#include "util.h"
using namespace std;

// A: Recursividad muy mal usada O(2^n)
//    No usar en produccion
//    Tiene demasiados cálculos repetidos
//    fib(n) = fib(n-1) + fib(n-2)
UTT1 fib_rec(UT1 n){
    if (n <= 1)
        return n;
    return fib_rec(n - 1) + fib_rec(n - 2);
}

// B: Iteratividad O(n)
UTT1 fib_iter(UT1 n){
    if (n <= 1)
        return n;
    UTT1 a = 0;
    UTT1 b = 1;
    UTT1 c;
    for (T1 i = 2; i <= n; i++){
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

// Factorial recursivo
// n! = n * (n-1)!
// 0! = 1
UTT1 fact_rec(UT1 n){
    if (n <= 1)
        return 1;
    return n * fact_rec(n - 1);
}

// Factorial iterativo
UTT1 fact_iter(UT1 n){
    if (n <= 1)
        return 1;
    UTT1 rpta = 1;
    for (UT1 i = 2; i <= n; i++)
        rpta *= i;
    return rpta;
}

void DemoUtil(){
    T1 n = 15;
    for (T1 i = 0; i <= n; i++){
        cout << "El fib_iter(" << i << ")= " << fib_iter(i) << endl;
        cout << "El fib_rec (" << i << ")= " << fib_rec (i) << endl;
        cout << "===========================" << endl;
    }

    for (T1 i = 0; i <= n; i++){
        cout << "El fact_iter(" << i << ")= " << fact_iter(i) << endl;
        cout << "El fact_rec (" << i << ")= " << fact_rec (i) << endl;
        cout << "===========================" << endl;
    }
}