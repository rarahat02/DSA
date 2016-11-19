#include<iostream>

using namespace std;

struct node
{
	int nodeID;
	//node *left, *right; 
	node *child;
	node *sibling;
	node *parent;
	//int level;
};

int main (void)
{
	
	node *root;
	node *node1;
	node1 = new node[1];
	root = &node1[0];
	root->child= NULL;
	root->sibling= NULL;
	root->parent= NULL;
	
	node2 = new node[1];
	root->child= node2[0];
	node2[0].child= NULL;
	node2[0].sibling= NULL;
	node2[0].parent= root;
	
	node3 = new node[1];
	node2[0].sibling = &node3[0];
	node3[0].child= NULL;
	node3[0].sibling= &node2[0];
	node3[0].parent= root;000000000000000000000000000000000000000000000000000000000000000000000000=
	
	return 0;
}
