//Name: Ethan Ward
//Class: ETEC 2110
//Assignment: Lab 2 - 'C' Performance
#include <stdio.h>
#include <time.h>

int collatz_length(long long int number);
int collatz_print_sequence(long long int number);

int main()
{
    time_t start_stamp = time(NULL);

    int highscore = 0;
    int champion = 0;
    for(int i=1; i<=1000000; i++)
    {
        int current = collatz_length(i); 
        if(current > highscore)
        {
            highscore = current;
            champion = i;
        }
    }
    printf("\n---High Score is!: <<%d>> with %d steps ---\n", champion, highscore);
    printf("High Score's sequence is as follows: ");
    collatz_print_sequence(champion);
    printf("\n\nThat took around %d seconds!\n", time(NULL)-start_stamp);
    return 0;
}

int collatz_length(long long int number)
{
    int tmp = number;
    int step_count = 1;
    while(tmp != 1)
    {
        if(tmp % 2 == 0)
            tmp /= 2;
        else
            tmp = (tmp*3)+1;
        step_count++;
    }
    printf("Step count of %d: %d\n", number, step_count);
    return step_count;
}

int collatz_print_sequence(long long int number)
{
    printf("%d", number);
    while(number != 1)
    {
        printf(",");
        if(number % 2 == 0)
            number /= 2;
        else
            number++;
        printf("%d", number);
    }
    return 0;
}
