#ifdef __INTELLISENSE__
#include "../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

int bucketNum(int x)
{
    x -= x % 100 == 0;
    return x / 100;
}

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> employee(n), buckets(1e7, 0);
    map<int, int> salary_freq;

    for (int i = 0; i < n; i++)
    {
        cin >> employee[i];
        salary_freq[employee[i]]++;
        buckets[bucketNum(employee[i])]++;
    }
    
    return 0;
}