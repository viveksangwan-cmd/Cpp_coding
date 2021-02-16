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

node* constructTreeFromInfixAndPost(int *in, int *pre, int s, int e) {
	static int i = 0;
	if (s > e) return NULL;

	node* current = new node(pre[i]);

	int index = -1;
	for (int j = s; j <= e; j++) {
		if (in[j] == pre[i]) {
			index = j;
			break;
		}
	}

	i++;
	current->left = constructTreeFromInfixAndPost(in, pre, s, index - 1);
	current->right = constructTreeFromInfixAndPost(in, pre, index + 1, e);

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
	int in[] = {3, 2, 8, 4, 1, 6, 7, 5};
	int pre[] {1, 2, 3, 4, 8, 5, 6, 7};
	int n = sizeof(in) / sizeof(in[0]);
	node* root = constructTreeFromInfixAndPost(in, pre, 0, n - 1);
	bfs(root);
}