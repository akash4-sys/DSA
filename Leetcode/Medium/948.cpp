#include "../../headers.h"

class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        sort(tokens.begin(), tokens.end());
        int score = 0, ans = 0, n = tokens.size();
        for (int l = 0, r = n - 1; l <= r && score >= 0; r--)
        {
            while (l <= r && tokens[l] <= power)
                power -= tokens[l++], score++;

            ans = max(ans, score);
            power += tokens[r];
            score--;
        }
        return ans;
    }
};