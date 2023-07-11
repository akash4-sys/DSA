#include "../../headers.h"

class Solution
{
public:
    int largestVariance(string s)
    {
        int ans = 0, ch[26] = {0};
        for (char c : s)
            ch[c - 'a']++;

        for (char a = 'a'; a <= 'z'; a++)
            for (char b = 'a'; b <= 'z'; b++)
                if (a != b && ch[a - 'a'] && ch[b - 'a'])
                {
                    int x = 0, y = 0, rb = ch[b - 'a'];
                    for (char c : s)
                    {
                        x += c == a;
                        if (c == b)
                            y++, rb--;
                        if (y)
                            ans = max(ans, x - y);
                        if (x < y && rb)
                            x = y = 0;
                    }
                }
        return ans;
    }
};

class Solution
{
public:
    int largestVariance(string s)
    {
        int ans = 0;
        vector<int> ch(26, 0);
        for (int i = 0; i < s.size(); i++)
        {
            ch[s[i] - 'a']++;
            vector<int> win = ch;
            for (int j = 0; j <= i; j++)
            {
                int mn = INT_MAX, mx = INT_MIN;
                for (int c = 0; c < 26; c++)
                    if (win[c])
                        mn = min(mn, win[c]), mx = max(mx, win[c]);
                win[s[j] - 'a']--;
                ans = max(ans, mx - mn);
            }
        }
        return ans;
    }
};