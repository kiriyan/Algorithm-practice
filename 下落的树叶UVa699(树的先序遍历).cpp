#include <iostream>
#include <cstdio>
#include <sstream>
#include <cstring>
using namespace std;
const int maxn = 1005, mid = 500;
int map[maxn], shu[maxn];
int min_m, max_m, l;
//l为在树中的查找坐标 
void dfs(int x){
	//在map中的坐标 
	if(shu[l] == -1) return;
	min_m = x < min_m ? x : min_m;
	max_m = x > max_m ? x : max_m;
	map[x] += shu[l];
	l++; dfs(x-1); 
	l++; dfs(x+1);
	return; 
}

int main(){
	freopen("下落的树叶.in", "r", stdin);
	string line;
	int i, cou = 0;
	while(getline(cin, line)){
		cou++;
		memset(shu, 0, sizeof(shu));
		memset(map, 0, sizeof(map));
		stringstream ss(line);
		i = l = 0;
		min_m = max_m = mid;
		while(ss >> shu[i++]);
		if(shu[0] == -1) break;
		dfs(mid);
		cout<<"case "<<cou<<":\n";
		for(int i=min_m;i<=max_m;i++) if(map[i]) cout<<map[i]<<" ";
		cout<<endl<<endl;
	}
}


/*
//以下是答案的做法，思路一致看但起来略复杂 
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1005;
int sum[maxn];
void build(int p){
	int v; cin>> v;
	if(v == -1) return; //空树
	sum[p] += v;
	build(p - 1); build(p + 1); 
}

//边读边统计
bool init_(){
	int v; cin >> v;
	if(v == -1) return false;
	memset(sum, 0, sizeof(sum));
	int pos = maxn/2; //树根的水平位置
	sum[pos] = v;
	build(pos - 1); build(pos + 1);
}

int main(){
	freopen("下落的树叶.in", "r", stdin);
	int kase = 0;
	while(init_()){
		int p = 0;
		while(sum[p] == 0) p++; //找最左边的叶子 
		cout<<"Case "<<++kase<<":\n"<<sum[p++]; //避免行末多余空格 (严谨的离谱)
		while(sum[p] != 0) cout<<" "<<sum[p++];
		cout<<"\n\n"; 
	}
	return 0;
}  
*/
