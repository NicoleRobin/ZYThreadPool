#include "threadpool.h"
#include <unistd.h>
#include <pthread.h>

#include <iostream>
#include <cstdio>

using namespace std;

void Print(void *arg)
{
	pthread_t tid = pthread_self();
	int *piTask = (int*)arg;
	for (int i = 0; i < 10; ++i)
	{
		cout << "tid:" << tid << " Task:" << *piTask << endl;
		sleep(*piTask + 1);
	}

	cout << "tid:" << tid << " Task " << *piTask << " end" << endl;

	delete piTask;
}

int main(int argc, char **args)
{
	ZY::CThreadPool pool(4);
	pool.Start();

	// sleep(2);

	ZY::Task task;
	task.func = Print;
	for (int i = 0; i < 10; ++i)
	{
		task.arg = new int(i);
		pool.AddTask(task);
	}

	getchar();
	pool.Stop();

	return 0;
}
