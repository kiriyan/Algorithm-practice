#include <cstdio>
#include <iostream>
#define MAX_SIZE 10005
using namespace std;
int n, label[MAX_SIZE];
int map[MAX_SIZE];

void print(){
	for(int i=0;i<n;i++) cout<<map[i]<<" ";
	cout<<endl;
}

void dfs(int dir, int floor){
	if (floor == n) return;
	for(int i=0;i<n;i++){
		if(!label[i]){
			map[floor] = i+1;
			label[i] = 1;
			if(floor == n-1) print();
			dfs(i, floor+1);
			label[i] = 0;
		}
	}
	return; 
}

int main(){
	cin>>n;
	for(int i=0;i<n+2;i++) label[i] = 0;
	dfs(0, 0);
}
