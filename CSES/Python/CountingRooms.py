from queue import Queue

dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]
n, m = map(int, input().split())
grid = [list(input()) for _ in range(n)]

def bfs(a, b):
    q = Queue()
    q.put((a, b))
    grid[a][b] = '#'
    while not q.empty():
        i, j = q.get()
        for dx, dy in dirs:
            x, y = i + dx, j + dy
            if 0 <= x < n and 0 <= y < m and grid[x][y] == '.':
                grid[x][y] = '#'
                q.put((x, y))

ans = 0
for i in range(n):
    for j in range(m):
        if grid[i][j] == '.':
            bfs(i, j)
            ans += 1
print(ans)