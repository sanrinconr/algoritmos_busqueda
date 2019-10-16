#include <stdio.h>
#include <iostream>
#include <ctime>
#include <sys/time.h>
#include <unistd.h>



void printArreglo (int a[]);
//1 para desordenado totalmente, 0 para ordenado totalmente
void llenarArreglo(int a[] , int orden , int n);
void imprimirArreglo(int a[] , int n);
int main() {

  //Las funciones para llenar y demas se encuentran en la clase manejo.cpp
  int n = 4;
  int a[n];
  //0 para ordenado 1 para desordenado

  llenarArreglo(a , 1 , n);
  imprimirArreglo(a,n);

}


void llenarArreglo(int a[], int orden , int n){

  int max = n;
  int min = 1;
  if (orden == 1) {
    for (int i = 0; i <n; i++) {
      a[i]=max;
      max--;
    }
  }else{
    for (int i = 0; i < n; i++) {
      a[i]=min;
      min++;
    }
  }
}

void imprimirArreglo(int a[] , int n){
  for (int i = 0; i < n; i++) {
    if(i == n-1){
      std::cout << a[i];
    }else{
      std::cout << a[i] << ",";
    }
  }
  std::cout << "" << '\n';
}
