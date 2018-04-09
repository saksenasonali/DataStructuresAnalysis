// This file tests the generated input by implementing it in a self-defined Min-Heap.

#include "myHeap.h"

void myHeapTest(int inp[], int count_add, int count_search, int count_del)
{
	myHeap heap,temp;
	for(int i=0; i< count_add ;i++)
		heap.insert(inp[i]);

	for(int i=0; i<count_search; i++)
	{
		while(heap.size() > 0)
		{
			if(heap.top() == inp[i+count_add])
			{
				//cout << "YES\n";
				break;
			}
			temp.insert(heap.top());
			heap.remove_min();
		}

		if(heap.size()==0)
		{
			//cout << "NO\n";
		}

		while(temp.size() > 0)
		{
			heap.insert(temp.top());
			temp.remove_min();
		}
	}

	for(int i=0; i<count_del; i++)
	{
		while(heap.size() > 0)
		{
			if(heap.top() == inp[i + count_add + count_search])
			{
				heap.remove_min();
				break;
			}
			temp.insert(heap.top());
			heap.remove_min();
		}

		while(!temp.empty())
		{
			heap.insert(temp.top());
			temp.remove_min();
		}
	}


	cout << "Self-defined Heap done !\n";
}