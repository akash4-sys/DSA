import sys
sys.setrecursionlimit(10**6)

# find cycle in directed graph
 
def inputGraph():
    data = list(map(int, sys.stdin.read().split()))
    n, m, idx = data[0], data[1], 2
    g = [[] for _ in range(n + 1)]
    for _ in range(m):
        u, v = data[idx], data[idx + 1]
        g[u].append(v)
        idx += 2
    return n, g
 
def solve():
    n, g = inputGraph()
    vis, ans = [0] * (n + 1), []
    
    def dfs(u):
        vis[u] = 1
        for v in g[u]:
            if vis[v] == 1 or (not vis[v] and dfs(v)):
                ans.append(v)
                return 1
        vis[u] = 2
        return 0
    
    cycle = 0
    for c in range(1, n + 1):
        if not vis[c]:
            cycle = dfs(c)
            if cycle: break
    
    if not cycle:
        print("IMPOSSIBLE")
        return
    
    start, i = ans[0], 1
    while i < len(ans) and ans[i] != start: i += 1
    print(i + 1)
    for j in range(i - 1, -1, -1):
        print(ans[j], end = " ")
    print(ans[i - 1])
 
if __name__ == "__main__":
    solve()