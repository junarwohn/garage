import random
import time
a = random.randint(0, 10)
b = random.randint(0, 10)
for i in range(5) :
    x = random.randint(0, 10)
    print(str(x) + " : " + str(a * x + b))

t_end = time.time() + 10;
score = 0
while time.time() < t_end:
    q_x = random.randint(0, 20)
    answer = a * q_x + b
    print(str(q_x) + "?\n")
    submit = int(input())
    if answer == submit :
        score = score + 1
print(a , b)
print(score)