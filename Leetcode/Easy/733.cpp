#include "../../headers.h"

class Solution {
public:

    void dfs(vector<vector<int>>& img, int i, int j, int color, int org)
    {
        if(i < 0 || j < 0 || i >= img.size() || j >= img[0].size() || img[i][j] != org)
            return;

        img[i][j] = color;
        dfs(img, i+1, j, color, org);
        dfs(img, i-1, j, color, org);
        dfs(img, i, j+1, color, org);
        dfs(img, i, j-1, color, org);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& img, int i, int j, int color) {
        int org = img[i][j];
        if(org == color)
            return img;
        dfs(img, i, j, color, org);
        return img;
    }
};