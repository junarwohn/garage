def init(star_list, n):
        for i in range(n):
                star_list.append(" " * (2 * n -1))
        for i in range(n):
                star_list[i] = star_list[i][:n - i - 1] + "*"*(2 * i + 1) + star_list[i][n + i:]

def erase_pyramid(star_list, row, col, height):
        if height <= 3:
                star_list[row + 1] = star_list[row + 1][:col] + " " + star_list[row + 1][col + 1:] 
                # print(star_list[row])
        else:
                erase_range = int(height/2 - 1)
                erase_row_s = int(row + (height) / 2)
                erase_col_s = int(col)
                for y in range(erase_row_s, row + height):
                        star_list[y] = star_list[y][:erase_col_s - erase_range] + " "*(2*erase_range + 1) + star_list[y][erase_col_s + erase_range + 1:]
                        erase_range = erase_range - 1
                erase_pyramid(star_list, row, col, int(height/2))
                erase_pyramid(star_list, row + int(height/2), col - int(height/2), int(height/2))
                erase_pyramid(star_list, row + int(height/2), col + int(height/2), int(height/2))

N = int(input())
star_arr = []
init(star_arr, N)
erase_pyramid(star_arr, 0, N - 1, N)
for line in star_arr:
        print(line)