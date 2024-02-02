#include "limits.h"

int reverse(int x)
{
    int reversed = 0;
    while (x != 0)
    {
        if (x > 0)
        {
            if (INT_MAX / 10 < reversed || INT_MAX - (x % 10) < reversed * 10)
            {
                return 0;
            }
        } else
        {
            if (INT_MIN / 10 > reversed || INT_MIN - (x % 10) > reversed * 10)
            {
                return 0;
            }
        }
        reversed *= 10;
        reversed += x % 10;
        x /= 10;
    }
    return reversed;
}

int main(void)
{
    reverse(-0x7fffffff + 7);
    return 0;
}