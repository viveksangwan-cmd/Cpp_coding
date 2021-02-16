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
struct node{
public:
    int data;
    node *next;
};

// print  Linked list
void printLL(node* head){
    node* temp;
    temp=head;
     while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
};

// push the element at the beginning of the link list
void pushAtBegg(node** head ,int data){
    node* newNode = new node();
    newNode->data=data;
    newNode->next = *(head);
    *head = newNode;
};

// push the element after specific node of the link list
void pushAfterNode(node* prevNode,int data){
    if((prevNode)==NULL){
        return;
    }
    node* newNode = new node();
    newNode->data=data;
    newNode->next=(prevNode->next);
    prevNode->next=newNode;
};

// push element at the end of link list
void pushAtEnd(node* head,int data){
    node* newNode = new node();
    newNode->data=data;
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}


// delete a node with specific data(key)
void deleteNode(node** head,int key){
    node* temp = *head;
    node* prev = NULL;
    if(temp->data==key){
        *head=(temp->next);
        delete temp;
        return;
    }
    while(temp!=NULL && temp->data!=key){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        return;
    }else{
        prev->next=temp->next;
        delete temp;
    }
}

// delete a position at specific positon
void deleteFromPos(node** head,int pos){
    if(*head==NULL){
        return;
    }
    node* temp = *head;
    if(pos==0){
        *head=temp->next;
        delete temp;
        return;
    }
    for(int i=0;i<pos-1 && temp!=NULL;i++){
        temp=temp->next;
    }
    if(temp==NULL || temp->next==NULL){
        return;
    }
    node* nextNode = temp->next->next;
    delete temp->next;
    temp->next=nextNode;
}

// reverse a link list using recursion
node* reverseRecursive(node* head){
    if(!head || !head->next ){
        return head;
    }

    // reverse the ret of link list rest-> HEAD , it will always point to Head after reaching base condition
    node* rest = reverseRecursive(head->next);

    // chages next nodes ->next point to itself
    head->next->next=head;
    // changs self's next pointer to NULL , it will change after next back call stack
    head->next=NULL;

    return rest;
}

// reverse a link list iteratively
node* reverseLL(node* head){
    node* temp = head;
    node* prev = NULL;
    node* nextNode = NULL;
    while(temp!=NULL){
        nextNode=temp->next;
        temp->next=prev;
        prev=temp;
        temp=nextNode;
    }
    return prev;
}

int main()
{
    node* head = new node();
    node* second = new node();
    head->next=second;
    head->data=11;
    second->data=15;
    second->next=NULL;
    pushAtBegg(&head,1);
    pushAfterNode((head->next->next),16);
    pushAtEnd(head,99);
    // deleteNode(&head,1);
    // deleteFromPos(&head,2);
    printLL(head);
    head = reverseRecursive(head);
    printLL(head);
 }