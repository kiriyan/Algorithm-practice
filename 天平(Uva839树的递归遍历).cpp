#include <iostream>
using namespace std;
const int maxn = 200;

int read_input(int s){
	int wl, dl, wr, dr;
	cin>>wl>>dl>>wr>>dr;
	int sum=0;
	if(wl) sum += wl;
	else sum += read_input(s);
	if(wr) sum += wr;
	else sum += read_input(s);
	return s+sum; 
}

int main(){
	freopen("天平(Uva839).in", "r", stdin);
	int t;
	cin>>t;
	while(t--){
		int wl, dl, wr, dr;
		cin>>wl>>dl>>wr>>dr;
		if(!wl) wl = read_input(0);
		if(!wr) wr = read_input(0);
		//cout<<wl<<" "<<wr<<endl;
		if(!wl*dl-wr*dr) cout<<"YES";
		else cout<<"NO";
		cout<<endl;
	}
	return 0;
}
/*
//其实已经很简单了 答案差不多 
#include <iostream>
using namespace std;

bool solve(int &W){
	int W1, D1, W2, D2;
	bool b1 = true, b2 = true;
	cin>>W1>>D1>>W2>>D2;
	if(!W1) b1 = solve(W1);
	if(!W2) b2 = solve(W2);
	W = W1 + W2;
	return b1 && b2 && (W1 * D1 == W2 * D2);
}

int main(){
	freopen("天平(Uva839).in", "r", stdin);
	int T, W;
	cin>>T;
	while(T--){
		if(solve(W)) cout<<"YES\n";
		else cout<<"NO\n";
		if(T) cout<<"\n";
	}
	return 0;
}
*/
