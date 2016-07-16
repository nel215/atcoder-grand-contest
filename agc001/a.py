import sys

N = int(sys.stdin.readline())
L = list(map(int, sys.stdin.readline().split()))
L.sort()
res = 0
for i in range(N):
    res += L[i*2]
print(res)
