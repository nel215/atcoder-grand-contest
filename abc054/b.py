N, M = map(int, input().split())
A, B = [], []
for _ in range(N):
    A.append(input())
for _ in range(M):
    B.append(input())

res = False
for sy in range(N - M + 1):
    for sx in range(N - M + 1):
        ok = True
        for dy in range(M):
            y = sy + dy
            a = A[y][sx:sx + M]
            ok = ok and a == B[dy]
        res = res or ok
print("Yes" if res else "No")

