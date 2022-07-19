#include "../../headers.h"

// visualize

class Solution
{
public:

    int count = 0;
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            vector<int> sum(matrix[0].size());
            for (int j = i; j < matrix.size(); j++)
            {
                unordered_map<int,int> mp;
                mp[0] = 1;
                int total = 0;
                for(int k=0; k < matrix[0].size(); k++)
                {
                    sum[k] += matrix[j][k];
                    total += sum[k];
                    count += mp[total - target];
                    mp[total]++;
                }
            }
        }
        return count;
    }
};


class Solution
{
public:
    int sum = 0, count = 0;

    void check(vector<vector<int>> &matrix, int i, int j, int target)
    {
        if (i <= 0 || j <= 0 || i >= matrix.size() || j >= matrix[0].size())
            return;
        if (sum + matrix[i][j] == target)
        {
            count++;
            return;
        }
        if (sum + matrix[i][j] < target)
        {
            sum += matrix[i][j];
            check(matrix, i + 1, j, target);
            check(matrix, i - 1, j, target);
            check(matrix, i, j + 1, target);
            check(matrix, i, j - 1, target);
        }
    }

    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] > target)
                    continue;
                if (matrix[i][j] == target)
                {
                    count++;
                    continue;
                }
                sum += matrix[i][j];
                check(matrix, i + 1, j, target);
                check(matrix, i - 1, j, target);
                check(matrix, i, j + 1, target);
                check(matrix, i, j - 1, target);
                sum = 0;
            }
        }
        return count;
    }
};