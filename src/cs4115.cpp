#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

using namespace std;

void mergesort( unsigned int lo , unsigned int hi );
void merge_halves( unsigned int lo, unsigned int mid , unsigned int hi );

unsigned int * data;

int main(int argc, char* argv[])
{
    if(argc < 2)
        return 0;

    int size = atoi(argv[1]);
    data = new unsigned int[ size ];

    struct timeval tp ;
    for(unsigned int i = 0; i < size; i++)
    {
        gettimeofday(&tp,NULL);
        srand(tp.tv_usec) ;
        data[i] =  rand() % size;
    }

    mergesort( 0 , size );

    for(unsigned int i = 0; i < size; i++)
    {
        cout << data[i] << endl;
    }

	return 0;
}

void mergesort( unsigned int lo , unsigned int hi )
{
    if (lo >= hi)
        return;

    unsigned int mid = ( lo + hi ) >> 1;

    mergesort( lo , mid );
    mergesort( mid + 1 , hi );

    merge_halves( lo , mid , hi ); // housekeeping
}


void merge_halves( unsigned int lo , unsigned int mid , unsigned int hi )
{
    unsigned int * temp = new unsigned int[ hi + 1 - lo ];
    unsigned int left , sorted , right , c_index;
    left = lo;
    sorted = 0;
    right = mid + 1;

    while( ( left <= mid ) && ( right <= hi ) )
    {
        if( data[left] <= data[right] )
        {
            temp[sorted] = data[left]; // left halve current, less than right halve current
            left++; // move to the next lo
        }
        else
        {
            temp[sorted] = data[right]; // right halve current, less than right halve current
            right++; // move to the next mid
        }
        sorted++; // move to next position in (b) temp array
    }


    if( left > mid ) // add any values left on right halve into the array
    {
        for( c_index = right; c_index <= hi; c_index++)
        {
            temp[sorted] = data[c_index];
            sorted++;
        }
    }
    else // add any values left on left halve into the array
    {
        for( c_index = left; c_index <= mid; c_index++ )
        {
            temp[sorted] = data[c_index];
            sorted++;
        }
    }

    // update the values in the current halve with the sorted values
    for( c_index = 0; c_index <= hi - lo; c_index++)
    {
        data[c_index+lo] = temp[c_index];
    }

    delete[] temp;
}

