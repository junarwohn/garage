import math
N = int(input())
era = [0,1]
pre = 2
while True:
    range_N = 2000000
    era += [0 for _ in range(pre, range_N + 1)]
    for devider in range(2, int((10 * N)**0.5)):
        for mul in range(math.ceil(pre / devider + 1) * devider, range_N, devider):
            era[mul] = 1
    is_found = False
#    print(era)
    for i in range(N, 2000001):
        if str(i) == str(i)[::-1] and era[i] == 0:
            is_found = True
            print(i)
            break
    if is_found:
        break
    else:
        pre = N
        N = range_N
        
