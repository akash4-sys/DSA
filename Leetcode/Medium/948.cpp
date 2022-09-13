#include "../../headers.h"

class Solution
{
public:
    int bagOfTokensScore(vector<int> &t, int p)
    {
        if(!t.size())
            return 0;
        int score = 0, i = 0, j = t.size() - 1;
        if(i == j && p >= t[0])
            return 1;
        sort(t.begin(), t.end());
        if(p < t[0])
            return 0;
        while (i < j)
        {
            while (p >= t[i])
                p -= t[i++], score++;

            if (score > 0 && i < j)
                p += t[j--], score--;
        }
        return score + (i == j && p >= t[i]);
    }
};