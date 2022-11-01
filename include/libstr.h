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
 * 
 * @return new string if creation is successful,
 * otherwise NULL.
*/
string_t new_string();

/**
 * Construct a new empty string with specific length.
 * 
 * @param length string pre-allocation length.
 * @return new string if creation is successful,
 * otherwise NULL.
*/
string_t new_string_sz(size_t length);

/**
 * Construct a new string with the value passed as argument.
 * 
 * @param c_str value of string.
 * @return new string object with assigned value.
*/
string_t new_string_cstr(const char *c_str);

/**
 * Delete string from memory.
 * 
 * @param str the string to delete.
 * @return NULL pointer.
*/
string_t delete_string(string_t str);

#endif