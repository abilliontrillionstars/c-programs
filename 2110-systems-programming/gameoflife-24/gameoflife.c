//Name: Ethan Ward
//Class: ETEC 2110
//Assignment: Lab 5 - Game Of Life
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "gameoflife.h"


void init_board(int board[BOARD_WIDTH][BOARD_HEIGHT], int num_alive)
{
  int x,y;
  srand((int)time(0));
  // fill the board with dead cells
  for(y=0; y<BOARD_HEIGHT; y++)
    for(x=0; x<BOARD_WIDTH; x++)
      board[x][y] = 0;
  while(num_alive)
  {
    x = rand()%BOARD_WIDTH;
    y = rand()%BOARD_HEIGHT;
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
    printf(":");
    for(int j=0; j<BOARD_WIDTH; j++)
      printf("%c", board[j][i] ? 'X':'-');
    printf(":\n");
  }
}

int num_neighbors(int board[BOARD_WIDTH][BOARD_HEIGHT], int x, int y)
{
  // get the sum of all the neighboring matches to a living cell at x and y.
  // '24 EDIT 2: now *here's* some decently respectable code. I'm a competent programmer I promise. lol.
  int count = 0;
  if(x)
  {
    count += board[x-1][y]; // left 
    if(y)
      count += board[x-1][y-1]; // up left
    if(y<BOARD_HEIGHT)
      count += board[x-1][y+1]; // down left
  }
  if(x<BOARD_WIDTH)
  {
    count += board[x+1][y]; // right
    if(y)
      count += board[x+1][y-1];// up right
    if(y<BOARD_HEIGHT)
      count += board[x+1][y+1];// down right
  }
  if(y)
    count += board[x][y-1]; // up
  if(y<BOARD_HEIGHT)
    count += board[x][y+1]; // down

  return count;
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

void next_generation(int board[BOARD_WIDTH][BOARD_HEIGHT])
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
}
