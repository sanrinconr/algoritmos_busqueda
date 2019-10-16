#include <stdio.h>
#include <iostream>


void burbuja (int a[] ,  int N);
void intercambio (int a[] , int anterior , int actual);
int main() {

  //Las funciones para llenar y demas se encuentran en la clase manejo.cpp
  int n=7;
  int a[n]={1,5,4,3,2,1,10};

  burbuja(a , n);
  
}

//El arreglo se pasa a la funcion siempre por referencia, lo que se modifique aqui se modifica en el main
void burbuja (int a[], int N){
  int i,j;
  for (i=N; i>=1; i--)
     for(j=2; j<=i; j++)
           if(a[j-1]> a[j])
            intercambio(a,j-1,j);
}

void intercambio (int a[] , int anterior , int actual){
  int temp;
  temp = a[anterior];
  a[anterior]=a[actual];
  a[actual]=temp;
}
