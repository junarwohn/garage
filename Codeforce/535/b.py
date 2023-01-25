def get_divisor_list(num):
    result = []
    for i in range(1, num+1):
        if num % i == 0:
            result.append(i)
    return result
q = int(input())
input_dividor_list = list(map(int, input().split()))
b = max(input_dividor_list)
b_divisor_list = get_divisor_list(b)
for e in b_divisor_list:
    input_dividor_list.remove(e)
a = max(input_dividor_list)
print("{} {}".format(str(a), str(b)))