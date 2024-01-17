#include "../../headers.h"

class Solution
{
public:
    int maximumLength(string &s)
    {
        int cnt = 0, p = s[0], ans = 0;
        vector<priority_queue<int>> ch(26);
        for (char &c : s)
            if (c != p)
                ch[p - 'a'].push(cnt), cnt = 1, p = c;
            else
                cnt++;
        ch[p - 'a'].push(cnt);
        
        for (int i = 0; i < 26; i++)
        {
            vector<int> max3(3, 0);
            for (int k = 0; k < 3 && !ch[i].empty(); k++)
                max3[k] = ch[i].top(), ch[i].pop();
            
            if (max3[0] == max3[1] && max3[0] > max3[2])
                max3[1]--;
            if (max3[0] + max3[1] + max3[2] >= 3)
                ans = max({ans, max3[0] - 2, max3[1]});
        }
        return ans == 0 ? -1 : ans;
    }
};