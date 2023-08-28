#include "../headers.h"

class Solution
{
    string minStr(string a, string b)
    {
        return (a.size() < b.size() || (a.size() == b.size() && a < b) ) ? a : b;
    }

    string combine(string &a, string &b)
    {
        if (b.find(a) != string::npos)
            return b;
        for (int i = 0; i < a.size(); ++i)
        {
            string t1 = a.substr(i), t2 = b.substr(0, t1.size());
            if (t1 == t2)
                return a + b.substr(t1.size());
        }
        return a + b;
    }
    string solve(string& a, string& b, string& c)
    { 
        string t1 = combine(a, b), t2 = combine(b, a);
        return minStr(minStr(combine(t1, c), combine(c, t1)),
            minStr(combine(t2, c), combine(c, t2)));
    }

public:
    string minimumString(string a, string b, string c)
    { 
        return minStr(minStr(solve(a, b, c), solve(b, c, a)), solve(c, a, b));
    }
};



class Solution
{
    string combineFromFront(string &a, string &b)
    {
        for (int i = 0; i < b.size(); i++)
        {
            int j = i;
            for (int k = 0; k < a.size() && j < b.size() && b[j] == a[k]; k++, j++);
            if (j == b.size())
                return b.substr(0, i) + a;
        }
        return b + a;
    }

    string combineFromBack(string &a, string &b)
    {
        for (int i = b.size() - 1; i >= 0; i--)
        {
            int j = i;
            for (int k = a.size() - 1; k >= 0 && j >= 0 && b[j] == a[k]; k--, j--);
            if (j == -1)
                return a + b.substr(i + 1);
        }
        return a + b;
    }

    string combineTo(string &a, string &b)
    {
        if (a.find(b) != string::npos)
            return a;
        string s = combineFromFront(a, b), r = combineFromBack(a, b);
        if (s.size() == r.size())
            return min(s, r);
        return (s.size() < r.size()) ? s : r;
    }

    string combine(string a, string b)
    {
        string s = combineTo(a, b), r = combineTo(b, a);
        if (s.size() == r.size())
            return min(s, r);
        return (s.size() < r.size()) ? s : r;
    }

public:
    string minimumString(string a, string b, string c)
    {
        string p = combine(combine(a, b), c), q = combine(a, combine(b, c)), r = combine(b, combine(a, c));
        int n = min({p.size(), q.size(), r.size()});

        vector<string> v;
        if (p.size() == n)
            v.push_back(p);
        if (q.size() == n)
            v.push_back(q);
        if (r.size() == n)
            v.push_back(r);
        sort(v.begin(), v.end());
        return v[0];
    }
};