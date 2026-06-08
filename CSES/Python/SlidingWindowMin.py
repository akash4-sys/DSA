# input
n, k = map(int, input().split())
x, A, B, C = map(int, input().split())
 
# Sparse Table
LOG, N = 10, 10**18
mat = [[N] * LOG for _ in range(n + 1)]
for i in range(n):
    mat[i][0] = x
    x = (A * x + B) % C
 
for j in range(1, LOG):
    for i in range(n):
        if i + (1 << (j - 1)) >= n: break
        mat[i][j] = min(mat[i][j - 1], mat[i + (1 << (j - 1))][j - 1])
 
def query(l, r):
    ln = r - l + 1
    c = ln.bit_length() - 1
    return min(mat[l][c], mat[r - (1 << c) + 1][c])
 
# Solve 
res = 0
for i in range(n - k + 1):
    res ^= query(i, i + k - 1)
print(res)