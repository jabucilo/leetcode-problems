#include <limits.h>
#include "assert.h"

int myAtoi(char *s)
{
    char neg = 0;
    long long res = 0;
    char digit;
    long long max = INT_MAX;
    while (*s == ' ')
    {
        s += 1;
    }
    if (*s == '+')
    {
        s += 1;
    } else if (*s == '-')
    {
        neg = 1;
        max = (long long)INT_MAX + 1;
        s += 1;
    }
    while (*s >= '0' && *s <= '9')
    {
        digit = *s - 48;
        res = res * 10 + digit;
        if (res >= max)
        {
            res = max;
            break;
        }
        s += 1;
    }
    if (neg)
        return (int)-res;
    return (int)res;
}


int main(void)
{
    char *a = "123";
    char *b = "+123";
    char *c = "-123";
    char *d = "00123";
    char *e = "a123";
    char *f = "123a";
    char *g = "000";
    char *h = "   s";
    char *i = "   -123s";
    char *j = "2147483648";
    char *k = "-3147483647";
    char *l = "-2147483648";
    char *m = "-2147483649";
    assert(myAtoi(a) == 123);
    assert(myAtoi(b) == 123);
    assert(myAtoi(c) == -123);
    assert(myAtoi(d) == 123);
    assert(myAtoi(e) == 0);
    assert(myAtoi(f) == 123);
    assert(myAtoi(g) == 0);
    assert(myAtoi(h) == 0);
    assert(myAtoi(i) == -123);
    assert(myAtoi(j) == INT_MAX);
    assert(myAtoi(k) == INT_MIN);
    assert(myAtoi(l) == INT_MIN);
    assert(myAtoi(m) == INT_MIN);
    return 0;
}
