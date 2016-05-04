#ifndef __THREAD_POOL_H__
#define __THREAD_POOL_H__

#include <pthread.h>

#include <vector>
#include <deque>

namespace ZY
{
	struct Task
	{
		void (*func)(void *);
		void *arg;
	};

	class CThreadPool
	{
	public:
		CThreadPool(int iSize, int iMaxSize);
		~CThreadPool();
		
	public:
		// initialize the thread pool
		int Start();
		int Stop();
		int AddTask(Task *task);
		
	private:
		static void* ThreadFunc(void *arg);

	private:
		pthread_mutex_t m_mutex;				// Mutex
		pthread_cond_t m_cond;					// Condition
		std::vector<pthread_t> m_vecThreads;	// Threads
		std::deque<Task> m_deqTask;				// Tasks
		int m_iThreadNum;						// The number of ThreadPool's threads
		int m_iMaxThread;						// The max number of ThreadPool's threads
		bool m_bStart;							// ThreadPool's state
	};
};

#endif /* __THREAD_POOL_H__ */
