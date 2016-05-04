#include "threadpool.h"

#include <iostream>
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

	for (int i = 0; i < 100; ++i)
	{
		pool.AddTask(Print, *i);
	}

	pool.Stop();

	return 0;
}
