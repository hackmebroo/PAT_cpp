#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct node{
	int x, y, z;
	int count;
	bool flag;
}Node;

const int max_m = 1286, max_n = 128, max_l = 60;
int n, m, l, t;
bool inq[max_m][max_n][max_l] = {false}; 
int slices[max_m][max_n][max_l];

int X[6] = {0,0,1,-1,0,0};
int Y[6] = {0,1,0,0,-1,0};
int Z[6] = {1,0,0,0,0,-1};

bool judge(int x, int y, int z){
	if(x >= m || x < 0 || y >= n || y < 0 || z >= l || z < 0) return false;
	if(slices[x][y][z] == 0 || inq[x][y][z] == true) return false;
	return true;
}

int BFS(int x, int y, int z, int t){
	int temp = 0;
	queue<node> Q;
	Node.x = x, Node.y = y, Node.z = z;
	Q.push(Node);
	inq[x][y][z] = true;
	while(!Q.empty()){
		node top = Q.front();
		Q.pop();
		temp++;
		for(int i = 0; i < 6; i++){
			int newX = top.x + X[i];
			int newY = top.y + Y[i];
			int newZ = top.z + Z[i];
			if(judge(newX, newY, newZ)){
				Node.x = newX, Node.y = newY, Node.z = newZ;
				Q.push(Node);
				inq[newX][newY][newZ] = true;
			}
		}
	}
	if(temp >= t)
		return temp;
	else return 0;
}

int main(){
	scanf("%d%d%d%d", &m, &n, &l, &t);
	for(int z = 0; z < l; z++){
		for(int x = 0; x < m; x++){
			for(int y = 0; y < n; y++){
				scanf("%d", &slices[x][y][z]);
			}
		}
	}
	int sum = 0;
	for(int z = 0; z < l; z++){
		for(int x = 0; x < m; x++){
			for(int y = 0; y < n; y++){
					if(slices[x][y][z] == 1 && inq[x][y][z] == false)
					sum += BFS(x, y, z, t);
			}
		}
	}
	printf("%d", sum);
	return 0;
}
