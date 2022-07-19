#include "../../headers.h"

class Solution {
public:
    int mod = 1e9 + 7;
    int kInversePairs(int n, int k) {
        vector<vector<int>> v(1001, vector<int>(1001));
        v[0][0] = 1;
        for(int i = 1; i <= n; i++)
        {
            long long x = 0;
            for(int j = 0; j <= k; j++)
            {
                x +=  v[i-1][j];
                if( j >= i) x -= v[i-1][j-i];
                v[i][j] = ((long long)v[i][j] + x) % mod;
            }
        }
        return v[n][k];
    }
};

int main() {
    Solution sol;
    cout<<sol.kInversePairs(3,0);
}