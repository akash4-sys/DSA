#include "../../headers.h"


class Solution
{
    int k;
    string recurse(string s, int st)
    {
        k -= (st == s.size());
        if (!k)
            return s;
        for (int i = st; i < s.size(); i++)
        {
            swap(s[i], s[st]); 
            string r = recurse(s, st + 1);
            if (r != "")
                return r;
        }
        return "";
    }

public:
    string getPermutation(int n, int k)
    {
        string s = "";
        for (int i = 1; i <= n; i++)
            s += to_string(i);
        
        this->k = k;
        return recurse(s, 0);
    }
};

class Solution
{
    vector<string> v;
    void recurse(string s, int st)
    {
        if (st == s.size())
            v.push_back(s);
        for (int i = st; i < s.size(); i++)
            swap(s[i], s[st]), recurse(s, st + 1);
    }

public:
    string getPermutation(int n, int k)
    {
        string s = "";
        for (int i = 1; i <= n; i++)
            s += to_string(i);
        recurse(s, 0);
        return v[k - 1];
    }
};