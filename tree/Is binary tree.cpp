/*   Vivek Sangwan
	Poornima University */

#include<bits/stdc++.h>
using namespace std;

void sublime()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.TXT", "r", stdin);
	freopen("output.TXT", "w", stdout);
#endif
}

class node
{
public:
	int data;
	node* left;
	node* right;

	node(int data, node* leftN = NULL, node* rightN = NULL)
	{
		this->data = data;
		left = leftN;
		right = rightN;
	}
};


node* build_BST()
{
	int d;
	cin >> d;

	if (d == -1) return NULL;

	node *root = new node(d);
	root->left = build_BST();
	root->right = build_BST();

	return root;
};

void printBST(node* root)
{
	if (root == NULL) return;
	cout << root->data << " ";
	printBST(root->left);
	printBST(root->right);
}

class checkBT
{
public:
	bool bst;
	int min;
	int max;
};

checkBT* isBinaryTree(node* root)
{
	if (root == NULL)
	{
		checkBT* n = new checkBT();
		n->bst = true;
		n->max = INT_MIN;
		n->min = INT_MAX;
		return n;
	}

	checkBT* lbt = isBinaryTree(root->left);
	checkBT* rbt = isBinaryTree(root->right);

	checkBT* n = new checkBT();
	n->bst = lbt->bst && rbt->bst && (root->data <= rbt->min && root->data >= lbt->max);
	n->max = max(root->data, max(lbt->max, rbt->max));
	n->min = min(root->data, min(lbt->min, rbt->min));
	return n;
}


int main()
{

	sublime();
	int n, target, k;
	cin >> n;
	node* root = build_BST();
	checkBT* t = isBinaryTree(root);
	cout << t->bst;
	return 0;
}


