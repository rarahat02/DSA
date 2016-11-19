#include<iostream>
#include<string>

using namespace std;

struct node
{
	int roll;
	string name;
	node *next, *prev;
};

node *head, *tail;

//cration
void listCreation(node *head, node *tail)
{
	head = NULL;
	tail = NULL;
}

//traverse
void traverseBeginningToENd(void)
{
	node *current;
	current = head;
	while(1)
	{
		if(current == NULL) break;
		else
		{
			cout << current->roll << "\t" << current->name << endl;
			current = current->next;
		}
	}
}
//searching
//insertion
void insertAtTheEnd(node &newNode)
{
	
	
	
	if(head ==NULL && tail ==NULL)
	{
		cout << "XXX" << endl;
		head = &newNode;
		tail = &newNode;
	}
	else
	{
		cout << "YYY" << endl;
		tail->next = &newNode;
		newNode.next = NULL;
		newNode.prev = tail;
		tail = &newNode;
	}
	
	//cout << head << " " << tail << " " << newNode.roll << " " << newNode.name << endl;
}
//deletion



int main (void)
{
	
	listCreation(head, tail);
	//head = tail = NULL;
	cout << head << " " << tail << endl;
	
	int noOfInitialEntries;
	cin >> noOfInitialEntries;
	
	for(int i= 0; i <noOfInitialEntries; i++)
	{
		node newNode;
		cin >> newNode.roll;
		cin >> newNode.name;
		
		insertAtTheEnd(newNode);
	}
	
	 traverseBeginningToENd();
	
	return 0;
}
