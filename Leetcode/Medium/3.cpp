#include "../../headers.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string sub = "";
        int curr = 0, ans = 0;
        for(int i = 0; i < s.length(); i++)
        {
            int found = sub.find(s[i]);
            if(found == string::npos)
            {
                sub += s[i];
                curr += 1;
            }
            else{
                ans = max(curr, ans);
                string r = sub.substr(found+1);
                curr = r.length() + 1;
                sub = r + s[i];
            }
        }
        ans = max(curr, ans);
        return ans;
    }
};