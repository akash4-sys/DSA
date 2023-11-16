#include "../../headers.h"

class Solution
{
public:
    int eliminateMaximum(vector<int> &d, vector<int> &s)
    {
        vector<double> time;
        for (int i = 0; i < d.size(); i++)
            time.push_back(d[i] / (s[i] * 1.0));
        
        sort(time.begin(), time.end());
        double ans = 1;
        for (int i = 1; i < time.size() && time[i] - i > 0; i++)
            ans++;
        return ans;
    }
};