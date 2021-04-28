//
// Created by zhaoyx on 2021/4/26.
//
#include <iostream>
#include <memory>

using namespace std;

int main(int argc, char* argv[])
{
    unique_ptr<int> uniquePtr(new int(20));
    cout << uniquePtr.get() << endl;
    return 0;
}
