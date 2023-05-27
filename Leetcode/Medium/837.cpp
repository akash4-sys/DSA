#include "../../headers.h"

// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution
{
public:
    double new21Game(int n, int k, int maxPts)
    {
        if (!k || n >= k + maxPts)
            return 1.0;

        vector<double> prob(n + 1, 0);
        prob[0] = 1.0;
        double sum = 1.0, ans = 0.0;
        for (int i = 1; i <= n; i++)
        {
            prob[i] = sum / maxPts;
            if (i < k)
                sum += prob[i];
            else
                ans += prob[i];
            if (i - maxPts >= 0)
                sum -= prob[i - maxPts];
        }
        return ans;
    }
};

// Time Limit Exceeded

class Solution
{
public:
    double new21Game(int n, int k, int maxPts)
    {
        vector<double> prob(n + 1);
        prob[0] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= maxPts; j++)
                if (i - j >= 0 && i - j < k)
                    prob[i] += (prob[i - j] / maxPts);
        return accumulate(prob.begin() + k, prob.end(), 0.0);
    }
};