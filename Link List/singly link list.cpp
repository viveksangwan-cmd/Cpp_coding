#include<iostream>
using namespace std;
void sublime()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.TXT", "r", stdin);
	freopen("output.TXT", "w", stdout);
#endif
}

struct node
{
public:
	int data;
	node* next;
};

void print(node *head)
{
	node* temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

void removeDuplicate(node *head )
{
	node *temp = head;
	node* next_next;
	if (temp == NULL) return ;
	while (temp->next != NULL)
	{
		if (temp->data != temp->next->data)
		{
			temp = temp->next;
		}
		else
		{
			next_next = temp->next->next;
			free(temp->next);
			temp->next = next_next;
		}
	}
}

void push(node** head, int data)
{
	node* new_data = new node();
	new_data->data = data;
	new_data->next = (*head);
	(*head) = new_data;
}

int main()
{
	sublime();
	node* t = NULL;
	push(&t, 8);
	push(&t, 99);
	push(&t, -3);
	push(&t, -3);
	push(&t, 99);
	print(t);
	removeDuplicate(t);
	print(t);
	return 0;
}

