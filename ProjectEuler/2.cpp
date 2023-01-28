#include "../headers.h"
// #include <bits/stdc++.h>

// @ https://www.xarg.org/puzzle/project-euler/problem-2/

// Brute Force
void sfib(int n)
{
    long long l = 1, ll = 1, sum = 0;
    while (l <= n)
    {
        long long curr = ll + l;
        ll = l;
        l = curr;
        if (l % 2 == 0)
            sum += l;
    }
    cout<<sum<<endl;
}

void onlyEvenFib(long long n)
{
    long long l = 2, ll = 0, sum = 0, curr = 2;
    while (l <= n)
    {
        sum += curr;
        curr = ll + 4 * l;
        ll = l;
        l = curr;
    }
    cout<<sum<<endl;
}

// There's one O(1) way to do it
// Using Binet's formula
// Too Complicated

int main()
{
    sfib(4e6);
    return 0;
}