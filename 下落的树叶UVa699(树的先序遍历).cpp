#include <iostream>
#include <cstdio>
#include <sstream>
#include <cstring>
using namespace std;
const int maxn = 1005, mid = 500;
int map[maxn], shu[maxn];
int min_m, max_m, l;
//lΪ�����еĲ������� 
void dfs(int x){
	//��map�е����� 
	if(shu[l] == -1) return;
	min_m = x < min_m ? x : min_m;
	max_m = x > max_m ? x : max_m;
	map[x] += shu[l];
	l++; dfs(x-1); 
	l++; dfs(x+1);
	return; 
}

int main(){
	freopen("�������Ҷ.in", "r", stdin);
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
//�����Ǵ𰸵�������˼·һ�¿��������Ը��� 
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1005;
int sum[maxn];
void build(int p){
	int v; cin>> v;
	if(v == -1) return; //����
	sum[p] += v;
	build(p - 1); build(p + 1); 
}

//�߶���ͳ��
bool init_(){
	int v; cin >> v;
	if(v == -1) return false;
	memset(sum, 0, sizeof(sum));
	int pos = maxn/2; //������ˮƽλ��
	sum[pos] = v;
	build(pos - 1); build(pos + 1);
}

int main(){
	freopen("�������Ҷ.in", "r", stdin);
	int kase = 0;
	while(init_()){
		int p = 0;
		while(sum[p] == 0) p++; //������ߵ�Ҷ�� 
		cout<<"Case "<<++kase<<":\n"<<sum[p++]; //������ĩ����ո� (�Ͻ�������)
		while(sum[p] != 0) cout<<" "<<sum[p++];
		cout<<"\n\n"; 
	}
	return 0;
}  
*/
