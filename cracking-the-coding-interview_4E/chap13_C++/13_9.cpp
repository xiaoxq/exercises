/*
 * 13_9.cpp
 *
 *  Created on: 2013-5-17
 *      Author: beet
 */

// The same with 7_10

#include <stdio.h>

template <class T>
class smart_ptr_impl
{
public:
	smart_ptr_impl(T* object)
	{
		instance = object;
		ref_count = 1;
	}
	void inc_ref()
	{
		++ref_count;
	}
	void dec_ref()
	{
		if( --ref_count == 0)
		{
			delete instance;
			printf( "Destroy instance\n" );
		}
	}
	T* get_instance()
	{
		return instance;
	}
	int get_ref_count()
	{
		return ref_count;
	}
private:
	T* instance;
	int ref_count;
};

template <class T>
class smart_ptr
{
public:
	smart_ptr(T* object)
	{
		smart_instance = new smart_ptr_impl<T>(object);
	}
	smart_ptr(smart_ptr& old_ref)
	{
		smart_instance = old_ref.smart_instance;
		smart_instance->inc_ref();
	}
	~smart_ptr()
	{
		smart_instance->dec_ref();
		if( smart_instance->get_ref_count()==0 )
		{
			delete smart_instance;
			printf( "Destroy smart instance\n" );
		}
	}
	T* operator()()
	{
		return smart_instance->get_instance();
	}
	int get_ref_count()
	{
		return smart_instance->get_ref_count();
	}
private:
	smart_ptr_impl<T>* smart_instance;
};

///////////////// TEST /////////////////
struct test_struct
{
	void who_am_i()
	{
		printf("I'm: %ul\n", this);
	}
	test_struct()
	{
		printf("Create struct: %ul\n", this);
	}
	~test_struct()
	{
		printf("Destroy struct: %ul\n", this);
	}
};

void test( smart_ptr<test_struct> para )
{
	para()->who_am_i(); // struct1
	printf( "Current ref_count is %d\n", para.get_ref_count() ); // 3
	smart_ptr<test_struct> ref(para);
	ref()->who_am_i(); // struct1
	printf( "Current ref_count is %d\n", para.get_ref_count() ); // 4

	/*
	 * Create struct2
	 * Destroy struct2
	 * Destroy instance2
	 * Destroy smart instance2
	 */
	smart_ptr<test_struct> ref1( new test_struct() );
	ref1()->who_am_i(); // struct2
}
int main()
{
	// Create struct1
	smart_ptr<test_struct> ref1( new test_struct() );
	ref1()->who_am_i(); // struct1
	printf( "Current ref_count is %d\n", ref1.get_ref_count() ); // 1
	smart_ptr<test_struct> ref2(ref1);
	ref2()->who_am_i(); // struct1
	printf( "Current ref_count is %d\n", ref1.get_ref_count() ); // 2
	test( ref2 );
	printf( "Current ref_count is %d\n", ref1.get_ref_count() ); // 2
	return 0;
	/*
	 * Destroy struct1
	 * Destroy instance1
	 * Destroy smart instance1
	 */
}
