/*
* C program for Tower of Hanoi using Recursion
*/
#include <stdio.h>
#include <iostream>

void towers(int, char, char, char);

int main()
{
  for (int i = 1; ; i++) {
    int num = i;
    std::cout << "N:" << i<<'\n';
    towers(num, 'A', 'C', 'B');
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
