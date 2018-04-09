// This file tests the generated input by implementing it in a self-defined Stack.

#include <iostream>
using namespace std;

#include "myStack.h"

void myStackTest(int inp[], int count_add, int count_search, int count_del)
{
	myStack st, temp;

	for(int i=0; i<count_add; i++)
		st.push(inp[i]);

	for(int i=0; i<count_search; i++)
	{
		while(!st.empty())
		{
			if(st.top() == inp[i+count_add])
			{
				//cout << "YES\n";
				break;
			}
			temp.push(st.top());
			st.pop();
		}

		if(st.size()==0)
		{
			//cout << "NO\n";
		}

		while(!temp.empty())
		{
			st.push(temp.top());
			temp.pop();
		}
	}

	for(int i=0; i<count_del; i++)
	{
		while(!st.empty())
		{
			if(st.top() == inp[i + count_add + count_search])
			{
				st.pop();
				break;
			}
			temp.push(st.top());
			st.pop();
		}

		while(!temp.empty())
		{
			st.push(temp.top());
			temp.pop();
		}
	}


	cout << "Self-defined Stack done !\n";
}