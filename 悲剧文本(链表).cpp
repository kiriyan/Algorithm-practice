#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
using namespace std;

vector<char> s;
vector<int> next;

int main(){
	freopen("±¯¾çÎÄ±¾.in", "r", stdin);
	next.push_back(1);
	s.push_back(0);
	int pos1 = 1, pos2 = 1, mode = 0, k = 0;
	string s0;
	while(getline(cin, s0)){
		if(!s0.size()) break;
		for(int i=0;i<s0.length();i++){
		//cout<<s0[i]<<" ";
			if(s0[i] == '[') {mode = -1; k = mode; pos1 = next[0];}
			else if(s0[i] == ']') {mode = 1; k = mode;}
			else{
				s.push_back(s0[i]);
				next.push_back(-1);
				if(mode == -1) {next[0] = next.size()-1; next[next.size()-1] = pos1;}
				if(mode < -1) {next[next.size()-2] = next.size()-1; next[next.size()-1] = pos1;} 
				else if(mode >= 0){
					next[pos2] = next.size() - 1;
					pos2 = next.size() - 1;
					next[next.size()-1] = -1; // -1ÎªÎ²¶Ë 
				}
				mode += k;
			}
		}
		//cout<<endl<<"tr "<<next[0]<<" "<<s[next[0]];
		int pos=0;
		while(1){
			if(!s[pos]) {pos = next[pos]; continue;}
			cout<<s[pos];
			if(next[pos] == -1) break;
			pos = next[pos];
		}
		cout<<endl;
		s0.clear();
		s.clear();
		next.clear();
	}
}
