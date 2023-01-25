import math
q = int(input())
for query in range(q):
    k, n, a, b = map(int, input().split())
    if k / n <= b:
        print(-1)
    else:
        a_max = (k - b * n) / (a -b)
        if a_max > n:
            print(n)
        else :
            print(math.ceil(a_max - 1))
