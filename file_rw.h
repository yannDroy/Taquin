/* Author : YANN DROY */
/******** 2015 ********/

#ifndef __FILE_RW__
#define __FILE_RW__

void load_leaderboards (SDL_Surface* window, int n);

void delete_leaderboard (char* filename);

void test_file (char* filename);

void save_score (int n, int file, char* name);

void sort (int* scores, char* players[], int n);

#endif
