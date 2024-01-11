//Name: Ethan Ward
//Class: ETEC 2110
//Assignment: Lab 4 - Arrays, Strings, and Flow Control
#include <stdio.h>
//a -> @, A -> 4 , s -> 5, S -> $, e or E -> 3, l or L -> 1, o or O -> 0, b -> 6, B -> 8 , z or Z -> 2, t or T -> 7
void convertToLeetSpeak( char * );

int main( )
{
  printf("Enter a message: ");
  char message[1000];
  scanf("%999[^\n]s", message);

  convertToLeetSpeak(message);
  printf("%s",message);

  return 0;
}

void convertToLeetSpeak( char * text )
{
  // code to convert the string as described above.
  do
  {
    if(*text == 'a') *text = '@';
    else if(*text == 'A') *text = '4';
    else if(*text == 's') *text = '5';
    else if(*text == 'S') *text = '$';
    else if(*text == 'e' || *text == 'E') *text = '3';
    else if(*text == 'l' || *text == 'L') *text = '1';
    else if(*text == 'o' || *text == 'O') *text = '0';
    else if(*text == 'b') *text = '6';
    else if(*text == 'B') *text = '8';
    else if(*text == 'z' || *text == 'Z') *text = '2';
    else if(*text == 't' || *text == 'T') *text = '7';
  }
  while(*text++);
}
