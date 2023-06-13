#include "../../headers.h"

class Solution
{
public:
    int calPoints(vector<string> &v)
    {
        vector<int> sc(1, 0);
        for (auto &s : v)
        {
            int n = sc.size();
            if (s == "+")
                sc.push_back(sc[n - 1] + sc[n - 2]);
            else if (s == "C")
                sc.pop_back();
            else if (s == "D")
                sc.push_back(sc.back() * 2);
            else
                sc.push_back(stoi(s));
        }
        return accumulate(sc.begin(), sc.end(), 0LL);
    }
};