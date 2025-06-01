import sys

sys.setrecursionlimit(10**6)

def dfs(u, g,  col):
    for v in g[u]:
        if col[u] == col[v]:
            return 0
        if col[v] == -1:
            col[v] = col[u] ^ 1
            if not dfs(v, g, col):
                return 0
    return 1

def solve():
    data = list(map(int, sys.stdin.read().split()))
    n, m, idx = data[0], data[1], 2
    g = [[] for _ in range(n + 1)]
    col = [-1] * (n + 1)
    for _ in range(m):
        u, v = data[idx], data[idx + 1]
        g[u].append(v)
        g[v].append(u)
        idx += 2
    
    for u in range(n):
        if col[u] == -1:
            col[u] = 0
            if not dfs(u, g, col):
                print("IMPOSSIBLE")
                return
    
    for i in range(1, n + 1):
        print(col[i] + 1, end = " ")

if __name__ == "__main__":
    solve()