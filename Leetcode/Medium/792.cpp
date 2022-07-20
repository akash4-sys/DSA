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
// idea : consider two strings abcde acd
// position of c shld be higher than a in abcde
// for similar strings we will maintain a array and loop through it to find if there is one tht's greater
class Solution
{
public:
    int numMatchingSubseq(string s, vector<string> &words)
    {
        unordered_map<string, queue<int>> umap;
        int count = 0;
        for (int i = 0; i < s.length(); i++)
        {
            string t = s[i]; //need to convert first from char* to char
            umap[t].push(i);
        }
        for (string &q : words)
        {
            string r = "";
            unordered_map<string, queue<int>> m = umap;
            for (int i = 0; i < q.length(); i++)
            {
                if(m[q[i]].front() > i)
                {

                }
            }
            if (r == q)
            {
                count++;
            }
        }
    }
};