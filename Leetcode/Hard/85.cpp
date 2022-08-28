#include "../../headers.h"

class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &m)
    {
        int ans = 0;
        vector<int> sums(m[0].size(), 0);
        for (int i = 0; i < m.size(); i++)
        {
            stack<int> st;
            for (int j = 0; j <= sums.size(); j++)
            {
                if(j != sums.size())
                    sums[j] += (m[i][j] == '0') ? -sums[j] : m[i][j] - '0';
                
                while (!st.empty() && (j == sums.size() || sums[st.top()] >= sums[j]))
                {
                    int height = sums[st.top()], width;
                    st.pop();
                    width = (st.empty()) ? j : j - st.top() - 1;
                    ans = max(ans, width * height);
                }
                st.push(j);
            }
        }
        return ans;
    }
};