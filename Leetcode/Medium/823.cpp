#include "../../headers.h"

class Solution
{
public:
    int numFactoredBinaryTrees(vector<int> &arr)
    {
        int mod = 1e9 + 7;
        long long ans = 0;
        unordered_map<int, long long> umap;
        sort(arr.begin(), arr.end());

        for (int i = 0; i < arr.size(); i++)
        {
            umap[arr[i]] = 1;
            for (int j = 0; j < i; j++)
                if (arr[i] % arr[j] == 0)
                    umap[arr[i]] = (umap[arr[i]] + (umap[arr[j]] * umap[arr[i] / arr[j]])) % mod;

            ans = (ans + umap[arr[i]]) % mod;
        }
        return ans;
    }
};