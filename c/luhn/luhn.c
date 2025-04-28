#include "luhn.h"
#include <string.h>

bool luhn(const char *num) {
    int sum = 0;
    int len = strlen(num);
    bool is_second = false;

    for (int i = len - 1; i >= 0; i--) {
        if (num[i] < '0' || num[i] > '9') {
            return false;
        }

        int digit = num[i] - '0';
        if (is_second) {
            digit *= 2;
            if (digit > 9) {
                digit -= 9;
            }
        }
        sum += digit;
        is_second = !is_second;
    }

    return sum % 10 == 0;
}
