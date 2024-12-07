//Name: Ethan Ward
//Class: ETEC 2110
//Assignment: Lab 5 - Game of Life
#include <stdio.h>
#include <string.h>
#include "gameoflife.h"
#include "gameoflife.c"

void main()
{
  int board[BOARD_WIDTH][BOARD_HEIGHT];
  init_board(board, 100);

  char input[10];
  while(strcmp(input,"q") && strcmp(input,"quit") && strcmp(input,"exit"))
  {
    display_board(board);
    printf("\ninput a character or two and press the enter key continue, or input 'quit','q', or 'exit' to stop.\ninput:  ");
    scanf("%4[^\n]s", input);
    getchar();
    next_generation(board); 
  }
  printf("\n\n\ndone!\n\n\n");
}
