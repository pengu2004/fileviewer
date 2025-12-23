#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
  printf("Enter the file you want to view");
  char input_file[1000];
  scanf("%s", input_file);

  FILE *pfile = fopen(input_file, "r");
  char image[100];
  fgets(image, sizeof(image), pfile); // first line
  printf("The file is %s", image);
  char line[100];
  fgets(line, sizeof(line), pfile); // second line
  char *pimage = line;
  char *width;
  char *height;
  height = strsep(&pimage, " ");
  width = strsep(&pimage, " ");
  int h = atoi(height);
  int w = atoi(width);
  printf("THis is the height %d and width %d\n", h, w);
  fgets(line, sizeof(line), pfile);
  printf("This is the maxval %s", line);

  SDL_Init(SDL_INIT_VIDEO); // initialize the sdl
  int running = 1;
  SDL_Event event;

  SDL_Window *pwindow = SDL_CreateWindow("File Viewer", SDL_WINDOWPOS_CENTERED,
                                         SDL_WINDOWPOS_CENTERED, w, h,
                                         0); // create the window
  SDL_Surface *psurface =
      SDL_GetWindowSurface(pwindow); // get the window surface
  unsigned char r, g, b;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {

      fread(&r, 1, 1, pfile);
      fread(&g, 1, 1, pfile);
      fread(&b, 1, 1, pfile);
      Uint32 pixel_val = SDL_MapRGB(psurface->format, r, g, b);
      SDL_Rect rect = {j, i, 1, 1};
      SDL_FillRect(psurface, &rect, pixel_val);
    }
  }

  SDL_UpdateWindowSurface(pwindow); // update surface
  while (running) {                 // gameloop
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
