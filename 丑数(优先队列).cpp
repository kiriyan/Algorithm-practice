#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;
typedef long long Ll;
const int bases[3] = {2, 3, 5}; 

int main(){
	priority_queue<Ll, vector<Ll>, greater<Ll> > pq;
	set<Ll> s;
	pq.push(1);
	s.insert(1);
	for(int i=1;;i++){
		Ll x = pq.top();
		pq.pop();
		if(i == 1500){
			cout<<x;
			break;
		}
		for(int j=0;j<3;j++){
			Ll x2 = x * bases[j];
			if(!s.count(x2)){
				s.insert(x2);
				pq.push(x2);
			}
		}
	}
	return 0;
}
