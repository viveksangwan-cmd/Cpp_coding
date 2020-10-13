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

class Dia
{
public:
	int hi;
	int dia;
	Dia(int hi = -1, int dia = 0)
	{
		this->hi = hi;
		this->dia = dia;
	}
};

Dia* diameter(node* root)
{
	if (root == NULL)
	{
		Dia* n = new Dia(-1, 0);
		return n;
	}
	Dia* ln = diameter(root->left);
	Dia* rn = diameter(root->right);

	Dia* n = new Dia();
	n->hi = max(ln->hi, rn->hi) + 1;

	int fes = ln->hi + rn->hi + 2;
	n->dia = max(fes, max(ln->dia, rn->dia));

	return n;
}

int main()
{

	sublime();
	int n, target, k;
	cin >> n;
	node* root = build_BST();
	Dia* d = diameter(root);
	cout << d->dia;
	return 0;
}


