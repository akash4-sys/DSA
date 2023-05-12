#include "../../headers.h"

// Time Complexity - O(1)
// Space Complexity - O(1)

class Solution
{
public:
    int findIntegers(int n)
    {
        int fib[32] = {0};
        fib[0] = 1, fib[1] = 2;
        for (int i = 2; i < 32; i++)
            fib[i] = fib[i - 1] + fib[i - 2];
        
        int ans = 0, prev = 0;
        for (int i = 30; i >= 0; i--)
        {
            if (n & (1 << i))
            {
                ans += fib[i];
                if (prev)
                    return ans;
            }
            prev = n & (1 << i);
        }
        return ans + 1;
    }
};


// Time Complexity - O(log(N) * numOfIntOfLen(x) * 32)
// Space Complexity - O(1)

#define ll long long
#define vv vector<vector<ll>>

class Solution
{
    vv mul(vv &a, vv &b)
    {
        vv res = {{0, 0}, {0, 0}};
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    res[i][j] += (a[i][k] * b[k][j]);
        return res;
    }

    ll matrixExponentiation(ll n)
    {
        vv ans = {{1, 0}, {0, 1}}, m = {{1, 1}, {1, 0}};
        for (; n > 0; n /= 2, m = mul(m, m))
            if (n & 1)
                ans = mul(ans, m);
        return ans[0][1];
    }

public:
    int findIntegers(int n)
    {
        int len = 32 - __builtin_clz(n);
        int ans = matrixExponentiation(len + 2);
        for (int num = (1 << len) - 1; num > n; num--)
        {
            bool noConsecutiveOne = 1;
            for (int i = 1; i < 32; i++)
                if (num & (1 << i) && num & (1 << (i - 1)))
                    noConsecutiveOne = 0;
            ans -= noConsecutiveOne;
        }
        return ans;
    }
};