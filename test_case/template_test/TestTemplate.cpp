//
// Created by zhaoyx on 2021/4/28.
//

#include "TestTemplate.h"
#include <iostream>
template<typename T>
void TestTemplate<T>::print() {
    std::cout << "TestTemplate:" << " " << data_ << std::endl;
}

template<typename T>
TestTemplate<T>::TestTemplate(T data):data_(data) {

}

template class TestTemplate<int>;
template class TestTemplate<double>;
