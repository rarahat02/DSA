#include<iostream>
#include<string>

using namespace std;

struct node
{
	int integer;
	node *next;
};

node *a, *head, *current, *old, newNode;
bool flag, flag2;
int size, i, j, deleting, searching, temp, newInt;

void Listing()
{
    cout << "Enter the number of integer in sorting :" <<endl;
	cin >> size;
	a = new node [size];

	cout << "Enter the sorted integers in ascending oreder:" << endl;

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

	cin >> searching;

	current = head;

	flag =false;

	while(1)
	{
		if(head==NULL)
		{
			cout << "your list is empty, nothing to search here" << endl;
			break;
		}

		if(searching == current->integer)
		{
			cout << "Found " << current->integer << endl;
			flag = true;
			break;
		}

		if(current->next==NULL)	break;
		else current = current->next;
	}
	if(!flag) cout << searching << " was not found in the sorted list" << endl;

}

void Deletion ()
{
    cout << "Enter the integer to be deleted: " ;

	cin >> deleting;

	old = head;
    current = head;

	while(1)
	{
		if(head==NULL)
		{
			cout << "Your list is empty, nothing to delete here" << endl;
			break;
		}
		if(deleting==current->integer)
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
		if(current->next==NULL)	
		{
		    cout << "The integer you wanted to delete was not in the list." << endl;  
		    break;
		}
		else
		{
			old = current;
			current = current->next;
		}
	}
	
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
	newNode.integer= newInt;


	if(newInt < a[0].integer)
    {
        node *newHead = &newNode;
        newNode.next = head;
        head = newHead;
    }

    else {
        current = head;
        flag2 = false;


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
                newNode.next = current->next;
                current->next = &newNode;
                flag2 = true;
                break;
            }
            if(current->next==NULL)	break;
            else current = current->next;
        }

        if(!flag2)
        {
            a[size-1].next = &newNode;
            newNode.next = NULL;
        }
    }

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
{
	
	Listing ();
	Deletion ();
	Insertion ();
	Search ();
	

    return 0;
}
