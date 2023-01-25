n = int(input())
s = input()
cnt_arr = [-1 * (n / 3) for i in range(3)]
for c in s:
    cnt_arr[int(c)] += 1
answer_arr = [-1 for i in range(n)]
for i in range(3):
    




for i, c in enumerate(s):
    cnt_of_c = cnt_arr[int(c)]
    if cnt_of_c > 0:
        for replace_num in range(3):
            if cnt_arr[replace_num] < 0:
                answer_arr[i] = replace_num
                cnt_arr[int(c)] -= 1
                cnt_arr[replace_num] += 1
                break
    else:
        answer_arr[i] = int(c)
print(*answer_arr, sep="")