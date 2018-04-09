// This file tests the generated input by implementing it in the Set defined in the Standard Template Library.

#include <set>

void setTest(int inp[], int count_add, int count_search, int count_del)
{
	set <int> mySet;
	for(int i=0; i< count_add ;i++)
		mySet.insert(inp[i]);

	for(int i=0; i< count_search; i++)
	{
		int ans = mySet.count(inp[count_add + i]);
		if( ans==0)
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
		mySet.erase(inp[count_add + count_search + i]);
	}


	cout << "Set STL done !\n";

}