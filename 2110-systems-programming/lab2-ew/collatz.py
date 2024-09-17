#Name: Ethan Ward
#Class: ETEC 2110
#Assignment: Lab 2 - 'C' Performance

#include <stdio.h> //Ha! gotcha!
import time

print("starting!!")
def collatz_length(number):
    step_count = 1
    tmp = number
    while tmp != 1:
        if tmp % 2 == 0:
            tmp = int(tmp//2)
        else:
            tmp = tmp*3 + 1
        step_count+=1
    print(f"{number} took {step_count} steps!")
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
        


start_stamp = time.time();

highscore = 0
champion = 0
for i in range(1, 1000000):
    current = collatz_length(i) 
    if current > highscore:
        highscore = current
        champion = i


print(f"\n---High Score is!: {champion} with {highscore} steps ---")
print("High Score's sequence is as follows: ")
collatz_print_sequence(champion)
print(f"\n\nThat took around {time.time()-start_stamp} seconds!\n")
