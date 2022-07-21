#include "../../headers.h"

// BRUTE FORCE
// TLE:
class Solution
{
public:
    int numMatchingSubseq(string s, vector<string> &words)
    {
        int count = 0;
        for (string &q : words)
        {
            string r = "";
            int j = 0;
            for (int i = 0; i < q.length(); i++)
            {
                while (j < s.length())
                {
                    if (q[i] == s[j])
                    {
                        r += s[j];
                        j++;
                        break;
                    }
                    j++;
                }
            }
            if (r == q)
            {
                count++;
            }
        }
        return count;
    }
};

// HASH MAP
class Solution
{
public:
    unordered_map<string, int> umap;

    int calc(string s, string q)
    {
        int j = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == q[j])
                j++;
            if (j == q.length())
                return 1;
        }
        return 0;
    }

    int numMatchingSubseq(string s, vector<string> &words)
    {
        int ans = 0;
        for (string &q : words)
        {
            if (umap.find(q) != umap.end())
            {
                ans += umap[q];
            }
            else
            {
                umap[q] = calc(s, q);
                ans += umap[q];
            }
        }
        return ans;
    }
};