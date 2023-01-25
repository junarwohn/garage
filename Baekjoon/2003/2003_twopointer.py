sum = start = end = 0
N, M = map(int, input().split()) 
input_list = list(map(int, input().split()))        
result = 0
for element in input_list:
    sum += element
    end += 1
    while sum >= M:
        if sum == M:
            result += 1
        sum -= input_list[start]
        start += 1
print(result)
