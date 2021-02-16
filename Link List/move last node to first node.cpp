#include <bits/stdc++.h>
using namespace std;
void c_p_c()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
class node{
public:
    int data;
    node *next=NULL;
    node(int data){
        this->data=data;
    }
};

void printLL(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data;
        temp=temp->next;
    }
}

void lastToFirst(node** head){
    node* temp = *head;
    if(!temp || !temp->next){
        return ;
    }
    while(temp->next->next){
        temp=temp->next;
    }
    temp->next->next=*head;
    (*head) = temp->next;
    temp->next=NULL;
}


int main()
{
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);
    head->next->next->next->next->next = new node(6);
    head->next->next->next->next->next->next = new node(7);
    head->next->next->next->next->next->next->next = new node(8);
    printLL(head); // 1 2 3 4 5 6 7 8
    cout<<endl;
    lastToFirst(&head);
    printLL(head); // 7 6 5 4 3 2 1
}