//Name: Ethan Ward
//Class: ETEC 2110
//Assignment: Lab 5 - Game of Life
#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include "blockhead.h"
#include "blockhead.c"

void window_init();

SDL_Window* window = NULL;
SDL_Surface* screen = NULL;
// the block of memory that has the head of our blockhead list
// the blockhead head block, if you will
struct BLOCKHEAD_NODE** head;

void main()
{
  window_init(window, screen);
  
  head = malloc(sizeof(struct BLOCKHEAD_NODE**));
  for(int i=0; i<10; i++)
  {
    struct BLOCKHEAD_NODE bh = {};
    addBlockHeadToList(head, bh);
  }


  const Uint8* keys = SDL_GetKeyboardState(NULL);
  SDL_Event e;
  while(1)
  {
    SDL_UpdateWindowSurface(window);
    
    SDL_PollEvent(&e);
    if(e.type == SDL_QUIT || keys[SDL_SCANCODE_ESCAPE]) break;
    if(e.type == SDL_KEYDOWN)
    {

    }
  } // end while

  SDL_DestroyWindow(window);
  SDL_Quit();
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
                              800, 600, SDL_WINDOW_SHOWN);

    if(!window) printf("error with window creation! code: %s\n", SDL_GetError());
    else
    {
      screen = SDL_GetWindowSurface(window); //Get window surface
      SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 127,127,127)); //Fill the surface white
      SDL_UpdateWindowSurface(window); //Update the surface
    }
  }
}
