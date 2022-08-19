#include "../../headers.h"

class Solution
{
public:
    bool isPossible(vector<int> &nums)
    {
        int n = nums.size();
        if(n < 3)
            return false;
        
        unordered_map<int, int> umap, prev;
        for(int num: nums)
            umap[num]++;
        
        for(int num: nums)
        {
            if(umap[num] == 0)
                continue;
            umap[num]--;
            if(prev[num - 1] > 0)
            {
                prev[num - 1]--;
                prev[num]++;
            }
            else if(umap[num + 1] > 0 && umap[num + 2] > 0)
            {
                umap[num + 1]--;
                umap[num + 2]--;
                prev[num + 2]++;
            }
            else
                return false;
        }
        return true;
    }
};