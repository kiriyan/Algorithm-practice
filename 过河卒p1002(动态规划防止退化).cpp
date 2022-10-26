#include <iostream>
using namespace std;
const int maxd = 20+5;
int b1, b2;
int map[maxd][maxd]; 
long long bj[maxd][maxd];
long long dp(int x, int y){
	if(!map[x][y]) return 0;
	if((x==2 && y==3) || (x==3 && y==2)){
		return map[x][y] ? 1 : 0;
	}
	if(bj[x][y]) return bj[x][y];
	long long a = map[x-1][y] ? dp(x-1, y) : 0;
	long long b = map[x][y-1] ? dp(x, y-1) : 0;
	bj[x][y] = a + b;
	return bj[x][y]; 
} 

void print_map(){
	for(int i=0;i<b1+3;i++){
		for(int j=0;j<b2+3;j++) cout<<map[i][j]<<" ";
		cout<<endl;
	}
}

int main(){
	//freopen("P1002_3.in", "r", stdin);
	//freopen("¹ýºÓ×ä.in", "r", stdin);
	int m, n;
	cin>>b1>>b2>>n>>m;
	for(int i=0;i<maxd;i++){
		for(int j=0;j<maxd;j++){
			map[i][j] = 1;
			if(i < 2 || j < 2) map[i][j] = 0;
			if(i == n+2 && j == m+2) map[i][j] = 0;
			if(i == n+1 && j== m+4) map[i][j] = 0;
			if(i == n && j== m+3) map[i][j] = 0;
			if(i == n && j== m+1) map[i][j] = 0;
			if(i == n+1 && j== m) map[i][j] = 0;
			if(i == n+3 && j== m) map[i][j] = 0;
			if(i == n+4 && j== m+1) map[i][j] = 0;
			if(i == n+4 && j== m+3) map[i][j] = 0;
			if(i == n+3 && j== m+4) map[i][j] = 0;
		}
	}
	//print_map();
	//cout<<"1\n";
	cout<<dp(b1+2, b2+2);
} 
