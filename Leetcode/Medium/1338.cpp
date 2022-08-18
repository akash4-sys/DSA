#include "../../headers.h"

class Solution
{
public:
    int minSetSize(vector<int> &arr)
    {
        unordered_map<int, int> umap;
        for (int n : arr)
            umap[n]++;

        int ans = 0, cnt = 0;
        priority_queue<int> q;
        for (auto p : umap)
            q.push(p.second);

        while (cnt < (arr.size() / 2))
        {
            ans++;
            cnt += q.top();
            q.pop();
        }

        return ans;
    }
};