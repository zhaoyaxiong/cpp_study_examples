//
// Created by hero on 2021/4/12.
//
#include <stdlib.h>
#include <string.h>
#include "list.h"

void list_init(List *list, void (*destroy)(void *data)) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    list->destroy = destroy;
}

void list_destroy(List *list) {
    void * data;

    while (list_size(list) > 0)
    {
        if (list_remove_next(list, NULL, &data) == 0 && list->destroy != NULL)
        {
            list_destroy(data);
        }
    }

    memset(list, 0, sizeof(List));
}

int list_insert_next(List *list, ListElement *listElement, const void *data) {
    ListElement *new_element = (ListElement *) malloc(sizeof(ListElement));
    if (new_element == NULL) {
        return -1;
    }
    new_element->data = (void *) data;

    if (listElement == NULL) {
        if (list_size(list) == 0) {
            list->tail = new_element;
        }
        new_element->next = list->head;
        list->head = new_element;

    } else {
        if (listElement->next == NULL) {
            list->tail = new_element;
        }

        new_element->next = listElement->next;
        listElement->next = new_element;
    }

    ++list->size;
    return 0;
}

int list_remove_next(List *list, ListElement *listElement, void **data) {
    if (list_size(list) == 0) {
        return -1;
    }
    ListElement *old_element = NULL;

    if (listElement == NULL) {
        *data = list->head->data;
        old_element = list->head;
        list->head = list->head->next;

        if (list_size(list) == 1) {
            list->tail = NULL;
        }
    } else {
        if (listElement->next == NULL) {
            return -1;
        }

        *data = listElement->next->data;
        old_element = listElement->next;
        listElement->next = listElement->next->next;

        if (listElement->next == NULL) {
            list->tail = NULL;
        }
    }

    free(old_element);
    --list->size;
    return 0;
}

