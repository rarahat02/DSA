#include<iostream>
#include<queue>
#include<string>

using namespace std;

struct content
{
    string clr;
    int dis;
    char prev;
};

int main ()
{
    int numberOfStates;
    cin >> numberOfStates;
    
    int **matrix;
    
    matrix = new int *[numberOfStates];
    for(int i=0; i<numberOfStates; i++)
    {
        matrix[i] = new int[numberOfStates];
    }
    
    for(int i=0; i<numberOfStates; i++)
    {
        for(int j=0; j<numberOfStates; j++)
        {
            cin >> matrix[i][j];
        }
    }
    
    content *vertex;
    vertex = new content[numberOfStates];
    for(int i=0; i<numberOfStates; i++)
    {
        vertex[i].clr = "white";
        vertex[i].dis = 99999;
        vertex[i].prev = 'C';
    }
    
    int indexOfStartState;
    cin >> indexOfStartState;
    indexOfStartState--;
    
    vertex[indexOfStartState].clr = "grey";
    vertex[indexOfStartState].dis = 0;
    
    string states;
    cin >> states;
    int loop=0;
    
    queue <int> myQ;
    myQ.push(indexOfStartState);
    1
    while(!myQ.empty())
    {
        int queue = myQ.front();
        myQ.pop();
        
        for(int i=0; i<numberOfStates; i++)
        {
            if(matrix[queue][i] == 1 && vertex[i].clr == "white")
            {
                vertex[i].clr = "grey";
                vertex[i].dis = vertex[queue].dis + 1;
                vertex[i].prev = states[queue];
                myQ.push(i);
            }
            else if(matrix[queue][i] == 1 && vertex[i].clr == "grey") loop++;
            vertex[queue].clr = "black";
        }
    }
    
    for(int i=0; i<numberOfStates; i++)
    {
        delete []matrix[i];
    }
    delete []matrix;
   

   cout << "Vertex\tdistance previous" << endl;
   for(int i=0; i<numberOfStates; i++)
   {
        cout << states[i] << "\t" << vertex[i].dis << "\t" << vertex[i].prev << endl;
   }
   cout << "\nThere are " << loop << "  loop." << endl;
   
   delete []vertex;
}
