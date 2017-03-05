N, K = map(int, input().split())
A = sorted(map(int, input().split()))
B = [i for i in range(K)]
print(sum(A[:K])+sum(B))

