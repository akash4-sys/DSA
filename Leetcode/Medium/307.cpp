#include "../../headers.h"

class BinaryIndexedTree
{
    vector<int> bit;

public:
    BinaryIndexedTree() {};
    BinaryIndexedTree(int n): bit(n + 1, 0) {}

    void update(int i, int val)
    {
        for(; i < bit.size(); i += i & (-i))
            bit[i] += val;
    }

    int getSum(int i)
    {
        int sum = 0;
        for(; i > 0; i -= i & (-i))
            sum += bit[i];
        return sum;
    }
};

class NumArray
{
    BinaryIndexedTree bit;
    vector<int> v;
public:
    NumArray(vector<int> &v)
    {
        this->bit = BinaryIndexedTree(v.size());
        this->v = v;
        for(int i = 0; i < v.size(); i++)
            bit.update(i + 1, v[i]);
    }

    void update(int i, int val)
    {
        int d = val - v[i];
        bit.update(i + 1, d);
        v[i] = val;
    }

    int sumRange(int left, int right)
    {
        return bit.getSum(right + 1) - bit.getSum(left);
    }
};




class NumArray
{
public:
    int len;
    vector<int> sums, nums;

    NumArray(vector<int> &nums) : nums(nums)
    {
        if (nums.empty())
            return;
        len = ceil(sqrt(nums.size()));
        sums = vector<int>(ceil((double)nums.size() / len));
        for (int i = 0; i < nums.size(); ++i)
        {
            sums[i / len] += nums[i];
        }
    }

    void update(int i, int val)
    {
        sums[i / len] += val - nums[i];
        nums[i] = val;
    }

    int sumRange(int i, int j)
    {
        int sum = 0, start = i / len, end = j / len;
        if (start == end)
        {
            while (i <= j)
                sum += nums[i++];
        }
        else
        {
            for (int k = (start + 1) * len - 1; k >= i; --k)
                sum += nums[k];
            for (int k = start + 1; k < end; ++k)
                sum += sums[k];
            for (int k = end * len; k <= j; ++k)
                sum += nums[k];
        }
        return sum;
    }
};