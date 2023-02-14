#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


struct color {
  int red;
  int green;
  int blue;
};

typedef struct color color_t;

// char *str = "ab234cid*(s349*(20kd", *p = str;
color_t *extract_colors(char *str) {
  char *p = str; 

  color_t *col = malloc(sizeof(color_t));

  int no_colors = 0;
  while (*p) { // While there are more characters to process...
      if ( isdigit(*p) || ( (*p=='-'||*p=='+') && isdigit(*(p+1)) )) {
          // Found a number
          int val = strtol(p, &p, 10); // Read number

          if (no_colors == 0) col->red = val;
          if (no_colors == 1) col->green = val;
          if (no_colors == 2) col->blue = val;

          no_colors++;
      } else {
          // Otherwise, move on to the next character.
          p++;
      }
  }

  return col;
}

int main() {
  // steg 1: lese inn farger fra et bilde
  // lese en fil 
  FILE *mitt_bilde;
  mitt_bilde = fopen("bilde.ppm", "r");

  char *line = calloc(300, sizeof(char));
  size_t len = 300;
  size_t read = 0;
  
  // gå gjennom fila linje for linje
  // hente ut pixelverdier
  int count = 0;
  color_t *read_color;
  while ((read = getline(&line, &len, mitt_bilde)) != -1) {
    if (count < 3) {
      printf("hoppe over header\n");
    } else if (line[0] == '#') {
      printf("hoppe over kommentar\n");
    } else {
      read_color = extract_colors(line);
      printf("%d %d %d \n", read_color->red, read_color->green, read_color->blue);
    }

    count++;
  }


  extract_colors("ab234cid*(s349*(20kd");


  // steg 2: clustering for å finne 16 farger

}
