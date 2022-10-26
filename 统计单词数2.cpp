#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int mystrlen(const char *p){
	int a=0;
	while(p[a]){
		a++;
	}
	return a;
} 

int mysff(const int *p){
	int a=0;
	while(p[a]){
		a++;
	}
	return a;
}

void mystrlwr(char *p){
	//char q[sizeof(p)];
	int i=0;
	while(p[i]){
		if(p[i]>=65&&p[i]<=92){
//			q[i]=(char)(p[i]+32);
			p[i]+=32;
		}
//		else{
//			q[i]=p[i];
//		}
		i++;
	}
} 

int main(){
	int size1,size2;
	int add=-1;
	int adc=-1;
	int store[1000000];
	char sent[1000000];
	char word[50],word1[50];
	int count=0;
	cin.getline(word,50);
	cin.getline(sent,1000000);
	mystrlwr(word);
	mystrlwr(sent);
	size1=mystrlen(word);
	size2=mystrlen(sent);
	for(int i=0;i<size2;i++){
		if(sent[i]==0){
			adc++;
			store[adc]=i;
		}
	}
	for(int j=0;j<mysff(store);j++){
		cout<<store[j]<<" ";
	}
	getchar();
	getchar();
	for(int i=0;i<size2-size1+1;i++){
		for(int j=0;j<size1;j++){
			word1[j]=sent[i+j];
		}
		if(!strcmp(word1,word)){
			if(add==-1) add=i;
			count++;
		}
		else continue;
	}
	if(add==-1) cout<<add;
	else cout<<count<<" "<<add<<endl;
	return 0;
} 
