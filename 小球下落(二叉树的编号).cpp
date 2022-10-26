#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
const int maxd = 20;

int shu[1<<20];
int zb(int bh, int D){ //������������  ��ţ������� 
	if(bh >= pow(2, D-1) && bh <= pow(2, D) - 1) return bh;
	if(shu[bh]){shu[bh] = 0; zb(2*bh+1, D);}
	else{shu[bh] = 1; zb(2*bh, D);} 
}

int main(){
	freopen("С������.in", "r", stdin);
	int D, I;
	while(scanf("%d%d", &D, &I) == 2){
		memset(shu, 0, sizeof(shu));
		for(int i=0;i<I-1;i++) zb(1, D);
		cout<<zb(1, D)<<endl;
	}
} 
 
/*
//�򻯰汾���ҹ���
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	freopen("С������.in", "r", stdin);
	int D, I, bh = 1;
	while(scanf("%d%d", &D, &I) == 2){
		bh = 1;
		while(--D){
			if(I == 1){bh = 2 * bh; continue;}
			if(I % 2){bh = 2 * bh; I = (I+1)/2;}
			else{bh = 2 * bh + 1; I = I/2;}
		}
		cout<<bh<<endl;
	}
} 
*/
