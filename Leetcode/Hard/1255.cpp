#include "../../headers.h"

class Solution
{
public:
    int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score)
    {
        vector<int> ch(26, 0);
        for (char &c : letters)
            ch[c - 'a']++;
        
        function<int(int)> rec = [&](int i) -> int {
            if (i == words.size())
                return 0;
            
            int res = rec(i + 1), canTake = 1, sum = 0;
            for (char &c : words[i]) {
                if (ch[c - 'a'] == 0)
                    canTake = 0;
                sum += score[c - 'a'];
                ch[c - 'a']--;
            }
            
            res = max(res, canTake ? rec(i + 1) + sum : 0);
            for (char &c : words[i])
                ch[c - 'a']++;
            return res;
        };
        return rec(0);
    }
};