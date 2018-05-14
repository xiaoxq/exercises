/*
 * 16_9.cpp
 *
 *  Created on: 2013-5-18
 *      Author: beet
 */

#include <malloc.h>
#define NULL 0

void* align_malloc( size_t size, size_t align )
{
	const size_t offsetForAlignment = align-1;
	const size_t offsetForRealPtr = sizeof(void*);

	char* ptrReal = (char*)malloc( size + offsetForAlignment + offsetForRealPtr );
	if(ptrReal==NULL)
		return NULL;

	void** ptrAligned = (void**)( (size_t)(ptrReal+offsetForAlignment +offsetForRealPtr) & ~offsetForAlignment );
	// store real ptr
	ptrAligned[-1] = ptrReal;
	return (void*)ptrAligned;
}

void aligned_free(void *ptr)
{
	free(((void**)ptr)[-1]);
}

///////////////// TEST /////////////////
#include <stdio.h>
void test(void* ptr)
{
	printf( "Malloc mem at %x, align at %x\n", ((void**)ptr)[-1], ptr );
	aligned_free(ptr);
}

int main()
{
	test( align_malloc( 500, 256 ) );
	test( align_malloc( 500, 64 ) );
	test( align_malloc( 500, 16 ) );
	test( align_malloc( 500, 4 ) );

	return 0;
}
