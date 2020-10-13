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

class ansNode
{
public:
	bool f;
	int h;
	node* n = NULL;
	int min_no = INT_MAX;
	int max_no = INT_MIN;
};


ansNode* isBalBT(node* root)
{
	if (root == NULL)
	{
		ansNode* n = new ansNode();
		n->f = true;
		n->h = 0;
		return n;
	}

	ansNode* ln = isBalBT(root->left);
	ansNode* rn = isBalBT(root->right);

	ansNode* nn = new ansNode();
	if ((root->data >= ln->max_no && root->data <= rn->min_no) && (rn->f == true) && (ln->f == true))
	{
		nn->f = true;
	} else nn->f = false;

	nn->min_no = min(root->data, min(ln->min_no, rn->min_no));
	nn->max_no = min(root->data, min(ln->max_no, rn->max_no));

	if (nn->f == true)
	{
		nn->n = root;
		nn->h = rn->h + ln->h + 1;
	} else if (rn->h > ln -> h)
	{
		nn->n = rn->n;
		nn->h = rn->h;
	}
	else
	{
		nn->n = ln->n;
		nn->h = ln->h;
	}
	return nn;

}

int main()
{

	sublime();
	int n, target, k;
	cin >> n;
	node* root = build_BST();
	ansNode* ans = isBalBT(root);
	cout << ans->n->data << "@" << ans->h;
	return 0;
}


