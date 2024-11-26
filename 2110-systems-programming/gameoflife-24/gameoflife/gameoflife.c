//Name: Ethan Ward
//Class: ETEC 2110
//Assignment: Lab 5 - Game Of Life
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "game_of_life.h"


int* init_board(int board[BOARD_WIDTH][BOARD_HEIGHT], int num_alive)
{
  srand((int)time(0));
  // fill the board with dead cells
  for(int i = 0; i < BOARD_HEIGHT; i++)
    for(int j = 0; j < BOARD_WIDTH; j++)
      board[i][j] = 0;
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
  for(int i=0; i<BOARD_HEIGHT; i++)
  {
    for(int j=0; j<BOARD_WIDTH; j++)
      printf("%c", board[i][j] ? 'X':'-');
    printf("\n");
  }
}

int num_neighbors(int board[BOARD_WIDTH][BOARD_HEIGHT], int x, int y)
{
  // get the sum of all the neighboring matches to X, a living cell.
  // NOTE '24 EDIT: yeahhh I know this is VERY ugly but I'm not going to touch it this time

  if(x && y && x!=BOARD_WIDTH && y!=BOARD_HEIGHT)// base case. anywhere not on the edge.
    return (board[++x][++y]) + (board[++x][y]) + (board[x][++y]) + (board[--x][y]) + (board[--x][++y]) + (board[--x][--y]) + (board[x][--y]) + (board[++x][--y]);
  else if(!x && !y)// case top-left
    return (board[++x][++y]) + (board[++x][y]) + (board[x][++y]);
  else if(x && !y && x!=BOARD_WIDTH)// case top edge
    return (board[++x][++y]) + (board[++x][y]) + (board[x][++y]) + (board[--x][y]) + (board[--x][++y]);
  else if(x == BOARD_WIDTH && !y)// case top-right
    return (board[x][++y]) + (board[--x][++y]) + (board[--x][y]);
  else if(x == BOARD_WIDTH && y && y!=BOARD_HEIGHT)// case right edge
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
  int n = num_neighbors(board, x, y);
  if(n==3)
    return 1;// cells with 3 neighbors should be alive regardless of their own state
  if(n==2 && board[x][y])
    return 1;// a living cell with 2 neighbors continues to live
  return 0;
}

int* next_generation(int board[BOARD_WIDTH][BOARD_HEIGHT])
{
  int proto_board[BOARD_WIDTH][BOARD_HEIGHT];

  for(int i=0; i<BOARD_HEIGHT; i++)
    for(int j=0; j<BOARD_WIDTH; j++)
      if(next_state(board, j, i))
        proto_board[j][i] = 1;
      else
        proto_board[j][i] = 0;
  // now that our protoboard (electronics pun, get it) is done, copy it over.
  for(int i = 0; i < BOARD_HEIGHT; i++)
    for(int j = 0; j < BOARD_WIDTH; j++)
        board[j][i] = proto_board[j][i];
  return board;
}
