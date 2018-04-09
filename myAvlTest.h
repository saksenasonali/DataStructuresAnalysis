// This file tests the generated input by implementing it in a self-defined AVL Tree.

#include "myAvl.h"

void avlTest(int inp[], int count_add, int count_search, int count_del)
{
	myAvl avl;
	for(int i=0; i< count_add ;i++)
		avl.insert(inp[i]);

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

	for(int i =0; i< count_del;i++)
	{
		avl.deletex(inp[count_add + count_search + i]);
	}


	cout << "AVL Tree done !\n";
}