#include "../../headers.h"

typedef pair<int, char> p;

class Solution
{
public:
    void decrementAll(vector<int> interval, int curr, int x)
    {
        for (int i = 0; i < 26; i++)
            if (i != curr && interval[i] != 0)
                interval[i] -= x;
    }

    int leastInterval(vector<char> &tasks, int n)
    {
        int ans = 0, cnt = 0;
        unordered_map<char, int> umap;
        vector<int> interval(26, 0);

        for (char c : tasks)
            umap[c]++;

        while (cnt < tasks.size())
        {
            bool flag = true;
            for (auto x : umap)
            {
                int curr = x.first - 'A';
                if (x.second && interval[curr] == 0)
                {
                    ans++;
                    umap[x.first]--;
                    interval[curr] += n;
                    decrementAll(interval, curr, 1);
                    ++cnt;
                    flag = false;
                }
            }
            if (flag)
            {
                int x = *min_element(interval.begin(), interval.end());
                decrementAll(interval, -1, x),
                ans+=x;
            }
        }
        return ans;
    }
};