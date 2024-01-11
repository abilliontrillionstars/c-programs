//Ethan Ward 301040
// Lab 6: SDL Graphics
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>


//Screen dimension constants
int SCREEN_WIDTH = 800, SCREEN_HEIGHT = 600;

int main(int argc, char *argv[])
{
  srand(0);


  SDL_Window* window = NULL; //The window we'll be rendering to
  SDL_Surface* screenSurface = NULL; //The surface contained by the window
  //Initialize SDL
  if( SDL_Init(SDL_INIT_VIDEO) < 0 )
    printf( "SDL not initialized. SDL_Error: %s\n", SDL_GetError() );
  else
  {
    //Create window
    window = SDL_CreateWindow( "why does it only work sometimes", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if( window == NULL )
      printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
    else
    {
      screenSurface = SDL_GetWindowSurface( window ); //Get window surface
      SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) ); //Fill the surface white
      SDL_UpdateWindowSurface( window ); //Update the surface
    }
  }

  Uint8 *keys = SDL_GetKeyboardState(NULL);
  SDL_Event * event;
  while(1)
  {
    SDL_PollEvent(event);

    if(keys[SDL_SCANCODE_ESCAPE] || event->type == SDL_QUIT)
      break;

    if(keys[SDL_SCANCODE_R])
    {
      SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, rand() %255, rand() %255, rand() %255) ); //Fill the surface
      SDL_UpdateWindowSurface( window ); //Update the surface
    }

  }


  SDL_DestroyWindow( window ); //Destroy window
  SDL_Quit(); //Quit SDL subsystems
  return 0;
}
