/* Author : YANN DROY */
/******** 2015 ********/

#ifndef __DISPLAY__
#define __DISPLAY__

void init ();

void init_window (SDL_Surface** window, int width, int heigth);

void sdl_kill ();

void display_image (SDL_Surface* window, SDL_Surface* image, int** table, int n, SDL_Rect* clip);

void display_fullimage(SDL_Surface* window, char* name);

void display_moveup(SDL_Surface* window, SDL_Surface* image, int** table, int n, SDL_Rect* clip);

void display_movedown(SDL_Surface* window, SDL_Surface* image, int** table, int n, SDL_Rect* clip);

void display_moveright(SDL_Surface* window, SDL_Surface* image, int** table, int n, SDL_Rect* clip);

void display_moveleft(SDL_Surface* window, SDL_Surface* image, int** table, int n, SDL_Rect* clip);

void display_which_place (SDL_Surface* window, SDL_Surface* image, int** table, SDL_Rect* clip, int n, int x, int y);

void display_which_clip (SDL_Surface* window, SDL_Surface* image, int** table, SDL_Rect* clip, int n, int x, int y);

void get_player (SDL_Surface* window, char* name, int nb_moves);

#endif
