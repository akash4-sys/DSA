from sys import setrecursionlimit, stdin
from queue import Queue
setrecursionlimit(10**6)

next = list(map(int, stdin.read().split()))
n = next[0]
next.pop(0)
vis, dist = [0] * n, [0] * n
path, steps = Queue(), 0

def dfs(u):
    global steps
    path.put(u)
    if vis[u]:
        steps += dist[u]
        return u

    vis[u] = 1
    steps += 1
    return dfs(next[u] - 1)

for i in range(n):
    if not vis[i]:
        steps = 0
        v = dfs(i)
        dec = 1
        while not path.empty():
            u = path.get()
            if u == v: dec = 0
            dist[u] = steps
            steps -= dec
print(*dist)