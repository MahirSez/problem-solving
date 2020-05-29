import sys
s = input()
a, b, c, k = s.split()

a = int(a)
b = int(b)
c = int(c)
k = int(k)


ans = 0
if k <= a:
	print(k)
	sys.exit()
ans += a
k -= a

if k <= b:
	print(ans)
	sys.exit()
k -= b

print(ans - k)
