class Frac(object):
    def __init__(self, a, b):
        self.a = a
        self.b = b

    def eq(self, f):
        return self.a * f.b == f.a * self.b

    def lt(self, f):
        return self.a * f.b > f.a * self.b

    def __repr__(self):
        return '%.6f' % (self.a / self.b)


def factorial(n):
    res = 1
    for i in range(n):
        res *= i+1
    return res


def nCr(n, r):
    return factorial(n) // factorial(r) // factorial(n - r)


N, A, B = map(int, input().split())
V = list(map(int, input().split()))
V.sort(reverse=True)

res = None
for i in range(A, B+1):
    now = Frac(sum(V[:i]), i)
    if res is None or now.lt(res[0]):
        res = [now]
    elif now.eq(res[0]):
        res.append(now)

cnt = 0
for now in res:
    p = V[:now.b]
    n = len(list(filter(lambda x: x == p[-1], V)))
    r = len(list(filter(lambda x: x == p[-1], p)))
    cnt += nCr(n, r)

print(res[0])
print(cnt)
