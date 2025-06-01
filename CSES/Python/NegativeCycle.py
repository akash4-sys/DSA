import sys
from collections import deque

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

def findNegCycle_SPFA():
    n, g = inputGraph()
    dist = [0] * n
    par = [-1] * n
    count = [0] * n
    in_queue = [True] * n
    q = deque(range(n))

    while q:
        u = q.popleft()
        in_queue[u] = False
        for v, w in g[u]:
            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                par[v] = u
                if not in_queue[v]:
                    q.append(v)
                    in_queue[v] = True
                    count[v] += 1
                    if count[v] > n:
                        print("YES")
                        cycle = []
                        x = v
                        for _ in range(n):
                            x = par[x]
                        
                        cur = x
                        vis = set()
                        while True:
                            if cur in vis:
                                break
                            vis.add(cur)
                            cycle.append(cur + 1)
                            cur = par[cur]
                        cycle.append(cur + 1)
                        cycle.reverse()
                        print(*cycle)
                        return

    print("NO")

if __name__ == "__main__":
    findNegCycle_SPFA()