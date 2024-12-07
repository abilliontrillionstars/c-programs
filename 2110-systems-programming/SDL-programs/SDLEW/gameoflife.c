//Name: Ethan Ward
//Class: ETEC 2110
//Assignment: Lab 5 - Game Of Life
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "gameoflife.h"

void init_board(int board[BOARD_WIDTH][BOARD_HEIGHT], int num_alive)
{
  srand(time(0));
  for(int i = 0; i < BOARD_WIDTH; i++)
    for(int j = 0; j < BOARD_HEIGHT; j++)
      board[i][j] = 0;
  // fill the board with dead cells

  while(num_alive)
  {
    int x = rand()%BOARD_HEIGHT;
    int y = rand()%BOARD_WIDTH;
    if(!board[x][y])
    {
      board[x][y] = 1;
      num_alive--;
    }
  }
}

void display_board(int board[BOARD_WIDTH][BOARD_HEIGHT])
{
  for(int i = 0; i < BOARD_HEIGHT; i++)
    for(int j = 0; j < BOARD_WIDTH; j++)
      printf("%c", board[i][j]);
    printf("\n");
}

int num_neighbors(int board[BOARD_WIDTH][BOARD_HEIGHT], int x, int y)
{
  // get the sum of all the neighboring matches to X, a living cell.

  if(x && y)// base case. anywhere not on the edge.
    return (board[++x][++y]) + (board[++x][y]) + (board[x][++y]) + (board[--x][y]) + (board[--x][++y]) + (board[--x][--y]) + (board[x][--y]) + (board[++x][--y]);
  else if(!x && !y)// case top-left
    return (board[++x][++y]) + (board[++x][y]) + (board[x][++y]);
  else if(x && !y)// case top edge
    return (board[++x][++y]) + (board[++x][y]) + (board[x][++y]) + (board[--x][y]) + (board[--x][++y]);
  else if(x == BOARD_WIDTH && !y)// case top-right
    return (board[x][++y]) + (board[--x][++y]) + (board[--x][y]);
  else if(x == BOARD_WIDTH && y)// case right edge
    return (board[x][++y]) + (board[--x][++y]) + (board[--x][y]) + (board[--x][--y]) + (board[x][--y]);
  else if(x == BOARD_WIDTH && !y)// case bottom-right
    return (board[x][--y]) + (board[--x][--y]) + (board[--x][y]);
  else if(x == BOARD_WIDTH && !y)// case bottom edge
    return (board[x][--y]) + (board[--x][--y]) + (board[--x][y]) + (board[++x][y]) + (board[++x][--y]);
  else if(x == BOARD_WIDTH && !y)// case bottom-left
    return (board[x][--y]) + (board[++x][--y]) + (board[++x][y]);
  else if(!x && y)// case left edge
    return (board[++x][++y]) + (board[++x][y]) + (board[x][++y]) + (board[x][--y]) + (board[++x][--y]);

}

int next_state(int board[BOARD_WIDTH][BOARD_HEIGHT], int x, int y)
{
  if(num_neighbors(board, x, y) == 3)
    return 1;// cells with 3 neighbors should be alive regardless of their own state
  else if(num_neighbors(board, x, y) == 2 && board[x][y])
    return 1;// a living cell with 3 neighbors continues to live
  else
    return 0;
}

void next_generation(int board[BOARD_WIDTH][BOARD_HEIGHT])
{
  char proto_board[BOARD_WIDTH][BOARD_HEIGHT];

  for(int i = 0; i < BOARD_HEIGHT; i++)
  {
    for(int j = 0; j < BOARD_WIDTH; j++)
    {
      if(next_state(board, i, j))
        proto_board[i][j] = 'X';
      else
        proto_board[i][j] = '-';
    }
  }
  // now that our protoboard (electronics pun, get it) is done, copy it over.
  for(int i = 0; i < BOARD_HEIGHT; i++)
  {
    for(int j = 0; j < BOARD_WIDTH; j++)
    {
        board[i][j] = proto_board[i][j];
    }
  }

}
