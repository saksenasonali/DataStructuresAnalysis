// This file tests the generated input by implementing it in the Stack defined in the Standard Template Library.

#include <iostream>
using namespace std;

#include <stack>

void stackTest(int inp[], int count_add, int count_search, int count_del)
{
	stack<int> st, temp;

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


	cout << "Stack STL done !\n";
}