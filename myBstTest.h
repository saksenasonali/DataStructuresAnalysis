// This file tests the generated input by implementing it in a self-defined Binary Search Tree.

#include "myBst.h"

void bstTest( int inp[], int count_add, int count_search, int count_del )
{
	myBst bst;
	for(int i=0; i< count_add ;i++)
		bst.insert(inp[i]);

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

	for(int i =0; i< count_del;i++)
	{
		bst.deletex(inp[count_add + count_search + i]);
	}

	cout << "Binary Search Tree done !\n";
}