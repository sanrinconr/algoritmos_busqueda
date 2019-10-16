#include <iostream>
#include <windows.h>

using namespace std;

// Prototipo de funciones---------------------------------------
void multiplicar(int **A, int **B, int **C, int N);
void llenarMatriz(int **A, int N, int M);
void borrarMatriz(int **a, int N, int M);
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b);
// -------------------------------------------------------------

int main() {
	
	LARGE_INTEGER t_ini, t_fin;
  	double secs;
  	int N=3;
  	int M=3;
  	
  	for(int i=0; i<10;i++){
  		 
  		int **A;
  		int **B;
  		int **C;
  	
  		A = new int*[M];
  		B = new int*[M];
  		C = new int*[M];
  		llenarMatriz(A, N, M);
  		llenarMatriz(B, N, M);
  	
		// Calculo del tiempo que tarda en multiplicar
		QueryPerformanceCounter(&t_ini);
  		multiplicar(A, B, C, M);
  		QueryPerformanceCounter(&t_fin);
		// -------------------------------------------------
	
		borrarMatriz(A, N, M);
		borrarMatriz(B, N, M);
		borrarMatriz(C, N, M);
	
		delete []A;
		delete []B;
		delete []C;
	
		secs = performancecounter_diff(&t_fin, &t_ini);
  		printf("\nPara M = %d tardo: %.15g milliseconds\n", M, secs * 1000.0);
  		
  		N*=2;
  		M*=2;
 	}
  	
	return 0;
}

void multiplicar(int **A, int **B, int **C, int N) {
	
	for(int i=0; i<N; i++) {
		C[i]= new int[N];
		for(int j=0; j<N; j++) {
			C[i][j]=0;
			for(int k=0; k<N; k++) {
				C[i][j]=C[i][j]+A[i][k]*B[k][j];
			}
			//cout<< ": "<<C[i][j]<<" : ";
		}
		//cout<<endl;
	} 
}

void llenarMatriz(int **A, int N, int M) {
	
	int val=1;
	for (int i=0; i<N; i++) {
		A[i]= new int[M];
		for(int j=0; j<M; j++) {
			A[i][j]=val;
			//cout<<A[i][j]<<"  ";
			val++;
		}
		//cout<<endl;
	}
	//cout<<"------------------"<<endl;
}

void borrarMatriz(int **a, int N, int M) {
	
	for (int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
		}
		delete[] a[i];
	}
	delete[] a;
}

// Metodo para calcular el tiempo que tarda un proceso --------------
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b) {
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}
// -------------------------------------------------------------------
