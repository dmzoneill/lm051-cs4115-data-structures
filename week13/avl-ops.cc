/*
 *  avl-ops.cc
 *
 *  Created on: 23 April 2010
 *  Author: David ONeill 0813001
 *
 *  read stream of numbers from command line into a avl 
 *
 * ==3779== HEAP SUMMARY:
 * ==3779==     in use at exit: 0 bytes in 0 blocks
 * ==3779==   total heap usage: 7 allocs, 7 frees, 168 bytes allocated
 * ==3779== 
 * ==3779== All heap blocks were freed -- no leaks are possible
 * ==3779== 
 * ==3779== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 4 from 4)
 * --3779-- 
 * --3779-- used_suppression:      2 Debian libc6 (2.10.x) stripped dynamic linker
 * --3779-- used_suppression:      2 Debian libc6 (2.10.x) stripped dynamic linker
 * ==3779== 
 * ==3779== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 4 from 4)
 *  
 *  
 */

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "avl.h"

using std::cout;
using std::endl;
using std::cin;


int main()
{       	
	clock_t t1, t2;

	AVL< short, short* > occurrences;
	AVL< short , short* >::Iterator< short , short* > iter ( &occurrences );

	short pair_key = 0;
	short * pair_val;

	bool found = false;
	bool empty = true;
	short i = 0;
	unsigned short count = 0;

        t1 = clock();

	//
	// INSERT AND UPDATE
	//	

	while ( cin >> i )
   	{
		if( empty == false )
		{
		    found = iter.Find( i , pair_val );		    
		}

		if ( found == false )
		{	
		    short* sPTR = new short( 1 );
		    occurrences.Insert( i , sPTR );
		}
		else
		{
		    *pair_val += 1;
		}
	
		count++;
		empty = false;
	}

	t2 = clock();
	float s = ( t2 - t1 ) / float(CLOCKS_PER_SEC);
	float avg = s / count;
	printf( "Total time taken = %.3f(s); avg. time per op: %.5f(us)\n" , s , avg );

	//
	// LIST
	// GET THE FIRST AND THEN START INTERATING
	//

	found = iter.GetFirst( pair_key , pair_val );
	while ( found )
	{
		cout << pair_key << ": " << *pair_val << "\n";
		found = iter.GetNext( pair_key , pair_val );
	}


	//	
	// CLEANUP
	// KEEP GETTING THE HEAD AND DELETE IT
	//	

	found = iter.GetFirst( pair_key , pair_val );
	while( found )
	{				
		delete pair_val;
		occurrences.Remove( pair_key );
		found = iter.GetFirst( pair_key , pair_val );
	}


	return 0;
}
