#include "../../headers.h"

// Time Complexity - O(N^2logN)
// Space Complexity - O(N)

class Solution
{
public:
    vector<string> simplifiedFractions(int n)
    {
        vector<string> ans;
        for (int i = 1; i < n; i++)
            for (int j = 1; j <= n; j++)
                if (i / j < 1 && gcd(i, j) == 1)
                    ans.push_back(to_string(i) + "/" + to_string(j));
        return ans;
    }
};

// Time Complexity - O(N^3)
// Space Complexity - O(N)

class Solution
{
    vector<string> ans;
    void checkFrac(int i, int j)
    {
        for (int k = 2; k <= j; k++)
            if (i % k == 0 && j % k == 0)
                return;
        ans.push_back(to_string(i) + "/" + to_string(j));
    }

public:
    vector<string> simplifiedFractions(int n)
    {
        for (int i = 1; i < n; i++)
            for (int j = 1; j <= n; j++)
                if (i / j < 1)
                    checkFrac(i, j);
        return ans;
    }
};