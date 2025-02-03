#include "test.h"

template<typename T>
test<T>::test(T e1, T e2) : x(e1), y(e2) {}

template<typename T>
T& test<T>::operator+(T e3) {
    return x + y + e3;
}