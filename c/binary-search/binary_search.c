#include <stdbool.h>
#include "binary_search.h"

int *binary_search(int value, const int *arr, size_t length) {
    int lower = 0;
    int higher = (int) length;
    int mid;

    if (!length) {
        return NULL;
    }

    while (true) {
        if (lower > higher) {
            return false;
        }

        mid = (lower + higher) / 2;

        if (arr[mid] > value) {
            higher = mid - 1;
        } else if (arr[mid] < value ) {
            lower = mid + 1;
        } else {
            return (int *) &arr[mid];
        }
    }
}
