N = int(input())
lottery = list(map(int, input().split()))
lottery[:] = [i - 1 for i in lottery]
lot_result = lottery[:]

def draw(_status, _lottery):
    result = [0 for i in range(len(_status))]
    for i, l in enumerate(_status):
        result[_lottery[i]] = l
    return result

is_possible = True 
for i, e in enumerate(lottery):
    if i == e:
        print("-1")
        is_possible = False
        break
if is_possible:
    print("1000003")
    '''
    min_prime = N
    while True:
        cnt = 0	
        for i in range(2, min_prime):
            if min_prime%i == 0:
                break
        if cnt == 0:
            break
        else:
            min_prime += 1
    result = 1
    lot_result = draw(lot_result, lottery)
    for i in range(min_prime):
        result += 1
        lot_result = draw(lot_result, lottery)
        check = [i for i, j in zip(lot_result, lottery) if i == j]
        if len(check) == 0:
            print(result)
            break
    if result >= min_prime:
        print("-1")
    '''
    
