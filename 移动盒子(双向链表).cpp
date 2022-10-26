#include <iostream>
#include <vector>
using namespace std;

struct node{
	int name;
	int left;
	int mid; 
	int right;
	node(int name=0, int left=-1, int mid = 0, int right=1){
		this->name = name; 
		this->left = left; 
		this->mid = mid;
		this->right = right;
	}
};

vector<node> N;
vector<int> line; 

int main(){
	freopen("�ƶ�����.in", "r", stdin);
	node n0(0, -1, 0, 1);
	N.push_back(n0);
	/*
	int *n = &n0.name;
	cout<<*(n+1);
	//��ָ����ʽṹ��Ԫ�أ��Ϳ���ʵ���±���� 
	*/
	
	int m, n;
	int dir = 1;//1Ϊ���� ��-1Ϊ����
	cin>>n>>m;
	for(int i=1;i<=n;i++){node ni(i, i-1, i, i+1); N.push_back(ni);}
	N[1].left = -1; N[n].right = -1;
	node n_tail = (n+1, -1, n+1, -1);//����β����ָֹ����� 
	N.push_back(n_tail);
	int ord, X, Y, *x, *y; 
	int r, l;
	for(int i=1;i<=m;i++){
		cin>>ord>>X>>Y;
		x = &N[X].mid; y = &N[Y].mid;
		r = dir; l = (-1) * dir; 
		int *xl = &N[*(x+l)].mid, *xr = &N[*(x+r)].mid;
		int *yl = &N[*(y+l)].mid, *yr = &N[*(y+r)].mid;
		if(ord == 1 && *(y+l) != X){ //��X����y��� 
			if(*(x+l) != -1) *(xl+r) = *(x+r);//x����Ǹ����ӵ��ұ���x�ұ��Ǹ����� 
			if(*(x+r) != -1) *(xr+l) = *(x+l);//x�ұ��Ǹ����ӵ������x����Ǹ�����
			if(*(y+l) != -1) *(yl+r) = X;//y����Ǹ����ӵ��ұ���x
			*(x+r) = Y;//x�ұߵĺ�����y
			*(x+l) = *(y+l);//x��ߵĺ�����y֮ǰ��ߵĺ���
			*(y+l) = X;//y��ߵĺ�����x 
		}
		if(ord == 2 && *(y+r) != X){
			if(*(x+l) != -1) *(xl+r) = *(x+r);//x����Ǹ����ӵ��ұ���x�ұ��Ǹ����� 
			if(*(x+r) != -1) *(xr+l) = *(x+l);//x�ұ��Ǹ����ӵ������x����Ǹ�����
			//cout<<*(xr+l)<<" * "<<;
			if(*(y+r) != -1) *(yr+l) = X;//y�ұ��Ǹ����ӵ������x
			*(x+l) = Y;//x��ߵĺ�����y
			*(x+r) = *(y+r);//x�ұߵĺ�����y֮ǰ�ұߵĺ���
			*(y+r) = X;//y�ұߵĺ�����x 
		}
		if(ord == 3){
			if(*(x+l) != -1) *(xl+r) = Y;//x����Ǹ����ӵ��ұ���y
			if(*(x+r) != -1) *(xr+l) = Y;//x�ұ��Ǹ����ӵ������y
			int Yl = *(y+l);
			int Yr = *(y+r);
			*(y+l) = *(x+l);//y��ߵĺ�����x��ߵĺ���
			*(y+r) = *(x+r);//y�ұߵĺ�����x�ұߵĺ��� 
			if(*(y+l) != -1) *(yl+r) = X;//y֮ǰ����Ǹ����ӵ��ұ���x
			if(*(y+r) != -1) *(yr+l) = X;//y֮ǰ�ұ��Ǹ����ӵ������x
			*(x+l) = Yl;//x��ߵĺ�����y֮ǰ��ߵĺ���
			*(x+r) = Yr;//x�ұߵĺ�����y֮ǰ�ұߵĺ���
		}
		if(ord == 4) dir *= -1;
		//for(int i=1;i<=n;i++) cout<<N[i].left<<" "<<N[i].right<<endl;
		//cout<<endl;
	}
	l = (-1) * dir;
	int pos;
	for(int i=1,*now;i<=n;i++){
		now = &N[i].mid;
		if(*(now+l) == -1){
			pos = i;
			break;
		}
	}
	int *next = &N[pos].mid, i = 1;
	long long s=0;
	//for(int i=1;i<=n;i++) cout<<N[i].left<<" "<<N[i].right<<endl;
	//cout<<pos<<endl;
	//cout<<*next<<endl;
	
	while(1){
		//cout<<N[pos].mid<<" ";
		if(i%2) s+=N[pos].mid;
		i++;
		if(*(next+dir) == -1) break;
		pos = *(next+dir);
		next = &N[pos].mid;
	}
	cout<<s;
}







