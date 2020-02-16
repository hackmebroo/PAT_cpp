#include <cstring>
#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;

const int maxn = 40;
int pre[maxn], in[maxn];
int N;

struct node{
	int data;
	node* lchild;
	node* rchild;
};


node* creat(int preL, int preR, int inL, int inR){
	if(preL > preR)
		return NULL;
	int i;
	for(i = inL; i <= inR; i++){
		if(pre[preL] == in[i])
			break;
	}
	node* root = new node;
	root->data = in[i];
	int number = i - inL;
	root->lchild = creat(preL + 1, preL + number, inL, inL + number - 1);
	root->rchild = creat(preL + number + 1, preR, inL + number + 1, inR);
	return root;
}

int sum = 0;
void postorder(node* root){
	if(root != NULL){
		postorder(root->lchild);
		postorder(root->rchild);
		printf("%d", root->data);
		sum++;
		if(sum < N)
			printf(" ");
	}
	return;
}

int main(){
	scanf("%d", &N);
	char str[5];
	int temp, num = 0, index = 0;
	stack<int> st;
	for(int i = 0; i < 2 * N; i++){
		scanf("%s", str);
		if(strcmp(str, "Push") == 0){
			scanf("%d", &temp);
			st.push(temp);
			pre[index++] = temp;
		}
		else{
			in[num++] = st.top();
			st.pop();
		}
	}
	node* tree = creat(0, N - 1, 0, N - 1);
	postorder(tree);
	return 0;
}
