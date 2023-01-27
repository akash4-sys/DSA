#include "../headers.h"
// #include <bits/stdc++.h>

// @ Solution - https://www.xarg.org/puzzle/project-euler/problem-1/#:~:text=If%20we%20list%20all%20the,of%20these%20multiples%20is%2023

// If n is low
void low()
{
    int sum = 0;
    for (int i = 1; i < 1000; i++)
        if (i % 3 == 0 || i % 5 == 0)
            sum += i;
    cout << sum;
}

// If n is high
void high(int n)
{
    long long a = n / 3, x = a + 1;
    long long b = n / 5, y = b + 1;
    long long c = n / 15, z = c + 1;   // 15 is lcm of 3 and 5
    long long ans = (((3 * a * x) + (5 * b * y)) - (15 * c * z)) / 2;
    cout<<ans;
}

int main()
{
    // low();
    high(1000);
    return 0;
}
