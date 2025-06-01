from sys import stdin, stdout
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
    
    order, dp = [], [0] * n
    while not q.empty():
        u = q.get()
        order.append(u)
        for v in g[u]:
            deg[v] -= 1
            if not deg[v]:
                q.put(v)
    
    dp[n - 1] = 1
    mod = 10 ** 9 + 7
    while order:
        u = order[-1]
        order.pop()
        for v in g[u]:
            dp[u] = (dp[u] + dp[v]) % mod
    stdout.write(f"{dp[0]}")