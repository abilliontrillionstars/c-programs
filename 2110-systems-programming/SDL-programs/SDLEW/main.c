//Name: Ethan Ward
//Class: ETEC 2110
//Assignment: Lab 5 - Game of Life
#include <stdio.h>
#include <string.h>
#include "gameoflife.h"
#include "gameoflife.c"


void main()
{
  char board[BOARD_WIDTH][BOARD_HEIGHT];
  init_board(board, 300);
 
  char input[10];
  while(strcmp("q", input) && strcmp("quit", input) && strcmp(input, "exit"))
  {
    display_board(board);
    printf("\ninput a character or two and press the enter key continue, or input 'quit','q', or 'exit' to stop.\ninput:  ");
    scanf("%4s", input);
    next_generation(board);
  }
  printf("\n\n\ndone!!\n\n\n");
  return;
}
