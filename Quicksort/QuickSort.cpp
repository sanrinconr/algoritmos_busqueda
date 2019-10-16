#include <iostream>
#include <windows.h>

using namespace std;

void ordenRapido(int a[], int izq, int der);
void intercambio(int a[], int i, int j);
void llenarArreglo(int a[], int n);
void verArreglo(int a[], int n);
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b);

int main() {
	
	for(int i=20; i<=500;i+=10){
	
		LARGE_INTEGER t_ini, t_fin;
		double secs;
		int arreglo[i];
		llenarArreglo(arreglo, i);
		
		// Calculo del tiempo que tarda el algoritmo quicksort
		QueryPerformanceCounter(&t_ini);
		ordenRapido(arreglo, 0, i-1);
	 	QueryPerformanceCounter(&t_fin);	
		// -------------------------------------------------
		//verArreglo(arreglo, i);

		secs = performancecounter_diff(&t_fin, &t_ini);
		printf("Para %d elementos tardo: %.15g milliseconds\n", i, secs * 1000.0);
	}
	return 0;
}

void ordenRapido(int a[], int izq, int der) {
	int i, j, v;
  	if (der> izq) {
	  	v= a[der]; i = izq -1; j= der;
       	for(;;) {
		   while (a[++i]<v);
		   while (a[--j] >v);
		   if(i>=j) break;
		   intercambio(a,i,j);
		}
		intercambio(a, i, der);
		ordenRapido(a, izq, i-1);
		ordenRapido(a, i+1,der);
	}
}

void intercambio(int a[], int i, int j) {
	
	int aux = a[i];
	a[i] = a[j];
	a[j] = aux;
}

void verArreglo(int a[], int n) {
	
	for(int i=0; i<n; i++) {
		cout<< a[i]<<endl;
	}
}

void llenarArreglo(int a[], int n) {
	
	int num=100000*n;
	
	for(int i=0; i<n; i++) {
		a[i] = num;
		num -=100000;
	}
}

// Metodo para calcular el tiempo que tarda un proceso --------------
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b) {
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}
// -------------------------------------------------------------------

