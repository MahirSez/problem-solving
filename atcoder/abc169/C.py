import math
a, b = input().split()
a = int(a)
c = int(b[0])
c = c*10 + int(b[2])
c = c*10 + int(b[3])

a *= c
a //= 100
print(a)
