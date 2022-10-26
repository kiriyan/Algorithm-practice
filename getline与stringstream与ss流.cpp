#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
	string line;
	while(getline(cin, line)){
		int sum = 0, x;
		stringstream ss(line);  //stringstream 创建字符串流（从line读取） 
		while(ss >> x) sum += x; // string 很慢  sstring更慢 --->谨慎使用 
		cout<<sum<<"\n";
	}
	return 0;
}
