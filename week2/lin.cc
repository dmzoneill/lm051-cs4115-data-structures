#include <fstream>
#include <iostream>

using std::cout;
using std::endl;
using std::ofstream;

#include <math.h>
#include <stdlib.h>

float fun(float, float);

int main(int argc, char *argv[])
{
  int n = atoi(argv[1]);
  int arr[25];


  for (int i = 0; i < n; i++)
  {
    ofstream fout;
    fout.open("blah.txt");

    int i = 234;

    if (i != 0)
      arr[12] = i;

    float z = fun(1.23, 4.56);
    fout<< z;

    fout.close();
  }
}

float fun(float x, float y)
{
  float z = x*y;

  return log(sin(sin(cos(z))));
}
