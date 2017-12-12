/* Author : YANN DROY */
/******** 2015 ********/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "display.h"
#include "image.h"
#include "menu.h"
#include "file_rw.h"
#include "const.h"

int main (int argc, char* argv[]){
  SDL_Surface* window = NULL;
  SDL_Surface* image = NULL;
  int** table = NULL;
  SDL_Rect* clip = NULL;
  char name[18] = {0};
  int x, run = 1;
  int n = 4, nb_moves, n_tmp;
  int change_image = 1;
  
  srand(time(NULL));
  init();
  n_tmp = n;

  while(run){
    nb_moves = 0;

    if(change_image)
      x = rand() % 79;
    change_image = 1;

    sprintf(name, "./Pictures/%d.jpg", x);
    image = IMG_Load(name);
    
    if(image == NULL){
      fprintf(stderr, "Image loading failure : %s.\n", SDL_GetError());
      exit(EXIT_FAILURE);
    }
    
    init_window(&window, image->w, image->h);

    table = create_table(n, n);
    init_table(table, n);

    clip = create_clip(n);    
    split_image(image, clip, n);
    scramble(table, (2 * n * n), n);
    display_image(window, image, table, n, clip);
    
    game(window, image, table, clip, &nb_moves, &n, &run, name);
    
    if(n != n_tmp){
      n_tmp = n;
      change_image = 0;
    }else if(run){
      load_leaderboards(window, n);
      menu(&run, 1);
    }
    
    SDL_FreeSurface(image);
    SDL_FreeSurface(window);
    free(table);
    free(clip);
  }
  
  sdl_kill();
  
  return EXIT_SUCCESS;
}
