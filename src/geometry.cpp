#include "geometry.h"
#include <iostream>

template<typename T>
Vec2<T>::Vec2() {};

template<typename T>
Vec2<T>::Vec2(T e0, T e1) : x(e0), y(e1) {};

template<typename T>
T& Vec2<T>::operator[] (uint8_t i) {return (&x)[i]; }

template<typename T>
void Vec2<T>::print() {
    std::cout << x <<std::endl;
    std::cout << y <<std::endl;
} 