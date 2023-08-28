#include "../../headers.h"

// Time Complexity - O(N)
// Space Complexity - O(26)

class Solution
{
public:
    string reorganizeString(string s)
    {
        int ch[26] = {0}, n = s.size(), maxf = 0, maxCh = 0, i = 0;
        for (char &c : s)
            ch[c - 'a']++;

        for (int i = 0; i < 26; i++)
            if (ch[i] > maxf)
                maxf = ch[i], maxCh = i;

        if (maxf > (n + 1) / 2)
            return "";

        while (ch[maxCh]--)
            s[i] = char(maxCh + 'a'), i += 2;

        for (int c = 0; c < 26; c++)
            for (; ch[c] > 0; ch[c]--, i += 2)
            {
                i = (i >= s.size()) ? 1 : i;
                s[i] = char(c + 'a');
            }
        return s;
    }
};

// Time Complexity - O(NlogN)
// Space Complexity - O(26)


class Solution
{
public:
    string reorganizeString(string s)
    {
        priority_queue<pair<int, char>> pq;
        int ch[26] = {0}, n = s.size();
        for (char &c : s)
            ch[c - 'a']++;
        
        for (int i = 0; i < 26; i++)
            if (ch[i])
                pq.push({ch[i], char(i + 'a')});
        
        string ans = "";
        while (!pq.empty())
        {
            auto [f, c] = pq.top();
            pq.pop();
            if (ans.size() && ans.back() == c)
            {
                if (pq.empty())
                    return "";
                auto [sf, sc] = pq.top();
                pq.pop();
                ans += sc;
                if (--sf)
                    pq.push({sf, sc});
            }
            else
                ans += c, f--;
            if (f)
                pq.push({f, c});
        }
        return ans;
    }
};