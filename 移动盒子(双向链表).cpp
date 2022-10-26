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
	freopen("移动盒子.in", "r", stdin);
	node n0(0, -1, 0, 1);
	N.push_back(n0);
	/*
	int *n = &n0.name;
	cout<<*(n+1);
	//用指针访问结构体元素，就可以实现下标访问 
	*/
	
	int m, n;
	int dir = 1;//1为正向 ，-1为反向
	cin>>n>>m;
	for(int i=1;i<=n;i++){node ni(i, i-1, i, i+1); N.push_back(ni);}
	N[1].left = -1; N[n].right = -1;
	node n_tail = (n+1, -1, n+1, -1);//增加尾部防止指针溢出 
	N.push_back(n_tail);
	int ord, X, Y, *x, *y; 
	int r, l;
	for(int i=1;i<=m;i++){
		cin>>ord>>X>>Y;
		x = &N[X].mid; y = &N[Y].mid;
		r = dir; l = (-1) * dir; 
		int *xl = &N[*(x+l)].mid, *xr = &N[*(x+r)].mid;
		int *yl = &N[*(y+l)].mid, *yr = &N[*(y+r)].mid;
		if(ord == 1 && *(y+l) != X){ //若X不在y左边 
			if(*(x+l) != -1) *(xl+r) = *(x+r);//x左边那个盒子的右边是x右边那个盒子 
			if(*(x+r) != -1) *(xr+l) = *(x+l);//x右边那个盒子的左边是x左边那个盒子
			if(*(y+l) != -1) *(yl+r) = X;//y左边那个盒子的右边是x
			*(x+r) = Y;//x右边的盒子是y
			*(x+l) = *(y+l);//x左边的盒子是y之前左边的盒子
			*(y+l) = X;//y左边的盒子是x 
		}
		if(ord == 2 && *(y+r) != X){
			if(*(x+l) != -1) *(xl+r) = *(x+r);//x左边那个盒子的右边是x右边那个盒子 
			if(*(x+r) != -1) *(xr+l) = *(x+l);//x右边那个盒子的左边是x左边那个盒子
			//cout<<*(xr+l)<<" * "<<;
			if(*(y+r) != -1) *(yr+l) = X;//y右边那个盒子的左边是x
			*(x+l) = Y;//x左边的盒子是y
			*(x+r) = *(y+r);//x右边的盒子是y之前右边的盒子
			*(y+r) = X;//y右边的盒子是x 
		}
		if(ord == 3){
			if(*(x+l) != -1) *(xl+r) = Y;//x左边那个盒子的右边是y
			if(*(x+r) != -1) *(xr+l) = Y;//x右边那个盒子的左边是y
			int Yl = *(y+l);
			int Yr = *(y+r);
			*(y+l) = *(x+l);//y左边的盒子是x左边的盒子
			*(y+r) = *(x+r);//y右边的盒子是x右边的盒子 
			if(*(y+l) != -1) *(yl+r) = X;//y之前左边那个盒子的右边是x
			if(*(y+r) != -1) *(yr+l) = X;//y之前右边那个盒子的左边是x
			*(x+l) = Yl;//x左边的盒子是y之前左边的盒子
			*(x+r) = Yr;//x右边的盒子是y之前右边的盒子
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







