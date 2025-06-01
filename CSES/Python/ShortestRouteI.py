import sys
from heapq import *
MAX = 10**18

def inputGraph():
    data = list(map(int, sys.stdin.read().split()))
    n, m, idx = data[0], data[1], 2
    g = [[] for _ in range(n)]
    for _ in range(m):
        u, v, w = data[idx], data[idx + 1], data[idx + 2]
        g[u - 1].append((v - 1, w))
        idx += 3
    return n, g

def dijkastra():
    n, g = inputGraph()
    dist = [MAX] * n
    dist[0] = 0
    pq = [(0, 0)]
    
    while len(pq):
        w, u = heappop(pq)
        if dist[u] >= w:
            for v, cw in g[u]:
                if dist[u] + cw < dist[v]:
                    dist[v] = dist[u] + cw
                    heappush(pq, (dist[v], v))
    return dist

if __name__ == "__main__":
    print(*dijkastra(), sep=" ")