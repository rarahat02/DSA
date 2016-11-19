#include<iostream>
#include<queue>

using namespace std;


struct content
{
	int flag;
	int distance;
};



int main(void)
{
	int n;
	cin >> n;
	int **matrix;
	
	matrix = new int *[n];
	for(int i=0; i<n; i++)
	{
		matrix[i] = new int [n]; 
	}



	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin >> matrix[i][j];
		}
	}
	
	
	int s;
	cin >> s;
	s--;
	
	
	content *vertex;
	vertex = new content [n];
	
	
	for(int i=0; i<n; i++)
	{
		vertex[i].flag = 0;
		vertex[i].distance = 2147483647;
	}
	
	
	vertex[s].flag = 1;
	vertex[s].distance = 0;
	
	
	queue <int> myQueue;
	myQueue.push(s);
	
	
	while(!myQueue.empty())
	{
		int u = myQueue.front();
		myQueue.pop();
		
		for(int i=0; i<n; i++)
		{
			if(matrix[u][i] == 1 && vertex[i].flag == 0)
			{
				vertex[i].flag = 1;
				vertex[i].distance = vertex[u].distance + 1;
				myQueue.push(i);
			}
		}
		
		vertex[u].flag = 2;
	}
	
	
	for(int i=0; i<n; i++)
	{
		delete []matrix[i];
	}
	
	delete []matrix;
	
	
	cout << endl << "Assuming states are" ;
	char a = 'A';
	for(int i=0; i<n; i++)
	{
		cout << " " << a << ",";
		a = a+1;
	}
	
	cout << endl << endl;
	
	
	a = 'A';
	for(int i=0; i<n; i++)
	{
		cout << a << "\t" <<  vertex[i].distance << endl;
		a = a+1;
	}
	
	
	delete []vertex;
	
	cout << endl;
	
	return 0;
}
