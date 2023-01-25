numlist = []
for i in range(9999):
    numlist.append(i+1)
   
def remove_num():
    n = 1
    while n < 10001:
        if n not in numlist:
            n += 1
            continue
        else:
            k = n
            while k < 10001:
                a = int(k/1000)
                b = int((k/100)%10)
                c = int((k/10)%10)
                d = k%10
                try:
                    numlist.remove(k + a + b + c + d)
                except:
                    break
                k += a + b + c + d
            n += 1

remove_num()
for l in numlist:
    print(l)