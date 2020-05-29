import sys

n, k = map(int, input().split())
ara = [0]
ara += list( map(int, input().split()) )

now = 1
vis = []
taken = [0]*(n+1)

while taken[now] == 0:
	vis.append(now)
	taken[now] = 1
	now = ara[now]

cycleLen = len(vis) - vis.index(now)

if k < vis.index(now):
	print(vis[k])
	sys.exit()

k -= vis.index(now)

k %= cycleLen

print(vis[k + vis.index(now) ])



