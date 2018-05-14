/*
 * 10_6.cpp
 *
 *  Created on: 2013-5-7
 *      Author: beet
 */

#include <vector>
#include <limits>
#include <algorithm>
#include <stdio.h>
using namespace std;

#define FloatEpsilon 0.000001f
#define InvalidFloat (numeric_limits<float>::max())

struct Point
{
	float x;
	float y;
};

inline bool equal( const float f1, const float f2 )
{
	return (f1>=f2 ? f1-f2 : f2-f1) < FloatEpsilon;
}

inline float getSlope( const Point& p1, const Point& p2 )
{
	if( p1.x==p2.x )
		return InvalidFloat;
	return (p2.y-p1.y) / (p2.x-p1.x);
}

void findLinePassingMostPoints( vector<Point>& points )
{
	if( points.empty() )
		return;

	const int num = points.size();
	vector<int> result( 1, 0 );

	for( int pos=0; pos + result.size() < num; ++pos )
	{
		// calculate every slope
		const int remain = num-pos-1;
		vector<float> slopes( remain );
		for( int i=pos+1; i<num; ++i )
			slopes[i-pos-1] = getSlope( points[pos], points[i] );

		// count the max-number of slopes
		vector<bool> counted( remain, false );
		for( int i=0; i<remain; ++i )
		{
			if( counted[i] )
				continue;
			counted[i] = true;

			float curSlope = slopes[i];
			vector<int> curSlopeSet;
			curSlopeSet.push_back( pos );
			curSlopeSet.push_back( pos+1+i );
			for( int j=i+1; j<remain; ++j )
			{
				if( equal( curSlope, slopes[j] ) )
				{
					curSlopeSet.push_back( pos+1+j );
					counted[j] = true;
				}
			}

			// update result
			if( curSlopeSet.size() > result.size() )
				curSlopeSet.swap( result );
		}
	}

	// print result
	printf( "%d points in one line mostly, they are: ", result.size() );
	for( vector<int>::const_iterator it=result.begin(); it!=result.end(); ++it )
		printf(" -> (%f,%f)", points[*it].x, points[*it].y);
	printf("\n");
}

///////////////// TEST /////////////////

int main()
{
	Point array[] = {
			{ 1.f,1.f },
			{ 2.f,2.f },
			{ 3.f,3.f },
			{ 3.f,2.f },
			{ 4.f,2.f },
			{ 5.f,2.f },
			{ 5.f,1.f },
			{ 6.f,0.f },
			{ 2.f,4.f },
	};
	vector<Point> points( array, array+2 );
	findLinePassingMostPoints( points ); //2

	points.assign( array, array+4 );
	findLinePassingMostPoints( points ); //3

	points.assign( array, array+6 );
	findLinePassingMostPoints( points ); //4

	points.assign( array, array+9 );
	findLinePassingMostPoints( points ); //5

	return 0;
}
