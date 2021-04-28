//
// Created by zhaoyx on 2021/4/16.
//
#include <iostream>
#include <forward_list>

template <typename T>
void traverseV1(std::forward_list<T>& list)
{
    for (T& x : list)
    {
        std::cout << x << std::endl;
    }
}

template <typename T>
void traverseV2(std::forward_list<T>& list)
{
    for (auto it = list.begin(); it != list.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
}

int main()
{
    std::forward_list<int> intList{77,2,16};
    intList.push_front(19);
    intList.push_front(25);

    traverseV1(intList);
    intList.pop_front();

    traverseV2(intList);
    return 0;
}

