#include <iostream>
#include <vector>
using namespace std;
typedef long long Ll;

struct BigInt{
	static const int BASE = 100000000;
	static const int WIDTH = 8;
	vector<int> s;
	
	BigInt(Ll num = 0){
		*this = num;
	}
	BigInt operator = (Ll num){
		s.clear();
		do{
			s.push_back(num % BASE);
			num /= BASE;
		}while(num > 0);
		return *this;
	} //第一种赋值方式： x = 70183189 直接将 Ll类型 赋值给 x 
	BigInt operator = (const string& str){
		s.clear();
		int x, len = (str.length() - 1) / WIDTH + 1;
		for(int i=0;i<len;i++){
			int end = str.length() - i*WIDTH;
			int start = max(0, end - WIDTH);
			sscanf(str.substr(start, end-start).c_str(), "%d", &x);
			s.push_back(x);
		}
		return *this;
	} //第二种赋值方式：x = "2444261316361535113513" 将 字符串 赋给x 
};

