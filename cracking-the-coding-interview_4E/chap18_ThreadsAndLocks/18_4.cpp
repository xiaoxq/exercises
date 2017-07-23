/*
 * 18_4.cpp
 *
 *  Created on: 2013-5-19
 *      Author: beet
 */

/*
 * In order for a deadlock to occur, must have the following four conditions met:
 * 1. Mutual Exclusion: Only one process can use a resource at a given time.
 * 2. Hold and Wait: Processes already holding a resource can request new ones.
 * 3. No Preemption: One process cannot forcibly remove another process’ resource.
 * 4. Circular Wait: Two or more processes form a circular chain where each process is waiting on another resource in the chain.
 */

#include <vector>
#include <algorithm>
using namespace std;

// every thread acquire resources by the same order
class Resource
{
public:
	static void acquire(int id){}
	static void release(int id){}
	// other fields
};
void* AThreadBreakCond4(void* para)
{
	static vector<int> requiredResIds;
	sort(requiredResIds.begin(), requiredResIds.end());
	for( vector<int>::const_iterator it=requiredResIds.begin(); it!=requiredResIds.end(); ++it )
		Resource::acquire( *it );

	// do something

	for( vector<int>::reverse_iterator it=requiredResIds.rbegin(); it!=requiredResIds.rend(); ++it )
		Resource::release( *it );
	return NULL;
}
