// This file tests the generated input by implementing it in a self-defined AVL Tree.

#include <iostream>
#include <ctime>
using namespace std;

#include "myAvl.h"

void avlTest(int inp[], int count_add, int count_search, int count_del)
{
	myAvl avl;

	clock_t t1 = clock();

	for(int i=0; i< count_add ;i++)
		avl.insert(inp[i]);

	clock_t t2 = clock();

	for(int i=0; i< count_search; i++)
	{
		int ans = avl.search(inp[count_add + i]);
		if( ans==-1)
		{
			//cout<<"NO"<<endl;
		}
		else
		{
			//cout<<"YES"<<endl;
		}
	}

	clock_t t3 = clock();

	for(int i =0; i< count_del;i++)
	{
		avl.deletex(inp[count_add + count_search + i]);
	}

	clock_t t4 = clock();

	cout << "\nAVL Tree done! The result times(in microseconds are) : \n";
	cout << "Inserting " << count_add << " values : " << float(t2-t1)  << "\n";
	cout << "Searching " << count_search << " values : " << float(t3-t2)  << "\n";
	cout << "Deleting " << count_del << " values : " << float(t4-t3)  << "\n";
}