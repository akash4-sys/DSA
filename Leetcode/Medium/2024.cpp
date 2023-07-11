#include "../../headers.h"

class Solution
{
public:
    int maxConsecutiveAnswers(string s, int k)
    {
        int ans = 0, cnt[2] = {0};
        for (int i = 0; i < k; i++)
            cnt[s[i] == 'T']++;
        
        for (int r = k, l = 0; r < s.size(); r++)
        {
            cnt[s[r] == 'T']++;
            for (; min(cnt[0], cnt[1]) > k; l++)
                cnt[s[l] == 'T']--;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};