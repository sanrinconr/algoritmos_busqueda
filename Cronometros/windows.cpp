#include <stdio.h>
#include <iostream>
#include <windows.h>

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b);



int main() {

  LARGE_INTEGER t_ini, t_fin;
  double secs;
  QueryPerformanceCounter(&t_ini);

  //EL CODIGO
  QueryPerformanceCounter(&t_fin);
  secs = performancecounter_diff(&t_fin, &t_ini);
	printf("%.15g milliseconds\n", secs * 1000.0);

}

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b) {
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}
