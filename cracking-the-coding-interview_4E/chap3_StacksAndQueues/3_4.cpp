/*
 * 3_4.cpp
 *
 *  Created on: 2013-4-17
 *      Author: beet
 */

#include <stack>
#include <stdio.h>
using namespace std;

struct Rod
{
	Rod( char name, int n = 0 )
	{
		this->name = name;

		for(int i=n; i>0; --i)
			disks.push(i);
	}

	static void move( int diskNum, Rod& from, Rod& to, Rod& free )
	{
		if(diskNum==0)
			return;

		move( diskNum-1, from, free, to );

		int temp = from.disks.top();
		printf( "move %d from %c to %c\n", temp, from.name, to.name );
		from.disks.pop();
		to.disks.push(temp);

		move( diskNum-1, free, to, from );
	}

	stack<int> disks;
	char name;
};

///////////////// TEST /////////////////
int main()
{
	Rod r1('A', 7);
	Rod r2('B');
	Rod r3('C');

	Rod::move( 3, r1, r2, r3 );

	return 0;
}
