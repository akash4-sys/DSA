import sys
from queue import Queue

# @ Topological Sort
 
def inputGraph():
    data = list(map(int, sys.stdin.read().split()))
    n, m, idx = data[0], data[1], 2
    g = [[] for _ in range(n + 1)]
    deg = [0] * (n + 1)
    for _ in range(m):
        u, v = data[idx], data[idx + 1]
        g[u].append(v)
        deg[v] += 1
        idx += 2
    return n, g, deg
 
if __name__ == "__main__":
    n, g, deg = inputGraph()
    q = Queue()
    
    for u in range(1, n + 1):
        if not deg[u]:
            q.put(u)
    
    ans = []
    while not q.empty():
        u = q.get()
        ans.append(u)
        for v in g[u]:
            deg[v] -= 1
            if not deg[v]:
                q.put(v)

    if len(ans) == n: print(*ans)
    else: print("IMPOSSIBLE")