#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct posi{
	int size1=0;
	int add=-1;
}posi1;
int main(){
	int n=0;
	char word[20],word1[20];
	cin>>word;
	strlwr(word);
	int size=strlen(word);
	while(scanf("%s",&word1)==1){
		int x=strlen(word1);
		int c=0;
		if(x>=size){
			strlwr(word1);
			if(!strcmp(word1,word)){
				n++;
				c++;
				if(posi1.add==-1) posi1.add=posi1.size1;
			}
		}
		if(x<size||c==0){
			posi1.size1+=x;
			posi1.size1++;
		}
		char word1[20];
	}
	if(posi1.add==-1) cout<<n;
	else cout<<n<<" "<<posi1.add;
}
