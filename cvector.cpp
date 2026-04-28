#include "sorting.h"
#include "cvector.h"
#include "util.h"

CVector::CVector(){
    m_nElem = 0;
    m_pVect = nullptr;
}

CVector::CVector(CVector &other){
    m_nElem = other.m_nElem;
    CreateVector(m_nElem);
    for(size_t i = 0 ; i < other.m_nElem ; ++i)
        m_pVect[i] = other.m_pVect[i];
}

CVector::~CVector(){
    DeleteVector();
}

void CVector::CreateVector(const size_t n){
    m_nElem = n;
    m_pVect = new TP[m_nElem];
}

void CVector::ReadVector(istream &is){
    for (size_t i = 0; i < m_nElem; i++){
        // cout << "Ingrese pVect[" << i << "]: ";
        is >> m_pVect[i];
    }
}

void CVector::Sort( bool (*pComp)(TP, TP) )
{
    BurbujaClasico(m_pVect, m_nElem, pComp);
}

void CVector::PrintVector(ostream &os){
    for (size_t i = 0; i < m_nElem; i++)
        os << m_pVect[i] << " ";
    os << endl;
}

void CVector::DeleteVector(){
    delete[] m_pVect;
    m_pVect = nullptr;
    m_nElem = 0;
}

void DemoCVector(){
    CVector v;
    int n;
    cout << "Ingrese nro de elementos: ";
    cin  >> n;

    v.CreateVector(n);
    v.ReadVector(cin);
    v.Sort( Mayor<TP>);
    v.PrintVector(cout);
    
    v.Sort(&Menor<TP>);
    v.PrintVector(cout);

    v.DeleteVector();
}