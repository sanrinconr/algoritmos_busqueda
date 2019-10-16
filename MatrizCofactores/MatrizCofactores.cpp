#include <iostream>
#include <cstdlib>
#include <cmath>
#include <time.h>
#include <sys/time.h>
#define MAX 100

using namespace std;

void mostrar_matriz(int matriz[][MAX], int orden);
int determinante(int matriz[][MAX], int orden);
int cofactor(int matriz[][MAX], int orden, int fila, int columna);

double timeval_diff(struct timeval *a, struct timeval *b)
{
  return
    (double)(a->tv_sec + (double)a->tv_usec/1000000) -
    (double)(b->tv_sec + (double)b->tv_usec/1000000);
}

int main()
{
  int matriz[MAX][MAX];
  int orden;




  for (orden =2 ; orden <=90 ;orden++){

    for (int i = 0; i < orden; i++) {
      for (int j = 0; j < orden; j++) {
        matriz[i][j] = rand() % 100;
      }
    }
    struct timeval t_ini, t_fin;
    double secs;

    gettimeofday(&t_ini, NULL);
    determinante(matriz, orden);
    gettimeofday(&t_fin, NULL);

    secs = timeval_diff(&t_fin, &t_ini);
    fprintf(stderr,"%.16g \n", secs * 1000.0);

  }

  return 0;
}

void mostrar_matriz(int matriz[][MAX], int orden)
{
  cout << "Orden: " << orden << endl;
  for (int i = 0; i < orden; i++) {
    for (int j = 0; j < orden; j++) {
      cout << "\t" << matriz[i][j];
    }
    cout << "\n";
  }
}


int determinante(int matriz[][MAX], int orden)
{
  int det = 0.0;

  if (orden == 1) {
    det = matriz[0][0];
  } else {
    for (int j = 0; j < orden; j++) {
      det = det + matriz[0][j] * cofactor(matriz, orden, 0, j);
    }
  }

  return det;
}


int cofactor(int matriz[][MAX], int orden, int fila, int columna)
{
  int submatriz[MAX][MAX];
  int n = orden - 1;

  int x = 0;
  int y = 0;
  for (int i = 0; i < orden; i++) {
    for (int j = 0; j < orden; j++) {
      if (i != fila && j != columna) {
        submatriz[x][y] = matriz[i][j];
        y++;
        if (y >= n) {
          x++;
          y = 0;
        }
      }
    }
  }

  return pow(-1.0, fila + columna) * determinante(submatriz, n);
}
