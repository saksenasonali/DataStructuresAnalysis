// This file tests the generated input by implementing it as an Unsorted Array.

#include <iostream>
using namespace std;

void unsortedArrayTest( int inp[], int count_add, int count_search, int count_del )
{
	int arr[count_add];

	for(int i=0; i<count_add; i++)
		arr[i] = inp[i];

	for(int i=0; i<count_search; i++)
	{
		int j;
		for(j=0; j<count_add; j++)
		{
			if(arr[j]==inp[i+count_add])
			{
				cout << "YES\n";
				break;
			}
		}
		if(j==count_add)
			cout << "NO\n";
	}

	for(int i=0; i<count_del; i++)
	{
		for(int j=0; j<count_add; j++)
		{
			if(arr[j]==inp[i+count_add+count_search])
			{
				for(int k=j; k<count_add-1; k++)
					arr[k] = arr[k+1];
				count_add--;
				break;
			}
		}
	}
}