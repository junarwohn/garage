N, M = map(int, input().split())
dp_list = [-1 for _ in range(N * M + 1)]
dp_list[1] = 0
def dp_search(_N):
	if dp_list[_N] != -1:
		return dp_list[_N]
	else:
		if _N % 2 == 0:
			return 2 * dp_search(int(_N / 2)) + 1
		else:
			return dp_search(int(_N / 2)) + dp_search(int((_N + 1) / 2)) + 1
print(dp_search(N * M))
