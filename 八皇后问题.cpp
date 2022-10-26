#include <iostream>
#include <cstdio>
using namespace std;
int map[8][8][8]={0};

void clear_map(int *a){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			map[*a][i][j]=0;
		}
	}
}

void ctrlcv(int *a,int *b){//a to b
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			map[*b][i][j]=map[*a][i][j];
		}
	}
}

int dfs(int x,int y){
	map[y][x][y]=1;
	if(x!=7){
		for(int i=0;i<8;i++) map[y+1][x][i]=2;//shu
		if(x+y<=7){
			for(int i=x+y;i>=0;i--){
				map[y+1][i][-1*i+x+y]=2;
			}
		}
		if(x+y>7){
			for(int i=7;i>=x+y-7;i--){
				map[y+1][i][-1*i+x+y]=2;
			}
		}
		if(x-y>=0){
			for(int i=x-y;i<=7;i++){
				map[y+1][i][i-x+y]=2;
			}
		}
		if(x-y<0){
			for(int i=0;i<=x-y+7;i++){
				map[y+1][i][i-x+y]=2;
			}
		}
		for(int i=0;i<=7;i++){
			if(map[y+1][y+1][i]!=2){
				dfs(i,y+1);
			}
		}
		return;//
	}
}
void print_map(int *a){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(map[*a][i][j]==1) cout<<"*";
		}
		cout<<endl;
	}
}

int main(){
	
}
