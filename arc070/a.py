X = int(input())

for i in range(100000):
    s = i * (i + 1) / 2
    if s >= X:
        print(i)
        break
