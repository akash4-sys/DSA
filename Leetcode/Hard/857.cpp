#include "../../headers.h"

class Solution
{
public:
    double mincostToHireWorkers(vector<int> &qa, vector<int> &wg, int k)
    {
        vector<pair<double, double>> v(wg.size());
        for (int i = 0; i < wg.size(); i++)
            v[i] = {(double)wg[i] / qa[i], (double)qa[i]};

        sort(v.begin(), v.end());
        double ans = DBL_MAX, sum = 0;
        priority_queue<int> pq;
        for (auto [r, q]: v)
        {
            pq.push(q);
            sum += q;
            if (pq.size() > k)
                sum -= pq.top(), pq.pop();
            if (pq.size() == k)
                ans = min(ans, sum * r);
        }
        return ans;
    }
};