#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

struct node{
	int data;
	node* lchild;
	node* rchild;
}; 

node* creat(int postL, int postR, int inL, int inR, int post[], int in[]){
	if(postL > postR)
		return NULL;
	node* root = new node;
	root->data = post[postR];
	int k;
	for(k = inL; k <= inR; k++){
		if(in[k] == post[postR])
			break;
	}
	int number = k - inL;
	root->lchild = creat(postL, postL + number - 1, inL, k - 1, post, in);
	root->rchild = creat(postL + number, postR - 1, k + 1, inR, post, in);
	return root;
}

int main(){
	int num;
	scanf("%d", &num);
	int post[num], in[num];
	for(int i = 0; i < num; i++){
		scanf("%d", &post[i]);
	}
	for(int i = 0; i < num; i++){
		scanf("%d", &in[i]);
	}
	node* tree = creat(0, num - 1, 0, num - 1, post, in);
	queue<node*> Q;
	Q.push(tree);
	int sum = 0;
	while(!Q.empty()){
		node* Node = Q.front();
		Q.pop();
		printf("%d", Node->data);
		sum++;
		if(sum < num) printf(" ");
		if(Node->lchild != NULL){
			Q.push(Node->lchild);
		}
		if(Node->rchild != NULL){
			Q.push(Node->rchild);
		}
	}
	return 0;
}
