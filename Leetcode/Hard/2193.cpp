#include "../../headers.h"

// Time Complexity - O(NlogN)
// Space Complexity - O(N)

class BIT
{
    vector<int> bit;
    int n;

public:
    BIT(int _n): n(_n), bit(_n, 0) {}

    void update(int i)
    {
        for (++i; i < n; i += i & (-i))
            bit[i]++;
    }

    int getSum(int i)
    {
        int sum = 0;
        for (++i; i > 0; i -= i & (-i))
            sum += bit[i];
        return sum;
    }
};

class Solution
{
public:
    int minMovesToMakePalindrome(string s)
    {
        int ans = 0, n = s.size();
        BIT bit(n + 1);
        deque<int> pos[26] = {};
        for (int i = 0; i < n; i++)
            pos[s[i] - 'a'].push_back(i);
        
        for (int i = n - 1; i >= 0; i--)
        {
            int j = s[i] - 'a';
            if(!pos[j].empty())
            {
                int p = pos[j].front() - bit.getSum(pos[j].front());        //pos[j].front() == first same element from left in string
                bit.update(pos[j].front());
                if(pos[j].size() > 1)
                    pos[j].pop_front();
                else
                    p /= 2;
                ans += p;
                pos[j].pop_back();
            }
        }
        return ans;
    }
};




// Time Complexity - O(N^2)
// Space Complexity - O(1)

class Solution
{
public:
    int minMovesToMakePalindrome(string s)
    {
        int l = 0, r = s.size() - 1, ans = 0, centerI = -1;
        while (l < r)
        {
            if (s[l] == s[r])
            {
                l++, r--;
                continue;
            }

            int k = l + 1;
            for (; k < r; k++)
                if (s[k] == s[r])
                    break;

            if (k == r)
            {
                centerI = r;
                r--;
                continue;
            }

            for (int j = k; j > l; j--)
                swap(s[j], s[j - 1]), ans++;   
            l++, r--;
        }

        if (centerI != -1)
            ans += (centerI - (s.size() / 2));
        return ans;
    }
};