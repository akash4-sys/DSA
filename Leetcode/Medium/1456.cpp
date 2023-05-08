#include "../../headers.h"

class Solution
{
    unordered_map<char, int> vowel = {{'a', 1}, {'e', 1}, {'i', 1}, {'o', 1}, {'u', 1}};
public:
    int maxVowels(string s, int k)
    {
        int cnt = 0, ans = 0;
        for (int i = 0; i < k; i++)
            cnt += vowel.count(s[i]);
        
        ans = cnt;
        for (int i = 1; i <= s.size() - k + 1; i++)
        {
            cnt -= vowel.count(s[i - 1]);
            cnt += vowel.count(s[i + k - 1]);
            ans = max(ans, cnt);
        }
        return ans;
    }
};