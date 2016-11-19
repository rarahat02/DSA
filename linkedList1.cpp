#include<iostream>
#include<string>

using namespace std;

struct node 
{
	int roll;
	string name;
	node *next;
};

int main (void)
{
	//creating a list
	node a, b, c, d, e, f;
	node *head;
	
	a.roll=1;
	a.name="fabiha";
	b.roll=2;
	b.name="nazmul";
	c.roll=3;
	c.name="zulfi";
	d.roll=4;
	d.name="shuvo";
	e.roll=5;
	e.name="rubayet";
	f.roll=6;
	f.name="tanvir";
	
	head = &a;
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;
	f.next = NULL;
	//end creating

	node *current;
	
	node myNewNode;
	myNewNode.name = "habib";
	myNewNode.roll= 23;

	//insert at beginning
//	myNewNode.next = head;
//	head = &myNewNode;
	//end insert at beginning
	
	// insert at end
/*	current = head;
	while(1)
	{
		if(head==NULL) 
		{
			cout << "your list is empty" << endl;
			break;
		}
		//cout << current->roll << "\t" << current->name << endl;
		if(current->next==NULL) break;
		else current = current->next;
	}
	
	current->next = &myNewNode;
	myNewNode.next = NULL;
*/	
	// insert at end
	
	//insert after a node
/*	cout << "enter a name after which i shall insert: " << endl;
	string searchNameForInsertion;
	cin >> searchNameForInsertion;
	
	//node *current;
	current = head;
	
	while(1)
	{
		if(head==NULL) 
		{
			cout << "your list is empty, cannot insert here" << endl;
			break;
		}
		if(!searchNameForInsertion.compare(current->name))
		{ 
			myNewNode.next = current->next;
			current->next = &myNewNode;
			break;
		}
		if(current->next==NULL)	break;
		else current = current->next;
	}
*/	//end insert after a node
	
	//deleting a node
/*	cout << "enter a name which i shall delete: " << endl;
	string searchNameForDeletion;
	cin >> searchNameForDeletion;
	
	node *old = head;
	current = head;
	
	while(1)
	{
		if(head==NULL) 
		{
			cout << "your list is empty, nothing to delete here" << endl;
			break;
		}
		if(!searchNameForDeletion.compare(current->name))
		{ 
			if(current == head)
			{
				head= current->next;
				current = head;
			}
			else
			{
				old->next= current->next;
				current = old;
			}
			break;
		}
		if(current->next==NULL)	break;
		else
		{ 
			old = current;
			current = current->next;
		}
	}
	//end deleting a node
	
	//traversing a list
	current = head;
	
	while(1)
	{
		if(head==NULL) 
		{
			cout << "your list is empty" << endl;
			break;
		}
		cout << current->roll << "\t" << current->name << endl;
		if(current->next==NULL) break;
		else current = current->next;	
	}
	//end traversing
	
	//searching a list
	
	cout << "enter a name to search: " << endl;
	string searchName;
	cin >> searchName;
	
	//node *current;
	current = head;
	
	bool flag =false;
	
	while(1)
	{
		if(head==NULL) 
		{
			cout << "your list is empty, nothing to search here" << endl;
			break;
		}
		
		if(!searchName.compare(current->name))
		{ 
			cout << "Found " << current->roll << "\t" << current->name << endl;
			flag = true;
			break;
		}
		
		if(current->next==NULL)	break;
		else current = current->next;
	}
	if(!flag) cout << searchName << " was not found in the list" << endl;
	//end searching
	
	*/
	
	
	
	
	
	
	
	
	
	return 0;
}
