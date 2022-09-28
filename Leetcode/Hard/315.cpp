#include "../../headers.h"

// Time complexity O(NlogN)
// Space Complexity O(N)

class Solution 
{
    void mergeCount(vector<pair<int, int>> &vidx, vector<pair<int, int>> &merged, vector<int> &ans, int low, int high)
    {
        if(low >= high)
            return;
        int mid = low + ((high - low) / 2);
        mergeCount(vidx, merged, ans, low, mid);
        mergeCount(vidx, merged, ans, mid + 1, high);

        // enhanced merge without function
        int l = low,  r = mid + 1, inverse = 0, i = low;
        while(l <= mid && r <= high)
            if(vidx[r].first < vidx[l].first)
                ++inverse, merged[i++] = vidx[r++];
            else
                ans[vidx[l].second] += inverse, merged[i++] = vidx[l++];

        while(l <= mid)
            ans[vidx[l].second] += inverse, merged[i++] = vidx[l++];

        while(r <= high)
            merged[i++] = vidx[r++];

        for(int i = low; i <= high; i++)
            vidx[i] = merged[i];
    }

public:
    vector<int> countSmaller(vector<int>& v) 
    {
        if(v.empty())
            return v;
        vector<int> ans(v.size(), 0);
        vector<pair<int, int>> vidx, merged;

        for(int i = 0; i < v.size(); i++)
            vidx.push_back({v[i], i}), merged.push_back({v[i], i});

        mergeCount(vidx, merged, ans, 0, v.size() - 1);
        return ans;
    }
};



// Simple way
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        ordered_set s;
        for(int i=nums.size()-1;i>=0;i--){
            s.insert(nums[i]);
            ans[i] = s.order_of_key(nums[i]);
        }
        return ans;
    }
};