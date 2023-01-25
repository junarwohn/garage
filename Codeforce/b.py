q = int(input())
for query in range(q):
    n, k = map(int, input().split())
    prices = list(map(int, input().split()))
    if min(prices) + k >= max(prices) -k:
        print(min(prices) + k)
    else:
        print(-1)