#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

struct node{
	int data;
	node* lchild;
	node* rchild;
}Node;

const int maxn = 1010;
int N, seq[maxn];

void insert(node* &root, int x){
	if(root == NULL){
		root = new node;
		root->data = x;
		root->lchild = NULL;
		root->rchild = NULL;
		return;
	}
	else if(x < root->data){
		insert(root->lchild, x);
	}
	else{
		insert(root->rchild, x);
	}
}

node* creat(){
	node* root = NULL;
	for(int i = 0; i < N; i++){
		insert(root, seq[i]);
	}
	return root;
}

int index1 = 0, index2 = 0; 
bool flag1 = true, flag2 = true;
bool preorder(node* root){
	int temp = index1;
	if(root != NULL){
		if(root->data == seq[temp]){
			index1++;
			preorder(root->lchild);
			preorder(root->rchild);
			return true && flag1;
		}
		else{
			flag1 = false;
			return false && flag1;
		}
	}
	return true;
}
bool postorder(node* root){
	int temp = index2;
	if(root != NULL){
		if(root->data == seq[temp]){
			index2++;
			postorder(root->rchild);
			postorder(root->lchild);
			return true && flag2;
		}
		else{
			flag2 = false;
			return false && flag2;
		}
	}
	return true;
}

int num = 0, num1 = 0;
void printpost(node* root){
	if(root != NULL){
		printpost(root->lchild);
		printpost(root->rchild);
		printf("%d", root->data);
		num++;
		if(num <= N - 1)
			printf(" ");
	}
	else 
		return;
}

void printpost_mirror(node* root){
	if(root != NULL){
		printpost_mirror(root->rchild);
		printpost_mirror(root->lchild);
		printf("%d", root->data);
		num1++;
		if(num1 <= N - 1)
			printf(" ");
	}
	else 
		return;
}

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d", &seq[i]);
	}
	node* tree = creat();
	if(preorder(tree)){
		printf("YES\n");
		printpost(tree);
	}
	else if(postorder(tree)){
		printf("YES\n");
		printpost_mirror(tree);
	}
	else
		printf("NO");
	return 0;
}
