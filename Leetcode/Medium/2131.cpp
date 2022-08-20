#include "../../headers.h"

class Solution {
public:
    int longestPalindrome(vector<string>& words) 
    {
        int ans = 0, l = 0;
        unordered_map<string, int> umap;
        for(string s: words)
            umap[s]++;
        
        for(auto mp: umap)
        {
            string r = mp.first, s = mp.first;
            reverse(r.begin(), r.end());
            if(s[0] == s[1])
            {
                if(mp.second % 2 == 0)
                    ans += (mp.second * 2), umap[s] = 0;
                else
                    ans += ((mp.second - 1) * 2), umap[s] = 1, l = 2;
            }
            else if(umap.count(r))
            {
                int mini = min(umap[r], mp.second);
                ans += (mini * 4);
                umap[r] -= mini;
                umap[s] -= mini;
            }
        }
        return ans + l;
    }
};