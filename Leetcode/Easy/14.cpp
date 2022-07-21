#include "../../headers.h"

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "", s = strs[0];
        for(int i = 0; i < s.length(); i++)
        {
            int j = 0;
            while(j < strs.size()) 
            {
                if(strs[j][i] != s[i])
                    return ans;
                j++;
            }
            ans += s[i];
        }
        return ans;
    }
};