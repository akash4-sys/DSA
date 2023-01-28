#include "../../headers.h"

// Time Complexity - O(NlogN)
// Space Complexity - O(1)
class Solution
{
public:
    int minOperations(vector<int> &v, vector<int> &b)
    {
        int g = b[0];
        for (int a: b)
            g = gcd(g, a);

        sort(v.begin(), v.end());
        for (int i = 0; i < v.size() && v[i] <= g; i++)
            if (g % v[i] == 0)
                return i;
        return -1;
    }
};


// Time Complexity - O(N^2)
// Space Complexity - O(N)

class Solution
{
public:
    int minOperations(vector<int> &a, vector<int> &b)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int n : a)
            pq.push(n);

        int d = 0;
        while (!pq.empty())
        {
            int x = pq.top(), all = 1;
            pq.pop();
            for (int n : b)
                if (n % x != 0)
                {
                    all = 0;
                    break;
                }

            if (all)
                return d;
            d++;
        }
        return -1;
    }
};