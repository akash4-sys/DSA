#include "../../headers.h"

class Fancy
{
    long inc = 0, mul = 1, mod = 1e9 + 7;
    vector<long> v;

    long modMulInv(long a, long b = 1e9 + 5)
    {
        long res = 1;
        for (; b; b >>= 1) {
            if (b & 1)
                res = (res * a) % mod;
            a = (a * a) % mod;
        }
        return res;
    }

public:
    Fancy() {}

    void append(int val) {
        long x = (((val - inc + mod) % mod) * modMulInv(mul)) % mod;
        v.push_back(x);
    }

    void addAll(int val) {
        (inc += val) %= mod;
    }

    void multAll(int m) {
        (mul *= m) %= mod;
        (inc *= m) %= mod;
    }

    int getIndex(int i)
    {
        if (i >= v.size())
            return -1;
        return ((1LL * v[i] * mul) % mod + inc) % mod;
    }
};