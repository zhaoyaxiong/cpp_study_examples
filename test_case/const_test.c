//
// Created by hero on 2021/4/13.
//
#include <stdio.h>

struct device
{
    int deviceNo;
};




int main(int argc, char* argv[])
{
    const int a = 10;
    int const b = 10;
   // a = 20;  a的值不能修改
   // b = 20;  b的值不能修改
    const int c[5] = {1, 2, 3, 4, 5};
    //c[0] = 10;  c数组中的变量不能修改

    const int *p1;
    p1 = c;
    // *p1 = 10;  *p1的值不能修改

    int * const p2 = c;
    printf("p2:%p\n", p2);
    printf("*p2:%d\n", *p2);
    *p2 = 10;

    for (int i = 0; i < (sizeof (c))/(sizeof (c[0])); i++)
    {
        printf("c[%d] = %d\n", i, c[i]);
    }

    const struct device dev[2] = {{1}, {2}};
    //dev[0].deviceNo = 3;  /dev是常量，不能修改，类似于数组

    struct device const* dev2[2] = {&dev[0], &dev[1]};
    struct device dev3 = {3};
    dev2[1] = &dev3;  //可以修改dev2指向


    struct device dev4[2] = {{1}, {2}};
    struct device const* dev5[2] = {&dev[0], &dev[1]};
    //dev5[1]->deviceNo = 3;  //*d
    // ev5表示元素不能修改
    dev4[0].deviceNo = 3;  //可以间接修改
    return 1;
 }
