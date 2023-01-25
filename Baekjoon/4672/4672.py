def sum_of_each_pos_number(n):
    return sum(int(i) for i in str(n))
def check_non_number(list, n):
    sum = n + sum_of_each_pos_number(n)
    if sum > 10000 or list[sum] == 0:
        return
    else:
        list[sum] = 0
        check_non_number(list, sum + sum_of_each_pos_number(sum))

list_ = []
for _ in range(10001):
    list_.append(1)
for i in range(1, 10000):
    check_non_number(list_, i)
for i in range(1, 10000):
    if list_[i] == 1:
        print(i)
