#include "sorting.h"
#include "cvector.h"
#include "util.h"

void DemoCVector(){
    CVector3<TP> v1;
    CVector3<TP> v2(v1);
    size_t n;
    cout << "Ingrese nro de elementos: ";
    cin  >> n;

    v1.CreateVector(n);
    v1.ReadVector(cin);
    v1.Sort( Mayor<TP>);
    v1.PrintVector(cout);
    
    v1.Sort(&Menor<TP>);
    v1.PrintVector(cout);
    
    CVector3<TP> *pV4 = nullptr;
    pV4 = &v1;
    pV4->Sort(&Mayor<TP>);
    v1.PrintVector(cout);

    CVector3<TP> *pV3 = new CVector3<TP>();
    pV3->CreateVector(5);
    pV3->ReadVector(cin);
    pV3->Sort(&Mayor<TP>);
    pV3->PrintVector(cout);
    delete pV3;
}