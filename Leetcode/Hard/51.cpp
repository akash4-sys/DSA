#include "../../headers.h"

class Solution {
public:
    vector<vector<string>> chess;

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
            chess.push_back(flatChess);
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

    vector<vector<string>> solveNQueens(int n) {
        vector<string> flatChess(n, string(n, '.'));
        queens(flatChess, n, 0);
        return chess;
    }
};








// for generating one solution

class Solution {
public:

    bool stable(vector<vector<string>> chess, int n, int i, int j) {

        // left side
        for(int x = 0; x < j; x++)
            if(chess[i][x] == "Q")
                return false;

        // upper diagonal
        int x = i, y = j;
        while(x >= 0 && y >= 0)
        {
            if(chess[x][y] == "Q")
                return false;
            x--;
            y--;
        }

        // lower diagonal
        x = i, y = j;
        while(x < n && y >= 0)
        {
            if(chess[x][y] == "Q")
                return false;
            x++;
            y--;
        }
        return true;
    }
    
    bool queens(vector<vector<string>> &chess, int n, int j)
    {
        if(j >= n)
            return true;
        
        for(int i = 0; i < n; i++)
        {
            if(stable(chess, n, i, j))
            {
                chess[i][j] = "Q";
                if(queens(chess, n, j+1))
                    return true;
                chess[i][j] = ".";
            }
        }
        return false;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> chess(n, vector<string>(n, "."));
        if(!queens(chess, n, 0))
            return {{}};
        return chess;
    }
};