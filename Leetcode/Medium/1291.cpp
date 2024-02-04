#include "../../headers.h"

class Solution
{
    string createStart(int n, char c) {
        if (n > 9)
            return string(11, '9');

        string s(1, c);
        while (s.size() < n)
            s += char(s.back() + 1);
        return s;
    }

public:
    vector<int> sequentialDigits(int low, int high)
    {
        vector<int> ans;
        string l = to_string(low);
        string s = l[0] != '9' ? createStart(l.size(), l[0]) : createStart(l.size() + 1, '1');

        for (long long x = stoll(s); x <= high; x = stoll(s))
        {
            if (x >= low)
                ans.push_back(x);
            if (s.back() < '9')
                s += char(s.back() + 1), s.erase(s.begin());
            else
                s = createStart(s.size() + 1, '1');
        }
        return ans;
    }
};