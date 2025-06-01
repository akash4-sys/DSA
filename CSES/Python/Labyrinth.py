from queue import Queue

dirs = [(-1, 0, 'U'), (1, 0, 'D'), (0, -1, 'L'), (0, 1, 'R')]
n, m = map(int, input().split())
grid = [list(input()) for _ in range(n)]
path = dict()

def f(x, y):
    return x * 1000 + y

def bfs(a, b):
    q = Queue()
    q.put(f(a, b))
    while not q.empty():
        idx = q.get()
        i, j = idx // 1000, idx % 1000
        if grid[i][j] == 'B':
            return i, j
        grid[i][j] = '#'
        for dx, dy, di in dirs:
            x, y = i + dx, j + dy
            if 0 <= x < n and 0 <= y < m and grid[x][y] != '#':
                path[f(x, y)] = di
                q.put(f(x, y))
    return -1, -1

for i in range(n):
    for j in range(m):
        if grid[i][j] == 'A':
            x, y = bfs(i, j)
            if x != -1:
                ans = ""
                while not (x == i and j == y):
                    ch = path[f(x, y)]
                    ans += ch
                    for dx, dy, di in dirs:
                        if di == ch:
                            x -= dx
                            y -= dy
                            break
                print(f'YES\n{len(ans)}\n{ans[::-1]}')
            else:
                print("NO")
            break