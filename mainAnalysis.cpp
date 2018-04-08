// This file is the main() function of our Analysis and runs the tests based on the generated inputs.

#include <iostream>
#include <stdio.h>
#include "arraySortedTest.h"
#include "arrayUnsortedTest.h"
#include "heapTest.h"
#include "myAvlTest.h"
#include "myBstTest.h"
#include "myHeapTest.h"
#include "myQueueTest.h"
#include "myStackTest.h"
#include "queueTest.h"
#include "setTest.h"
#include "stackTest.h"

using namespace std;

int main()
{
	int choice;
	cout<<"Enter the size of your data set to run the analysis :- \n";
	cout << "1. Very small data set (10 inputs). \n";
	cout << "2. Small data set (100 inputs). \n";
	cout << "3. Medium set (1000 inputs). \n";
	cout << "4. Large data set (10,000 inputs). \n";
	cout << "Please enter your choice : ";
	cin >> choice;

	int count_add, count_search, count_del;

	switch(choice)
	{
		case 1:	freopen("vsmallIn.txt", "r", stdin);
				break;
		case 2:	freopen("smallIn.txt", "r", stdin);
				break;
		case 3:	freopen("mediumIn.txt", "r", stdin);
				break;
		case 4:	freopen("largeIn.txt", "r", stdin);
				break;
	}

	cin >> count_add >> count_search >> count_del;

	int inp[count_add + count_search + count_del];

	for(int i=0; i<count_add + count_search + count_del; i++)
		cin >> inp[i];

	unsortedArrayTest(inp, count_add, count_search, count_del);
	sortedArrayTest(inp, count_add, count_search, count_del);
	myStackTest(inp, count_add, count_search, count_del);
	stackTest(inp, count_add, count_search, count_del);
	myQueueTest(inp, count_add, count_search, count_del);
	queueTest(inp, count_add, count_search, count_del);
	bstTest(inp, count_add, count_search, count_del);
	avlTest(inp, count_add, count_search, count_del);
	heapTest(inp, count_add, count_search, count_del);
	myHeapTest(inp, count_add, count_search, count_del);
	setTest(inp, count_add, count_search, count_del);
	
	return 0;
}