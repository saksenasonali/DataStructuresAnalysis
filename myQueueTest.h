// This file tests the generated input by implementing it in a self-defined Queue.

#include <iostream>
using namespace std;

#include "myQueue.h"

void myQueueTest(int inp[], int count_add, int count_search, int count_del)
{
	myQueue que;

	for(int i=0; i<count_add; i++)
		que.push(inp[i]);

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

	for(int i=0; i<count_del; i++)
	{
		myQueue temp;
		while(!que.empty())
		{
			if(que.top() == inp[i + count_add + count_search])
			{
				que.pop();
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


	cout << "Self-defined Queue done !\n";
}