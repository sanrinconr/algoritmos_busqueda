#include <stdio.h>
#include <iostream>
#include <windows.h>

int main() {


    LARGE_INTEGER frequency;
    LARGE_INTEGER start;
    LARGE_INTEGER end;
    double interval;

    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);

    //EL CODIGO
    QueryPerformanceCounter(&end);
    interval = (double) (end.QuadPart - start.QuadPart) / frequency.QuadPart;

    std::cout<<n<<",";
    printf("%f\n", interval);

  }


}
