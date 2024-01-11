//Name: Ethan Ward
//Class: ETEC 2110
//Assignment: Lab 5 - Game of Life
#include <stdio.h>
#include <string.h>
#include "game_of_life.h"
#include "gameoflife.c"

void main()
{
  char board[BOARD_WIDTH][BOARD_HEIGHT];
  init_board(board, 300);

  char input[5];
  strcpy(input, "wah."); // just in case our user is so unlucky that the program would quit itself
  while(input != "q" && input != "quit" && input != "exit")
  {
    display_board(board);
    printf("\ninput a character or two and press the enter key continue, or input 'quit','q', or 'exit' to stop.\ninput:  ");
    scanf("%4s", input);
    next_generation(board);
  }
}
