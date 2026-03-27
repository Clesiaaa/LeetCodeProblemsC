#include <string.h>

int numJewelsInStones(char *j, char *s)
{
    int cnt[256] = {0};  // enough for all ASCII chars
    int sol = 0;

    // mark jewels
    for (int i = 0; j[i]; i++)
        cnt[(unsigned char)j[i]] = 1;

    // count stones
    for (int i = 0; s[i]; i++)
        sol += cnt[(unsigned char)s[i]];

    return sol;
}