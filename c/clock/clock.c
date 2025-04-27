#include "clock.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

clock_t clock_create(int hour, int minute) {
    clock_t clock;
    snprintf(clock.text, MAX_STR_LEN, "%02d:%02d",
             normalize_hour(hour + (minute / 60)), normalize_minute(minute));
    return clock;
}

clock_t clock_add(clock_t clock, int minute_add) {
    char *clock_text = clock.text;

    int hour = clock_text[0] - '0' + (clock_text[1] - '0') * 10;
    int minute = clock_text[3] - '0' + (clock_text[4] - '0') * 10;

    minute += minute_add;
    hour += minute / 60;
    minute %= 60;
    hour %= 24;
    sprintf(clock_text, "%02d:%02d", hour, minute);
    clock_t new_clock = {*clock_text};

    return new_clock;
}

clock_t clock_subtract(clock_t clock, int minute_subtract) {
    char *clock_text = clock.text;

    int hour = clock_text[0] - '0' + (clock_text[1] - '0') * 10;
    int minute = clock_text[3] - '0' + (clock_text[4] - '0') * 10;

    minute -= minute_subtract;
    hour -= minute / 60;
    minute %= 60;
    hour %= 24;
    sprintf(clock_text, "%02d:%02d", hour, minute);
    clock_t new_clock = {*clock_text};

    return new_clock;
}
bool clock_is_equal(clock_t a, clock_t b) {
    if (strcmp(a.text, b.text) == 0) {
        return true;
    }
    return false;
}

int normalize_hour(int hour) {
    hour %= 24;
    if (hour < 0) {
        hour += 24;
    }
    return hour;
}

int normalize_minute(int minute) {
    minute %= 60;
    if (minute < 0) {
        minute += 60;
    }
    return minute;
}
