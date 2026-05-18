#ifndef __MATRIX4_H__
#define __MATRIX4_H__

#include <functional>
#include <iostream>

using namespace std;

template <typename T>
void Print4(T &n, ostream &os) { os << n << " "; }

template <typename T>
class matrix4 {
    private:
        T     **m_pmatrix = nullptr;
        size_t m_size=0; 
        size_t n_size=0;

    public:
        matrix4()      { }
        ~matrix4()     { Destroy(); }
        void     Create() { m_pmatrix = new T*[n_size];
         for (size_t i = 0; i < n_size; ++i) m_pmatrix[i] = new T[m_size]; };
        istream &Read(istream &is);
        template <typename Func, typename... Args>
        void ApplyFunctionToAll(Func func, Args&& ...args);
        ostream &Print(ostream &os);
        void Destroy();
};

template <typename T>
istream &matrix4<T>::Read(istream &is) {
    is >> n_size >> m_size;
    Create();
    for (size_t i = 0; i < n_size; ++i)
        for (size_t j=0 ; j<m_size; ++j)
             is >> m_pmatrix[i][j];
    return is;
}

// Variadic template
template <typename T>
template <typename Func, typename... Args>
void matrix4<T>::ApplyFunctionToAll(Func func, Args&& ...args) {
    for (size_t i = 0; i < n_size; ++i)
        for (size_t j=0 ; j<m_size; ++j)
            func(m_pmatrix[i][j], forward<Args>(args)...);
}

template <typename T>
ostream &matrix4<T>::Print(ostream &os) {
    os << n_size << " " << m_size << "\n";
    for (size_t i = 0; i < n_size; ++i){
             for (size_t j=0 ; j<m_size; ++j){
                 os  << m_pmatrix[i][j] << " ";
                }
          os << endl;
            }
          return os;
}

template <typename T>
void matrix4<T>::Destroy() {
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

template <typename T>
istream &operator>>(istream &isM, matrix4<T> &matrix){
    return matrix.Read(isM);
}

template <typename T>
ostream &operator<<(ostream &osM, matrix4<T> &matrix){
    matrix.ApplyFunctionToAll(Print4<T>, osM);
    return osM;
}

#endif // __MATRIX4_H__