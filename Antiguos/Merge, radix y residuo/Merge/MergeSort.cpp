#include <iostream>
#include <windows.h>

using namespace std;

void mergeSort(int a[], int first, int last);
void mergeList(int a[], int start1, int end1, int start2, int end2);
void llenarArreglo(int a[], int n);
void verArreglo(int a[], int n);
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b);

int main() {
	
	for(int i = 1000; i<=5000; i+=100) {
	
		LARGE_INTEGER t_ini, t_fin;
		double secs;
		int arreglo[i];
		llenarArreglo(arreglo, i);
		//verArreglo(arreglo, i);
	
		// Calculo del tiempo que tarda el algoritmo quicksort
		QueryPerformanceCounter(&t_ini);
		mergeSort(arreglo, 0, i-1);
		QueryPerformanceCounter(&t_fin);	
		// -------------------------------------------------
	
		//verArreglo(arreglo, i);
		
		secs = performancecounter_diff(&t_fin, &t_ini);
		printf("Para %d elementos tardo: %.15g milliseconds\n", i, secs * 1000.0);
	}

	return 0;
}

void mergeSort(int a[], int first, int last) {
	
	if(first<last) {
		
		int middle = (first+last)/2;
		mergeSort(a, first, middle);
		mergeSort(a, middle+1, last);
		mergeList(a, first, middle, middle+1, last);
	}
}

void mergeList(int a[], int start1, int end1, int start2, int end2) {
	
	int finalStart = start1;
	int finalEnd = end2;
	int indexC = 0;
	int result[end2-start1];
	
	while((start1<=end1) && (start2<=end2)){
		if(a[start1]<a[start2]) {
			result[indexC] = a[start1];
			start1++;
		} else {
			result[indexC] = a[start2];
			start2++;
		}
		indexC++;
	}
	
	if(start1<=end1) {
		
		for(int i=start1; i<=end1; i++) {
			
			result[indexC] = a[i];
			indexC++;
		}
	} else {
		
		for(int i = start2; i<=end2; i++) {
			
			result[indexC] = a[i];
			indexC ++;
		}
	}
	
	//Aqui se ponen los valores de result en el arreglo original
	indexC = 0;
	for(int i = finalStart; i<=finalEnd; i++) {
		
		a[i] = result[indexC];
		indexC++;
	}
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
