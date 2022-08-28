#include "headers.h"

// Approach I could come up in Contest
// Time complexity - O(N^2)
// Space complexity - O(1)

class Solution
{
public:
    int garbageCollection(vector<string> &garbage, vector<int> &travel)
    {
        int g = 0, m = 0, p = 0, gt = 0, mt = 0, pt = 0, ans = 0;
        g += count(garbage[0].begin(), garbage[0].end(), 'G');
        m += count(garbage[0].begin(), garbage[0].end(), 'M');
        p += count(garbage[0].begin(), garbage[0].end(), 'P');
        ans = g + m + p;

        g = 0;
        m = 0;
        p = 0;

        for (int i = 1; i < garbage.size(); i++)
        {
            string s = garbage[i];
            g += count(s.begin(), s.end(), 'G');
            m += count(s.begin(), s.end(), 'M');
            p += count(s.begin(), s.end(), 'P');

            gt += travel[i - 1];
            mt += travel[i - 1];
            pt += travel[i - 1];
            if (g != 0)
            {
                ans += (g + gt);
                gt = 0;
                g = 0;
            }
            if (m != 0)
            {
                ans += (m + mt);
                mt = 0;
                m = 0;
            }
            if (p != 0)
            {
                ans += (p + pt);
                pt = 0;
                p = 0;
            }
        }
        return ans;
    }
};


// Clean Solution

// Time Complexity - O(N^2)
//  Space Complexity - O(1)

class Solution
{
public:
    int garbageCollection(vector<string> &garbage, vector<int> &travel)
    {
        int dist[3] = {}, mins = 0;
        partial_sum(travel.begin(), travel.end(), travel.begin());
        for(int i = 0; i < garbage.size(); i++)
        {
            for(char c: garbage[i])
            {
                int gid = (c == 'M') ? 0 : (c == 'P') ? 1 : 2;
                dist[gid]  = (i > 0) ? travel[i - 1] : 0;
                ++mins;
            }
        }
        return mins + accumulate(begin(dist), end(dist), 0);
    }
};