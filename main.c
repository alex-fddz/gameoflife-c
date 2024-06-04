#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEAD ' '
#define LIVE '#'

#define XSIZE 80
#define YSIZE 20
#define MAX_ITER 20

#define DEAD_PROBA 25

char grid[XSIZE][YSIZE];

char init_cell(int dead_probability) {
  return rand() % dead_probability > 0 ? DEAD : LIVE;
}

void init_grid() {
  for (int y = 0; y < YSIZE; y++) {
    for (int x = 0; x < XSIZE; x++) {
        grid[x][y] = init_cell(DEAD_PROBA);
    }
  }
}

void show_grid() {
  // clear the screen
  printf("\e[1;1H\e[2J");
  // show the grid
  // border
  printf("+");
  for (int n = 0; n < XSIZE; n++) printf("-");
  printf("+\n");
  // actual grid
  for (int y = 0; y < YSIZE; y++) {
    printf("|");
    for (int x = 0; x < XSIZE; x++) {
        printf("%c", grid[x][y]);
    }
    printf("|\n");
  }
  // end
  printf("+");
  for (int n = 0; n < XSIZE; n++) printf("-");
  printf("+");
}

int main() {
  time_t t, st;
  srand((unsigned) time(&t));
  init_grid();

  for (int i = 0; i < MAX_ITER; i++) {
    init_grid();
    show_grid();

    time(&st);
    do {
      time(&t);
    } while (difftime(t, st) < 1);
  }

  return 0;
}
