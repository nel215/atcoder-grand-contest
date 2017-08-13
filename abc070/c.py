import fractions
import functools


def lcm(a, b):
    return a * b // fractions.gcd(a, b)


N = int(input())
T = []
for i in range(N):
    T.append(int(input()))
res = functools.reduce(lcm, T)
print(res)
