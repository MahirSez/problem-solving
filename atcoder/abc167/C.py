n, m, x = map(int, input().split())
inn = [ list( map(int, input().split() ) ) for _ in range(n) ]
c = [inn[_][0] for _ in range(n) ]
ara = [ inn[_][1:] for _ in range(n)]

ans = 1e9

for mask in range(2**n):
	cost = 0
	cnt = [0 for _ in range(m)]
	for i in range(n):
		if ( (1 << i) & mask ) == 0:
			continue
		cost += c[i]
		for j in range(m):
			cnt[j] += ara[i][j]
	ok = 1
	for i in range(m):
		if cnt[i] < x:
			ok = 0
	if ok:
		ans = min(ans, cost)

if ans == 1e9:
	ans = -1

print(ans)



