#include <iostream>
#include <stack>
#include <string>
#include <set>
using namespace std;

stack<int> lk; //left
set<int> rk; //right

int main(){
	freopen("À¨ºÅÆ¥Åä.in", "r", stdin);
	
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i] == '(') lk.push(i);
	}
	while(lk.size()){
		for(int i=lk.top();;i++){
			cout<<s[i];
			if(s[i] == ')' && rk.find(i) == rk.end()){
				rk.insert(i);
				lk.pop();
				break;
			}
		}
		cout<<endl;
	}
}
