#include "../../headers.h"

// @ binary indexed tree

// Time Complexity - O(NlogN)
// Space Complexity - O(N)

class Solution
{
    void update(vector<int> &bit, int i, int val)
    {
        for (; i < bit.size(); i += (i & (-i)))
            bit[i] += val;
    }

    int getSum(vector<int> &bit, int i, int sum = 0)
    {
        for (; i > 0; i -= (i & (-i)))
            sum += bit[i];
        return sum;
    }

public:
    vector<int> processQueries(vector<int> &qr, int n)
    {
        vector<int> bit((2 * n) + 1, 0), ans;
        unordered_map<int, int> hmap;

        for (int i = 1; i <= n; i++)
            hmap[i] = i + n, update(bit, i + n, 1);

        for (int q : qr)
        {
            ans.emplace_back(getSum(bit, hmap[q]) - 1);
            update(bit, hmap[q], -1);
            update(bit, n, 1);
            hmap[q] = n;
            n--;
        }
        return ans;
    }
};

// Time Complexity - O(N^2)
// Space Complexity - O(N)

class Solution
{
public:
    vector<int> processQueries(vector<int> &qr, int n)
    {
        vector<int> v(n), ans;
        iota(v.begin(), v.end(), 1);
        for (int q : qr)
        {
            auto p = find(v.begin(), v.end(), q);
            v.erase(p);
            v.insert(v.begin(), q);
            ans.emplace_back(p - v.begin());
        }
        return ans;
    }
};