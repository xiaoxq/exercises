/*
 * 3_6.cpp
 *
 * O(n^2)
 *
 *  Created on: 2013-4-18
 *      Author: beet
 */

#include <stack>
using namespace std;

void sortStack( stack<int>& s )
{
	// temp is always empty at beginning
	static stack<int> temp;

	while(!s.empty())
	{
		temp.push( s.top() ); s.pop();
	}

	while(!temp.empty())
	{
		int current = temp.top(); temp.pop();
		while( !s.empty() && s.top()<current )
		{
			temp.push( s.top() ); s.pop();
		}
		s.push(current);
	}
}

///////////////// TEST /////////////////
#include <stdio.h>
int main()
{
	stack<int> s;
	s.push(1);
	s.push(3);
	s.push(5);
	s.push(4);
	s.push(2);
	s.push(9);

	sortStack(s);
	while(!s.empty())
	{
		printf("%d\n",s.top());
		s.pop();
	}

	return 0;
}
