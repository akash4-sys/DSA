#include "../../headers.h"

// Time Complexity - O(N^2) Runtime 250 ms
class Solution
{
    bool isgood(string &w, vector<int> ch)
    {
        for(char c: w)
            if(ch[c - 'a'] <= 0)
                return 0;
            else ch[c - 'a']--;
        return 1;
    }

    int getScore(string &w, vector<int> &ch, vector<int> &v, int sc = 0)
    {
        for(char c: w)
            ch[c - 'a']--, sc += v[c - 'a'];
        return sc;
    }

public:
    int maxScoreWords(vector<string> &w, vector<char> &letters, vector<int> &v)
    {
        vector<int> ch(26, 0);
        for(char l: letters)
            ch[l - 'a']++;
        
        int ans = 0, n = w.size();
        for(int i = 1; i < (1 << n); i++)
        {
            int currSC = 0;
            vector<int> temp = ch;
            for(int j = 0; j < n; j++)
                if(i & (1 << j) && isgood(w[j], temp))
                    currSC += getScore(w[j], temp, v);
            ans = max(ans, currSC);
        }
        return ans;
    }
};



// Time Complexity is far better in this case Runtime 7ms
class Solution
{
    bool isgood(string &w, vector<int> ch)
    {
        for(char c: w)
            if(ch[c - 'a'] <= 0)
                return 0;
            else ch[c - 'a']--;
        return 1;
    }

    int getScore(string &w, vector<int> &ch, vector<int> &v, int sc = 0)
    {
        for(char c: w)
            ch[c - 'a']--, sc += v[c - 'a'];
        return sc;
    }

    int recurse(vector<string> &w, vector<int> &ch, vector<int> &v, int ans, int i)
    {
        if(i >= w.size())
            return ans;
        vector<int> temp = ch;
        if(isgood(w[i], ch))
        {
            int currSC = getScore(w[i], temp, v);
            return max(recurse(w, temp, v, ans + currSC, i + 1), recurse(w, ch, v, ans, i + 1));
        }
        return recurse(w, ch, v, ans, i + 1);
    }

public:
    int maxScoreWords(vector<string> &w, vector<char> &letters, vector<int> &v)
    {
        vector<int> ch(26, 0);
        for(char l: letters)
            ch[l - 'a']++;
        return recurse(w, ch, v, 0, 0);
    }
};


// @lc app=leetcode id=1255 lang=cpp