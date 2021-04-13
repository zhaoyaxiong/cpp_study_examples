//
// Created by hero on 2021/4/13.
//
#include <stdio.h>
typedef  union perdata_
{
    int class;
    char office[10];
}perdata;

int main()
{
    char a = 'a';
    char b = 'b';
    int c = a << 8 | b ;
    printf("c=%d\n", c);

    perdata  perdata1;
    perdata1.class = c;
    printf("office:%c\n", perdata1.office[0]);
    printf("office:%s\n", perdata1.office);

    short n = 1;
    char *p1 = (char*)(&n);
    printf("%d\n", *p1);
    printf("%d\n", *(p1+1));
    printf("%d\n", *(p1+2));
    printf("%d\n", *(p1+3));

    return 1;
}

