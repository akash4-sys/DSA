from sys import stdin, stdout, exit
from queue import Queue
 
def inputGraph():
    data = list(map(int, stdin.read().split()))
    n, m, idx = data[0], data[1], 2
    g = [[] for _ in range(n)]
    deg = [0] * n
    for _ in range(m):
        u, v = data[idx], data[idx + 1]
        g[u - 1].append(v - 1)
        deg[v - 1] += 1
        idx += 2
    return n, g, deg
 
if __name__ == "__main__":
    n, g, deg = inputGraph()
    q = Queue()
    
    for u in range(n):
        if not deg[u]:
            q.put(u)
    
    order, dist, next = [], [0] * n, [0] * n
    while not q.empty():
        u = q.get()
        order.append(u)
        for v in g[u]:
            deg[v] -= 1
            if not deg[v]:
                q.put(v)
    
    dist[n - 1] = 1
    while order:
        u = order[-1]
        order.pop()
        for v in g[u]:
            if dist[v] and dist[v] + 1 > dist[u]:
                dist[u] = dist[v] + 1
                next[u] = v
    
    if not dist[0]:
        stdout.write("IMPOSSIBLE\n")
        exit()
    
    stdout.write(f"{dist[0]}\n")
    u = 0
    next[n - 1] = -1
    while u != -1:
        stdout.write(f"{u + 1} ")
        u = next[u]