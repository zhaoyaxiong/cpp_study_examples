//
// Created by zhaoy on 2021/5/19.
//
#include <memory>
#include <iostream>
#include <cassert>
#include <map>
#include "TestA.h"

using namespace std;

map<int, shared_ptr<int>> g_intMap;

void deletePtr(const int* param)
{
    cout << "delete..." <<endl;
    delete param;
}

void deleteTestPtr(TestA *test)
{
    delete test;
}


shared_ptr<TestA> getTestA()
{
    //auto* testA = new TestA();
    TestA testA1(0,1);
    return std::make_shared<TestA>(testA1);
}

int main(int argc, char* argv[])
{
    //shared_ptr<int> ptr1 = make_shared<int>(42);
    shared_ptr<int> ptr1(new int (42), deletePtr);
    assert(ptr1 != nullptr);
    cout << "share ptr" <<endl;
    std::cout << ptr1.unique() << endl;

    auto ptr2 = ptr1;
    cout << ptr2.unique() <<endl;
    cout << (ptr1 == ptr2) << endl;
    cout << "ptr1:" << ptr1.use_count() << endl;
    cout << "ptr2:" << ptr2.use_count() <<endl;

    g_intMap.insert(make_pair(1, ptr1));
    g_intMap.insert(make_pair(2, ptr2));
    cout << "ptr1:" << ptr1.use_count() << endl;
    cout << "ptr 2:" << ptr2.use_count() <<endl;
    shared_ptr<int> ptr3 = g_intMap.at(1);
    shared_ptr<int> ptr4 = g_intMap.at(2);
    cout << "ptr3:" << ptr3.use_count() << endl;

    auto ptr5 = g_intMap.find(1);
    cout << ptr5->first << endl;
    cout << ptr5->second.use_count() << endl;
    shared_ptr<int> ptr6 = ptr5->second;
    cout << "ptr6:" << ptr5->second.use_count() << endl;

    shared_ptr<TestA> testAPtr = getTestA();
    cout << testAPtr.use_count() <<endl;
    cout << *testAPtr <<endl;
}
