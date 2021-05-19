//
// Created by zhaoy on 2021/5/19.
//
#include <memory>
#include <iostream>
#include <cassert>
using namespace std;

template<class T, class... Args>
unique_ptr<T> make_unique(Args&&... args)
{
    return unique_ptr<T>(new T(std::forward<Args>(args)...));
}


int main(int argc, char* argv[])
{
    unique_ptr<int> ptr1(new int(10));
    assert(*ptr1 == 10);
    assert(ptr1 != nullptr);
    //ptr1++;       编译出错，未定义++运算符

    unique_ptr<string> ptr2(new string("hello"));
    assert(*ptr2 == "hello");
    assert(ptr2->size() == 5);
    //ptr2 += 2;    编译出错，未定义+=运算符

    auto ptr3 = make_unique<int>(42);
    assert(ptr3 && *ptr3==42);

    auto ptr4 = make_unique<string>("hello");
    assert(!ptr4->empty());

}
