#pragma once

#include <string>
using namespace std;

#define ll long long

class RabinKarp
{
    ll mod = 1e9 + 7, ch = 26;

public:
    pair<int, int> genHash(string &s, string &p)
    {
        ll pHash = 0, sHash = 0;
        for (int i = 0; i < p.size(); i++)
        {
            pHash = ((ch * pHash) + p[i]) % mod;
            sHash = ((ch * sHash) + s[i]) % mod;
        }
        return {sHash, pHash};
    }
};