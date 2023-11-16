#include "headers.h"

// Time Complexity - O(N)
// Space Complexity - O(N)

static unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
class Solution
{
public:
    string sortVowels(string s)
    {
        int v[58] = {0}, j = 0;
        for (char &c : s)
            if (vowels.find(tolower(c)) != vowels.end())
                v[c - 'A']++;
        
        for (int i = 0; i < 58; i++)
            while (v[i])
                if (vowels.find(tolower(s[j])) != vowels.end())
                    s[j++] = 'A' + i, v[i]--;
        return s;
    }
};

// Time Complexity - O(NlogN)
// Space Complexity - O(N)

class Solution
{
public:
    string sortVowels(string s)
    {
        unordered_map<char, int> mp = {{'a', 1}, {'e', 1}, {'i', 1}, {'o', 1}, {'u', 1}};
        string t(s.size(), '0'), r = "";

        for (int i = 0; i < s.size(); i++)
            if (!mp.count(tolower(s[i])))
                t[i] = s[i], s[i] = 'z' + 1;

        sort(s.begin(), s.end());
        for (int i = 0, j = 0; i < t.size(); i++)
            if (t[i] == '0')
                t[i] = s[j++];
        return t;
    }
};