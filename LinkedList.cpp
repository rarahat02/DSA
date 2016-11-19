#include<iostream>
#include<string>

using namespace std;

struct node
{
	int integer;
	node *next;
};

node *a, *head, *current, *old, myNewNode;
bool flag, token;
int size, i, j, deletionInt, searchInt, temp, newInt;

void Listing()
{
    cout << "Enter the number of nodes:" <<endl;
	cin >> size;
	a = new node [size];

	cout << "Enter the sorted integers:" << endl;

	for(i = 0; i<size; i++){
        cin >> a[i].integer;
	}

    head = &a[0];
	for(i = 0, j=1; i<size-1; i++, j++){
        a[i].next = &a[j];
	}
	a[size-1].next = NULL;

}

void Search ()
{
    cout << "Enter an integer to search: ";

	cin >> searchInt;

	current = head;

	flag =false;

	while(1)
	{
		if(head==NULL)
		{
			cout << "your list is empty, nothing to search here" << endl;
			break;
		}

		if(searchInt == current->integer)
		{
			cout << "Found " << current->integer << endl;
			flag = true;
			break;
		}

		if(current->next==NULL)	break;
		else current = current->next;
	}
	if(!flag) cout << searchInt << " was not found in the list" << endl;

}

void Deletion ()
{
    cout << "Enter the integer to be deleted: " ;

	cin >> deletionInt;

	old = head;
    current = head;

	while(1)
	{
		if(head==NULL)
		{
			cout << "Your list is empty, nothing to delete here" << endl;
			break;
		}
		if(deletionInt==current->integer)
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
			cout << "Your list is empty" << endl;
			break;
		}
		cout << current->integer << endl;
		if(current->next==NULL) break;
		else current = current->next;
	}

}

void Insertion ()
{
    cout << "Insert an integer: ";
	cin >> newInt;
	myNewNode.integer= newInt;


	if(newInt < a[0].integer)
    {
        node *newHead = &myNewNode;
        myNewNode.next = head;
        head = newHead;
    }

    else {
        current = head;
        token = false;


        for(i = 0; i< size; i++){
            if(a[i].integer<newInt){
                temp = a[i].integer;
            }
        }

        while(1)
        {
            if(head==NULL)
            {
                cout << "Your list is empty, cannot insert here" << endl;
			break;
            }
            if(temp==current->integer)
            {
                myNewNode.next = current->next;
                current->next = &myNewNode;
                token = true;
                break;
            }
            if(current->next==NULL)	break;
            else current = current->next;
        }

        if(!token)
        {
            a[size-1].next = &myNewNode;
            myNewNode.next = NULL;
        }
    }
    //end insert after a node

	//traversing a list
	current = head;

	while(1)
	{
		if(head==NULL)
		{
			cout << "your list is empty" << endl;
			break;
		}
		cout << current->integer << endl;
		if(current->next==NULL) break;
		else current = current->next;
	}
}

int main (void)
{//end creating
	//insert after a node
	Listing ();
	Deletion ();
	Insertion ();
	Search ();
	//end traversing

    return 0;
}
