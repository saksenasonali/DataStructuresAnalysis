// This file tests the generated input by implementing it in a self-defined Min-Heap.

#include <iostream>
#include <ctime>
using namespace std;

#include "myHeap.h"

void myHeapTest(int inp[], int count_add, int count_search, int count_del)
{
	myHeap heap,temp;

	clock_t t1 = clock();

	for(int i=0; i< count_add ;i++)
		heap.insert(inp[i]);

	clock_t t2 = clock();

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

	clock_t t3 = clock();

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

	clock_t t4 = clock();

	cout << "\nSelf-defined Heap done! The result times(in microseconds are) : \n";
	cout << "Inserting " << count_add << " values : " << float(t2-t1)  << "\n";
	cout << "Searching " << count_search << " values : " << float(t3-t2)  << "\n";
	cout << "Deleting " << count_del << " values : " << float(t4-t3)  << "\n";
}