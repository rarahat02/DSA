#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct person
{
	string name;
	int age;
};

class comparePerson {
public:
    bool operator()(person& p1, person& p2)
    {
       if (p1.age < p2.age) return true;
       else return false;
    }
};

int main (void)
{
  priority_queue<person, vector<person>, comparePerson> mypq;
  int noOfPersons;
  cin >> noOfPersons;
  string s;
  getline(cin, s);

  for(int i=0; i<noOfPersons;i++)
  {
  	person node;
  	getline(cin, node.name);
  	cin >> node.age;
  	getline(cin, s);
  	
  	mypq.push(node);
  }
  
  
  cout << "Popping out elements..." << endl;
  
  while (!mypq.empty())
  {
     person nodeTemp = mypq.top();
     cout << nodeTemp.name << "\t" << nodeTemp.age << endl;
     mypq.pop();
  }
  
  cout << endl;

  return 0;
}
