#include <stdio.h>
#include <stdlib.h>


struct color {
  int red;
  int green;
  int blue;
};

typedef struct color color_t;

int main() {
  // steg 1: lese inn farger fra et bilde
  // lese en fil 
  FILE *mitt_bilde;
  mitt_bilde = fopen("bilde.ppm", "r");

  char *line = calloc(300, sizeof(char));
  size_t len = 300;
  size_t read = 0;
  
  while ((read = getline(&line, &len, mitt_bilde)) != -1) {
    printf("Retrieved line of length %zu:\n", read);
    printf("%s", line);
  }

  // hente ut pixelverdier


  // steg 2: clustering for å finne 16 farger

}
