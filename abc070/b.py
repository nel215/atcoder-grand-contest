A, B, C, D = map(int, input().split())
X = set(range(A, B))
Y = set(range(C, D))
print(len(X.intersection(Y)))
