q = int(input())
garland = [c for c in input()]
original_list = garland[:]
check_list = ['R', 'G', 'B']
is_pass = False
while not is_pass:
    is_pass = True
    for checker in check_list:
        for start_index in range(q - 1):
            standard = garland[start_index]
            for i in range(1, min(3, q - start_index)):
                if standard == garland[start_index + i]:
                    garland[start_index + i] = checker
                    is_pass = False
changes = 0
for a, b in zip(garland, original_list):
    if a != b:
        changes += 1
print(changes)
print(*garland, sep='')