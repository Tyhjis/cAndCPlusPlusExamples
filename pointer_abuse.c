// Tämä ohjelma demonstroi pointterien, eli osoitinmuuttujien (pointer) käyttöä kokonaislukumatriisin avulla.

#include <stdio.h>
#include <stdlib.h>

#define ROWS_COLS 3

int* initialize_pointers(int array[], int arrayLength);
void print_results(int *p, int arrayLength);
void double_results(int *p, int arrayLength);
void print_array(int array[], int arrayLength);
void print_square_matrix(int array[ROWS_COLS][ROWS_COLS], int arrayLength);

int main()
{
  // Alustetaan matriisi.
  int h[3][3];
  int i, j;
  for(i = 0; i < 3; i++){
    for(j = 0; j < 3; j++){
      h[i][j] = i + j * 2;
    }
  }
  printf("Matriisi alussa\n");
  print_square_matrix(h, 3);
  // Alustetaan pointterille arvot matriisin ensimmäiselle riville.
  int *p = initialize_pointers(h[0], 3);
  printf("Ensimmainen rivi:\n");
  print_results(p, 3);
  // Tuplataan pointterin arvot. Toistetaan alustus kaikkien matriisin rivien kanssa.
  double_results(p, 3);
  p = initialize_pointers(h[1], 3);
  double_results(p, 3);
  p = initialize_pointers(h[2], 3);
  double_results(p, 3);
  printf("Matriisi lopussa\n");
  print_square_matrix(h, 3);
  return 0;
}

// Osoitinmuuttujan osoittamien arvojen näyttäminen.
void print_results(int *p, int arrayLength)
{
  int i, temp;
  for(i = 0; i < arrayLength; i++) {
    // temp-muuttujalle asetetaan arvo, johon osoitin p osoittaa. Osoittimen p osoitetta inkrementoidaan silmukan jokaisella iteraatiolla.
    temp = *(p + i);
    printf("%d\n", temp);
  }
  printf("\n");
}

void double_results(int *p, int arrayLength)
{
  int i;
  for(i = 0; i < arrayLength; i++) {
    // Kaksinkertaistetaan osoittimen p osoittama arvo.
    *p = *p * 2;
    p += 1;
  }
}

// Koko matriisin tulostaminen.
void print_square_matrix(int array[ROWS_COLS][ROWS_COLS], int arrayLength)
{
  int i;
  for(i = 0; i < arrayLength; i++) {
    print_array(array[i], arrayLength);
  }
}

// Yhden rivin tulostamisen funktio.
void print_array(int array[], int arrayLength)
{
  int i;
  for(i = 0; i < arrayLength; i++) {
    printf("%d\t", array[i]);
  }
  printf("\n");
}

int* initialize_pointers(int array[], int arrayLength)
{
  int *p;
  int i;
  for(i = 0; i < arrayLength; i++) {
    // Ampersand (&) antaa tavallisen muuttujan osoitteen, eli osoittimen.
    p = &array[i];
    p++;
  }
  // Palautetaan p:n osoittimen arvo ensimmäiseen paikkaan.
  for(i = 0; i < arrayLength; i++) {
    p--;
  }
  return p;
}
