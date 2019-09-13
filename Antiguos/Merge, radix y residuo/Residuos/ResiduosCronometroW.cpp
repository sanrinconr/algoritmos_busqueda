#include <stdio.h>
#include <iostream>
#include <limits.h>
#include <windows.h>

//********PROTOTIPOS****************//
char *chartobin ( unsigned char c );
unsigned bits (char x ,int k, int j);
void intercambio(char a[], int i, int j);
void imprimirArreglo(char a[] , int n);
void llenarArreglo(char a[], int n);
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b);

//********PROTOTIPOS****************//


//Funcion que imprime un char en su forma binaria
char *chartobin ( unsigned char c ){
  static char bin[CHAR_BIT + 1] = {0};
  int i;
  for( i = CHAR_BIT - 1; i >= 0; i-- )
  {
    bin[i] = (c % 2) + '0';
    c /= 2;
  }
  return bin;
}

//Corriemiento de bits
unsigned bits (char x ,int k, int j){
  //K es lo que se corre a la derecha
  //J es la mascara, cuantos digitos permite visualizar luego de el corrimiento
  return (x>>k)&~(~0<<j);
}

//Intercambia valores
void intercambio(char a[], int i, int j) {
	char aux = a[i];
	a[i] = a[j];
	a[j] = aux;
}

void cambioresiduos(char a[], int izq, int der, int b){
  int i,j;
  if (der>izq && b>0){
    i= izq; j=der;
    while(j!=i){
      //Ya que es solo una funcion se mete dentro y no se usa el punto
      while(!bits(a[i],b,1) && i<j)i++;
      while(bits(a[j],b,1) && j>i)j--;
      intercambio(a, i, j);
    }
    if (!bits(a[i],b,1)) j++;
    cambioresiduos(a, izq, j-1, b-1);
    cambioresiduos(a, j, der, b-1);
  }
}

//Imprime el arrglo char
void imprimirArreglo(char a[] , int n){
  for (int i = 0; i < n; i++) {
    std::cout << a[i] ;
    }
      std::cout << "\n" ;

}
//LLENA EL ARREGLO TAL QUE Z.....AZ.....A
void llenarArreglo(char a[], int n){
  char letra = 'Z';

  for (int i = 0; i < n; ++i) {
    a[i]=letra;
    if(letra != 'A')
    --letra;
    else
    letra='Z';
  }



}
int main(){
  for (int i = 1000; i <= 5000; i+=100) {
    int n=i;
    char a[n];
    llenarArreglo(a ,n);

    LARGE_INTEGER t_ini, t_fin;
    double secs;
    QueryPerformanceCounter(&t_ini);

    cambioresiduos(a,0,n-1,n);

    QueryPerformanceCounter(&t_fin);
    secs = performancecounter_diff(&t_fin, &t_ini);
    printf("%.15g milliseconds\n", secs * 1000.0);

  }
  return 0;
}
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b) {
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}
