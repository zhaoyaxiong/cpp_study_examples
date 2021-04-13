//
// Created by hero on 2021/4/13.
//
#include <stdio.h>
enum Color
{
    GREEN = 1,
    RED,
    BLUE
}ColorVal;

int main()
{
    printf("Size Of Color:%llu\n", sizeof (ColorVal));

    enum Color color = RED;
    printf("Enum Color:%d\n", color);
    return 1;
}