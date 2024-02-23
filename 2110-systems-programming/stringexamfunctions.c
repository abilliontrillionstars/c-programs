//Name: Ethan Ward
//Class: ETEC 2110
//Assignment: Midterm Exam
#include <stdio.h>

void stringReverse(char * string);
void cryptogramify(char * message);
void rhombus(unsigned int size);
void rhombus2(unsigned int size);

void main()
{
  char buffer[] = "HELLO WORLD!!";
  //stringReverse(buffer);
  printf("%s\n", buffer);
  rhombus(8);
  rhombus2(5);
}


void stringReverse(char * string)
{
  int length = 0;
  while(*string++)
    length++;

  char newString[length + 1];

  for(int i = 1; i < length; i++)
  {
    newString[i - 1] = string[length - i];
  }
  newString[length + 1] = '\0';

  for(int i = 0; i < length; i++)
  {
    string[i] = newString[i];
  }
}

void cryptogramify(char * message)
{
  char alphabet[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  while(*message++)
  {
    for(int i = 0; i < 27; i++)
    {
      if(*message == alphabet[i])
      {
        *message = alphabet[26 - i];
        break;
      }
    }
  }
}

void rhombus(unsigned int size)
{
  for(int i = 0; i < size; i++)
  {
    for(int j = 0; j < size - i; j++)
      printf(" ");
    for(int j = 0; j < size; j++)
      printf("* ");
    printf("\n");
  }
}

void rhombus2(unsigned int size)
{
  for(int i = 0; i < size; i++)
  {
    for(int j = 0; j < size - i; j++)
      printf(" ");
    if(!i || i == size - 1)
    {
      printf("*");
      for(int j = 0; j < size + 2; j++)
        printf("-");
      printf("*");
    }
    else
    {
      for(int j = 0; j < size; j++)
        if(!j || j == size - 1)
          printf("/ ");
        else
          printf("* ");
    }
    printf("\n");
  }
}
