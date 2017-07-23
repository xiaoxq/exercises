/*
 * 8_3.cpp
 *
 *  Created on: 2013-5-1
 *      Author: beet
 */

#include <set>
#include <vector>
#include <iostream>
using namespace std;

// from front to back
template <class T>
void getSubSets( const set<T>& source, typename set<T>::iterator currentPos, set<T>& subset )
{
	if( currentPos==source.end() )
	{
		cout << "{";
		for( typename set<T>::iterator it=subset.begin(); it!=subset.end(); ++it )
			cout << *it << ", ";
		cout << "}" << endl;
		return;
	}

	// with the current pos
	typename set<T>::iterator it = subset.insert( *currentPos ).first;
	++currentPos;
	getSubSets( source, currentPos, subset );
	subset.erase(it);

	// without the current pos
	getSubSets( source, currentPos, subset );
}

// from back to front
template <class T>
void getSubSets2( const set<T>& source, typename set<T>::iterator currentPos, vector< set<T> >& subsets )
{
	// an empty set
	if( currentPos==source.end() )
	{
		subsets.push_back( set<T>() );
		return;
	}

	T me = *(currentPos++);
	getSubSets2( source, currentPos, subsets );
	const int size = subsets.size();
	for( int i=0; i<size; ++i )
	{
		subsets.push_back( subsets[i] );
		subsets[size+i].insert( me );
	}
}
///////////////// TEST /////////////////
int main()
{
	int number[] = {1,2,3,4};
	set<int> source( number, number+4 );
	set<int> subset;
	getSubSets(source, source.begin(), subset);

	vector< set<int> > subsets;
	getSubSets2(source, source.begin(), subsets);
	for( vector< set<int> >::iterator it = subsets.begin(); it!=subsets.end(); ++it )
	{
		cout << "{";
		for( set<int>::iterator p=it->begin(); p!=it->end(); ++p )
			cout << *p << ", ";
		cout << "}" << endl;
	}

	return 0;
}
