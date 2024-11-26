//Name: Ethan Ward
//Class: ETEC 2110
//Assignment: Lab 5 - Game Of Life
#pragma once
#define BOARD_WIDTH 20
#define BOARD_HEIGHT 30

int * init_board(int board[BOARD_WIDTH][BOARD_HEIGHT], int num_alive);
void display_board(int board[BOARD_WIDTH][BOARD_HEIGHT]);
int num_neighbors(int board[BOARD_WIDTH][BOARD_HEIGHT], int x, int y);
int next_state(int board[BOARD_WIDTH][BOARD_HEIGHT], int x, int y);
int * next_generation(int board[BOARD_WIDTH][BOARD_HEIGHT]);

