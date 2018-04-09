// This file tests the generated input by implementing it in a self-defined Binary Search Tree.

#include <iostream>
#include <ctime>
using namespace std;

#include "myBst.h"

void bstTest( int inp[], int count_add, int count_search, int count_del )
{
	myBst bst;

	clock_t t1 = clock();

	for(int i=0; i< count_add ;i++)
		bst.insert(inp[i]);

	clock_t t2 = clock();

	for(int i=0; i< count_search; i++)
	{
		int ans = bst.search(inp[count_add + i]);
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
		bst.deletex(inp[count_add + count_search + i]);
	}

	clock_t t4 = clock();

	cout << "\nBinary Search Tree done! The result times(in microseconds are) : \n";
	cout << "Inserting " << count_add << " values : " << float(t2-t1)  << "\n";
	cout << "Searching " << count_search << " values : " << float(t3-t2)  << "\n";
	cout << "Deleting " << count_del << " values : " << float(t4-t3)  << "\n";
}