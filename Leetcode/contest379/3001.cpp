#include "../../headers.h"

class Solution
{
    int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int dig[4][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f)
    {
        for (auto di : dirs)
        {
            int x = a, y = b;
            for (int i = 1; i < 8; i++)
            {
                x += di[0], y += di[1];
                if (x == c && y == d)
                    break;
                if (x == e && y == f)
                    return 1;
            }
        }

        for (auto di : dig)
        {
            int x = c, y = d;
            for (int i = 1; i < 8; i++)
            {
                x += di[0], y += di[1];
                if (x == a && y == b)
                    break;
                if (x == e && y == f)
                    return 1;
            }
        }
        return 2;
    }
};