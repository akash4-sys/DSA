import sys

def solve(n, a, b):
    if a + b > n:
        print("NO")
        return
    
    B, k = [0] * n, 1
    for i in range(n, a + b, -1):
        B[i - 1] = i
    for i in range(b):
        B[i] = i + a + 1
    for i in range(b, a + b):
        B[i] = k
        k += 1    
    for i in range(n):
        a -= i + 1 > B[i]
        b -= i + 1 < B[i]

    if a != 0 or b != 0:
        print("NO")
        return
    print("YES")
    for i in range(n): print(i + 1, end = " ")
    print("")
    print(*B)

data = list(map(int, sys.stdin.read().split()))
i = 1
for _ in range(data[0]):
    solve(data[i], data[i + 1], data[i + 2])
    i += 3