#ifndef __CVECTOR_H__
#define __CVECTOR_H__

#include <iostream>
#include "types.h"

using namespace std;

class CVector{
    TP     *m_pVect;
    size_t  m_nElem;
    public:
        // Constructores
        // 1. Tiene el mismo nombre que la clase
        // 2. No devuelve ningun tipo (ni siquiera void)
        // 3. Pueden haber varios (con tipos de parametros distintos)
        // 4. Se llaman al declarar un objeto (cuando es estatico) o
        //    all crear un objeti dinamico con new
        // 5. Un constructor puede llamar a otro constructor   
        CVector();
        CVector(CVector &other);

        // Destructor
        // 1. Tiene el mismo nombre que la clase pero con ~
        // 2. No devuelve ningun tipo (ni siquiera void)
        // 3. Solo hay uno
        // 4. Si es estatico:
        //    * Se llaman cuando el objeto sale de las {} donde fue creado 
        //    Si es dinamico (fue creado con new)
        //    * Se llama con delete
        ~CVector();

        void CreateVector(const size_t n);
        void ReadVector(istream &is);
        void Sort( bool (*)(TP, TP) );
        void PrintVector(ostream &os);
        void DeleteVector();
};

void DemoCVector();

#endif // __CVECTOR_H__