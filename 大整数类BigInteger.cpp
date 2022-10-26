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
	} //��һ�ָ�ֵ��ʽ�� x = 70183189 ֱ�ӽ� Ll���� ��ֵ�� x 
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
	} //�ڶ��ָ�ֵ��ʽ��x = "2444261316361535113513" �� �ַ��� ����x 
};

