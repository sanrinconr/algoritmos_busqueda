/*
* C program for Tower of Hanoi using Recursion
*/
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <sys/time.h>

void towers(int, char, char, char);

double timeval_diff(struct timeval *a, struct timeval *b)
{
  return
    (double)(a->tv_sec + (double)a->tv_usec/1000000) -
    (double)(b->tv_sec + (double)b->tv_usec/1000000);
}

int main()
{
  for (int i = 1; ; i++) {
    int num = i;
    struct timeval t_ini, t_fin;
    double secs;

    gettimeofday(&t_ini, NULL);
    towers(num, 'A', 'C', 'B');
    gettimeofday(&t_fin, NULL);

    secs = timeval_diff(&t_fin, &t_ini);
    fprintf(stderr,"%.16g  N = %d\n", secs * 1000.0 , i);
  }
  return 0;
}
void towers(int num, char frompeg, char topeg, char auxpeg)
{
  if (num == 1)
  {
    return;
  }
  towers(num - 1, frompeg, auxpeg, topeg);
  towers(num - 1, auxpeg, topeg, frompeg);
}
