#include "headers.h"

// Time Complexity - O(nlogn)
// Space Complexity - O(N)

class Solution
{
public:
    int mostFrequentEven(vector<int> &v)
    {
        auto even_end = remove_if(begin(v), end(v), [](int n){ return n % 2; });
        sort(begin(v), even_end);
        int cnt = 0, max_cnt = 0, ans = -1;
        for(auto it = begin(v); it != even_end; ++it)
        {
            cnt = it != begin(v) && *it == *prev(it) ? cnt + 1 : 1;
            ans = max_cnt < cnt ? *it : ans;
            max_cnt = max(max_cnt, cnt);
        }
        return ans;
    }
};



// Time Complexity - O(nlogn)
// Space Complexity - O(N)

class Solution
{
public:
    int mostFrequentEven(vector<int> &v)
    {
        map<int, int> mp;
        for(int n: v)
            if(n % 2 == 0)
                mp[n]++;

        if(!mp.size())
            return -1;
        
        int ans, f = 0;
        for(auto x: mp)
            if(x.second > f)
                ans = x.first, f = x.second;

        return ans;
    }
};