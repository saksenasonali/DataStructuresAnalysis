// This file tests the generated input by implementing it in a self-defined Queue.

#include <iostream>
#include <ctime>
using namespace std;

#include "myQueue.h"

void myQueueTest(int inp[], int count_add, int count_search, int count_del)
{
	myQueue que;

	clock_t t1 = clock();

	for(int i=0; i<count_add; i++)
		que.push(inp[i]);

	clock_t t2 = clock();

	for(int i=0; i<count_search; i++)
	{
		myQueue temp;
		while(!que.empty())
		{
			if(que.top() == inp[i+count_add])
			{
				//cout << "YES\n";
			}
			temp.push(que.top());
			que.pop();
		}

		if(que.size()==0)
		{
			//cout << "NO\n";
		}

		while(!temp.empty())
		{
			que.push(temp.top());
			temp.pop();
		}
	}

	clock_t t3 = clock();

	for(int i=0; i<count_del; i++)
	{
		myQueue temp;
		while(!que.empty())
		{
			if(que.top() == inp[i + count_add + count_search])
			{
				que.pop();
				break;
			}
			temp.push(que.top());
			que.pop();
		}

		while(!temp.empty())
		{
			que.push(temp.top());
			temp.pop();
		}
	}

	clock_t t4 = clock();

	cout << "\nSelf-defined Queue done! The result times(in microseconds are) : \n";
	cout << "Inserting " << count_add << " values : " << float(t2-t1)  << "\n";
	cout << "Searching " << count_search << " values : " << float(t3-t2)  << "\n";
	cout << "Deleting " << count_del << " values : " << float(t4-t3)  << "\n";
}