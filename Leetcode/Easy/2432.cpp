#include "headers.h"

class Solution
{
public:
    int hardestWorker(int n, vector<vector<int>> &logs)
    {
        int d = logs[0][1], id = logs[0][0];
        for(int i = 1; i < logs.size(); i++)
        {
            if(d < logs[i][1] - logs[i - 1][1])
                d = logs[i][1] - logs[i - 1][1], id = logs[i][0];
            else if(d == logs[i][1] - logs[i - 1][1])
                id = min(logs[i][0], logs[i-1][0]);
        }
        return id;
    }
};