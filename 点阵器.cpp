#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <windows.h>
#define MAX_SIZE 1000
using namespace std;
string dzt[MAX_SIZE][MAX_SIZE];
char zf;
int a,b,c;//a*a�Ĵ�С��b֡��,c���ʱ�� 

void pointdraw()
{
	for(int i=0;i<b;i++){
		printf("�����%d֡\n",i+1);
		for(int j=0;j<a;j++){
			cin>>dzt[i][j];
		}
		cout<<endl;
	}
}
void printdraw(){
	for(int i=0;i<b;i++){
		for(int j=0;j<a;j++){
			for(int k=0;k<a;k++){
				if(dzt[i][j][k]=='0') cout<<" ";
				if(dzt[i][j][k]=='1') cout<<zf;
				//else cout<<" ";
				cout<<" ";
			}
			cout<<endl;
		}
		Sleep(c*1000);
		system("cls");
	}
}

int main(){
	printf("����a*a�Ĵ�С��b֡��,c���ʱ�䣺\n");
	cin>>a>>b>>c;
	printf("�����ַ�:\n");
	cin>>zf;
	pointdraw();
	Sleep(1000);
	system("cls");
	printdraw();
} 
