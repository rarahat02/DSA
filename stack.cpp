#include<iostream>
#include <stack>

using namespace std;

int main (void)
{
	stack <int> jonabStack;
	
	for(int i=0;i<10;i++)
	{
		jonabStack.push(i*10);
	}
	
	cout << "size: " << jonabStack.size() << endl;
	
	while(!jonabStack.empty())
	{
		cout << jonabStack.top() << endl;
		jonabStack.pop();
	}
	
	return 0;
}
