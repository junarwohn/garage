input_num = int(input())
while True:
    sum_input = 0
    for e in list(str(input_num)):
        sum_input += int(e)
    if sum_input % 4 == 0:
        break
    input_num += 1
print(input_num)