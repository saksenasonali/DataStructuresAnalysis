// This file tests the generated input by implementing it as an Unsorted Array.

#include <iostream>
#include <ctime>
using namespace std;

void unsortedArrayTest( int inp[], int count_add, int count_search, int count_del )
{
	int arr[count_add];

	clock_t t1 = clock();

	for(int i=0; i<count_add; i++)
		arr[i] = inp[i];

	clock_t t2 = clock();

	for(int i=0; i<count_search; i++)
	{
		int j;
		for(j=0; j<count_add; j++)
		{
			if(arr[j]==inp[i+count_add])
			{
				//cout << "YES\n";
				break;
			}
		}
		if(j==count_add)
		{
			//cout << "NO\n";
		}
	}

	clock_t t3 = clock();

	int curr = count_add;

	for(int i=0; i<count_del; i++)
	{
		for(int j=0; j<count_add; j++)
		{
			if(arr[j]==inp[i+count_add+count_search])
			{
				for(int k=j; k<curr-1; k++)
					arr[k] = arr[k+1];
				curr--;
				break;
			}
		}
	}

	clock_t t4 = clock();

	cout << "\nUnsorted Array done! The result times(in microseconds are) : \n";
	cout << "Inserting " << count_add << " values : " << float(t2-t1)  << "\n";
	cout << "Searching " << count_search << " values : " << float(t3-t2)  << "\n";
	cout << "Deleting " << count_del << " values : " << float(t4-t3)  << "\n";

}