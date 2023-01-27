#include "../headers.h"
// #include <bits/stdc++.h>

// Brute Force
void fib(int n)
{
    long long l = 1, ll = 1, sum = 0;
    for (long long i = 3; i <= n; i++)
    {
        long long curr = ll + l;
        ll = l;
        l = curr;
        if (l % 2 == 0)
            sum += l;
    }
    cout<<sum<<endl;
}

int main()
{
    fib(4e6);
    return 0;
}