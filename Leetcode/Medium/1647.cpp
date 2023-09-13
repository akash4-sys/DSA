#include "../../headers.h"

// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution
{
public:
    int minDeletions(string s)
    {
        int ch[26] = {0}, maxf = 0, ans = 0;
        for (char &c : s)
            maxf = max(maxf, ++ch[c - 'a']);
        
        vector<int> cnt(maxf + 1, 0);
        for (int f : ch)
            cnt[f]++;
        
        for (int i = maxf; i > 0; i--)
            if (cnt[i] > 1) {
                ans += cnt[i] - 1;
                cnt[i - 1] += cnt[i] - 1;
            }
        return ans;
    }
};

// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution
{
public:
    int minDeletions(string s)
    {
        int ch[26] = {0}, ans = 0;
        for (char &c : s)
            ++ch[c - 'a'];
        
        unordered_set<int> st;
        for (int f : ch) {
            for (; f > 0 && st.count(f); --f, ans++);
            st.insert(f);
        }
        return ans;
    }
};

// @lc app=leetcode id=1647 lang=cpp