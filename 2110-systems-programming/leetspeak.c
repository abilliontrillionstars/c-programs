//Name: Ethan Ward
//Class: ETEC 2110
//Assignment: Lab 4 - Arrays, Strings, and Flow Control
#include <stdio.h>
//a -> @, A -> 4 , s -> 5, S -> $, e or E -> 3, l or L -> 1, o or O -> 0, b -> 6, B -> 8 , z or Z -> 2, t or T -> 7
void convertToLeetSpeak(char* text);

int main()
{
  printf("Enter a message: ");
  char message[1000];
  scanf("%999[^\n]s", message);

  convertToLeetSpeak(message);
  printf("%s",message);

  return 0;
}

void convertToLeetSpeak(char* text)
{
  // code to convert the string as described above.
  do
  {
    switch(*text)
    {
      case 'a': *text = '@'; break;
      case 'A': *text = '4'; break;
      case 's': *text = '5'; break;
      case 'S': *text = '$'; break;
      case 'E':
      case 'e': *text = '3'; break;
      case 'L':
      case 'l': *text = '1'; break;
      case 'O':
      case 'o': *text = '0'; break;
      case 'b': *text = '6'; break;
      case 'B': *text = '8'; break;
      case 'Z':
      case 'z': *text = '2'; break;
      case 'T':
      case 't': *text = '7'; break;
    }
  }
  while(*(text++));
}
