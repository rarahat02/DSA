#include<iostream>
#include<list>

using namespace std;

struct node 
{
	int roll;
	string name;
};

int main (void)
{
	
	list <node> jonabList;
	
	int initialSize;
	cin >> initialSize;
	
	for (int i=0; i<initialSize; i++)
	{
		node tempNode;
		cin >> tempNode.roll >> tempNode.name;
		jonabList.push_back(tempNode);
		jonabList.push_front(tempNode);
	}
	
	
	jonabList.pop_back();
	//for(list<node>:: iterator it = jonabList.end()-1; it != jonabList.begin(); it--)
	for(list<node>:: iterator it = jonabList.begin(); it != jonabList.end(); it++)
	{
		cout << it->roll << " " << it->name << endl;
	}
	

	return 0;
}
