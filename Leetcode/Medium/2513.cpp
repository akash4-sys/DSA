#include "../../headers.h"

// Mathematical

#define ll long long
class Solution
{
    bool check(ll x, ll y, ll a, ll b, ll n) // needs ll for x and y otherwise lcm will overflow
    {
        ll p = n / x;
        ll _p = n - p;
        ll q = n / y;
        ll _q = n - q;
        ll pIq = n / lcm(x, y);
        ll pUq = p + q - pIq;
        ll _pI_q = n - pUq;
        ll arr1 = (_p - _pI_q >= a) ? 0 : a - (_p - _pI_q);
        ll arr2 = (_q - _pI_q >= b) ? 0 : b - (_q - _pI_q);
        return (_pI_q >= arr1 + arr2);
    }

public:
    int minimizeSet(int x, int y, int a, int b)
    {
        ll l = 1, h = 1e17;
        while (h > l + 1)
        {
            ll mid = (l + h) / 2;
            if (check(x, y, a, b, mid))
                h = mid;
            else
                l = mid;
        }
        return h;
    }
};



// Same thing as above
class Solution
{
    int getMax(int b, long long x, long long y = 1)
    {
        long long d = lcm(x, y);
        return b + b / (d - 1) - (b % (d - 1) ? 0 : 1);
    }

public:
    int minimizeSet(int x, int y, int a, int b2)
    {
        return max({getMax(a, x), getMax(b2, y), getMax(a + b2, x, y)});
    }
};

// @lc app=leetcode id=2513 lang=cpp