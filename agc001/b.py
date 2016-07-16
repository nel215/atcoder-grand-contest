

def rec(a, b):
    mx = max(a, b)
    mn = min(a, b)
    #print(mn, mx//mn)
    if mx % mn == 0:
        return (2 * (mx // mn) - 1) * mn
    return (2 * mn * (mx // mn)) + rec(mn, mx % mn)

N, X = list(map(int, input().split()))
#print(N, X)

print(rec(N-X, X) + N)
