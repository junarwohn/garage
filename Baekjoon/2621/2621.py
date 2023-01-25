card_list = []
for i in range(5):
    card_list.append(tuple(map(str, input().split())))

color_list = [i[0] for i in card_list]
num_list = [int(i[1]) for i in card_list]
color_type_list = list(set(color_list))
num_type_list = list(set(num_list))
# is all color same
if len(color_type_list) == 1:
    max_num = max(num_type_list)
    if sorted([i - max_num for i in num_list]) == [-4, -3 ,-2, -1, 0]:
        print(900 + max_num)
    else:
        print(600 + max_num)
elif len(num_type_list) == 2:
    for i in num_type_list:
        if num_list.count(i) == 4:
            print(int(i) + 800)
            break
        if num_list.count(i) == 3:
            num_type_list.remove(i)
            print(700 + int(i)*10 + int(num_type_list[0]))
elif len(num_type_list) == 5:
    max_num = max(num_type_list)
    if sorted([i - max_num for i in num_list]) == [-4, -3 ,-2, -1, 0]:
        print(max_num + 500)
    else:
        print(100 + max_num)
elif len(num_type_list) == 3:
    is_two_same = 0
    for i in num_type_list:
        if num_list.count(i) == 3:
            print(i + 400)
            break
        if num_list.count(i) == 2:
            if is_two_same == 0:
                is_two_same = i
            else:
                if is_two_same > i:
                    print(300 + is_two_same * 10 + i)
                else:
                    print(300 + i * 10 + is_two_same)
                break
elif len(num_type_list) == 4:

    for i in num_type_list:
        if num_list.count(i) == 2:
            print(200 + i)
else:
    max_num = max(num_type_list)
    print(100 + max_num)
