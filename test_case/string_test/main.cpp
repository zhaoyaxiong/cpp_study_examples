//
// Created by zhaoyx on 2021/4/28.
//
#include "Staff.h"
#include <iostream>
#include <memory>

using namespace std;

int main(int argc, char *argv[]) {
    std::string staff_name = "daxiong";
    Staff staff(staff_name, 30);
    std::cout << staff << std::endl;

    std::string s = "abc";
    const char *p = s.c_str();
    std::cout << p << std::endl;

    const char *c1 = "hello";
    std::string s2(c1);
    std::cout << s2 << std::endl;

    char *c2 = const_cast<char *>(c1);
    std::cout << c2 << std::endl;

    char *c3= new


    return 0;
}
