// This file tests the generated input by implementing it in a Sorted Array.

#include <iostream>
using namespace std;

int binarySearchIns(int arr[],int size,int val)
{
	int l=0;
	int u=arr[size-1];
	while(l < u)
	{
		int mid=(l+u)/2;
		if(val < arr[mid])
			u=mid-1;
		else if(val > arr[mid])
			l=mid+1;
		else
		{
			return mid;
		}
	}
	return l;
}
int binarySearch(int arr[],int size,int val)
{
	int l=0;
	int u=arr[size-1];
	while(l < u)
	{
		int mid=(l+u)/2;
		if(val < arr[mid])
			u=mid-1;
		else if(val > arr[mid])
			l=mid+1;
		else
		{
			return mid;
		}
	}
	return -1;
}

void sortedArrayTest( int inp[], int count_add, int count_search, int count_del )
{
	int arr[count_add];


	for(int i=0; i<count_add; i++)
	{
		int j=binarySearchIns(arr,i,inp[i]);
		for(int k=j; k< i;k++)
		{
			arr[k+1]=arr[k];
		}
		arr[j]=inp[i];
	}

	for(int i=0; i<count_search; i++)
	{
		int flag=binarySearch(arr,count_add,inp[count_add+i]);
		if(flag!=-1)
		{
			cout << "YES\n";
		}
		else
			cout << "NO\n";
	}

	for(int i=0; i<count_del; i++)
	{
		int j=binarySearch(arr,count_add,inp[count_add+count_search+i]);

		for(int k=j; k<count_add-1; k++)
			arr[k] = arr[k+1];
		count_add--;
	}
}