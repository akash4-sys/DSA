#include "../headers.h"

// In this problem a kth ancestor will always exist as from given constraints -1 is not allowed in input value,
// that means atleast one node has to point at another node that will result in a cycle. Try a to make a acyclic graph.
// So unlike classic binary lifting we don't -1 in ancestor to check whether kth ancestor exists

class Solution
{
    int n, maxDepth;
    vector<vector<long long>> ancestor, ksum;

    void binaryLifting(vector<int> &par)
    {
        n = par.size();
        ksum = ancestor = vector(n, vector<long long>(maxDepth, 0));

        for (int i = 0; i < n; i++)
            ancestor[i][0] = ksum[i][0] = par[i];
        
        for (int j = 1; j < maxDepth; j++)
            for (int i = 0; i < n; i++)
            {
                ancestor[i][j] = ancestor[ancestor[i][j - 1]][j - 1];
                ksum[i][j] = ksum[i][j - 1] + ksum[ancestor[i][j - 1]][j - 1];
            }
    }

    long long kthAncestorSum(int node, long long k)
    {
        long long res = node;
        for (int i = 0; i < maxDepth; i++)
            if (k & (1LL << i))
            {
                res += ksum[node][i];
                node = ancestor[node][i];
            }
        return res;
    }

public:
    long long getMaxFunctionValue(vector<int> &v, long long k)
    {
        maxDepth = log2(k) + 1;
        binaryLifting(v);

        long long ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, kthAncestorSum(i, k));
        return ans;
    }
};