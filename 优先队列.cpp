#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct cmp{
	bool operator () (const int a, const int b) const{
		return a % 10 > b % 10; 
		//���� �Ƚϳ���10�������ı��ʽ��ֵ ��Ϊ�ж�ab��С������ 
	} //a�����ȼ���bСʱ����ture 
};

priority_queue<int>pq1; //Ĭ�����ȶ��� ����������ֵԽС���ȼ�ԽС 
priority_queue<int, vector<int>, cmp> pq2; 
//�Զ������ȶ��� <�洢����������, pq2����������, ���������> 


int main(){
	freopen("���ȶ���.in", "r", stdin);
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
