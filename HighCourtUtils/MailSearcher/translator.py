import csv
f = open('list.csv', 'r', encoding='utf-8')
rdr = csv.reader(f)
list_ = []
for l in rdr:
    list_.append(l[0] + "  " + l[1])

fh = open("data__.txt","w")

print(list_, file=fh)
fh.close()
