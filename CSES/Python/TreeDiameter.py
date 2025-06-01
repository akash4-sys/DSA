def dfs(depth, u, par):
    for v in g[u]:
        if v != par:
            depth[v] = depth[u] + 1
            dfs(depth, v, u)

def diameter(g):
    a, b, n = 0, 0, len(g)
    depth = [0] * n
    dfs(depth, 1, 0)
    for i, d in enumerate(depth):
        if depth[a] < d:
            a = i

    depth[a] = 0
    dfs(depth, a, 0)
    for i, d in enumerate(depth):
        if depth[b] < d:
            b = i
    return b, depth

if __name__ == "__main__":
    n = int(input())
    g = [[] for _ in range(n + 1)]
    for _ in range(n - 1):
        u, v = list(map(int, input().split()))
        g[u].append(v)
        g[v].append(u)

    b, depth_a = diameter(g)
    depth_b = [0] * (n + 1)
    dfs(depth_b, b, 0)
    for i in range(1, n + 1):
        print(max(depth_a[i], depth_b[i]), end = " ")