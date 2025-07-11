#include "hash.h"

unsigned int DJBHash(const char* str)
{
    int hash = 5381;
    while (*str != '\0')
    {
        hash = hash * 33 + *str;
        str++;
    }
    return hash;
}