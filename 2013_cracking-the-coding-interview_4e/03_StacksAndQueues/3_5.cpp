/*
 * 3_5.cpp
 *
 *  Created on: 2013-4-18
 *      Author: beet
 */

#include <stack>
using namespace std;

class MyQueue
{
public:
	void push_back(int elem)
	{
		m_back.push(elem);
	}

	int front()
	{
		if(m_front.empty())
			trans();
		//assert( !m_front.empty() );
		return m_front.top();
	}

	void pop_front()
	{
		//assert( !m_front.empty() );
		m_front.pop();
	}
private:
	stack<int> m_front;
	stack<int> m_back;

	void trans()
	{
		while(!m_back.empty())
		{
			m_front.push( m_back.top() );
			m_back.pop();
		}
	}
};

///////////////// TEST /////////////////
#include <stdio.h>
int main()
{
	MyQueue q;
	q.push_back(1);
	q.push_back(2);
	q.push_back(3);
	printf("%d\n",q.front());
	q.push_back(4);
	q.push_back(5);
	q.pop_front();
	q.pop_front();
	printf("%d\n",q.front());
	q.pop_front();
	printf("%d\n",q.front());
	q.pop_front();
	printf("%d\n",q.front());

	return 0;
}
