import openpyxl
f = open("tmp_table_code.txt", "w", encoding="utf-8-sig")
FILE_PATH = input()
if FILE_PATH[0] == '"' and FILE_PATH[-1] == '"':
    FILE_PATH = FILE_PATH[1:-1]

wb = openpyxl.load_workbook(FILE_PATH)
ws = wb.active
li = []

for r in ws.rows:
    result_str = "INSERT INTO @TargetTable VALUES("
    for i in range(len(r)):
        result_str += "'" + str(r[i].value) + "',"
    result_str = result_str[:-1]
    result_str += ")\n"
    li.append(result_str)
    f.write(result_str)

print(li)
wb.close()
f.close()
