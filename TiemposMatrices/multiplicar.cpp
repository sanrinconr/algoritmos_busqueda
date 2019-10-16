#include <stdio.h>
#include <iostream>

void Proc_sumar (int a[3][3], int b[3][3], int c[3][3] , int N);
int main() {

int a[3][3] = {1,2,3,4,5,6,7,8,9};
int b[3][3] = {1,1,1,1,1,1,1,1,1};
int c[3][3];
Proc_sumar(a,b,c,3);
for (int i = 0; i < 3; i++) {
  for (int j = 0; j < 3; j++) {
    std::cout<<b[i][j]<<",";
  }
  std::cout<<"w"<<std::endl;
}
}

void Proc_sumar (int a[3][3], int b[3][3], int c[3][3] , int N){
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      c[i][j]=0;
      for (int k = 0; k < N; k++) {
        c[i][j] = c[i][j]+a[i][k]*b[k][j];
      }
    }
  }
}
