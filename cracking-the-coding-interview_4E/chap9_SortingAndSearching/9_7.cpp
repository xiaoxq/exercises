/*
 * 9_7.cpp
 *
 *  Created on: 2013-5-6
 *      Author: beet
 */

#include <vector>
#include <algorithm>
using namespace std;

struct Person
{
	int height;
	int weight;

	static bool compareByHeight( const Person& p, const Person& q )
	{
		return p.height<q.height;
	}
};

// sort by height, then find the longest part
int findLongestTower( const vector<Person>& people, vector<int>& counted_table, int cur, int preHeight, int preWeight )
{
	if( cur==people.size() )
		return 0;

	// without the current person
	int maxi = findLongestTower( people, counted_table, cur+1, preHeight, preWeight );

	// with the current
	if( preHeight < people[cur].height && preWeight < people[cur].weight )
	{
		if( counted_table[cur]==0 )
			counted_table[cur] = 1 + findLongestTower(people, counted_table, cur+1, people[cur].height, people[cur].weight);
		if( maxi<counted_table[cur] )
			maxi = counted_table[cur];
	}

	return maxi;
}

// wrapper
int findLongestTower( vector<Person>& people )
{
	vector<int> counted_table( people.size(), 0 );
	sort( people.begin(), people.end(), Person::compareByHeight );
	return findLongestTower( people, counted_table, 0, -1, -1 );
}

///////////////// TEST /////////////////
#include <stdio.h>
int main()
{
	Person people[] = {
			{1,1},
			{4,4},
			{2,5},
			{5,2},
			{2,4},
			{3,5},
			{4,6}
	};
	vector<Person> people_vec( people, people+5 );
	// {1,1} {4,4} = 2
	printf( "findLongestTower(people)=%d\n", findLongestTower(people_vec));
	// {1,1} {2,4} {3,5} = 3
	people_vec.push_back( people[5] );
	printf( "findLongestTower(people)=%d\n", findLongestTower(people_vec));

	return 0;
}
