//
// Created by zhaoyx on 2021/4/28.
//
#include <iostream>
#include "TestTemplate.h"
int main(int argc, char* argv[]) {
    TestTemplate<int> testTemplate(10);
    testTemplate.print();

    TestTemplate<double> aTemplate(100.0527);
    aTemplate.print();
    return 0;
}