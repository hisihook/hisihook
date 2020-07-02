/**
* Copyright (C), 2016, 
* All rights reserved.
*
* @file                my_string.h
* @brief             解决hi3519a中没有strlcpy和 strlcat函数，为了与其他海思编译器兼容特引入该头文件
* @author         shliu
* @date             2019.12.09
*/

#ifndef __MY_STRING_H__
#define __MY_STRING_H__

#include <sys/types.h>
#include <string.h>

#if 0
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */
#endif
/*
 * Copy src to string dst of size siz.  At most siz-1 characters
 * will be copied.  Always NUL terminates (unless siz == 0).
 * Returns strlen(src); if retval >= siz, truncation occurred.
 */

inline size_t
strlcpy(char *dst, const char *src, size_t siz)
{
    register char *d = dst;
    register const char *s = src;
    register size_t n = siz;
 
    if (s == 0 || d == 0) return 0;
 
    /* Copy as many bytes as will fit */
    if (n != 0 && --n != 0) {
        do {
            if ((*d++ = *s++) == 0)
                break;
        } while (--n != 0);
    }
 
    /* Not enough room in dst, add NUL and traverse rest of src */
    if (n == 0) {
        if (siz != 0)
            *d = '\0';      /* NUL-terminate dst */
        while (*s++)
            ;
    }
 
    return(s - src - 1);    /* count does not include NUL */
}


/*
 * Appends src to string dst of size siz (unlike strncat, siz is the
 * full size of dst, not space left).  At most siz-1 characters
 * will be copied.  Always NUL terminates (unless siz <= strlen(dst)).
 * Returns strlen(src) + MIN(siz, strlen(initial dst)).
 * If retval >= siz, truncation occurred.
 */
inline size_t
strlcat(char *dst, const char *src, size_t siz)
{
    register char *d = dst;
    register const char *s = src;
    register size_t n = siz;
    size_t dlen;
 
    if (s == 0 || d == 0) return 0;
 
    /* Find the end of dst and adjust bytes left but don't go past end */
    while (n-- != 0 && *d != '\0')
        d++;
    dlen = d - dst;
    n = siz - dlen;
 
    if (n == 0)
        return(dlen + strlen(s));
    while (*s != '\0') {
        if (n != 1) {
            *d++ = *s;
            n--;
        }
        s++;
    }
    *d = '\0';
 
    return(dlen + (s - src));   /* count does not include NUL*/
}

#if 0
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */
#endif

#endif /**__MY_STRING_H__*/