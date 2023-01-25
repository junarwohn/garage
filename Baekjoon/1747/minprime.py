min_prime = 1000000
N = 1000000
while True:
    cnt = 0	
    for i in range(2, min_prime):
        if min_prime%i == 0:
            cnt += 1
            break
    if cnt == 0:
        break
    else:
        min_prime += 1
print(min_prime)
