#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<stack>

using namespace std;


struct content
{
	float number;
	char symbol;
	bool flag;
};

char operators[6] = {'+','-','*','/','(',')'};

void replaceSymbols(string &numbers)
{
	for(int i=0;i<6;i++)
	{
		for(int j=0; j<numbers.length(); j++)
		{
			if(operators[i]==numbers[j]) numbers[j] = ' ';
		}
	}
}

void makeContentWithNumber(content &node, float numberObtained)
{
	node.number = numberObtained;
	node.flag = true;
}

void makeContentWithSymbol(content &node, char symbolFromInputStringArray)
{
	node.symbol = symbolFromInputStringArray;
	node.flag = false;
}

void parsingInput(string inputString, vector <content> &infix)
{
	string numbers = inputString;
	replaceSymbols(numbers);
	
	istringstream iss(numbers);
	
	vector <float> numbersObtained;
	float temp;
	while (iss >> temp)
	{
		numbersObtained.push_back(temp);
	}
	
	for(int i=0; i<numbers.size(); i++)
	{
		if(numbers[i]== ' ')
		{
			if(i != 0)
			{
				if(numbers[i-1] != ' ')
				{
					content node;
					makeContentWithNumber(node, numbersObtained[0]);
					infix.push_back(node);
					numbersObtained.erase(numbersObtained.begin());
					
					makeContentWithSymbol(node, inputString[i]);
					infix.push_back(node);
				}
				else
				{
					content node;
					makeContentWithSymbol(node, inputString[i]);
					infix.push_back(node);
				}
			}
			else
			{
				//jodi amra 0 tomo jaigate space pai
				content node;
				makeContentWithSymbol(node, inputString[i]);
				infix.push_back(node);
			}
		}
	}
	
	if(!numbersObtained.empty())
	{
		content node;
		makeContentWithNumber(node, numbersObtained[0]);
		infix.push_back(node);
		numbersObtained.erase(numbersObtained.begin());
	}
}

bool higherPrecedence(char infixSymbol , char stackSymbol)
{
	if((infixSymbol=='+'||infixSymbol=='-')&&(stackSymbol=='*'||stackSymbol=='/')) return true;
	else return false;
}

void infixToPrefix(vector <content> &infix, vector <content> &prefix){
	stack <content> myStack;
	content node;
	makeContentWithSymbol(node, ')');
	myStack.push(node);
	makeContentWithSymbol(node, '(');
	infix.insert(infix.begin(),node);
	
	for(int i=infix.size()-1;i>=0;i--){
		
		if(infix[i].flag)	{
			prefix.push_back(infix[i]);
		}
			
		else
		{
			if (infix[i].symbol==')')
			{
				myStack.push(infix[i]);
			}
			else if(infix[i].symbol=='('){
				
				while(1){
					content tempNode=myStack.top();
					if(tempNode.symbol==')') break;
					prefix.push_back(tempNode);
					myStack.pop();
				}
				myStack.pop();
				}
			else
			{
				while(1)
				{
					content tempNode1= myStack.top();
					if((higherPrecedence(infix[i].symbol,tempNode1.symbol))==true)
					{	
						prefix.push_back(tempNode1);
						myStack.pop();
					}
					else break;
				}
				myStack.push(infix[i]);
			}
		}
						
	}	
}


float prefixArithmetic(float a, float b, char symbol){
	switch(symbol)
	{
	case '+':
	return a+b;
	case '-':
	return a-b;
	case '*':
	return b*a;
	case '/':
	return a/b;	
	} 
}

float evaluatePrefixArithmetic(vector <content> prefix){

	stack <float> myStack;
	for(int i=0;i<prefix.size();i++){
		if(prefix[i].flag){
			
			myStack.push(prefix[i].number);
		}
		else {
			float stackTop1,stackTop2,result;
			stackTop1=myStack.top();
			myStack.pop();
			stackTop2=myStack.top();
			myStack.pop();
			result=prefixArithmetic(stackTop1,stackTop2,prefix[i].symbol);
			myStack.push(result);
			
		}
	}
	return myStack.top();
}

int main (void)
{
	string inputString;
	
	getline(cin, inputString);
	cout <<inputString << endl;
	vector <content> infix;
	parsingInput(inputString, infix);
	vector <content> prefix;
	infixToPrefix(infix, prefix);
	int prefixSize=prefix.size();
	for(int i=prefixSize-1; i>=0;i--){
		if(prefix[i].flag) cout << prefix[i].number << endl;
		else cout << prefix[i].symbol << endl;
	}

	cout << " Result is: " << evaluatePrefixArithmetic(prefix) << endl;

	return 0;
}









