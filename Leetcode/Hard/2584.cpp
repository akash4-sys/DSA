#include "../../headers.h"

class Solution
{
    unordered_set<int> distPF(int n)
    {
        unordered_set<int> s;
        if (n == 2)
            s.insert(n);
        for (int i = 2, sq = sqrt(n); i <= sq; i++)
            for (; !(n % i); n /= i)
                s.insert(i);
        if (n > 2)
            s.insert(n);
        return s;
    }

public:
    int findValidSplit(vector<int> &v)
    {
        unordered_map<int, int> mp;
        int line[10001] = {0};
        for (int i = 0; i < v.size(); i++)
            for (auto x : distPF(v[i]))
            {
                if (!mp.count(x))
                    mp[x] = i;
                ++line[mp[x]];
                --line[i];
            }
        
        partial_sum(begin(line), end(line), begin(line));
        int ans = find(begin(line), end(line), 0) - begin(line);
        return ans < v.size() - 1 ? ans : -1;
    }
};


// Time Complexity - O(N^2)
class Solution
{
    unordered_set<int> distPF(int n)
    {
        unordered_set<int> s;
        if (n == 2)
            s.insert(n);
        for (int i = 2, sq = sqrt(n); i <= sq; i++)
            for (; !(n % i); n /= i)
                s.insert(i);
        if (n > 2)
            s.insert(n);
        return s;
    }

public:
    int findValidSplit(vector<int> &v)
    {
        unordered_map<int, int> mp, pf;
        for (int n : v)
            for (auto x : distPF(n))
                mp[x]++;

        for (int i = 0, c = 0; i <= (int)v.size() - 2; i++)
        {
            for (auto x : distPF(v[i]))
                c += (!pf.count(x)) - (++pf[x] == mp[x]);
            if (!c)
                return i;
        }
        return -1;
    }
};


// TLE - Don't know why
// Time Complexity - O(N^2)
// Space Complexity - O(N)

class Solution
{
    void distPF(unordered_map<int, int> &mp, int n)
    {
        mp[n] += n == 2;
        for (int i = 2, sq = sqrt(n); i <= sq; i++)
            for (; !(n % i); n /= i)
                mp[i]++;
        mp[n] += n > 2;
    }

    bool check(unordered_map<int, int> &mp, unordered_map<int, int> &pf)
    {
        for (auto [x, c] : pf)
            if (mp[x] - c != 0)
                return 0;
        return 1;
    }

public:
    int findValidSplit(vector<int> &v)
    {
        unordered_map<int, int> mp, pf;
        for (int n : v)
            distPF(mp, n);

        for (int i = 0; i <= (int)v.size() - 2; i++)
        {
            distPF(pf, v[i]);
            if (check(mp, pf))
                return i;
        }
        return -1;
    }
};