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

node* searchByName(string searchKeyName)
{
	node *current;
	current = head;
	bool flag = false;
	
	while(1)
	{
		if(current == NULL)
		{
			break;
		}
		if (!searchKeyName.compare(current->name))
		{
			//cout << current->roll << " " << current->name << endl;
			flag = true;
			break;
		}
		else current = current->next;
	}
	if(!flag) 
	{
		//cout << "item not found in the list (inside searchByName)" << endl;
		return NULL;
	}
	else return current;
}

void insertAfterAnItem(node *newNode, string searchKeyName)
{
	node *current = searchByName(searchKeyName);
	if(current == NULL) cout << "The item is not in the list how i should insert?" << endl;
	else
	{
		//cout << current->roll << " " << current->name << endl;
		if(current != tail) 
		{
			newNode->next = current->next;
			newNode->next->prev = newNode;
		}
		else 
		{
			newNode->next = NULL;
			tail=newNode;
		}
		newNode->prev = current;
		current->next = newNode;
		
	}
}

void deleteAnItem(string searchKeyName)
{
	node *current = searchByName(searchKeyName);
	if(current == NULL) cout << "The item is not in the list how i should delete?" << endl;
	else
	{
		//cout << current->roll << " " << current->name << endl;
		current->prev->next = current->next;
		current->next->prev = current->prev;
		delete [] current;
		
	}
}


void traverseListForward(void)
{
	cout << "in forward direction the list contains " << endl;
	
	node *current;
	current = head;
	
	while(1)
	{
		if(current == NULL)
		{
			break;
		}
		cout << current->roll << " " << current->name << endl;
		current = current->next;
	}
}

void traverseListBackword(void)
{
	cout << "in backword direction the list contains " << endl;
	
	node *current;
	current = tail;
	
	while(1)
	{
		if(current == NULL)
		{
			break;
		}
		cout << current->roll << " " << current->name << endl;
		current = current->prev;
	}
}

void insertAtEnd(node *newNode)
{
	if(head == NULL && tail == NULL)
	{
		head = newNode;
		tail = newNode;
		newNode->next=NULL;
		newNode->prev=NULL;
	}
	else
	{
		tail->next = newNode;
		newNode->prev = tail;
		newNode->next = NULL;
		tail = newNode;
	}
}

void insertAtBeginning(node *newNode)
{
	if(head == NULL && tail == NULL)
	{
		head = newNode;
		tail = newNode;
		newNode->next=NULL;
		newNode->prev=NULL;
	}
	else
	{
		newNode->next = head;
		head->prev = newNode;
		newNode->prev = NULL;		
		head = newNode;
	}
}


void createLinkedList()
{
	head = NULL;
	tail = NULL;
}

void searchAndPrintRecord(string searchKeyName)
{
	node *current = searchByName(searchKeyName);
	if(current == NULL) cout << "The item is not in the list, i cannot print" << endl;
	else
	{
		cout << "Found " << current->roll << " " << current->name << endl;
		
	}
}

int main (void)
{
	createLinkedList();

	int initialSize;
	cin >> initialSize;

	node *newNode;
	
	for (int i=0; i<initialSize; i++)
	{
		newNode = new node[1];
		cin >> newNode[0].roll;
		cin >> newNode[0].name;
		
		insertAtEnd(&newNode[0]);
		//insertAtBeginning(&newNode[0]);
	}
	
	traverseListForward();
	traverseListBackword();

	string searchKeyName;
	cin >> searchKeyName;
	
	searchAndPrintRecord(searchKeyName);
	
	newNode = new node[1];
	cin >> newNode[0].roll >> newNode[0].name;
	cin >> searchKeyName;
	insertAfterAnItem(&newNode[0], searchKeyName);
	
	traverseListForward();
	traverseListBackword();

	cin >> searchKeyName;
	deleteAnItem(searchKeyName);
	
	traverseListForward();
	traverseListBackword();
	
	return 0;
}
