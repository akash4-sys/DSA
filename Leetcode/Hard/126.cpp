#include "../../headers.h"

class Solution
{
public:
    vector<vector<string>> findLadders(string begW, string endW, vector<string> &wordList)
    {
        unordered_set<string> s(begin(wordList), end(wordList));
        if(s.count(endW) == 0)
            return {};
        
        unordered_map<string, int> m;
        queue<string> q;
        q.push(begW);
        
        int n = begW.length(), step = 0;
        m[begW] = step;

        while(q.size())
        {
            while(!q.empty())
            {
                string u = q.front(), v = u;
                q.pop();
            }
            step++;
        }
    }
};