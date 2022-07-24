#include "../../headers.h"
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


// Something is wrong, can't find it
class Solution
{
public:
    vector<int> ans;

    void merge(vector<pair<int, int>> p, int l, int mid, int r)
    {
        int lsize = mid - l + 1, rsize = r - mid;
        vector<pair<int, int>> left(lsize), right(rsize);

        for (int i = 0; i < lsize; i++)
            left[i] = p[l + i];
        for(int i = 0; i < rsize; i++)
            right[i] = p[mid + i + 1];

        int i = 0, j = 0, k = l, count = 0;

        while(i < lsize && j < rsize)
        {
            if(left[i].second <= right[j].second)
            {
                ans[left[i].first] += count;
                p[k] = left[i];
                i++;
            }
            else
            {
                count++;
                p[k] = right[j];
                j++;
            }
            k++;
        }

        while(i < lsize)
        {
            ans[left[i].first] += count;
            p[k] = left[i];
            k++;
            i++;
        }

        while(j < rsize)
        {
            p[k] = right[j];
            k++;
            j++;
        }
    }

    void mergesort(vector<pair<int, int>> p, int l, int r)
    {
        if (l >= r)
            return;
        int mid = (l + r) / 2;
        mergesort(p, l, mid);
        mergesort(p, mid + 1, r);
        merge(p, l, mid, r);
    }

    vector<int> countSmaller(vector<int> &nums)
    {
        int n = nums.size();
        vector<pair<int, int>> vp(n);

        vector<int> t(n, 0);
        ans = t;

        for (int i = 0; i < n; i++)
        {
            vp[i].first = i;
            vp[i].second = nums[i];
        }

        mergesort(vp, 0, n - 1);
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {10, 9, 5, 2, 7, 6, 11, 0, 2};
    sol.countSmaller(nums);
    return 0;
}