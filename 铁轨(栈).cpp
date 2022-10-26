#include <iostream>
#include <stack>
#include <queue>
using namespace std;

stack<int> st1, st2;
queue<int> q;

int main(){
	int n, a;
	cin>>n;
	while(n){
		cin>>a;
		q.push(a);
		//cout<<"q push : "<<a<<" \n";
		st1.push(n);
		n--;
	}
	st2.push(st1.top());
	//cout<<st1.top()<<" to st2\n";
	st1.pop();
	while(q.size()){
		if(st2.size() == 0 && st1.size() != 0){
			st2.push(st1.top());
			//cout<<st1.top()<<" to st2\n";
			st1.pop();
		}
		if(st2.top() != q.front() && st1.size() == 0) break;
		if(st2.top() != q.front()){
			st2.push(st1.top());
			//cout<<st1.top()<<" to st2\n";
			st1.pop();
		}
		else{
			//cout<<"st2 pop : "<<st2.top()<<"\n";
			st2.pop();
			q.pop();
		}
	}
	if(!q.size()) cout<<"can";
	else cout<<"cannot";
}
