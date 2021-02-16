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

class node {
public:
	int data;
	node* left;
	node* right;

	node(int data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

node* insertIntoBST(node* root, int d) {
	if (root == NULL) {
		return new node(d);
	}

	if (d <= root->data) {
		root->left = insertIntoBST(root->left, d);
	} else {
		root->right = insertIntoBST(root->right, d);
	}

	return root;
}

node* deleteFromBST(node* root, int data) {
	if (root == NULL) return NULL;

	if (data < root->data) {
		root->left = deleteFromBST(root->left, data);
	} else if (data == root->data) {
		// No children
		if (root->left == NULL && root->right == NULL) {
			delete root;
			return NULL;
		}

		// 1 children
		else if (root->left != NULL && root->right == NULL) {
			node* temp = root->left;
			delete root;
			return temp;
		}
		else if (root->right != NULL && root->left == NULL) {
			node* temp = root->right;
			delete root;
			return temp;
		}

		// 2 children
		else {
			node* temp = root->right;
			while (temp->left != NULL) {
				temp = temp->left;
			}

			root->data = temp->data;
			root->right = deleteFromBST(root->right, temp->data);
		}

	} else {
		root->right = deleteFromBST(root->right, data);
	}
	return root;
}

node* createBST() {
	int d;
	cin >> d;

	node* root = NULL;

	while (d != -1) {
		root = insertIntoBST(root, d);
		cin >> d;
	}

	return root;
}

void bfs(node* root) {
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while (!q.empty()) {
		node* current = q.front();
		q.pop();
		if (current == NULL) {
			cout << endl;
			if (!q.empty()) {
				q.push(NULL);
			}
		} else {
			cout << current->data << ", ";
			if (current->left) q.push(current->left);
			if (current->right) q.push(current->right);
		}
	}
}

void inorder(node *root) {
	if (root == NULL) return;

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

int main() {
	sublime();
	node* root = createBST();
	inorder(root);
	cout << endl;
	bfs(root);
	deleteFromBST(root, 1);
	inorder(root);
	cout << endl;
	bfs(root);
}