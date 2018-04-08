// This file tests the generated input by implementing it in the queue defined in the Standard Template Library.

#include <iostream>
using namespace std;

#include <queue>

void queueTest(int inp[], int count_add, int count_search, int count_del)
{
	queue<int> que;

	for(int i=0; i<count_add; i++)
		que.push(inp[i]);

	for(int i=0; i<count_search; i++)
	{
		queue<int> temp;
		while(!que.empty())
		{
			if(que.front() == inp[i+count_add])
			{
				cout << "YES\n";
			}
			temp.push(que.front());
			que.pop();
		}

		if(que.size()==0)
			cout << "NO\n";

		que = temp;
	}

	for(int i=0; i<count_del; i++)
	{
		queue<int> temp;
		while(!que.empty())
		{
			if(que.front() == inp[i + count_add + count_search])
			{
				que.pop();
			}
			temp.push(que.front());
			que.pop();
		}

		que = temp;
	}
}	