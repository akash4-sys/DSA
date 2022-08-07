#include "../../headers.h"

class Solution
{
public:

    bool valid(vector<vector<char>> board, int i, int j, char num)
    {
        board[i][j] = '.';
        for(int k = 0; k < 9; k++)
            if(board[i][k] == num || board[k][j] == num)
                return false;
        
        int stX = (i / 3) * 3, stY = (j / 3) * 3;

        for (int x = stX; x < stX + 3; x++)
            for (int y = stY; y < stY + 3; y++)
                if (board[x][y] == num)
                    return false;
        
        board[i][j] = num;
        return true;
    }

    bool isValidSudoku(vector<vector<char>> &board)
    {
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
                if(board[i][j] != '.' && !valid(board, i, j, board[i][j]))
                    return false;
        
        return true;
    }
};