/*
 *  map-ops.cc
 *
 *  Created on: 23 April 2010
 *  Author: David ONeill 0813001
 *  
 *  read stream of numbers from command line into a map
 *  
 * ==26252== HEAP SUMMARY:
 * ==26252==     in use at exit: 0 bytes in 0 blocks
 * ==26252==   total heap usage: 40 allocs, 40 frees, 1,920 bytes allocated
 * ==26252== 
 * ==26252== All heap blocks were freed -- no leaks are possible
 * ==26252== 
 * ==26252== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 4 from 4)
 * --26252-- 
 * --26252-- used_suppression:      2 Debian libc6 (2.10.x) stripped dynamic linker
 * --26252-- used_suppression:      2 Debian libc6 (2.10.x) stripped dynamic linker
 * ==26252== 
 * ==26252== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 4 from 4)
 *  
 */

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <map>

using std::map;
using std::make_pair;
using std::cout;
using std::endl;
using std::cin;

map< short , short > occurrences;

int main()
{
	clock_t t1, t2;

	short i = 0;
	int cnt = 0;
	int temp = 0;    
	map< short, short >::iterator item; 

	t1 = clock();

	while ( cin >> i )
	{    
		item = occurrences.find( i );

		if ( item == occurrences.end() )
		{
		    	occurrences.insert( make_pair ( i , (short)1 ) );
		}
		else
		{
		    	item->second = item->second + 1;
		}   
		cnt++;     
	}

	t2 = clock();
	float s = ( t2 - t1 ) / float(CLOCKS_PER_SEC);
	float avg = s / cnt;
	printf( "Total time taken = %.3f(s); avg. time per op: %.2f(us)\n" , s , avg );

	for ( item = occurrences.begin(); item != occurrences.end(); ++item ) 
	{
		cout << item->first << " : " << item->second << endl;        
	}

	occurrences.clear();

	return 0;
}
