n, x, y = map(int, input().split())
a = list(map(int, input().split()))
if x > y:
    print(n)
elif x <= y:
    insecure_doors = 0
    for e in a:
        if e <= x:
            insecure_doors += 1
    print(int((insecure_doors + 1) / 2))