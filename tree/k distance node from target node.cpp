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

void printBST(node* root)
{
	if (root == NULL) return;
	cout << root->data << " ";
	printBST(root->left);
	printBST(root->right);
}

vector<node*> v;
bool path(node* node, int data)
{
	if (node == NULL) return false;
	if (node->data == data)
	{
		v.push_back(node);
		return true;
	}
	bool leftN = path(node->left, data);
	if (leftN) {
		v.push_back(node);
		return true;
	}
	bool rightN = path(node->right, data);
	if (rightN) {
		v.push_back(node);
		return true;
	}
	return false;
}

void printkLevel(node* root, int level , node* blocker)
{
	if (root == NULL || root == blocker) return;
	if (level == 0)
	{
		cout << root->data << endl;
		return;
	}
	printkLevel(root->left, level - 1 , blocker);
	printkLevel(root->right, level - 1 , blocker);
}

int main()
{
	sublime();
	int n, target, k;
	cin >> n;
	node* root = build_BST();
	cin >> target >> k;
	bool t = path(root, target);
	if (t)
	{
		for (int i = 0; i < v.size(); i++) {
			printkLevel(v[i], k - i, i == 0 ? NULL : v[i - 1]);
		}
	}

	return 0;
}


