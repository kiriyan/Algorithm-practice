#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct cmp{
	bool operator () (const int a, const int b) const{
		return a % 10 > b % 10; 
		//定义 比较除以10的余数的表达式的值 作为判断ab大小的运算 
	} //a的优先级比b小时返回ture 
};

priority_queue<int>pq1; //默认优先队列 定义整数数值越小优先级越小 
priority_queue<int, vector<int>, cmp> pq2; 
//自定义优先队列 <存储的数据类型, pq2的容器类型, 重载运算符> 


int main(){
	freopen("优先队列.in", "r", stdin);
	int n, a;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		pq1.push(a);
		pq2.push(a);
	}
	for(int i=0;i<n;i++){
		cout<<pq1.top()<<" ";
		pq1.pop();
	}
	cout<<endl;
	for(int i=0;i<n;i++){
		cout<<pq2.top()<<" ";
		pq2.pop();
	}
}
