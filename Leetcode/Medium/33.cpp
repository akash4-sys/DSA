#include "../../headers.h"

class Solution
{
public:
    int search(vector<int> &v, int t)
    {
        for (int l = 0, r = v.size(); l < r; )
        {
            int mid = (l + r) / 2;
            int x = v[mid] < v[0] == t < v[0] ? v[mid] : (t < v[0] ? INT_MIN : INT_MAX);
            if (x == t)
                return mid;
            x < t ? l = mid + 1 : r = mid;
        }
        return -1;
    }
};



class Solution
{
public:
    int search(vector<int> &v, int t)
    {
        int left = 0, right = v.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (v[mid] == t)
                return mid;

            else if (v[mid] >= v[left])
            {
                if (t >= v[left] && t < v[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else
            {
                if (t <= v[right] && t > v[mid])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
};