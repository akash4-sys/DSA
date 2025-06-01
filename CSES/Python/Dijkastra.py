import sys
from heapq import *

def inputGraph():
    data = list(map(int, sys.stdin.read().split()))
    n, m, k, idx = data[0], data[1], data[2], 3
    g = [[] for _ in range(n)]
    for _ in range(m):
        u, v, w = data[idx], data[idx + 1], data[idx + 2]
        g[u - 1].append((v - 1, w))
        idx += 3
    return n, k, g
 
def dijkastra():
    n, k, g = inputGraph()
    pq, vis = [(0, 0)], [0] * n
    
    while len(pq):
        w, u = heappop(pq)
        if vis[u] >= k:
            continue
        if u == n - 1:
            print(w, end=" ")
        vis[u] += 1
        for v, cw in g[u]:
            heappush(pq, (w + cw, v))
    return
 
if __name__ == "__main__":
    dijkastra()