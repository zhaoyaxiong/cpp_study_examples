//
// Created by zhaoyx on 2021/4/29.
//
#include "SmartPtr.h"
#include <iostream>
#include <memory>
#include <string>
#include <cstring>
using namespace std;

void deleteIntPtr(const int* p) {
    std::cout << "delete int ptr" << std::endl;
    std::cout << *p << std::endl;
    std::cout << "delete success" << std::endl;
    delete p;
}


template<typename T>
std::shared_ptr<T> make_shared_array(size_t size) {
    return std::shared_ptr<T>(new T[size], std::default_delete<T[]>());
}

int main(int argc, char* argv[]) {
//    SmartPtr<int> a(new int(10));
//    //SmartPtr<int> b = a;   //调用拷贝构造函数
//    SmartPtr<int> c;
//    //c = a;                 //调用赋值函数
//    std::cout << *a << std::endl;
//
//    if (a) {
//        std::cout << "OK" << std::endl;
//    }

    std::shared_ptr<int> p(new int (1), [](const int* p) {delete p;});
    std::shared_ptr<int> p2 = p;
    std::shared_ptr<int> ptr;
    ptr.reset(new int (1), deleteIntPtr);

    int *intP = p.get();
    std::cout << *intP << std::endl;
    std::cout << "user count: " << p.use_count() << std::endl;

    if (ptr) {
        std::cout << "ptr is not null" << std::endl;
    }

    //default_delete默认不支持数组,C++17及以后才被支持
    std::shared_ptr<int> array(new int[10], [](const int*p){std::cout << "delete array" << std::endl; delete[] p;});

    //new产生指针，所以长度为8
    std::shared_ptr<char> p5 = make_shared_array<char>(10);
    std::cout << "Size: " << sizeof (p5.get()) << endl;

    char testArray[10] = {0};
    std::cout << "Array size:" << sizeof (testArray) << endl;

    strncpy(p5.get(), "hello", strlen("hello"));
    cout << p5.get() << endl;

    int* ptr2 = new int;
    shared_ptr<int> p10(ptr);
    cout << p10.use_count();
    shared_ptr<int> p11(ptr);   //会导致重复释放
    cout << p10.use_count();
    return 0;
}