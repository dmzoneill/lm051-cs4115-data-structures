/*
 * fib-iter.cpp
 *
 *  Created on: 11 Mar 2010
 *      Author: David ONeill 0813001
 */

#include <iostream>
#include <stdlib.h>

using std::cout;
using std::endl;


int main(int argc, char **argv)
{

    unsigned int n = (unsigned int) atoi(argv[1]);

    unsigned int first = 0;
    unsigned int second = 1;
    unsigned int temp;

    for(int it = 2; it < (n +1); it++)
    {
        temp = first + second;
        first = second;
        second = temp;
    }

    if(n==0)
       second = 0;

    cout << second << endl;

    return 0;
}

