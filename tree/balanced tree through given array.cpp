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
	node*right;
	node(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};


node* constructTreeFromArray(int *arr, int i, int n) {

	if (i > n) return NULL;
	int mid = (i + n) / 2;

	node* current = new node(arr[mid]);
	current->left = constructTreeFromArray(arr, i, mid - 1);
	current->right = constructTreeFromArray(arr, mid + 1, n);

	return current;
}

void bfs(node *root) {
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while (!q.empty()) {
		node* current = q.front();
		if (current == NULL) {
			q.pop();
			cout << endl;
			if (!q.empty()) {
				q.push(NULL);
			}
		}
		else {
			q.pop();
			cout << current->data << ",";
			if (current->left)	q.push(current->left);
			if (current->right)	q.push(current->right);
		}
	}
}

int main() {
	sublime();
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	int n = 7;
	// create balanced tree through array
	node* root = constructTreeFromArray(arr, 0, 6);
	bfs(root);
}