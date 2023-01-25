stack = []
N, M = map(int, input().split()) 
input_list = list(map(int, input().split()))        
result = 0
for element in input_list:
    sum += element
    end += 1
    stack.append(element)          
    while sum(stack) >= M:
        if sum(stack) == M:
            result += 1
        stack.pop(0)
print(result)
