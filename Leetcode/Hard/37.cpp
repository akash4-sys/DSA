#include "../../headers.h"

class Solution
{
public:
    bool valid(vector<vector<char>> &board, int i, int j, int num)
    {
        for (int k = 0; k < 9; k++)
        {
            if (board[i][k] == num + '0')
                return false;
            if (board[k][j] == num + '0')
                return false;
        }

        int stX = (i / 3) * 3, stY = (j / 3) * 3;

        for (int x = stX; x < stX + 3; x++)
            for (int y = stY; y < stY + 3; y++)
                if (board[x][y] == num + '0')
                    return false;

        return true;
    }

    bool solver(vector<vector<char>> &board, int i, int j)
    {
        if (i == 9)
            return true;

        int row = 0, col = 0;

        if (j != 9)
        {
            row = i;
            col = j + 1;
        }
        else
        {
            row = i + 1;
            j = 0;
        }

        if (board[i][j] == '.')
        {
            for (int k = 1; k <= 9; k++)
            {
                if (!valid(board, i, j, k))
                    continue;
                board[i][j] = k + '0';
                if (solver(board, row, col))
                    return true;
                board[i][j] = '.';
            }
        }
        else if (solver(board, row, col))
            return true;

        return false;
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        solver(board, 0, 0);
        return;
    }
};