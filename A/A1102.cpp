#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;

const int maxn = 15;
int n;
bool flag[maxn] = {false};

struct node{
	int data;
	int lchild;
	int rchild;
}Node[maxn];

int transform(char x){
	return x - '0';
}

int sum = 0;
void levelorder(int k){
	queue<int> q;
	q.push(k);
	while(!q.empty()){
		int now = q.front();
		printf("%d", now);
		sum++;
		if(sum < n)
			printf(" ");
		q.pop();
		if(Node[now].rchild != -1) q.push(Node[now].rchild);
		if(Node[now].lchild != -1) q.push(Node[now].lchild);
	}
	return;
}

int sum1 = 0;
void inorder(int k){
	if(k != -1){
		inorder(Node[k].rchild);
		printf("%d", k);
		sum1++;
		if(sum1 < n)
			printf(" ");
		inorder(Node[k].lchild);
	}
	return;
}

int main(){
	scanf("%d", &n);
	char temp, temp1;
	for(int i = 0; i < n; i++){
		getchar();
		scanf("%c %c", &temp, &temp1);
		if(temp == '-')
			Node[i].lchild = -1;
		else{
			Node[i].lchild = transform(temp);
			flag[transform(temp)] = true;
		}
		if(temp1 == '-')
			Node[i].rchild = -1;
		else{
			Node[i].rchild = transform(temp1);
			flag[transform(temp1)] = true;
		}
	}
	int k;
	for(k = 0; k < n; k++){
		if(!flag[k])
			break;
	}
	levelorder(k);
	printf("\n");
	inorder(k);
	return 0;
}
