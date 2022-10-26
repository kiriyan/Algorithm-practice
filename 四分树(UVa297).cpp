
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1000, root = 1024;
int cnt = 0, sum = 0, x;
struct node{
	int v; //1=fill 0=empty 2=node
	int one, two, three, four;
	node(int v=0, int one=0,int two=0,int three=0,int four=0){
		this->v = v;
		this->one = one;
		this->two = two;
		this->three = three;
		this->four = four;
	}
};
node N1[maxn], N2[maxn];
void plantTree(node N[], string &s, int bh){
	x++;
	if(x >= s.length()) return;
	char ch = s[x];
	if(ch == 'f'){N[bh].v = 1; return;}
	else if(ch == 'e'){N[bh].v = 0; return;}
	else N[bh].v = 2;
	N[bh].one = ++cnt; plantTree(N, s, cnt);
	N[bh].two = ++cnt; plantTree(N, s, cnt);
	N[bh].three = ++cnt; plantTree(N, s, cnt);
	N[bh].four = ++cnt; plantTree(N, s, cnt);
}

void sumTree(int bh1, int bh2, int flr){
	if(N1[bh1].v == 1 || N2[bh2].v == 1){sum += root/pow(4, flr);return;}
	if(N1[bh1].v == 0 && N2[bh2].v == 0){return;}
	if(N1[bh1].v == 2 && N2[bh2].v == 2){
		//cout<<"=";
		sumTree(N1[bh1].one, N2[bh2].one, flr+1);
		sumTree(N1[bh1].two, N2[bh2].two, flr+1);
		sumTree(N1[bh1].three, N2[bh2].three, flr+1);
		sumTree(N1[bh1].four, N2[bh2].four, flr+1);
	}
	if(N1[bh1].v == 2 && N2[bh2].v == 0){
		//cout<<">";
		sumTree(N1[bh1].one, 0, flr+1);
		sumTree(N1[bh1].two, 0, flr+1);
		sumTree(N1[bh1].three, 0, flr+1);
		sumTree(N1[bh1].four, 0, flr+1);
	}
	if(N1[bh1].v == 0 && N2[bh2].v == 2){
		//cout<<"<";
		sumTree(0, N2[bh2].one, flr+1);
		sumTree(0, N2[bh2].two, flr+1);
		sumTree(0, N2[bh2].three, flr+1);
		sumTree(0, N2[bh2].four, flr+1);
	}
}


int main(){
	freopen("四分树.in", "r", stdin);
	string s1, s2;
	int n, m=0;
	cin>>n;
	while(n--){
		cin>>s1>>s2;
		sum = 0;
		//node N1[maxn], N2[maxn];
		N1[0] = (0,0,0,0,0);
		N2[0] = (0,0,0,0,0);
		cnt = 1; x = -1; plantTree(N1, s1, 1);
		cnt = 1; x = -1; plantTree(N2, s2, 1); 
		sumTree(1, 1, 0);
		printf("There are %d black pixels.\n", sum);
	}
}

/*
//没想到答案真的就画了个四分图 。。。。不过确实不大因为最大只有32个像素(失策了) 
//不过不知道为甚，这个第一个样例错了 
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int len = 32;
const int maxn = 1024 + 10;
char s[maxn];
int buf[len][len], cnt;

//把字符串s[p..]导出到以(r, c)为左上角，边长为w的缓冲区中
//2 1
//3 4
void draw(const char *s, int &p, int r, int c, int w){
	char ch = s[p++];
	if(ch == 'p'){
		draw(s, p, r, c+w/2, w/2); //1
		draw(s, p, r, c, w/2); //2
		draw(s, p, r+w/2, c, w/2); //3
		draw(s, p, r+w/2, c+w/2, w/2); //4
	}
	else if(ch == 'f'){
		//画黑像素(白像素不画)
		for(int i=r;i<r+w;i++){
			for(int j=c;j<c+w;j++){
				if(buf[i][j] == 0) {buf[i][j] == 1; cnt++;}
				//只在之前没画过的地方画 
			}
		} 
	}
}

int main(){
	freopen("四分树.in", "r", stdin);
	int T;
	cin>>T;
	while(T--){
		memset(buf, 0, sizeof(buf));
		cnt = 0;
		for(int i=0;i<2;i++){
			cin>>s;
			int p = 0;
			draw(s, p, 0, 0, len);
		}
		printf("There are %d black pixels.\n", cnt);
	}
	return 0;
} 
*/
