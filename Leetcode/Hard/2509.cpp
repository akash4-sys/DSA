#include "../../headers.h"

// Time Complexity - (NlogN)
// Space Complexity - O(1)

class Solution
{
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>> &queries)
    {
        vector<int> ans;
        for (auto q : queries)
        {
            int c = 1;
            while (q[0] != q[1])
            {
                if (q[0] < q[1])
                    swap(q[0], q[1]);
                q[0] /= 2;
                c++;
            }
            ans.push_back(c);
        }
        return ans;
    }
};


// Time Complexity - (NlogN)
// Space Complexity - O(N)

class Solution
{
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>> &queries)
    {
        vector<int> ans;
        for (auto q : queries)
        {
            vector<int> x, y;
            for (; q[0] > 0; q[0] /= 2)
                x.push_back(q[0]);
            for (; q[1] > 0; q[1] /= 2)
                y.push_back(q[1]);

            int l = x.size() - 1, r = y.size() - 1;
            while (l >= 0 && r >= 0 && x[l] == y[r])
                l--, r--;

            ans.push_back(l + r + 3); // +3 coz l and r both are index so +2 from there and +1 for entire path
        }
        return ans;
    }
};