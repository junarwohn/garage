# -*- coding: utf-8 -*-


def TImes(x,y,z):
	
	numbers = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9] #디폴트 목록에 모든 자릿수의 숫자가 한개씩 있으면, 처음 목록에 포함 된 숫자 때문에 결과값이 달라지지는 않을 것이다.
	
	a = x*y*z
	while a > 0:
		w = a % 10
		numbers.append(w) #a에서 뽑아낸 자릿수를 numbers에 추가해준다.
		a = int(a / 10) #a에서 첫번째 자릿수를 빼낸다


	non = []
	for index in range(10):
		non.append(numbers.count(index)) #목록에서 index의 개수
	
	largest = non[0]
	
	for num in non:
		if num >= largest:
			largest = num 

	
	for non_index in range(len(non)):
		if non[non_index] == largest:
			print(non_index)
	
a = int(input())
b = int(input())
c = int(input())

TImes(a,b,c)