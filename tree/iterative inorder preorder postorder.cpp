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

void inorderIterative(node* root){
    stack<node*> st;
    node* curr = root;
    while(curr!=NULL || !st.empty()){
        if(curr!=NULL){
            st.push(curr);
            curr=curr->left;
        }else{
            curr = st.top();
            st.pop();
            cout<<curr->data<<endl;
            curr=curr->right;
        }
    }
}


void preorderIterative(node* root){
    if(root==NULL) return;
    stack<node*> st;
    node* curr = root;
    st.push(root);
    while(!st.empty()){
        node* temp = st.top();
        st.pop();
        if(temp->left!=NULL){
            st.push(temp->left);
        }
        if(temp->right!=NULL){
            st.push(temp->right);
        }
    }
}
void postorderIterative(node* root){
    if(root==NULL) return;
    stack<node*> st;
    node* curr = root;
    st.push(root);
    while(!st.empty()){
        node* temp = st.top();
        st.pop();
        if(temp->right!=NULL){
            st.push(temp->right);
        }
        if(temp->left!=NULL){
            st.push(temp->left);
        }
    }
}


int main()
{
    node* tree = buildTree();
    preorderIterative(tree);
}