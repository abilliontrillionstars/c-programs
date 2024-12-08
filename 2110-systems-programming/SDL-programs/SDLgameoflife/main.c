//Name: Ethan Ward
//Class: ETEC 2110
//Assignment: Lab 5 - Game of Life
#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include "gameoflife.h"
#include "gameoflife.c"

void window_init();
void render_board(SDL_Surface* sur, int board[BOARD_WIDTH][BOARD_HEIGHT]);

SDL_Window* window = NULL;
SDL_Surface* screen = NULL;

void main()
{
  // set up our windowe
  window_init(window, screen);
  // set up our boarde
  int board[BOARD_WIDTH][BOARD_HEIGHT];
  clear_board(board);
  populate_board(board, (BOARD_WIDTH*BOARD_HEIGHT)/2);
  
  int paused = 0;

  const Uint8* keys = SDL_GetKeyboardState(NULL);
  SDL_Event e;
  while(1)
  {
    // rendeur le board
    //display_board(board);
    render_board(screen, board);
    SDL_UpdateWindowSurface(window);
    // advance le board, if we are ne pause
    if(!paused) next_generation(board);
    
    // handle les quis & event inputs
    SDL_PollEvent(&e);
    if(e.type == SDL_QUIT || keys[SDL_SCANCODE_ESCAPE]) break;
    if(e.type == SDL_KEYDOWN)
    {
      if(keys[SDL_SCANCODE_R])
      {
        clear_board(board);
        populate_board(board, (BOARD_WIDTH*BOARD_HEIGHT)/2);
      }
      if(keys[SDL_SCANCODE_A])
        populate_board(board, (BOARD_WIDTH*BOARD_HEIGHT)/200);
      // TODO: P, pause feature
      if(keys[SDL_SCANCODE_P])
        paused = !paused;
      if(keys[SDL_SCANCODE_SPACE])
        next_generation(board);
      if(keys[SDL_SCANCODE_K])
        for(int y=0; y<BOARD_HEIGHT; y++)
          for(int x=0; x<BOARD_WIDTH; x++)
            if(rand()%10 == 1)
              board[x][y] = 0;
    }
  } // end while

  SDL_DestroyWindow( window ); //Destroy window
  SDL_Quit(); //Quit SDL subsystems
}


void window_init()
{
  //Initialize SDL
  if(SDL_Init(SDL_INIT_VIDEO) < 0)
    printf("init error! code: %s\n", SDL_GetError());
  else
  {
    // normally I *hate* wrapping function calls like this but I have no choice :( 
    // darn long enums and #define names...
    //Create window
    window = SDL_CreateWindow("chromeos window names don't show up lol", 
                              SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
                              1+(BOARD_WIDTH*5), 1+(BOARD_HEIGHT*5), SDL_WINDOW_SHOWN);

    if(!window) printf("error with window creation! code: %s\n", SDL_GetError());
    else
    {
      screen = SDL_GetWindowSurface(window); //Get window surface
      SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 127,127,127)); //Fill the surface white
      SDL_UpdateWindowSurface(window); //Update the surface
    }
  }
}

void render_board(SDL_Surface* sur, int board[BOARD_WIDTH][BOARD_HEIGHT])
{
  SDL_Rect rect;
  rect.w=4;
  rect.h=4;
  Uint32 color;
  for(int y=0; y<BOARD_HEIGHT; y++)
    for(int x=0; x<BOARD_WIDTH; x++)
      {
        rect.x =(x*5)+1;
        rect.y =(y*5)+1;
        if(board[x][y])
          color = SDL_MapRGB(sur->format, 255,255,255);
        else
          color = SDL_MapRGB(sur->format, 0,0,0);
        SDL_FillRect(sur, &rect, color);
      }
  
}
