#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 10000;
int shu[maxn];

int half_search(int left, int right, int sh){    //���ֲ��� 
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
	freopen("����ʯ����.in", "r", stdin);
	
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
		//���ֲ��� 
		*/
		int x = que[i];
		int p = lower_bound(shu, shu+n, x) - shu; 
		//lower_bound ���Ҵ��ڻ����x�ĵ�һ��λ�� 
		if(shu[p] == x) printf("%d found at %d\n", x, p+1);
		else printf("%d not found\n", x);
	}
	
} 
