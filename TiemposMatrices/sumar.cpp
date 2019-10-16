#include <stdio.h>
#include <iostream>
#include <windows.h>

int main() {
  int max=1;
  for (int n = 1; n < 2000; n=n*2) {

    std::cout << "wi" << '\n';

    int a[n][n];
    int b[n][n];
    int c[n][n];

    //SE LLENA LA MATRIX A CON NUMEROS 1,2,3,4,5,6,7,8,9 .....
    //SE LLENA B DE UNOS
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        c[i][j] = 0;
        b[i][j] = 1;
        a[i][j] = max;
        max++;
      }
    }
    max=1;

    //SE REALIZA EL PROCESO DE LA SUMA
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        c[i][j] = a[i][j] + b[i][j];
      }
    }

  }
