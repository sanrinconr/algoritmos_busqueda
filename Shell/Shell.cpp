#include <iostream>
#include <windows.h>

using namespace std;

// Prototipo de funciones---------------------------------------
void shell(int a[], int n);
void llenarArreglo(int a[], int n);
void verArreglo(int a[], int n);
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b);
// -------------------------------------------------------------

int main() {
	
	for(int i=20; i<=500; i+=10){
	
		LARGE_INTEGER t_ini, t_fin;
  		double secs;
  	
  		int arreglo[i];
  		llenarArreglo(arreglo, i);
  	
  		// Calculo del tiempo que tarda el algoritmo burbuja
		QueryPerformanceCounter(&t_ini);
		shell(arreglo, i);
 		QueryPerformanceCounter(&t_fin);	
		// -------------------------------------------------
		//cout<<"Despues de ordenar"<<endl;
		//verArreglo(arreglo, i);
	
		secs = performancecounter_diff(&t_fin, &t_ini);
		printf("Para %d elementos tardo: %.15g milliseconds\n", i, secs * 1000.0);	
	}
	
	return 0;
}

void shell(int a[], int n) {
	
	int i,j,h;
	int v;
	for(h=1; h<=n/9; h=3*h+1);
	for(; h>0; h/=3) {
		for(i=h+1; i<=n; i+=1) {
			v = a[i];
			j = i;
			while(j>=h && a[j-h]>v) {
				
				a[j] = a[j-h];
				j-=h;
			}
			a[j] = v;
		}
	}
}

void llenarArreglo(int a[], int n) {
	
	int num=10000000*n;
	
	for(int i=0; i<n; i++) {
		a[i] = num;
		num -=10000000;
		//cout<< a[i]<<endl;
	}
}

void verArreglo(int a[], int n) {
	
	for(int i=0; i<n; i++) {
		cout<< a[i]<<endl;
	}
}

// Metodo para calcular el tiempo que tarda un proceso --------------
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b) {
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}
// -------------------------------------------------------------------
