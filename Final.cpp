#include<iostream>
#include<queue>
#include<string>

using namespace std;

struct node
{
	int d;
	string clr;
	char prev;
};

int main()
{
	int nOv;
	cin >> nOv;
	char *s;
	
	
	
	s = new char[nOv];
	for(int i=0;i<nOv;i++)
	{
		cin >> s[i];
	}
	
	
	
	int **m;

	m = new int *[nOv];
	for(int i=0;i<nOv;i++)
	{
		m[i] = new int[nOv];
	}	
	
	
	

	for(int i=0;i<nOv;i++)
	{
		for(int j=0;j<nOv;j++)
		{
			cin >> m[i][j];
		}
	}
	
	
	
	
	char startVertexName;
	int start;
	cin >> startVertexName;
	for(int i=0;i<nOv;i++)
	{
		if(startVertex==s[i])
		{
			start = i;
			break;
		}
	}
	
	cout << "\n\nThe start vertex is : " << s[start] << endl;
	


	node *vertex;
	vertex = new node [nOv];
	

	for(int i=0;i<nOv;i++)
	{
		vertex[i].clr ="White";
		vertex[i].d = 9999999;
		vertex[i].prev = '0';
	}
	

	vertex[start].d=0;
	vertex[start].clr="Gray";
	vertex[start].prev='0';
	


	queue <int> myQueue;
	myQueue.push(start);
	


	int loop=0;
	while(!myQueue.empty())
	{
		int top = myQueue.front();
		myQueue.pop();
		
		for(int i=0;i<nOv;i++)
		{
			if( m[top][i]==1 && vertex[i].clr=="White" )
			{
				vertex[i].clr = "Gray";
				vertex[i].d = vertex[top].d + 1;
				vertex[i].prev = s[top];
				myQueue.push(i);
			}
			else if( m[top][i]==1 && vertex[i].clr=="Gray")
			{
				loop++;
			} 
		}
		vertex[top].clr = "Black";	
	}
	


	for(int i=0;i<nOv;i++)
	{
		delete []m[i];
	}
	delete []m;
	


	cout <<"\nVertex\tdistance\tprev\tclr\n" << endl;
	
	for(int i=0;i<nOv;i++)
	{
		cout << s[i] << "\t" << vertex[i].d << "\t\t" << vertex[i].prev << "\t" << vertex[i].clr << endl;
	}
	
	cout << "\nThere exist " << loop << " loop in the graph\n" << endl;
	
	
	delete []vertex;
	
	return 0;
}
