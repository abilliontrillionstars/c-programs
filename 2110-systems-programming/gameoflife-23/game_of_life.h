//Name: Ethan Ward
//Class: ETEC 2110
//Assignment: Lab 5 - Game Of Life
#ifndef GAME_OF_LIFE_H_INCLUDED
#define GAME_OF_LIFE_H_INCLUDED

#define BOARD_WIDTH 30
#define BOARD_HEIGHT 20

int * init_board(int board[BOARD_WIDTH][BOARD_HEIGHT], int num_alive);
void display_board(int board[BOARD_WIDTH][BOARD_HEIGHT]);
int num_neighbors(int board[BOARD_WIDTH][BOARD_HEIGHT], int x, int y);
int next_state(int board[BOARD_WIDTH][BOARD_HEIGHT], int x, int y);
int * next_generation(int board[BOARD_WIDTH][BOARD_HEIGHT]);


#endif // GAME_OF_LIFE_H_INCLUDED

