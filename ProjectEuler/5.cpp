#include "../headers.h"

unordered_set<int> distinctPrimeFactors(int n)
{
    unordered_set<int> s;
    if (n == 2)
        s.insert(n);
    for (int i = 2, sq = sqrt(n); i <= sq; i++)
        for (; !(n % i); n /= i)
            s.insert(i);
    if (n > 2)
        s.insert(n);
    return s;
}

void largestDiv(int n)
{
    long long mul = 1;
    for (long long i = 1; i <= n; i++)
        if (mul % i != 0)
        {
            auto st = distinctPrimeFactors(i);
            for (auto x : st)
                mul = (mul * (long long)x);
        }
    cout<<mul<<endl;
}

void largestDivII(int n)
{
    int x = 1;
    for (int i = 1; i <= n; i++) 
        x = lcm(x, i);
    cout<<x<<endl;
}

int main()
{
    largestDiv(20);
    return 0;
}