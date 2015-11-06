#ifndef __THREAD_POOL_H__
#define __THREAD_POOL_H__

#include <thread.h>

#include <list>
#include <map>


namespace ZY
{
	class ThreadPool
	{
	public:
		ThreadPool();
		~ThreadPool();
		
	public:
		// initialize the thread pool
		int Initialize();
		
		
	private:
		list<>
		list<>
		int m_nMaxThread;			// the max number of ThreadPool's threads
		int m_nMinThread;			// the min number of ThreadPool's threads
	};
};

#endif /* __THREAD_POOL_H__ */