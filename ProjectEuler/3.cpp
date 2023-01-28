#include "../headers.h"

void factors(long long n)
{
    set<int> s;
    if (n == 2)
        s.insert(n);
    for (int i = 2, sq = sqrt(n); i <= sq; i++)
        for (; !(n % i); n /= i)
            s.insert(i);
    if (n > 2)
        s.insert(n);

    cout<<*s.rbegin()<<endl;
}

int main()
{
    long long n = 600851475143;
    factors(n);
}