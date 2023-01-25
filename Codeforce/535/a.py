q = int(input())
for i in range(q):
    l1, r1, l2, r2 = map(int, input().split())
    try:
        if l1 < r2:
            p1 = l1
            p2 = r2
            for p1 in range(l1, r1 + 1):
                for p2 in range(r2, l2 - 1, -1):
                    if p1 != p2:
                        print('{} {}'.format(str(p1), str(p2)))
                        raise Exception          
        elif l2 < r1:
            p2 = l2
            p1 = r1
            for p2 in range(l2, r2 + 1):
                for p1 in range(r1, l1 - 1, -1):
                    if p1 != p2:
                        print('{} {}'.format(str(p1), str(p2)))
                        raise Exception
    except:
        pass