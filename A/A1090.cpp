#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

const int maxn = 100010;
int n;
double p, r;
bool flag[maxn] = {false};
vector<int> fac;

struct node{
	int layer;
	int number;
	vector<int> child;
}Node[maxn];

int max_layer = -1, max_num = 0;
void add_layer(int k, int index){
	Node[k].layer = index;
	if(index > max_layer){
		max_layer = index;
		max_num = 1;
	}
	else if(index == max_layer && Node[k].child.size() == 0){
		max_num++;
		return;
	}
	for(int i = 0; i < Node[k].child.size(); i++){
		add_layer(Node[k].child[i], index + 1);
	}
	return;
}

int main(){
	scanf("%d%lf%lf", &n, &p, &r);
	int root, temp;
	for(int i = 0; i < n; i++){
		scanf("%d", &temp);
		if(temp != -1)
			Node[temp].child.push_back(i);
		else 
			root = i;
	}
	r = r / 100 + 1.0;
	add_layer(root, 0);
	printf("%.2lf %d", p * pow(r, max_layer), max_num);
}
