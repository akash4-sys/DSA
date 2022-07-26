#include "../../headers.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0, j = matrix[0].size()-1;
        while(i >= 0 && j >= 0 && i < matrix.size() && j < matrix[0].size())
        {
            if(matrix[i][j] == target)
                return true;
            (target < matrix[i][j]) ? j-- : i++;
        }
        return false;
    }
};