#include "../../headers.h"

class Solution
{
public:
    vector<vector<int>> resultGrid(vector<vector<int>> &image, int threshold)
    {
        int n = image.size(), m = image[0].size();
        vector cnt(n, vector<int>(m, 0)), avg = cnt;

        for (int i = 0; i < n - 2; i++)
            for (int j = 0; j < m - 2; j++)
            {
                int sum = 0, isRegion = 1;
                for (int x = i; x < i + 3; x++)
                    for (int y = j; y < j + 3; y++)
                    {
                        sum += image[x][y];
                        isRegion &= x == i || abs(image[x][y] - image[x - 1][y]) <= threshold;
                        isRegion &= y == j || abs(image[x][y] - image[x][y - 1]) <= threshold;
                    }

                for (int x = i; x < i + 3 && isRegion; x++)
                    for (int y = j; y < j + 3; y++)
                        avg[x][y] += (sum / 9), cnt[x][y]++;
            }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (cnt[i][j])
                    image[i][j] = avg[i][j] / cnt[i][j];
        return image;
    }
};