#include "list_ops.h"
#include <stdio.h>
#include <stdlib.h>

list_t *new_list(size_t length, list_element_t elements[]) {
    list_element_t *el = malloc(sizeof(list_element_t) * length);
    for (unsigned long i = 0; i < length; i++) {
        el[i] = elements[i];
    }

    list_t *list = malloc(sizeof(list_t));
    list->length = length;
    list->elements = el;

    return list;
}

list_t *append_list(list_t *list1, list_t *list2) {
    size_t l1 = list1->length;
    size_t l2 = list2->length;

    list_element_t *el = malloc(sizeof(list_element_t) * (l1 + l2));
    for (unsigned long i = 0; i < l1; i++) {
        el[i] = list1->elements[i];
    }

    for (unsigned long i = l1; i < l1 + l2; i++) {
        el[i] = list2->elements[i - l1];
    }

    list_t *list = malloc(sizeof(list_t));
    list->length = l1 + l2;
    list->elements = el;
    return list;
}

// filter list returning only values that satisfy the filter function
list_t *filter_list(list_t *list, bool (*filter)(list_element_t)) {
    size_t length = 0;
    for (unsigned long i = 0; i < list->length; i++) {
        if (filter(list->elements[i])) {
            length++;
        }
    }

    list_element_t *elements = malloc(sizeof(list_element_t) * length);
    size_t index = 0;
    for (unsigned long i = 0; i < list->length; i++) {
        if (filter(list->elements[i])) {
            elements[index++] = list->elements[i];
        }
    }

    list_t *filtered = malloc(sizeof(list_t));
    filtered->length = length;
    filtered->elements = elements;
    return filtered;
}

// returns the length of the list
size_t length_list(list_t *list) { return list->length; }

// return a list of elements whose values equal the list value transformed by
// the mapping function
list_t *map_list(list_t *list, list_element_t (*map)(list_element_t)) {
    size_t length = list->length;
    list_element_t *elements = malloc(sizeof(list_element_t) * length);
    for (unsigned long i = 0; i < length; i++) {
        elements[i] = map(list->elements[i]);
    }

    list_t *mapped = malloc(sizeof(list_t));
    mapped->length = length;
    mapped->elements = elements;
    return mapped;
}

// folds (reduces) the given list from the left with a function
list_element_t foldl_list(list_t *list, list_element_t initial,
                          list_element_t (*foldl)(list_element_t,
                                                  list_element_t)) {
    list_element_t result = initial;
    for (unsigned long i = 0; i < list->length; i++) {
        result = foldl(result, list->elements[i]);
    }
    return result;
}

// folds (reduces) the given list from the right with a function
list_element_t foldr_list(list_t *list, list_element_t initial,
                          list_element_t (*foldr)(list_element_t,
                                                  list_element_t)) {
    if (list->length == 0) {
        printf("Error: Empty list passed to foldr_list\n");
        printf("%zu", list->length);
        return initial;
    }

    list_element_t result = initial;
    printf("foldr_list: initial = %d, result = %d\n", initial, result);
    for (long i = list->length - 1; i >= 0; i--) {
        printf("i = %zu, element = %d\n", i, list->elements[i]);
        result = foldr(list->elements[i], result);
    }
    return result;
}

// reverse the elements of the list
list_t *reverse_list(list_t *list) {
    size_t length = list->length;
    list_element_t *elements = malloc(sizeof(list_element_t) * length);
    for (unsigned long i = 0; i < length; i++) {
        elements[i] = list->elements[length - 1 - i];
    }

    list_t *reversed = malloc(sizeof(list_t));
    reversed->length = length;
    reversed->elements = elements;
    return reversed;
}

// destroy the entire list
// list will be a dangling pointer after calling this method on it
void delete_list(list_t *list) {
    free(list->elements);
    free(list);
}
