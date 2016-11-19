#include <iostream>
#include <queue>

using namespace std;

int main (void)
{
	queue <int> q;
	
	for(int i=0; i<10; i++)
	{
		q.push(i);
	}
	
	cout << "last element inserted is " << q.back();
	
	cout << "size is "<< q.size() << endl;
	
	while(!q.empty())
	{
		cout << q.front() << endl;
		q.pop();
	}
	
	
	return 0;
}
