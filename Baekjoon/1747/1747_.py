N = int(input())
era = [0]
pre = 0
while True:
    range_N = 10 * N
    if range_N > 1000000:
        range_N = 1000000
    era += [0 for _ in range(pre, range_N)]
    pre += 1
    for devider in range(2, int((10 * N)**0.5) + 1):
        for mul in range(int(pre / devider + 1) * devider, range_N, devider):
            era[mul] = 1
    is_found = False
    for i in range(N, 10*N + 1):
        if str(i) == str(i)[::-1] and era[i] == 0:
            is_found = True
            print(i)
            break
    if is_found:
        break
    else:
        pre = N
        N = range_N
        
