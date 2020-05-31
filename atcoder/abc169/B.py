n = int(input())
ara = list(map(int, input().split()))
ara.sort()
ret = 1

mx = 10**18

for val in ara:
	ret *= val
	if ret > mx:
		print(-1)
		exit(0)

print(ret)