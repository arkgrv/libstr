#include "libstr.h"

#include <stdlib.h>

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

/**
 * Construct a new empty string.
 * 
 * @return new string if creation is successful,
 * otherwise NULL.
*/
string_t new_string()
{
    // Allocate memory and just assign the small buffer to the
    // data pointer.
    
    string_t str = malloc(sizeof(struct string_t_));
    if (str == NULL)
        return NULL;

    str->data = str->small_data;

    return str;
}
