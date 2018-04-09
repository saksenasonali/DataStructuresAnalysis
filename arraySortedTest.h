// This file tests the generated input by implementing it in a Sorted Array.

#include <iostream>
#include <ctime>
using namespace std;

int binarySearchIns(int arr[],int size,int val)
{
	int l=0;
	int u=size-1;
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
	int u=size-1;
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

	clock_t t1 = clock();

	for(int i=0; i<count_add; i++)
	{
		int j=binarySearchIns(arr,i,inp[i]);
		for(int k=j; k< i;k++)
		{
			arr[k+1]=arr[k];
		}
		arr[j]=inp[i];
	}

	clock_t t2 = clock();

	for(int i=0; i<count_search; i++)
	{
		int flag=binarySearch(arr,count_add,inp[count_add+i]);
		if(flag!=-1)
		{
			//cout << "YES\n";
		}
		else
		{
			//cout << "NO\n";
		}
	}

	clock_t t3 = clock();

	int curr = count_add;

	for(int i=0; i<count_del; i++)
	{
		int j=binarySearch(arr,count_add,inp[count_add+count_search+i]);

		for(int k=j; k<curr-1; k++)
			arr[k] = arr[k+1];
		curr--;
	}

	clock_t t4 = clock();

	cout << "\nSorted Array done! The result times(in microseconds are) : \n";
	cout << "Inserting " << count_add << " values : " << float(t2-t1)  << "\n";
	cout << "Searching " << count_search << " values : " << float(t3-t2)  << "\n";
	cout << "Deleting " << count_del << " values : " << float(t4-t3)  << "\n";
}