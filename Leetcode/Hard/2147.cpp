#include "../../headers.h"

class Solution
{
public:
    int numberOfWays(string &s)
    {
        long long mod = 1e9 + 7, ans = 1, j = 0, k = 0;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == 'S')
            {
                if (++k > 2 && k % 2 == 1)
                    ans = (ans * (i - j)) % mod;
                j = i;
            }
        return k % 2 || !k ? 0 : ans;
    }
};


class Solution
{
public:
    int numberOfWays(string &s)
    {
        long long mod = 1e9 + 7, ans = 1, seat = 0, plant = 0, totseat = 0;
        for (char &c : s)
        {
            totseat += c == 'S';
            seat += c == 'S';
            if (seat == 2)
                plant += c == 'P';
            if (seat == 3) {
                ans = (ans * (plant + 1)) % mod;
                plant = 0, seat = 1;
            }
        }
        return (totseat % 2 || !totseat) ? 0 : ans;
    }
};