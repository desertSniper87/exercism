#include "armstrong_numbers.h"

int pow_(int n, int p);

int pow_(int n, int p) {
    int res = 1;

    while(p) {
        res *= n;
        p--;
    }

    return res;
}

bool is_armstrong_number(int candidate) {
    int arr[100];
    int number_of_digit = 0;
    int r;

    if (!candidate) {
        return true;
    }

    int N = candidate;

    while (candidate != 0) {
  
        r = candidate % 10;
  
        arr[number_of_digit] = r;
        number_of_digit++;
  
        candidate = candidate / 10;
    }

    int res = 0;

    for(int loop = 0; loop < number_of_digit; loop++) {
        res += pow_(arr[loop], number_of_digit);
    }

    return res == N;
}