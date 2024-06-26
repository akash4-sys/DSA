#include "headers.h"

class Solution
{
public:
    vector<int> smallestSubarrays(vector<int> &n)
    {
        vector<int> ans(n.size(), 1), bit(30, 0);
        for(int i = n.size()-1; i >= 0; i--)
            for(int j = 0; j < 30; j++)
            {
                if(n[i] & (1 << j))
                    bit[j] = i;
                ans[i] = max(ans[i], bit[j] - i + 1);
            }
        return ans;
    }
};


// Time Complexity - O(N*32)
// Space Complexity - O(N * 32)

class Solution
{
    bool sameNum(vector<int> &bit, vector<int> &bitpf)
    {
        for (int i = 0; i < 32; i++)
            if ((bit[i] && !bitpf[i]) || (!bit[i] && bitpf[i]))
                return 0;
        return 1;
    }

public:
    vector<int> smallestSubarrays(vector<int> &v)
    {
        int n = v.size();
        vector<int> ans(n, 0), bit(32, 0), bitpf(32, 0);
        for (int a : v)
            for (int i = 0; i < 32; i++)
                bitpf[i] += ((a & (1 << i)) != 0);

        for (int i = 0, j = 0; i < n; i++)
        {
            for (int x = 0; x < 32 && i; x++)
            {
                bit[x] -= ((v[i - 1] & (1 << x)) != 0);
                bitpf[x] -= ((v[i - 1] & (1 << x)) != 0);
            }

            for (; j < n && !sameNum(bit, bitpf); j++)
                for (int x = 0; x < 32; x++)
                    bit[x] += ((v[j] & (1 << x)) != 0);
            
            ans[i] = j <= i ? 1 : j - i;
        }
        return ans;
    }
};