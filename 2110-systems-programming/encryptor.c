//Name: Ethan Ward
//Class: ETEC 2110
//Assignment: Lab 4 - Arrays, Strings, and Flow Control
#include <stdio.h>
#include <string.h>

void crypt(char*, int, char*);


int main()
{
  printf("Enter a message: ");
  char message[1000];
  scanf("%999[^\n]s", message);

  printf("\nEncryption key: ");
  char key[1000];
  scanf("%999s", key);

  crypt(message, 0, key);
  printf("\n\n%s", message);

  crypt(message, 0, key);
  printf("\n%s", message);
  return 0;
}
void crypt( char * message, int length, char * key)
{
 // code to encrypt the message using XOR with the key string.
 for(int i = 0; i < strlen(message); i++)
 {
   message[i] ^= key[i % strlen(key)];
 }
}

