/*
 * 18_3.cpp
 *
 *  Created on: 2013-5-19
 *      Author: beet
 */

class Lock
{
public:
	void acquire(){}
	void release(){}
};

template <class T>
class Singleton
{
private:
	static T* mInstance;
	static Lock mLock;
protected:
	// cannot be instantiated by caller
	Singleton(){}
public:
	static T* instance()
	{
		if(!mInstance)
		{
			mLock.acquire();
			if(!mInstance)
				mInstance = new T;
			mLock.release;
		}
		return mInstance;
	}
};

//Lock Singleton<T>::mLock;
