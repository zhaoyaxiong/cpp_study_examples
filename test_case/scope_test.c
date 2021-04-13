//
// Created by hero on 2021/4/13.
//
#include <stdio.h>
extern int global_count;
int get_global_salary();


int main()
{
    printf("Global count:%d\n", global_count);
    printf("Global count:%d\n", get_global_salary());
}