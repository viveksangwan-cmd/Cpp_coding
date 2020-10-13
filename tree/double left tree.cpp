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


node* newDobleLeftBST(node* root)
{
	if (root == NULL) return NULL;
	node* nln = newDobleLeftBST(root->left);
	node* nrn = newDobleLeftBST(root->right);

	node* Newnode = new node(root->data, nln, NULL);
	root->left = Newnode;
	root->right = nrn;
	return root;
}

int main()
{
	sublime();
	int n, target, k;
	cin >> n;
	node* root = build_BST();
	root = newDobleLeftBST(root);
	printBST(root);
	return 0;
}


