height_list = []
for i in range(9):
    height_list.append(int(input()))
height_list.sort()
sum_of_all = sum(height_list)
rest = sum_of_all - 100
for i in height_list: 
    if rest - i in height_list:
        height_list.remove(rest - i)
        height_list.remove(i)
        break
print(*height_list, sep=' ')
