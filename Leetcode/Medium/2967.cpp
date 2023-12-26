#include "../../headers.h"

class Solution
{
    int isPalindrome(int n)
    {
        int num = n, rev = 0;
        for (; n; n /= 10)
            rev = (rev * 10) + (n % 10);
        return rev == num;
    }

    long long lessThan(int x) {
        for (; !isPalindrome(x); x--);
        return x;
    }

    long long greaterThan(int x)
    {
        if (x == 1e9)
            return -1;
        for (; !isPalindrome(x); x++);
        return x;
    }

    long long calcCost(vector<int> &v, int x)
    {
        long long ans = 0;
        for (int a : v)
            ans += abs(a - x);
        return ans;
    }

    long long cost(vector<int> &v, int x)
    {
        long long a = lessThan(x), b = greaterThan(x);
        return min(calcCost(v, a), b != -1 ? calcCost(v, b) : LLONG_MAX);
    }

public:
    long long minimumCost(vector<int> &v)
    {
        sort(v.begin(), v.end());
        int n = v.size();
        long long ans = cost(v, v[n / 2]);
        return n % 2 ? ans : min(ans, cost(v, v[(n / 2) - 1]));
    }
};