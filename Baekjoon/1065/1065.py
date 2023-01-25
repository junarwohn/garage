input_num = input()
if len(input_num) < 3:
    print(input_num)
else:
    result = 99
    for i in range(100, int(input_num) + 1):
        if int(str(i)[0]) + int(str(i)[2]) == 2 * int(str(i)[1]):
            result = result + 1
    print(result)