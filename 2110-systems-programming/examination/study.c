
#include <string.h>
#include <stdio.h>
#include <stdlib.h>



void main()
{
    char* str = "aiwudnaiwbd"; // deref happens FIRST! vvv
    printf("char %c at %p, char %c at %p.", *str, str, *str+2, str);

}