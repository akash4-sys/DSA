#include "../../headers.h"

class Solution
{
public:
    int kthGrammar(int n, int k)
    {
        return __builtin_popcount(k - 1) & 1;
    }
};


class Solution
{
public:
    int kthGrammar(int n, int k)
    {
        int ans = 0;
        for (; k > 1; ans ^= 1)
            k = k % 2 ? k + 1 : k / 2;
        return ans;
    }
};


class Solution
{
    int rec(int n, int k)
    {
        if (!n)
            return 0;
        int m = 1 << (n - 1), res = rec(n - 1, k % m);
        return k >= m ? !res : res;
    }

public:
    int kthGrammar(int n, int k)
    {
        return rec(n - 1, k - 1);
    }
};