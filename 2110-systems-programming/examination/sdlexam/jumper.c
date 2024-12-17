#include <SDL2/SDL.h>
#include <stdlib.h>

//Screen dimension constants
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
void window_init();
void render_face(int index);
void move_face(int index);

SDL_Window* window = NULL;
SDL_Surface* screen = NULL;
// let me keep my initializer list syntax,,,
SDL_Rect jumper = {(SCREEN_WIDTH/2)-25,(SCREEN_HEIGHT/2)-25, 50,50};
// yeah yeah yeahyeahyeah this is bad design but I need TIME right now
SDL_Rect faces[100];
int speeds[100];
int color[3] = {255,255,0};

int main(int argc, char* argv[])
{
  const Uint8* keys = SDL_GetKeyboardState(NULL);
  SDL_Event event;
  window_init();
  faces[0] = jumper;
  speeds[0] = -5;

  while(1)
  {
    SDL_PollEvent(&event);

    if(keys[SDL_SCANCODE_ESCAPE] || event.type == SDL_QUIT) 
      break;

    // backgrounding
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0,0,0)); //Fill the surface white   
    SDL_Rect bordure = {0, SCREEN_HEIGHT-50, SCREEN_WIDTH, 50};
    SDL_FillRect(screen, &bordure, SDL_MapRGB(screen->format, 0,0,255));
    bordure.y = 0;
    SDL_FillRect(screen, &bordure, SDL_MapRGB(screen->format, 0,0,255));

    render_face(0);
    move_face(0);

    SDL_UpdateWindowSurface(window);
  }
  SDL_DestroyWindow(window);
  SDL_Quit(); 
  return 0;
}

void render_face(int index)
{
  SDL_FillRect(screen, faces+index, SDL_MapRGB(screen->format, color[0],color[1],color[2]));
}
void move_face(int index)
{
  if(faces[index].y>(SCREEN_HEIGHT-50-faces[index].h-speeds[index]))
  {
    speeds[index] = -5;
    color[0] = rand()%255;
    color[1] = rand()%255;
    color[2] = rand()%255;    
  }
  else if(faces[index].y<60+speeds[index])
  {
    speeds[index] = 5;
    color[0] = rand()%255;
    color[1] = rand()%255;
    color[2] = rand()%255;    
  }
  faces[index].y += speeds[index];
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
                              SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if(!window) printf("error with window creation! code: %s\n", SDL_GetError());
    else
    {
      screen = SDL_GetWindowSurface(window); //Get window surface
      SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0,0,0)); //Fill the surface white 
      SDL_UpdateWindowSurface(window); //Update the surface
    }
  }
}

int rand_int(int min, int max)
{
  return (rand()%max+1)+min;
}

int rand_float(float min, float max)
{
  //return (float)((rand()%max+1)+min);
  // aren't I so funny
}

