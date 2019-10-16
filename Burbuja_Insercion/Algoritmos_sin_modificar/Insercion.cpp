#include <stdio.h>
#include <iostream>


void insercion (int a[] ,  int N);
int main() {

  //Las funciones para llenar y demas se encuentran en la clase manejo.cpp
  int n = 3;
  int a[n]={3,2,1};

  insercion(a , n);

}

//El arreglo se pasa a la funcion siempre por referencia, lo que se modifique aqui se modifica en el main
void insercion (int  a[], int N){
  int i,j;
  int v;
  for (i=1; i<N; i++){
    j=i;
    v=a[j];

    //El j>1 se cambia por j>0 pues el arreglo empieza en 0 y no 1 como antes
    while(a[j-1]>v && j>0){
      a[j]=a[j-1];
      j--;
    }

    a[j]= v;
  }
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
