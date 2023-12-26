#pragma once

#include <vector>

using namespace std;

void floydWarshall(vector<vector<long long>> &dist)
{
    int n = dist.size();
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n && dist[i][k] < LLONG_MAX; j++)
                if (dist[k][j] < LLONG_MAX)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}