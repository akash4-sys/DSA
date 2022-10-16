#include "../../headers.h"

class Solution
{
public:
    int compress(vector<char> &v)
    {
        int i = 0;
        for(int j = 1, n = 1; j <= v.size(); j++, n++)
            if(j == v.size() || v[j] != v[j - 1])
            {
                v[i++] = v[j - 1];
                if(n != 1)
                    for(char ch: to_string(n))
                        v[i++] = ch;
                n = 0;
            }
        return i;
    }
};



// Time Complexity O(N)
// Space complexity O(N)
class Solution
{
public:
    int compress(vector<char> &v)
    {
        string s = "";
        int i = 0;
        while (i < v.size())
        {
            char c = v[i];
            s += c;
            int n = 0;
            for (; i < v.size() && c == v[i]; i++)
                n++;
            if (n != 1)
                s += to_string(n);
        }
        v.clear();
        for (char c : s)
            v.push_back(c);
        return s.size();
    }
};