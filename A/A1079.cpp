#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

const int maxn = 100010;
int n;
double p, r, sum = 0;
bool flag[maxn] = {false};
vector<int> fac;

struct node{
	int layer;
	int number;
	vector<int> child;
}Node[maxn];


void add_layer(int k, int index){
	Node[k].layer = index;
	if(Node[k].child.size() == 0){
		sum += Node[k].number * pow(r, Node[k].layer);
		return;
	}
	for(int i = 0; i < Node[k].child.size(); i++){
		add_layer(Node[k].child[i], index + 1);
	}
	return;
}

int main(){
	scanf("%d%lf%lf", &n, &p, &r);
	int num, temp;
	for(int i = 0; i < n; i++){
		getchar();
		scanf("%d", &num);
		if(num != 0){
			for(int j = 0; j < num; j++){
				scanf("%d", &temp);
				Node[i].child.push_back(temp);
			}
		}
		else{
			scanf("%d", &Node[i].number);
		}
	}
	r = r / 100 + 1.0;
	add_layer(0, 0);
	printf("%.1lf", p * sum);
}
