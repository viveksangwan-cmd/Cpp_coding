#include <bits/stdc++.h>
#define int long long
#define	mod	1000000007
#define endl '\n'
using namespace std;

void sublime()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}


void buildTree(int* arr,int* tree,int start,int end,int treeNode){
	if(start==end){
		tree[treeNode] = arr[start];
		return;
	}

	int mid = start + (end - start)/2;
	buildTree(arr,tree,start,mid,2*treeNode);
	buildTree(arr,tree,mid+1,end,(2*treeNode)+1);

	tree[treeNode] = tree[treeNode*2] + tree[(2*treeNode)+1];
}


void updateTree(int* arr,int* tree,int start,int end,int treeNode,int index,int val){
	if(start==end ){
		arr[index] = val;
		tree[treeNode] = val;
		return ;
	}

	int mid = start + (end - start)/2;
	if(index<=mid){
		updateTree(arr,tree,start,mid,2*treeNode,index,val);
	}else{
		updateTree(arr,tree,mid+1,end,2*treeNode+1,index,val);
	}
	tree[treeNode] = tree[2*treeNode] + tree[(2*treeNode)+1];
}


int query(int* tree,int start,int end,int treeNode,int left,int right){
	if(right<start || left>end){
		return 0;
	}
	if(start>=left && right>=end){
		return tree[treeNode];
	}

	int mid = start + (end - start)/2;
	int leftPart = query(tree,start,mid,2*treeNode,left,right);
	int rightPart = query(tree,mid+1,end,2*treeNode+1,left,right);

	return leftPart + rightPart;
}


int32_t main() {
	sublime();

	int n = 5;
	int arr[n] = {1,2,3,4,5};

	int* tree = new int[2*n];
	buildTree(arr,tree,0,4,1);

	for(int i=1;i<2*n;i++){
		cout<<tree[i]<<" ";
	}
	cout<<endl;	

	updateTree(arr,tree,0,4,1,2,10);
	for(int i=1;i<2*n;i++){
		cout<<tree[i]<<" ";
	}

	cout<<endl;
	cout << query(tree,0,4,1,2,4); 
}
