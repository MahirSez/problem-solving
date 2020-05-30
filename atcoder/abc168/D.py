from collections import deque


n, m = map(int, input().split())
edg = [[] for i in range(n+1)]
ans = [-1]*(n+1)


for _ in range(m):
	u, v = map(int, input().split())
	edg[u].append(v)
	edg[v].append(u)



def bfs():
	q = deque()
	q.append(1)
	ans[1] = 1

	while q:
		top = q[0]
		q.popleft()
		for child in edg[top]:
			if ans[child] == -1:
				# print(str(top) + " --> " + str(child))
				ans[child] = top
				# print(ans[child])
				q.append(child)


bfs()
if -1 in ans[1:]:
	print("No")
else:
	print("Yes")
	for i in ans[2:]:
		print(i)
