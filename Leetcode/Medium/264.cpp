#include "../../headers.h"

#define ll long long
vector<int> ugly;
class Solution
{
    int m = INT_MAX;
public:
    int nthUglyNumber(int n)
    {
        if(ugly.empty())
        {
            for(ll i = 1; i <= m; i *= 2)
                for(ll j = i; j <= m; j *= 3)
                    for(ll k = j; k <= m; k *= 5)
                        ugly.emplace_back(k);
            sort(ugly.begin(), ugly.end());
        }
        return ugly[n-1];
    }
};


// All are tle down here
// A memoized approach where i pre generate value till 1690

vector<int> ugly;
int primes[3] = {2, 3, 5}, preRun = 1;
void preRunner()
{
    int cnt = 0, i = 1, n = 1690;
    while (i)
    {
        int x = i;
        for (int p : primes)
            while (x % p == 0)
                x = x / p;
        cnt += x == 1;
        if (x == 1)
            ugly.push_back(i);
        if (cnt == n)
            return;
        i++;
    }
}

// this was supposed to call the function when file starts executing but not actually working
// void(preRunner());

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        if(preRun)
            preRunner(), preRun = 0;
        return ugly[n - 1];
    }
};


// just memoizing till largest n and then continuing from it

vector<int> ugly;
class Solution
{
    int primes[3] = {2, 3, 5};
public:
    int nthUglyNumber(int n)
    {
        int cnt = 0, i = 1;
        if (ugly.size() >= n)
            return ugly[n - 1];
        if(!ugly.empty())
            i = ugly.back() + 1;
        while (i)
        {
            int x = i;
            for (int p : primes)
                while (x % p == 0)
                    x = x / p;
            cnt += x == 1;
            if (x == 1)
                ugly.push_back(i);
            if (cnt == n)
                return i;
            i++;
        }
        return -1;
    }
};