// This file tests the generated input by implementing it in the Priority Queue defined in the Standard Template Library.

#include <iostream>
using namespace std;

#include <queue>

void heapTest(int inp[], int count_add, int count_search, int count_del)
{
	priority_queue <int> que;

	for(int i=0; i<count_add; i++)
		que.push(inp[i]);

	for(int i=0; i<count_search; i++)
	{
		priority_queue <int> temp;
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

		que = temp;
	}

	for(int i=0; i<count_del; i++)
	{
		priority_queue <int> temp;
		while(!que.empty())
		{
			if(que.top() == inp[i + count_add + count_search])
			{
				que.pop();
			}
			temp.push(que.top());
			que.pop();
		}

		que = temp;
	}

	cout << "Heap STL done !\n";
}