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

int min_layer = 100010, min_num = 0;
void add_layer(int k, int index){
	Node[k].layer = index;
	if(index < min_layer && Node[k].child.size() == 0){
		min_layer = index;
		min_num = 1;
	}
	else if(index == min_layer && Node[k].child.size() == 0){
		min_num++;
		return;
	}
	else if(index > min_layer)
		return;
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
	}
	r = r / 100 + 1.0;
	add_layer(0, 0);
	printf("%.4lf %d", p * pow(r, min_layer), min_num);
}
