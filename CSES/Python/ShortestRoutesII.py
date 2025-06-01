import sys
from heapq import *
MAX = 10**15
 
def floydWarshall(n, dist):
    for k in range(n):
        for i in range(n):
            if dist[i][k] < MAX:
                for j in range(n):
                    if dist[j][k] < MAX:
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
    
def solve():
    data = list(map(int, sys.stdin.read().split()))
    n, m, q, idx = data[0], data[1], data[2], 3
    dist = [[MAX for _ in range(n)] for _ in range(n)]
    for _ in range(m):
        u, v, w = data[idx] - 1, data[idx + 1] - 1, data[idx + 2]
        dist[u][v] = dist[v][u] = w
        idx += 3
    
    floydWarshall(n, dist)
    for _ in range(q):
        u, v = data[idx] - 1, data[idx + 1] - 1
        print(dist[u][v] if dist[u][v] != MAX else -1)
        idx += 2
 
if __name__ == "__main__":
    solve()