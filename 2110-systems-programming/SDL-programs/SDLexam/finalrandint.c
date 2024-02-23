//Ethan Ward 301040

#include <stdio.h>
#include <stdlib.h>

int rand_int(int lower, int upper)
{
    srand((int)time(0));
    int result = rand();
    if(result =< upper && result >= lower)
        return result;
    else
        rand_int(lower, upper);

    //not my proudest solution, but the fastest to implement
}

float rand_float(float lower, float upper)
{
    srand((int)time(0));
    float result = (float)rand();
    if(result =< upper && result >= lower)
        return result;
    else
        rand_float(lower, upper);

    //again, not my proudest solution. I'm running out of time here
}
