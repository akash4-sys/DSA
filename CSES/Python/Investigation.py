import sys
from heapq import *
MAX, mod = 10**18, 10**9 + 7

def inputGraph():
    data = list(map(int, sys.stdin.read().split()))
    n, m, idx = data[0], data[1], 2
    g = [[] for _ in range(n)]
    for _ in range(m):
        u, v, w = data[idx], data[idx + 1], data[idx + 2]
        g[u - 1].append((v - 1, w))
        idx += 3
    return n, g

n, g = inputGraph()
dist, paths, x, y = [MAX] * n, [0] * n, [MAX] * n, [0] * n
pq = [(0, 0)]
x[0] = dist[0] = 0
paths[0] = 1

while len(pq):
    w, u = heappop(pq)
    if dist[u] < w: continue

    for v, cw in g[u]:
        if dist[u] + cw == dist[v]:
            paths[v] = (paths[v] + paths[u]) % mod
            x[v] = min(x[v], x[u] + 1)
            y[v] = max(y[v], y[u] + 1)

        if dist[u] + cw < dist[v]:
            paths[v] = paths[u]
            x[v] = x[u] + 1
            y[v] = y[u] + 1
            dist[v] = dist[u] + cw
            heappush(pq, (dist[v], v))

print(dist[n - 1], paths[n - 1], x[n - 1], y[n - 1])