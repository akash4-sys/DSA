#include "../../headers.h"

class Solution
{
    int find(vector<long long> &a, int i) {
        return a[i] < 0 ? i : a[i] = find(a, a[i]);
    }

    void merge(vector<long long> &a, int i, int j)
    {
        int p1 = find(a, i), p2 = find(a, j);
        a[p2] += a[p1];
        a[p1] = p2;
    }

public:
    vector<long long> maximumSegmentSum(vector<int> &v, vector<int> &idx)
    {
        int n = v.size();
        vector<long long> ans(n, 0), a(n, INT_MAX);
        for (int j = idx.size() - 1; j > 0; j--)
        {
            int i = idx[j];
            a[i] = -v[i];
            if (i && a[i - 1] != INT_MAX)
                merge(a, i, i - 1);
            if (i < n - 1 && a[i + 1] != INT_MAX)
                merge(a, i, i + 1);
            ans[j - 1] = max(ans[j], -a[find(a, i)]);
        }
        return ans;
    }
};

// Time Complexity - O(NlogN)
// Space Compplexity - O(N)

class Solution
{
public:
    vector<long long> maximumSegmentSum(vector<int> &v, vector<int> &idx)
    {
        int n = v.size();
        vector<long long> ans, pf(n + 1, 0);
        for (int i = 1; i <= n; i++)
            pf[i] = pf[i - 1] + v[i - 1];

        set<int> st = {0, n + 1};
        multiset<long long> sum = {pf[n]};
        for (int i : idx)
        {
            i++;
            auto it = st.lower_bound(i);
            int l = *prev(it), r = *it;

            r--, l++;
            long long csum = pf[r] - pf[l - 1];
            sum.erase(sum.find(csum));
            st.insert(i);

            if (i == l)
                sum.insert(pf[r] - pf[l]);
            else if (i == r)
                sum.insert(pf[r - 1] - pf[l - 1]);
            else
            {
                sum.insert(pf[i - 1] - pf[l - 1]);
                sum.insert(pf[r] - pf[i]);
            }
            ans.push_back(*sum.rbegin());
        }
        return ans;
    }
};