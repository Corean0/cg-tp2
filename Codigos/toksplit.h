
#include <stddef.h>

const char *toksplit(const char *src, char tokchar, char *token, size_t lgh)
{
    if (src)
    {
        while (' ' == *src) *src++;

        while (*src && (tokchar != *src))
        {
            if (lgh)
            {
                *token++ = *src;
                --lgh;
            }
            src++;
        }
        if (*src && (tokchar == *src))
        {
            src++;
        }
    }
    *token = '\0';
    return src;
}
