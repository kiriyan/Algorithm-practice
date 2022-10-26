#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 100 + 5;
int m, n, idx[maxn][maxn];
char pic[maxn][maxn];

void dfs(int r, int c){
	if(r < 0 || r >= m || c < 0 || c >= n) return; //出界的格子
	if(idx[r][c] > 0 || pic[r][c] != '@') return; //不是"@"或者已访问过的格子
	idx[r][c] = 1;
	for(int dr = -1; dr <= 1; dr++){
		for(int dc = -1; dc <= 1; dc++){
			if(dr != 0 || dc != 0) dfs(r+dr, c+dc);
		}
	} 
}

int main(){
	freopen("油田(UVa572).in", "r", stdin);
	//cout<<"hhh";
	int m1, n1;
	/*
	while(scanf("%d %d", &m1, &n1) == 2){
		m = m1; n = n1;
		cout<<"hhh";
		for(int i=0;i<m;i++) scanf("%s", pic[i]);
		memset(idx, 0, sizeof(idx));
		
		int cnt = 0;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(idx[i][j] == 0 && pic[i][j] == '@') dfs(i, j);
			}
			//cout<<"hhh";
		}
		//cout<<"fff";
		cout<<cnt<<endl;
	}
	*/
	scanf("%d %d", &m1, &n1);
	m = m1; n = n1;
	cout<<"hhh";
	for(int i=0;i<m;i++) scanf("%s", pic[i]);
	memset(idx, 0, sizeof(idx));
	int cnt = 0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<"fff";
			if(idx[i][j] == 0 && pic[i][j] == '@'){
				dfs(i, j);
				cnt++;
			}
		}
		//cout<<"hhh";
	}
	//cout<<"fff";
	cout<<cnt<<endl;
	return 0;
} 
