#include "../../headers.h"

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> uset(begin(wordList), end(wordList));
        if (uset.count(endWord) == 0)
            return 0;

        queue<string> q;
        q.push(beginWord);
        int depth = 0;

        while (!q.empty())
        {
            int currSize = q.size();
            depth++;
            while (currSize--)
            {
                string curr = q.front();
                q.pop();

                for (int i = 0; i < curr.length(); i++)
                {
                    string temp = curr;
                    for (char c = 'a'; c <= 'z'; c++)
                    {
                        temp[i] = c;
                        if(temp == curr)
                            continue;
                        if(temp == endWord)
                            return depth+1;
                        if(uset.count(temp) != 0)
                        {
                            q.push(temp);
                            uset.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};