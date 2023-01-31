#include "../headers.h"

void diff(int n)
{
    long long sum = 0, sqsum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
        sqsum += (i * i);
    }
    sum *= sum;
    cout<<sum - sqsum<<endl;
}

void diff2(int n)
{
    long long sum = n * (n + 1) / 2;
    long long sumsq = ((2LL * n) + 1) * (n + 1) * n / 6;
    sum *= sum;
    cout << sum - sumsq<<endl;
}

int main()
{
    diff(100);
    return 0;
}