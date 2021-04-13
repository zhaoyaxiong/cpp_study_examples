//
// Created by hero on 2021/4/12.
//

#ifndef CPP_STUDY_EXAMPLES_LIST_H
#define CPP_STUDY_EXAMPLES_LIST_H

#include <stdio.h>

typedef struct ListElement_ {
    void *data;
    struct ListElement_ *next;
} ListElement;

typedef struct List_ {
    int size;

    int (*match)(const void *key1, const void *key2);

    void (*destroy)(void *data);

    ListElement *head;
    ListElement *tail;
} List;

void list_init(List *list, void (*destroy)(void *data));

void list_destroy(List *list);

int list_insert_next(List *list, ListElement *listElement, const void *data);

int list_remove_next(List *list, ListElement *listElement, void **data);

#define list_size(list) ((list)->size)
#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)
#define list_is_head(list, element) ((element)==(list)->head ? 1 : 0)
#define list_is_tail(element) ((element)->next == NULL ? 1 : 0)
#define list_data(element) ((element)->data)
#define list_next(element) ((element)->next)
#endif //CPP_STUDY_EXAMPLES_LIST_H
