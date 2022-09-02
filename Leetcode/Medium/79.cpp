#include "../../headers.h"

class Solution
{
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool dfs(vector<vector<char>> &board, string word, int i, int j, int idx)
    {
        if(idx == word.size())
            return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[idx])
            return false;
        
        char c = board[i][j];
        board[i][j] = '.';
        for (auto &[dx, dy] : dirs)
            if(dfs(board, word, dx + i, dy + j, idx+1))
                return true;
        board[i][j] = c;
        return false;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++)
                if (board[i][j] == word[0] && dfs(board, word, i, j, 0))
                    return true;
        return false;
    }
};