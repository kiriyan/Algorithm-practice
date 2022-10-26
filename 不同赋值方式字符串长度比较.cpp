#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int p[8]={11,12,13,14,15,16,17,18};
	//for(int k=0;k<8;k++) p[k] = 10+k+1;
	int i=0,j=0;
	while(i++<7){
		if(p[i]%2) j+=p[i]; 
	}
	cout<<j;
}
