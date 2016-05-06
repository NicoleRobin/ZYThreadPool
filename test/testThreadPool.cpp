#include "threadpool.h"
#include "unistd.h"
#include <iostream>
#include <cstdio>

using namespace std;

void Print(void *arg)
{
	int *piTask = (int*)arg;
	for (int i = 0; i < 10; ++i)
	{
		cout << "Task " << *piTask << endl;
		sleep(*piTask + 1);
	}

	cout << "Task " << *piTask << " end" << endl;

	delete piTask;
}

int main(int argc, char **args)
{
	ZY::CThreadPool pool(4, 10);
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
