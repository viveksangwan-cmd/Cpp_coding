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
    int data ;
    node* left = NULL;
    node* right = NULL;
    node(int data){
        this->data=data;
    }
};

node* buildTree(){
    int n; cin>>n;
    if(n==-1) return NULL;
    node* temp = new node(n);
    temp->left = buildTree();
    temp->right = buildTree();
    return temp;
}

void printPreOrderTree(node* root){
    if(root==NULL) {
        return;
    }
    cout<<root->data<<" ";
    printPreOrderTree(root->left);
    printPreOrderTree(root->right);
}

void reverseLevelOrderTraversal(node* root){
    stack<int> st;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* current = q.front();
        q.pop();
        st.push(current->data);
        if(current->right!=NULL){
            q.push(current->right);
        }       
        if(current->left){
            q.push(current->left);
        }
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

int main()
{
    node* tree = buildTree();
    printPreOrderTree(tree);
    cout<<endl;
    reverseLevelOrderTraversal(tree);
}