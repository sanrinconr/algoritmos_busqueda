#include <stdio.h>
#include <iostream>
#include <sys/time.h>
#include <unistd.h>



void insercion (int a[] ,  int N);
void llenarArreglo(int a[] , int orden , int n);
void imprimirArreglo(int a[] , int n);

double timeval_diff(struct timeval *a, struct timeval *b)
{
  return
    (double)(a->tv_sec + (double)a->tv_usec/1000000) -
    (double)(b->tv_sec + (double)b->tv_usec/1000000);
}
int main() {

  //Las funciones para llenar y demas se encuentran en la clase manejo.cpp
  for (int i = 200; i < 40000; i+=100) {
    int n = i;
    int a[n];
    llenarArreglo(a,0,n);

    struct timeval t_ini, t_fin;
    double secs;
    gettimeofday(&t_ini, NULL);

    insercion(a , n);

    gettimeofday(&t_fin, NULL);

    secs = timeval_diff(&t_fin, &t_ini);
    std::cout<<printf("%.5f", secs * 1000.0)<<std::endl;

  }

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
