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

	node(int data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
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

void print_BST(node* root)
{
	if (root == NULL) return;

	cout << root->data << " ";
	print_BST(root->left);
	print_BST(root->right);
}


int main()
{
	sublime();
//	vector<int> v{50, 25, 12, NULL, NULL, 37, 30, NULL, NULL, NULL, 75, 62, NULL, 70, , NULL, NULL, 80, NULL, NULL};

	node* root = build_BST();
	print_BST(root);

	return 0;
}


