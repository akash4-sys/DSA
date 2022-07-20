#include "../../headers.h"

class Solution {
public:
    bool isMatch(string s, string p) 
    {
        int n = s.length(), m = p.length();
        if( m == 0 )
        {
            if( n == 0) { return true; }
        }
        
        vector<vector<bool>> vis(n+1, vector<bool>(m+1, false));
        vis[0][0] = true;
        
        for(int i=1; i <= m; i++)
        {
            if(p[i-1] == '*')
            {
                vis[0][i] = vis[0][i-1];
            }
        }
        
        for(int i=1; i <= n; i++)
        {
            for(int j=1; j <= m; j++)   
            {
                if(p[j-1] == '*')
                {
                    vis[i][j] = vis[i][j-1] || vis[i-1][j];
                }
                else
                if(p[j-1] == '.' || p[j-1] == s[i-1])
                {
                    vis[i][j] = vis[i-1][j-1];
                }
                else
                {
                    vis[i][j] = false;
                }
            }
        }
        return vis[n][m];
    }
};