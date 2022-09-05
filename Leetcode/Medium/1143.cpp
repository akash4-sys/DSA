#include "../../headers.h"

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        string s, t;
        if(text1.length() >= text2.length())
            s = text1, t = text2;
        else
            s = text2, t = text1;
        
        int ans = 0, st = 0, prev = 0;
        for(int i = 0; i < t.length(); i++)
        {
            for(int j = st; j < s.length(); j++)
                if(t[i] == s[j])
                {
                    st = j + 1;
                    ans++;
                    break;
                }
        }
        return ans;
    }
};