#ifndef __CVECTOR_H__
#define __CVECTOR_H__

#include <iostream>
#include "types.h"

using namespace std;

template <typename T>
class CVector3{
    T     *m_pVect;
    size_t  m_nElem;
    public:
        // Constructores
        // 1. Tiene el mismo nombre que la clase
        // 2. No devuelve ningun tipo (ni siquiera void)
        // 3. Pueden haber varios (con tipos de parametros distintos)
        // 4. Se llaman al declarar un objeto (cuando es estatico) o
        //    all crear un objeti dinamico con new
        // 5. Un constructor puede llamar a otro constructor   
        CVector3();
        CVector3(CVector3<T> &other);

        // Destructor
        // 1. Tiene el mismo nombre que la clase pero con ~
        // 2. No devuelve ningun tipo (ni siquiera void)
        // 3. Solo hay uno
        // 4. Si es estatico:
        //    * Se llaman cuando el objeto sale de las {} donde fue creado 
        //    Si es dinamico (fue creado con new)
        //    * Se llama con delete
        ~CVector3();

        void CreateVector(const size_t n);
        void ReadVector(istream &is);
        void Sort( bool (*)(T, T) );
        void PrintVector(ostream &os);
        void DeleteVector();
};

template <typename T>
CVector3<T>::CVector3(){
    m_nElem = 0;
    m_pVect = nullptr;
}

template <typename T>
CVector3<T>::CVector3(CVector3 &other){
    m_nElem = other.m_nElem;
    CreateVector(m_nElem);
    for(size_t i = 0 ; i < other.m_nElem ; ++i)
        m_pVect[i] = other.m_pVect[i];
}

template <typename T>
CVector3<T>::~CVector3(){
    DeleteVector();
}

template <typename T>
void CVector3<T>::CreateVector(const size_t n){
    m_nElem = n;
    m_pVect = new T[m_nElem];
}

template <typename T>
void CVector3<T>::ReadVector(istream &is){
    for (size_t i = 0; i < m_nElem; i++){
        // cout << "Ingrese pVect[" << i << "]: ";
        is >> m_pVect[i];
    }
}

template <typename T>
void CVector3<T>::Sort( bool (*pComp)(T, T) )
{
    BurbujaClasico(m_pVect, m_nElem, pComp);
}

template <typename T>
void CVector3<T>::PrintVector(ostream &os){
    for (size_t i = 0; i < m_nElem; i++)
        os << m_pVect[i] << " ";
    os << endl;
}

template <typename T>
void CVector3<T>::DeleteVector(){
    delete[] m_pVect;
    m_pVect = nullptr;
    m_nElem = 0;
}

void DemoCVector3();

#endif // __CVECTOR_H__