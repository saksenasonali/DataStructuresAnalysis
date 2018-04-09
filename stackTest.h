// This file tests the generated input by implementing it in the Stack defined in the Standard Template Library.

#include <iostream>
#include <ctime>
using namespace std;

#include <stack>

void stackTest(int inp[], int count_add, int count_search, int count_del)
{
	stack<int> st, temp;

	clock_t t1 = clock();

	for(int i=0; i<count_add; i++)
		st.push(inp[i]);

	clock_t t2 = clock();

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

	clock_t t3 = clock();

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

	clock_t t4 = clock();

	cout << "\nStack STL done! The result times(in microseconds are) : \n";
	cout << "Inserting " << count_add << " values : " << float(t2-t1)  << "\n";
	cout << "Searching " << count_search << " values : " << float(t3-t2)  << "\n";
	cout << "Deleting " << count_del << " values : " << float(t4-t3)  << "\n";
;
}