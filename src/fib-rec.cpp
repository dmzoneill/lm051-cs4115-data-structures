/*
 * fib-rec.cpp
 *
 *  Created on: 11 Mar 2010
 *      Author: David ONeill 0813001
 */

#include <iostream>
#include <stdlib.h>

using std::cout;
using std::endl;

unsigned int fib(unsigned int n);

unsigned int fib(unsigned int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return fib(n - 1) + fib(n - 2);
    }
}

int main(int argc, char **argv)
{
    unsigned int n = (unsigned int) atoi(argv[1]);
    cout << fib(n) << endl;

    return 0;
}
