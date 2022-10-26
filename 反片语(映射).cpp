#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

set<string> dict, dict1, dict2;
map<string, string> words;

int main(){
	freopen("·´Æ¬Óï.in", "r", stdin);
	
	string s, s1, s2;
	while(cin >> s){
		if(s[0] == '#') break;
		for(int i=0;i<s.length();i++) s1.push_back(tolower(s[i]));
		words[s1] = s;
		dict.insert(s1);
		s1.clear();
	}
	for(set<string>::iterator it = dict.begin(); it != dict.end(); ++it){
		int cou = -1;
		for(set<string>::iterator it1 = it; it1 != dict.end(); ++it1){
			cou++;
			if(cou == 0) continue;
			s1 = *it;
			s2 = *it1;
			sort(&s1[0], &s1[0]+s1.length());
			sort(&s2[0], &s2[0]+s2.length());
			if(s1.compare(s2)==0){
				dict2.insert(*it);
				dict2.insert(*it1);
				break;
			} 
		}
	}
	for(set<string>::iterator it = dict2.begin(); it != dict2.end(); ++it){
		dict.erase(*it);
	}
	for(set<string>::iterator it = dict.begin(); it != dict.end(); ++it){
		dict1.insert(words[*it]);
	}
	for(set<string>::iterator it = dict1.begin(); it != dict1.end(); ++it){
		cout<<*it<<"\n";
	}
}
