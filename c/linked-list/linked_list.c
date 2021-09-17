#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

struct list_node {
   struct list_node *prev, *next;
   ll_data_t data;
};

struct list {
   struct list_node *first, *last;
};

struct list *list_create(void) {
//    struct list_node *node;
//    node = malloc(sizeof(struct list_node));

    struct list *list;
    list = malloc(sizeof(struct list));

    list->first = (struct list_node *) NULL;
    list->last = (struct list_node *) NULL;

    return list;
}

size_t list_count(const struct list *list) {
    int c = 0;
    struct list_node * lstPtr = list -> last;
    while ( lstPtr != NULL) {
        c ++;
        lstPtr = lstPtr ->next;
    }

    return c;
}

void list_push(struct list *list, ll_data_t item_data) {

    printf("Pushing %d\n", item_data);

    struct list_node * lastPtr = list -> last;

    struct list_node *node;
    node = malloc(sizeof(struct list_node));
    node -> data = item_data;

    if (lastPtr == NULL) {
        list -> first = node;
    } else {
        lastPtr -> next = node;
        node -> prev = lastPtr;
    }
    list -> last = node;
}

ll_data_t list_pop(struct list *list) {
    struct list_node * lastPtr = list -> last;

    struct list_node * prevPtr = lastPtr -> prev;

    if (prevPtr != NULL) {
        prevPtr -> next = NULL;
    }

    list -> last = prevPtr;

    return lastPtr -> data;
}

void list_destroy(struct list *list) {
    list -> first = (struct list_node *) NULL;
}