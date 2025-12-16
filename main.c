#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window *pwindow = SDL_CreateWindow("File Viewer", SDL_WINDOWPOS_CENTERED,
                                         SDL_WINDOWPOS_CENTERED, 800, 800, 0);
  SDL_Surface *psurface = SDL_GetWindowSurface(pwindow);
  SDL_FillRect(psurface, NULL, 0x00FF0000);
  SDL_UpdateWindowSurface(pwindow);
  int running = 1;
  SDL_Event event;
  while (running) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        running = 0;
      }
      SDL_Delay(16);
    }
  }
  SDL_DestroyWindow(pwindow);
  SDL_Quit();
  return 0;
};
