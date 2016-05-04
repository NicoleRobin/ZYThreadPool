#include "threadpool.h"

namespace ZY
{
	void* CThreadPool::ThreadFunc(void *arg)
	{
		CThreadPool *pThreadPool = (CThreadPool*)arg;

		for (;;)
		{
			pthread_mutex_lock(&(pThreadPool->m_mutex));

			pthread_cond_wait(&(pThreadPool->m_cond), &(pThreadPool->m_mutex));

			if (!pThreadPool->m_bStart)
			{
				break;
			}

			Task task = pThreadPool->m_deqTask.back();
			pThreadPool->m_deqTask.pop_back();

			pthread_mutex_unlock(&(pThreadPool->m_mutex));

			(*(task.func))(task.arg);
		}

		pthread_mutex_unlock(&(pThreadPool->m_mutex));
		pthread_exit(NULL);
		return NULL;
	}

	CThreadPool::CThreadPool(int iSize, int iMaxSize)
		: m_iThreadNum(iSize), m_iMaxThread(iMaxSize), m_bStart(false)
	{

	}

	CThreadPool::~CThreadPool()
	{
	
	}

	int CThreadPool::Start()
	{
		m_bStart = true;
		pthread_mutex_init(&m_mutex, NULL);
		pthread_cond_init(&m_cond, NULL);

		pthread_t tid = 0;
		for (int i = 0;i < m_iThreadNum; ++i)
		{
			if (0 != pthread_create(&tid, NULL, ThreadFunc, this))
			{
				return -1;
			}

			m_vecThreads.push_back(tid);
		}

		return 0;
	}

	int CThreadPool::Stop()
	{
		pthread_mutex_lock(&m_mutex);
		m_bStart = false;
		pthread_mutex_unlock(&m_mutex);

		pthread_cond_broadcast(&m_cond);

		for (int i = 0; i < m_iThreadNum; ++i)
		{
			pthread_join(m_vecThreads[i], NULL);
		}

		return 0;
	}

	int CThreadPool::AddTask(Task *task)
	{
		pthread_mutex_lock(&m_mutex);
		m_deqTask.push_back(*task);
		pthread_mutex_unlock(&m_mutex);

		pthread_cond_signal(&m_cond);

		return 0;
	}
};
