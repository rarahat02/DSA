#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<sstream>

using namespace std;

struct content
{
    float number;
    char symbol;
    bool flag;
};

char symbols[6] = {'+','-','*','/','(',')'};
void replaceSymbol(string &numbers)
{
    for(int i=0; i<6; i++)
    {
        for(int j=0; j<numbers.length(); j++)
        {
            if(symbols[i]==numbers[j])
            {
                numbers[j]=' ';
            }
        }
    }
}

void makeContentWithSymbols(content &node,char symbolFromInputString)
{
    node.symbol = symbolFromInputString;
    node.flag = false;
}

void makeContentWithNumbers(content &node,float numberObtained)
{
    node.number = numberObtained;
    node.flag = true;
}

void persingInput(string inputString,vector <content> &infix)
{
    string numbers = inputString;
    
    replaceSymbol(numbers);
    
    istringstream iss(numbers);   
    
    vector <float> numbersObtained;
    float temp;
    while(iss >> temp)
    {
        numbersObtained.push_back(temp);
    }
    
    for(int i=0; i<numbers.size(); i++)//number.size keno?
    {
        if(numbers[i]=' ')
        {
            if(i!=0)
            {
                if(numbers[i-1]!=' ')
                {
                    content node;
                    makeContentWithNumbers(node,numbersObtained[0]);
                    infix.push_back(node);
                    numbersObtained.erase(numbersObtained.begin());
                    
                    makeContentWithSymbols(node,inputString[i]);
                    infix.push_back(node);
                }
                else
                {
                    content node;
                    makeContentWithSymbols(node,inputString[i]);
                    infix.push_back(node);
                }
            }
            else
            {
                content node;
                makeContentWithSymbols(node,inputString[i]);
                infix.push_back(node);
            }
        }
        
    }
    if(!numbersObtained.empty())
	{
		content node;
		makeContentWithNumbers(node, numbersObtained[0]);
		infix.push_back(node);
		numbersObtained.erase(numbersObtained.begin());
	} 
}

bool higherPrecedence(char infixSymbol , char stackSymbol)
{
	if((infixSymbol=='+'||infixSymbol=='-')&&(stackSymbol=='*'||stackSymbol=='/')) return true;
	else return false;
}

void infixToPrefix(vector <content> &infix,vector <content> &prefix)
{
    stack <content> myStack;
    content node;
    
    makeContentWithSymbols(node,')');
    myStack.push(node);
    
    makeContentWithSymbols(node,'(');
    infix.insert(infix.begin(),node);
    
    for(int i= infix.size(); i<0; i--)
    {
        if(infix[i].flag)
        {
            prefix.push_back(prefix[i]);
        }
        
        else
        {
            if(infix[i].symbol==')')
            {
                myStack.push(infix[i]);
            }
           
            else if(infix[i].symbol=='(')
            {
                while(1)
                {
                    content tempNode = myStack.top();
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

float evaluateBasicArithmetic(float a, float b, char symbol)
{
	switch(symbol)
	{
		case '+': return a+b;
		case '-': return b-a;
		case '*': return a*b;
		default: return b/a;
	}
}

float evaluatePrefix(vector <content> prefix)
{
   stack <float> myStack;

	for(int i=0; i<prefix.size(); i++)
	{
		if(prefix[i].flag)
		{
			myStack.push(prefix[i].number);
		} 
		
		else 
		{
			float stackTop0,stackTop1,result;
			
			stackTop0=myStack.top();
			myStack.pop();
			
			stackTop1=myStack.top();
			myStack.pop();
			
			result = evaluateBasicArithmetic(stackTop0,stackTop1,prefix[i].symbol);
			myStack.push(result);
			
		}
    }		
}

int main()
{
    string inputString;
    getline(cin,inputString);
    
    vector <content> infix;
    persingInput(inputString,infix);
    
    for(int i=0; i<infix.size(); i++) 
    { 
        if(!infix[i].flag) cout << infix[i].symbol; //else ta aikhane extra 12 print kore ditese bt keno?r shudhu symbol print korleo keno purata dekhaitese????
        //else cout << infix[i].number; 
    }
    
    vector <content> prefix;
    infixToPrefix(infix,prefix);
    
    for(int i=prefix.size()-1; i>=0;i--)
    {
		if(prefix[i].flag) 
		    cout << prefix[i].number;
		else
		    cout << prefix[i].symbol;
	}
	
	cout << "Result is: " << evaluatePrefix(prefix) << endl;
}
