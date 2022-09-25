#include "headers.h"

// More clean way
class Solution
{
public:
    vector<int> goodIndices(vector<int> &v, int k)
    {
        int n = v.size();
        vector<int> inc(n, 1), dec(n, 1), ans;
        
        for (int i = 1; i < n; i++)
            if (v[i - 1] >= v[i])
                dec[i] = dec[i - 1] + 1;

        for (int i = n - 2; i >= 0; i--)
            if(v[i] <= v[i+1])
                inc[i] = inc[i + 1] + 1;

        for(int i = k; i < n - k; i++)
            if(dec[i - 1] >= k && inc[i + 1] >= k)
                ans.push_back(i);
        return ans;
    }
};


// Time complexity O(N)
// Space complexity - O(N)
class Solution
{
public:
    vector<int> goodIndices(vector<int> &v, int k)
    {
        int n = v.size();
        vector<int> ans;
        deque<int> inc, deq;
        int i = k;
        for (int j = i - k; j < i; j++)
        {
            if (deq.empty() || deq.back() >= v[j])
                deq.push_back(v[j]);
            else if (deq.back() < v[j])
                deq = {}, deq.push_back(v[j]);
        }
        for (int j = i + 1; j <= i + k && j < n; j++)
        {
            if (inc.empty() || inc.back() <= v[j])
                inc.push_back(v[j]);
            else if (inc.back() > v[j])
                inc = {}, inc.push_back(v[j]);
        }
        if (inc.size() == k && deq.size() == k)
            ans.push_back(i);

        for (i = k + 1; i < n - k; i++)
        {
            if (deq.size() > k - 1)
                deq.pop_front();
            if (inc.size() > k - 1)
                inc.pop_front();
            if (deq.empty() || deq.back() >= v[i - 1])
                deq.push_back(v[i - 1]);
            else
                deq = {}, deq.push_back(v[i - 1]);
            if (inc.empty() || ((i + k) < n && inc.back() <= v[i + k]))
                inc.push_back(v[i + k]);
            else
                inc = {}, inc.push_back(v[i + k]);
            if (inc.size() == k && deq.size() == k)
                ans.push_back(i);
        }
        return ans;
    }
};