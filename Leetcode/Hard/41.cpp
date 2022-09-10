#include "../../headers.h"

// Time Complexity - O(N)
// Space Complexity - O(1)

// Explanation-
// Swap x with the index x starting from 1 until x > 0 and x <= v.size()

class Solution
{
public:
    int firstMissingPositive(vector<int> &v)
    {
        for (int &n : v)
            while (n > 0 && n <= v.size() && v[n - 1] != n)
                swap(n, v[n - 1]);
        
        for(int i = 0; i < v.size(); i++)
            if(v[i] != i + 1)
                return i + 1;
        return v.size() + 1;
    }
};





class Solution
{
public:
    int firstMissingPositive(vector<int> &v)
    {
        for (int &n : v)
            n = max(n, 0);

        for (int &n : v)
        {
            int val = abs(n) - 1;
            if (val + 1 >= 1 && val + 1 <= v.size())
            {
                v[val] = min(v[val], v[val] * -1);
                if (v[val] == 0)
                    v[val] = -1 * (v.size() + 1);
            }
        }

        for (int i = 0; i <= v.size(); i++)
            if (v[i - 1] >= 0)
                return i;
        return v.size() + 1;
    }
};