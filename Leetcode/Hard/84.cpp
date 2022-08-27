#include "../../headers.h"

//  Monotonic Stack

class Solution {
public:
    int largestRectangleArea(vector<int>& h) 
    {
        stack<int> st;
        int ans = 0;
        for(int i = 0; i <= h.size(); i++)
        {
            while(!st.empty() && (i == h.size() || h[st.top()] >= h[i]))
            {
                int height = h[st.top()], width;
                st.pop();
                width = (st.empty()) ? i : i - st.top() - 1;
                ans = max(ans, width * height);
            }
            st.push(i);
        }
        return ans;
    }
};