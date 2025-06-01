import sys
sys.setrecursionlimit(10**6)
 
def inputGraph():
    data = list(map(int, sys.stdin.read().split()))
    n, m, idx = data[0], data[1], 2
    g = [[] for _ in range(n)]
    rg = [[] for _ in range(n)]
    for _ in range(m):
        u, v = data[idx], data[idx + 1]
        g[u - 1].append(v - 1)
        rg[v - 1].append(u - 1)
        idx += 2
    return n, g, rg
 
def solve():
    n, g, rg = inputGraph()
    vis = [0] * n
    
    def dfs(adj, u):
        vis[u] = 1
        for v in adj[u]:
            if not vis[v]:
                dfs(adj, v)
    
    dfs(g, 0)
    for i in range(n):
        if not vis[i]:
            print(f"NO\n1 {i + 1}")
            return

    vis = [0] * n
    dfs(rg, 0)
    for i in range(n):
        if not vis[i]:
            print(f"NO\n{i + 1} 1")
            return
    print("YES")

if __name__ == "__main__":
    solve()