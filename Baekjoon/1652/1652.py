N = int(input())
room_row = []
room_col = ['' for _ in range(N)]
for _ in range(N):
    room_row.append(input())
    for c in range(N):
        room_col[c] += room_row[-1][c]
        
cnt_row = 0
cnt_col = 0
for i, j  in zip(room_row, room_col):
    li = i.split('X')
    lj = j.split('X')
    for e in li:
        if len(e) > 1:
            cnt_row += 1
    for e in lj:
        if len(e) > 1:
            cnt_col += 1

print(str(cnt_row) + ' ' + str(cnt_col))
