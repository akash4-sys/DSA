#include "../../headers.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size(), c = matrix[0].size();
        int i = 0, j = c - 1;
        while(i >= 0 && i < r && j >= 0 && j < c)
        {
            if(matrix[i][j] == target)
                return true;
            if(matrix[i][j] < target)
                j--;
            else
                i++;
        }
        return false;
    }
};