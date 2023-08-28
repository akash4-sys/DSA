#include "headers.h"

// Time Complexity - O(N)
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