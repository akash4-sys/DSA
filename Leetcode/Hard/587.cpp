#include "../../headers.h"

// @ Convex Hull - Montone Algorithm or Andrew's algorithm
// ? https://en.wikibooks.org/wiki/Algorithm_Implementation/Geometry/Convex_hull/Monotone_chain
// ? https://www.hackerearth.com/practice/math/geometry/line-sweep-technique/tutorial/

// Time Complexity - O(NlogN)
// Space Complexity - O(N)
class Solution
{
    double getRotationAngle(vector<int> &origin, vector<int> &a, vector<int> &b)
    {
        return ((a[0] - origin[0]) * (b[1] - origin[1])) - ((a[1] - origin[1]) * (b[0] - origin[0]));
    }

public:
    vector<vector<int>> outerTrees(vector<vector<int>> &points)
    {
        if(points.size() <= 3)
            return points;

        int k = 0;
        vector<vector<int>> ans(2 * points.size());
        sort(points.begin(), points.end());

        for(auto p: points)
        {
            while(k >= 2 && getRotationAngle(ans[k - 2], ans[k - 1], p) < 0)
                k--;
            ans[k++] = p;
        }

        for(int i = points.size() - 2, t = k + 1; i >= 0; i--)
        {
            while(k >= t && getRotationAngle(ans[k - 2], ans[k - 1], points[i]) < 0)
                k--;
            ans[k++] = points[i];
        }

        // This part is question specific couldn't figure out why original algorithm didn't require sorted twice or anything like unique either
        ans.resize(k);
        sort(ans.begin(), ans.end());
        auto it = unique(ans.begin(), ans.end(), [&](auto &a, auto &b){
            return (a[0] == b[0] && a[1] == b[1]);
        });
        ans.erase(it, ans.end());
        return ans;
    }
};


// A way to do it without sorting twice or unique

class Solution 
{
    double getRotationAngle(vector<int> &origin, vector<int> &a, vector<int> &b)
    {
        return ((a[0] - origin[0]) * (b[1] - origin[1])) - ((a[1] - origin[1]) * (b[0] - origin[0]));
    }
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& points) 
    {
        if (points.size() <= 3)
            return points;

        vector<vector<int>> ans;
        sort(points.begin(), points.end());

        for(auto p: points)
        {
            while(ans.size() > 1 && getRotationAngle(ans[ans.size() - 2], ans.back(), p) < 0)
                ans.pop_back();
            ans.push_back(p);
        }

        if(ans.size() == points.size()) return ans;

        for(int i = points.size() - 2; i >= 0; i--)
        {
            while(ans.size() > 1 && getRotationAngle(ans[ans.size() - 2], ans.back(), points[i]) < 0)
                ans.pop_back();
            ans.push_back(points[i]);
        }

        ans.pop_back();
        return ans;
    }
};