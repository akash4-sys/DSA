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


// Time Complexity - O(NSqrt(N))
// Space Complexity - O(Sqrt(N))

class Solution
{
    void commonFactors(vector<int> &v, unordered_set<int> &st)
    {
        int g = v[0];
        for (int i = 1; i < v.size(); i++)
            g = gcd(v[i], g);
        for (int i = 1; i * i <= g; i++)
            if (g % i == 0)
            {
                st.insert(i);
                if (g / i != i)
                    st.insert(g / i);
            }
    }

public:
    int minOperations(vector<int> &v, vector<int> &div)
    {
        sort(v.begin(), v.end());
        unordered_set<int> st;
        commonFactors(div, st);
        for (int i = 0; i < v.size(); i++)
            if (st.count(v[i]))
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