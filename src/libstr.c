#include "libstr.h"

#include <stdlib.h>
#include <string.h>

#define SMALL_STR_BUF 25 + 1

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
    string_t str = (struct string_t_*) malloc(sizeof(struct string_t_));
    if (str == NULL)
        return NULL;

    // Initialize small data
    memset(str->small_data, 0, sizeof(str->small_data));
    // Perform assignments
    str->data = str->small_data;
    str->capacity = SMALL_STR_BUF;
    str->length = 0;

    return str;
}

/**
 * Construct a new empty string with specific length.
 * 
 * @param length string pre-allocation length.
 * @return new string if creation is successful,
 * otherwise NULL.
*/
string_t new_string_sz(size_t length)
{
    const size_t cap = length + 1;
    if (length < SMALL_STR_BUF - 1) return new_string();

    string_t str = (struct string_t_*) malloc(sizeof(struct string_t_));
    if (str == NULL) return NULL;

    // Setup everything
    str->data = (char*) malloc(sizeof(char) * cap);
    if (str->data == NULL) {
        free(str);
        return NULL;
    }

    memset(str->data, 0, sizeof(char) * cap);

    str->capacity = cap;
    str->length = 0;

    return str;
}

/**
 * Construct a new string with the value passed as argument.
 * 
 * @param c_str value of string.
 * @return new string object with assigned value.
*/
string_t new_string_cstr(const char *c_str)
{
    string_t str;

    if (strlen(c_str) <= SMALL_STR_BUF - 1) {
        str = new_string();
        if (str == NULL) return NULL;
        strncpy(str->data, c_str, strlen(c_str));
        return str;
    }

    str = new_string_sz(strlen(c_str));
    if (str == NULL) return NULL;
    strncpy(str->data, c_str, strlen(c_str));

    return str;
}

/**
 * Delete string from memory.
 * 
 * @param str the string to delete.
 * @return NULL pointer.
*/
string_t delete_string(string_t str)
{
    if (str == NULL)
        return NULL;

    if (str->data == str->small_data) {
        free(str);
        return NULL;
    }

    free(str->data);
    free(str);
    return NULL;
}
