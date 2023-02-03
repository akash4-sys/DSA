#include "../headers.h"

bool isPrime(int n)
{
    if (n == 1)
        return 0;
    for (int i = 2, sq = sqrt(n); i <= sq; i++)
        if (n % i == 0)
            return 0;
    return 1;
}

void nthPrime(int n)
{
    int c = 2, x = 0;
    while (c < n)
    {
        x += 6;
        c += isPrime(x + 1);
        c += isPrime(x - 1);
    }
    cout << x + 1 << endl;
}

int main()
{
    nthPrime(10001);
    return 0;
}