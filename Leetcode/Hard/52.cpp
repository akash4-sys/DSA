#include "../../headers.h"

class Solution {
public:
    int ans = 0;

    bool stable(vector<string> &flatChess, int n, int i, int j) {

        // left side
        for(int x = 0; x < j; x++)
            if(flatChess[i][x] == 'Q')
                return false;

        // upper diagonal
        int x = i, y = j;
        while(x >= 0 && y >= 0)
        {
            if(flatChess[x][y] == 'Q')
                return false;
            x--;
            y--;
        }

        // lower diagonal
        x = i, y = j;
        while(x < n && y >= 0)
        {
            if(flatChess[x][y] == 'Q')
                return false;
            x++;
            y--;
        }
        return true;
    }
    
    void queens(vector<string> &flatChess, int n, int j)
    {
        if(j >= n)
        {
            ans++;
            return;
        }
        
        for(int i = 0; i < n; i++)
        {
            if(stable(flatChess, n, i, j))
            {
                flatChess[i][j] = 'Q';
                queens(flatChess, n, j+1);
                flatChess[i][j] = '.';
            }
        }
        return;
    }

    int totalNQueens(int n) {
        vector<string> flatChess(n, string(n, '.'));
        queens(flatChess, n, 0);
        return ans;
    }
};