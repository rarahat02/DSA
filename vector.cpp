#include<iostream>
#include<vector>

using namespace std;

//size, push_back, max_size, capacity, empty, [], at, front, back, pop_back, 
// begin, end

int main (void)
{
	vector <int> jonabVector;
	cout << jonabVector.size()<< endl;
	
	for(int i=0; i<10; i++)
	{
		jonabVector.push_back(i);
	}
	
//	jonabVector.pop_back();
	
	vector<int> :: iterator it;
	it = jonabVector.begin();
	jonabVector.erase(it, it+4);
		
	cout << "My vector contains:" << endl;// << jonabVector.back() << endl;

	for(int i=0; i<jonabVector.size(); i++)
	{
		cout << jonabVector.at(i) << endl;
	}
	
	jonabVector.clear();
	
//	jonabVector.clear();	
	
	cout << "It now contains: "<< jonabVector.size() << endl;
	
	it = jonabVector.begin() ;
	jonabVector.insert(it, 100);
	
	cout << "My vector contains:" << endl;// << jonabVector.back() << endl;

	for(int i=0; i<jonabVector.size(); i++)
	{
		cout << jonabVector.at(i) << endl;
	}
	
	return 0;
}
