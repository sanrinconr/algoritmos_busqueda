#include <stdio.h>
#include <time.h>
#include <sys/time.h>

/* retorna "a - b" en segundos */
double timeval_diff(struct timeval *a, struct timeval *b)
{
  return
    (double)(a->tv_sec + (double)a->tv_usec/1000000) -
    (double)(b->tv_sec + (double)b->tv_usec/1000000);
}

int main(int argc, char *argv[])
{
  struct timeval t_ini, t_fin;
  double secs;

  gettimeofday(&t_ini, NULL);
  /* ...hacer algo... */
  gettimeofday(&t_fin, NULL);

  secs = timeval_diff(&t_fin, &t_ini);
  printf("%.16g milliseconds\n", secs * 1000.0);
  return 0;
}
