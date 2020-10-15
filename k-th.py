import random

def partition(a, pivot, high):
    i = pivot + 1
    j = high
    while True:
        while i <= high and a[pivot] > a[i]:
            i += 1
        while j > pivot and a[j] > a[pivot]:
            j -= 1
        if j <= i:
            break
        a[i], a[j] = a[j], a[i]
        i += 1
        j -= 1
    a[pivot], a[j] = a[j], a[pivot]
    return j


def selection(a, low, high, n):
    pivot = partition(a, low, high)
    if n < pivot:
        return selection(a, low, pivot - 1, n)
    elif n == pivot:
        return a[pivot]
    else:
        return selection(a, pivot + 1, high, n)


random_list = [i for i in range(10000)]
for i in range(10000):
    random.shuffle(random_list)
    result = selection(random_list, 0, len(random_list) -1, i)
    random_list.sort()
    if result != random_list[i]:
        print("error occured!", i)
    if i % 1000 == 0:
        print(i)