#Name: Ethan Ward
#Class: ETEC 2110
#Assignment: Lab 2 - 'C' Performance
#include <stdio.h> //Ha! gotcha!

import time

def collatz_length(number):
    step_count = 1
    while number != 1:
        if number % 2 == 0:
            number /= 2
        else:
            number+=1
        step_count+=1
    return step_count

def collatz_print_sequence(number):
    print(number)
    while number != 1:
        print(",")
        if number % 2 == 0:
            number /= 2
        else:
            number+=1
        print(number)
        
start = time.time()

highscore = 0
for i in range(1000000):
    if collatz_length(i) > highscore:
        highscore = collatz_length(i)
print(highscore)

end = time.time()
print("that took", end - start, "seconds!")
