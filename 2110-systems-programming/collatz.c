//Name: Ethan Ward
//Class: ETEC 2110
//Assignment: Lab 2 - 'C' Performance
#include <stdio.h>

int collatz_length(long long int number);
void collatz_print_sequence(long long int number);

main()
{
    for(int i=1; 1<=1000000; i++)
    {
        int highscore = 0;
        if(collatz_length(i) > highscore)
        {
            highscore = collatz_length(i);
        }
    }
    printf(highscore);
}

int collatz_length(long long int number)
{
    int step_count = 1;
    while(number != 1)
    {
        if(number % 2 == 0)
        {
            number /= 2;
        }
        else
        {
            number++;
        }
        step_count++;
    }
    return step_count;
}

void collatz_print_sequence(long long int number)
{
    printf(number);
    while(number != 1)
    {
        printf(",");
        if(number % 2 == 0)
        {
            number /= 2;
        }
        else
        {
            number++;
        }
        printf(number);
    }
    return;
}
