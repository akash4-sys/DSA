#include "../../headers.h"

// @ binary exponentiation
// @ muliplicative inverse


#define ll long long
class Solution
{
    int mod = 1e9 + 7, factorial[100002];
    void generateFact()
    {
        factorial[0] = factorial[1] = 1;
        for (int i = 2; i <= 100001; i++)
            factorial[i] = modMul(factorial[i - 1], i);
    }

    int modMul (int a, int b)
    {
        return ((ll)(a % mod) * (b % mod)) % mod;
    }

    int binaryExponentiation(int a, int b)
    {
        if (!b)
            return 1;
        int res = binaryExponentiation(a, b / 2);
        if (b & 1)
            return modMul(a, modMul(res, res));
        return modMul(res, res);
    }

    // @ Iterative binary exponentiation - not working can't figure out why
    // int binaryExponentiation(int a, int b) 
    // {
    //     int res = 1;
    //     while (b)
    //     {
    //         if (b % 2)
    //             res = modMul(res, res);
    //         a = modMul(a, a);
    //         b /= 2;
    //     }
    //     return res;
    // }

    int modMulInv(int n)
    {
        return binaryExponentiation(n, mod - 2);
    }

public:
    int countAnagrams(string r)
    {
        generateFact();
        int ans = 1;
        istringstream ss(r);
        string s;
        while (ss >> s)
        {
            int ch[26] = {0}, fact = 1, total = factorial[s.size()];
            for (char c : s)
                ch[c - 'a']++;

            for (int i = 0; i < 26; i++)
                fact = modMul(fact, factorial[ch[i]]);
            int perms = modMul(total, modMulInv(fact));
            ans = modMul(ans, perms);
        }
        return ans;
    }
};


// Simple solution
// Time complexity - O(N)
// Space Complexity - O(N)

class Solution
{
    ll factorial(ll n)
    {
        ll fact = 1;
        for (int i = 2; i <= n; i++)
            fact = fact * i;
        return fact;
    }

public:
    int countAnagrams(string r)
    {
        ll ans = 1, mod = 1e9 + 7;
        istringstream ss(r);
        string s;
        while (ss >> s)
        {
            int ch[26] = {0};
            for (char c : s)
                ch[c - 'a']++;
            
            ll fact = 1;
            for (int i = 0; i < 26; i++)
                fact *= factorial(ch[i]);
            ans = (ans * (factorial(s.length()) / fact)) % mod;
        }
        return ans;
    }
};