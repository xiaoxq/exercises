/*
 * 8_2.cpp
 *
 *  Created on: 2013-5-1
 *      Author: beet
 */

#include <vector>
using namespace std;

struct Step
{
	int x;
	int y;
};

int pathsToGo( bool** grids, int N, Step current, vector<Step>& path )
{
	// find a path
	if(current.x==N-1 && current.y==N-1)
	{
		printf("Path: ");
		for(vector<Step>::iterator it=path.begin(); it!=path.end(); ++it)
			printf("(%d,%d) -> ", it->x, it->y);
		printf("(%d,%d)", current.x, current.y);
		return 1;
	}
	int pathes = 0;
	// try increase x
	if( current.x!=N-1 && grids[current.x+1] )
	{
		path.push_back(current);
		++current.x;
		pathes = pathsToGo(grids,N,current,path);
		--current.x;
		path.pop_back();
	}
	// try increase y
	if( current.y!=N-1 && grids[current.y+1] )
	{
		path.push_back(current);
		++current.y;
		pathes += pathsToGo(grids,N,current,path);
		--current.y;
		path.pop_back();
	}
	return pathes;
}
