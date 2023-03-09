#include "../../headers.h"

// Time Complexity - O(N * 26)
// Space Complexity - O(1)

class Solution 
{
public:
    vector<int> findAnagrams(string s, string p) 
    {
        if (p.size() > s.size())
            return {};

        vector<int> ans, a(26, 0), b(26, 0);
        for (int i = 0; i < p.size(); i++)
        {
            a[s[i] - 'a']++; 
            b[p[i] - 'a']++;
        }
        
        if (a == b)
            ans.push_back(0);
        for (int i = 1; i <= s.size() - p.size(); i++)
        {
            a[s[i - 1] - 'a']--;
            a[s[i + p.size() - 1] - 'a']++;
            if (a == b)
                ans.push_back(i);
        }
        return ans;
    }
};