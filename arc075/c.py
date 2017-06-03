N = int(input())
S = [int(input()) for i in range(N)]
T = list(filter(lambda x: x % 10 > 0, S))
res = sum(S)
if res % 10 == 0:
    if len(T) == 0:
        res = 0
    else:
        res -= min(T)

print(res)
