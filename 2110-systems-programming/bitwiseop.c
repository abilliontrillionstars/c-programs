//Name: Ethan Ward
//Class: ETEC 2110
//Assignment: Lab 3 - Functions, Bitwise Operators
#include <stdio.h>

void printTable(unsigned char, unsigned char);
void printBinary(unsigned char);
void printHex(unsigned char);

int main()
{
    printTable('A','Z');
}
void printTable(unsigned char startChar, unsigned char endChar)
{
 printf("num  ch  bin       hex\n");

 for(char c = startChar; c <= endChar; c++)
 {
     printf("%d   %c   ",c,c);
     printBinary(c);
     printf("  ");
     printHex(c);
     printf("\n");
 }
}

void printBinary(unsigned char ch)
{
    // shift the greater bits all the way to the right and print them one by one.
    for(int i = 0; i < 8; i++)
    {
        printf("%d", ((ch >> 7-i) & 00000001)); // the & separates the rest of the digits
    }
}
void printHex(unsigned char ch)
{
    char hexdigits[17] = "0123456789ABCDEF"; // 'dict' of hex digits
    printf("0x%c", hexdigits[(ch >> 4)]); // index the string by the upper and lower nibbles.
    printf("%c", hexdigits[(ch & 0x0F)]);
}
