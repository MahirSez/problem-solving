import math

MOD = 10**9 + 7
n = int(input())
mp = {}
ans1 = 0


def process(lst):
	a = lst[0]
	b = lst[1]
	gcd = math.gcd(a, b)
	a //= gcd
	b //= gcd
	if b < 0:
		a *= -1
		b *= -1
	a = abs(a) if b == 0 else a
	b = abs(b) if a == 0 else b
	lst[0] = a
	lst[1] = b
	return lst


for _ in range(n):
	a, b = map(int, input().split())
	if a == 0 and b == 0:
		ans1 += 1
		continue

	a, b = process([a, b])
	mp.setdefault((a, b), 0)
	mp[(a, b)] += 1

	a, b = process([-b, a])
	y = mp.setdefault( (a, b), 0)

ans = 1

taken = {}

for a, b in mp:
	if taken.get((a, b), 0):
		continue
	taken.setdefault((a, b), 0)
	taken[(a, b)] = 1

	x = mp.get( (a, b), 0)

	# print(a, b, x, end=" + ")
	a, b = process([-b, a])
	y = mp.get( (a, b), 0)

	taken.setdefault((a, b), 0)
	taken[(a, b)] = 1

	# print(a, b, y)
	ans = (ans * ( pow(2, x, MOD) + pow(2, y, MOD) - 1 + MOD) % MOD ) % MOD
	# print(ans)


ans = ( ans - 1 + ans1 + MOD ) % MOD
print(ans)




