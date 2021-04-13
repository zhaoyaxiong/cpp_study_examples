//
// Created by hero on 2021/4/12.
//
#include <stdlib.h>
#include "list.h"

void print_list(List *list) {
    int *data = NULL;
    ListElement *listElement = list_head(list);
    printf("List Siz:%d\n", list_size(list));
    printf("Print List Element Start...\n");
    for (int i = 0; i < list_size(list); i++) {
        data = (int *) list_data(listElement);
        printf("Element Value:%d\n", *data);
        listElement = listElement->next;
    }
    printf("Print List Element Finish...\n");
}

int main(int argc, char **args) {
    List list;
    list_init(&list, free);

    int *data = NULL;

    //测试链表插入
    for (int i = 0; i < 5; i++) {
        data = (int *) malloc(sizeof(int));
        if (data == NULL) {
            list_destroy(&list);
            printf("Malloc memory failed");
            return -1;
        }
        *data = i;

        list_insert_next(&list, NULL, data);
    }

    ListElement *listElement = list_head(&list);
    printf("Print Sequential List Element ...\n");
    //测试链表顺序访问
    for (int i = 0; i < 3; i++) {
        printf("Element value:%d\n", *(int *) (listElement->data));
        listElement = list_next(listElement);
    }
    int result = list_remove_next(&list, listElement, ((void**)(&data)));
    if (result != 0)
    {
        list_destroy(&list);
        return -1;
    }
    printf("Delete Element value:%d\n", *(data));
    print_list(&list);
    return 0;
}

