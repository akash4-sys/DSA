#include "headers.h"

class Solution
{
public:
    int getCommon(vector<int> &a, vector<int> &b)
    {
        for (int i = 0, j = 0; i < a.size() && j < b.size();)
        {
            if (a[i] == b[j])
                return a[i];
            if (a[i] > b[j])
                j++;
            else i++;
        }
        return -1;
    }
};


class Solution
{
public:
    int getCommon(vector<int> &a, vector<int> &b)
    {
        map<int, int> ump, umb;
        for (int n : a)
            ump[n] = 1;
        for (int n : b)
            umb[n] = 1;
        for (auto [n, _]: ump)
            if (umb.count(n))
                return n;
        return -1;
    }
};