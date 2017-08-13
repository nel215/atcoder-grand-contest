n = input()
rev = ''.join(list(reversed(n)))
res = 'Yes' if int(n) == int(rev) else 'No'
print(res)
