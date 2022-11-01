#ifndef LIB_STRING_H
#define LIB_STRING_H

#include <stddef.h>

/**
 * This object represents a string.
 * The implementation is hidden as it might
 * change in the future.
*/
typedef struct string_t_ *string_t;

/**
 * Construct a new empty string.
*/
string_t new_string();

/**
 * Construct a new empty string with specific length.
 * 
 * @param length string pre-allocation length.
*/
string_t new_string_sz(size_t length);

#endif