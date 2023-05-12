#pragma once
#include <vector>
using namespace std;

// @ A example of matrix exponentiation
// nth term in fibonacci series - in O(logN) time

#define ll long long
#define vv vector<vector<ll>>

vv mul(vv &a, vv &b)
{
    ll mod = 1e9 + 7;
    vv res = {{0, 0}, {0, 0}};
    
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                (res[i][j] += (a[i][k] * b[k][j])) %= mod;

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