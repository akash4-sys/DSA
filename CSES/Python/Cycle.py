import sys
sys.setrecursionlimit(10**6)

# Find any valid cycle in directed graph
 
def inputGraph():
    data = list(map(int, sys.stdin.read().split()))
    n, m, idx = data[0], data[1], 2
    g = [[] for _ in range(n + 1)]
    for _ in range(m):
        u, v = data[idx], data[idx + 1]
        g[u].append(v)
        g[v].append(u)
        idx += 2
    return n, m, g
 
def solve():
    n, m, g = inputGraph()
    vis = [0] * (n + 1)
    path = [0] * (n + 1)
    
    def dfs(par, u, cycle):
        cycle += 1
        vis[u] = cycle
        for v in g[u]:
            if not vis[v]:
                path[v] = u
                res = dfs(u, v, cycle)
                if res:
                    return res
            elif v != par and vis[v] < vis[u]:
                print(vis[u] - vis[v] + 2)
                path[v] = u
                return v
        vis[u] = cycle
        return 0
    
    u, start = 0, 0
    for c in range(1, n + 1):
        if not vis[c]:
            u = dfs(0, c, 0)
            if u:
                break
    
    if not u:
        print("IMPOSSIBLE")
        return
    
    while u != start:
        if not start: start = u
        print(u, end = " ")
        u = path[u]
    print(u, end = " ")
 
if __name__ == "__main__":
    solve()