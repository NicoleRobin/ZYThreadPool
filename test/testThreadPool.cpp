#include "threadpool.h"
#include "unistd.h"
#include <iostream>
#include <cstdio>

using namespace std;

void Print(void *arg)
{
	int iTask = *((int*)arg);
	for (int i = 0; i < 100; ++i)
	{
		cout << "Task " << iTask << endl;
		sleep(2);
	}

	cout << "Task " << iTask << " end" << endl;
}

int main(int argc, char **args)
{
	ZY::CThreadPool pool(4, 10);
	pool.Start();

	ZY::Task task;
	task.func = Print;
	for (int i = 0; i < 100; ++i)
	{
		task.arg = &i;
		pool.AddTask(&task);
	}

	getchar();
	pool.Stop();

	return 0;
}
