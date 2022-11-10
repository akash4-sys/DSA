#include "../../headers.h"

// Time Complexity O(N)
// Space Complexity O(1)
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &v)
    {
        vector<int> ans(v.size());
        for (int i = v.size() - 2; i >= 0; i--)
        {
            int x = i + 1;
            while(x < v.size() && v[x] <= v[i])
                x += ans[x] ? ans[x] : v.size();
            if(x < v.size())
                ans[i] = x - i;
        }
        return ans;
    }
};


// Time Complexity - O(N)
// Space Complexity - O(N)
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &v)
    {
        vector<int> ans(v.size());
        stack<int> st;
        for(int i = v.size() - 1; i >= 0; i--)
        {
            while(!st.empty() && v[st.top()] <= v[i])
                st.pop();
            ans[i] = st.empty() ? 0 : st.top() - i;
            st.push(i);
        }
        return ans;
    }
};


class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &v)
    {
        vector<int> ans(v.size());
        stack<int> st;
        for (int i = 0; i < v.size(); i++)
        {
            while(!st.empty() && v[i] > v[st.top()])
                ans[st.top()] = i - st.top(), st.pop();
            st.push(i);
        }
        return ans;
    }
};