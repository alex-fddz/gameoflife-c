/* 
 * game of life implementation out of the top of my head
 * without tutorials just to test myself and for the lulz
 * - alex-fddz
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ascii characters to use
#define DEAD ' '
#define LIVE '#'

// size of the grid/screen
#define XSIZE 80
#define YSIZE 20
//
// finite life of program
#define MAX_ITER 20
// initialization param for initial state of cells
#define DEAD_PROBA 25

char grid[XSIZE][YSIZE];

// initialize a cell as dead or alive (1st generation)
char init_cell(int dead_probability) {
  return rand() % dead_probability > 0 ? DEAD : LIVE;
}

// fill-in the grid with the initial cells
void init_grid() {
  for (int y = 0; y < YSIZE; y++) {
    for (int x = 0; x < XSIZE; x++) {
        grid[x][y] = init_cell(DEAD_PROBA);
    }
  }
}

// draw the ascii grid in its current state
void show_grid() {
  // clear the screen
  printf("\e[1;1H\e[2J");
  // show the grid
  // border
  printf("+");
  for (int n = 0; n < XSIZE; n++) printf("-");
  printf("+\n");
  // actual grid, line per line
  for (int y = 0; y < YSIZE; y++) {
    printf("|");
    for (int x = 0; x < XSIZE; x++) {
        printf("%c", grid[x][y]);
    }
    printf("|\n");
  }
  // end, border
  printf("+");
  for (int n = 0; n < XSIZE; n++) printf("-");
  printf("+");
}

int main() {
  // get the time so that random seed is different
  time_t t, st;
  srand((unsigned) time(&t));
  // get the 1st-gen grid
  init_grid();

  // temp loop just to test how the screen updates
  for (int i = 0; i < MAX_ITER; i++) {
    show_grid();

    // delay between screen updates
    time(&st);
    do {
      time(&t);
    } while (difftime(t, st) < 1);
    // re initialize it so it changes
    init_grid();
  }

  return 0;
}

