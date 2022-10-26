#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 10000;
int shu[maxn];

int half_search(int left, int right, int sh){    //二分查找 
	if(left == right && shu[left] != sh) return -1;
	if(left == right && shu[left] == sh) return left;
	if(right-left==1){
		if(shu[left]==sh) return left;
		if(shu[right]==sh) return right;
		return -1;
	}
	int mid = int((right+left)/2);
	if(sh > shu[mid]) half_search(mid, right, sh);
	else if(sh < shu[mid]) half_search(left, mid, sh);
	else return mid;
}

int main(){
	freopen("大理石在哪.in", "r", stdin);
	
	int que[maxn], n, q;
	cin>>n>>q;
	for(int i=0;i<n;i++) cin>>shu[i];
	for(int j=0;j<q;j++) cin>>que[j];
	sort(shu, shu+n);
	
	for(int i=0;i<q;i++){
		/*
		int pd = half_search(0, n-1, que[i]);
		if(pd == -1) cout<<que[i]<<" not found"<<endl;
		else cout<<que[i]<<" found at "<<pd+1<<endl;
		//二分查找 
		*/
		int x = que[i];
		int p = lower_bound(shu, shu+n, x) - shu; 
		//lower_bound 查找大于或等于x的第一个位置 
		if(shu[p] == x) printf("%d found at %d\n", x, p+1);
		else printf("%d not found\n", x);
	}
	
} 
