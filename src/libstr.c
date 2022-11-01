#include "libstr.h"

#define SMALL_STR_BUF 25

/**
 * Implementation of string struct
*/
struct string_t_ {
    size_t length;
    size_t capacity;
    char *data;
    char small_data[SMALL_STR_BUF];
};


