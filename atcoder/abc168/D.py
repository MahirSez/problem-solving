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
		top = q.popleft()
		for child in edg[top]:
			if ans[child] == -1:
				ans[child] = top
				q.append(child)


bfs()

if -1 in ans[1:]:
	print("No")
else:
	print("Yes")
	print("\n".join(map(str, ans[2:])))
