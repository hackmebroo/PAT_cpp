#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 110;
struct node{
	int weight;
	vector<int> child;
}Node[maxn];

bool cmp(int a, int b){
	return Node[a].weight > Node[b].weight;
}

int N, M, S;
vector<int> fac;
int path[maxn];

void DFS(int sum, int index, int numNode){
	if(sum == S && Node[index].child.size() == 0){
		for(int i = 0; i < numNode; i++){
			printf("%d", Node[path[i]].weight);
			if(i != numNode - 1)
				printf(" ");
		}
		printf("\n");
		return;
	}
	if(sum > S) return;
//	printf("\n*%d %d*\n", Node[index].weight, sum);
	for(int i = 0; i < Node[index].child.size(); i++){
		int child = Node[index].child[i];
		path[numNode] = child;
		DFS(sum + Node[child].weight, child, numNode + 1);
	}
}


int main(){
	scanf("%d%d%d", &N, &M, &S);
	for(int i = 0; i < N; i++){
		scanf("%d", &Node[i].weight);
	}
	int temp, child_num, temp_child;
	for(int i = 0; i < M; i++){
		scanf("%d%d", &temp, &child_num);
		for(int j = 0; j < child_num; j++){
			scanf("%d", &temp_child);
			Node[temp].child.push_back(temp_child);
		}
		sort(Node[i].child.begin(), Node[i].child.end(), cmp);
	}
	path[0] = 0;
	DFS(Node[0].weight, 0, 1);
	return 0;
}

