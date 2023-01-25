n, k = map(int, input().split())
a = list(map(int, input().split()))
cnt_arr = [0 for i in range(n + 1)]
for e in a:
    cnt_arr[e] += 1
is_possible = True
for c in cnt_arr:
    if c > k:
        is_possible = False
if is_possible:
    print("YES")
    answer_arr = [0 for i in range(n)]
    for i, e in enumerate(a):
        answer_arr[i] = cnt_arr[e]
        cnt_arr[e] -= 1
    print(*answer_arr)
else:
    print("NO")

비우는것 체크