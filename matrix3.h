#ifndef __MATRIX3_H__
#define __MATRIX3_H__
#include <functional>
#include <iostream>

using namespace std;

template <typename T>
class matrix3 {
    private:
        T     **m_pmatrix = nullptr;
        size_t  m_size   = 0;
        size_t n_size =0 ;
    public:
        matrix3()      {  }
        ~matrix3()     { Destroy(); }
        void Create() { m_pmatrix = new T*[n_size];
         for (size_t i = 0; i < n_size; ++i) {
            m_pmatrix[i] = new T[m_size]; }
         }
        void Read(istream &isM);
        template <typename Func>
        void ApplyMFunctionToAll(Func func);
        void Print(ostream &osM);
        void Destroy();
};

template <typename T>
void matrix3<T>::Read(istream &isM) {
    isM >> n_size;
    isM>>m_size;
    Create();
    for (size_t i = 0; i < n_size; ++i){
            for (size_t j=0 ; j<m_size; ++j){
                    isM >> m_pmatrix[i][j];
            }
    }
}

template <typename T>
template <typename Func>
void matrix3<T>::ApplyMFunctionToAll(Func func) {
    for (size_t i = 0; i < n_size; ++i){
        for (size_t j=0 ; j<m_size; ++j){
            func(m_pmatrix[i][j]);
        }
    }
}

template <typename T>
void matrix3<T>::Print(ostream &osM) {
    osM << n_size << " " << m_size << "\n";
    for (size_t i = 0; i <n_size; ++i){
        for (size_t j=0 ; j<m_size; ++j){
             osM << m_pmatrix[i][j] << " ";
  
        }
          osM << endl;
    }
        
}

template <typename T>
void matrix3<T>::Destroy() {
    if (m_pmatrix != nullptr) {
        for (size_t i = 0; i < n_size; ++i) {
            delete[] m_pmatrix[i];
        }
        delete[] m_pmatrix;
        m_pmatrix = nullptr;
        n_size = 0;
        m_size = 0;
    }
}

#endif // __MATRIX3_H__