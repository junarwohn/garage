l = []
for i in range(1000):
    l.append(i+1) # 1 to 1000 in l
del l[0] # now no 1 at the beginning
def eras(k, h):
    for j in range(2, 500):
        if h[h.index(k)] == 0:
            continue
        else:
            try:
                h[h.index(k*j)] = 0
            except:
                pass
for i in l:
    eras(i,l)

print(l)
