#include <iostream> // cout
#include "arit.h"
using namespace std;

// En el .cpp va la implementacion de mis funciones
T1 suma(T1 a, T1 b){
    return a + b;
}

T1 resta(T1 a, T1 b){
    return a - b;
}

T1 producto(T1 a, T1 b){
    return a * b;
}

void DemoAritmetica(){
    T1 a = 50;
    T1 b = 20;
    T1 c = suma(a, b);
    cout << c << endl;
    //cout << "La suma de " << a << " y " << b << " es " << c << endl;
    c = resta(a, b);
    cout << c << endl;
    //cout << "La resta de " << a << " y " << b << " es " << c << endl;
    
    c = producto(a, b);
    cout << c << endl;
    //cout << "El producto de " << a << " y " << b << " es " << c << endl;
}
