//Ethan Ward 301040
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

int SCREEN_WIDTH = 800, SCREEN_HEIGHT = 600;

int main(int argc, char *argv[])
{
  SDL_Window* window = NULL;
  SDL_Surface* screenSurface = NULL;

  if(SDL_Init(SDL_INIT_VIDEO) < 0)
    printf("SDL not initialized. SDL_Error: %s\n", SDL_GetError());
  else
  {
    //Create window
    window = SDL_CreateWindow("It's the final brain cell", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if(window == NULL)
      printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError());
    else
    {
      screenSurface = SDL_GetWindowSurface(window);
      SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x00, 0x00, 0x00));
      SDL_UpdateWindowSurface(window);
    }
  }
  SDL_Rect * bgrect;

  Uint8 *keys = SDL_GetKeyboardState(NULL);
  SDL_Event * event;
  while(1)
  {
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x00, 0x00, 0x00));
    SDL_PollEvent(event);
    if(keys[SDL_SCANCODE_ESCAPE] || event->type == SDL_QUIT)
      break;



    SDL_UpdateWindowSurface(window);
  }

  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
