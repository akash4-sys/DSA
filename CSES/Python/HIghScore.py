import sys
from heapq import *
sys.setrecursionlimit(10**6)
MIN = 10**18 * -1

# @ Bellman-Ford

def inputGraph():
    data = list(map(int, sys.stdin.read().split()))
    n, m, idx = data[0], data[1], 2
    g = [[] for _ in range(n)]
    rg = [[] for _ in range(n)]
    for _ in range(m):
        u, v, w = data[idx], data[idx + 1], data[idx + 2]
        g[u - 1].append((v - 1, w))
        rg[v - 1].append((u - 1, w))
        idx += 3
    return n, g, rg

def dfs(g, vis, u):
    vis[u] = 1
    for v, w in g[u]:
        if not vis[v]:
            dfs(g, vis, v)

def highScore():
    n, g, rg = inputGraph()
    dist, fvis, bvis = [MIN] * n, [0] * n, [0] * n
    dist[0] = 0
    dfs(g, fvis, 0)
    dfs(rg, bvis, n - 1)
    
    for i in range(n):
        flag = 0
        for u in range(n):
            for v, w in g[u]:
                if dist[u] + w > dist[v]:
                    if i == n - 1 and fvis[v] and bvis[v]:
                        return -1
                    dist[v] = dist[u] + w
                    flag = 1
        if not flag:
            break
    return dist[n - 1]

if __name__ == "__main__":
    print(highScore())