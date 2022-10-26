#include <iostream>
#include <cstdio>
#include <windows.h>
#include <cstring>
#include <conio.h>
#include <string>
//#define MAP_SIZE 27
using namespace std;
const int MAP_SIZE = 27;

bool pdlogin=0;
char name1[6],name2[6],check[1005],winner[6]; 
char map[MAP_SIZE][MAP_SIZE];  //���̴�С n*n
int x1=(MAP_SIZE-1)/2, y1=(MAP_SIZE-1)/2,x2=(MAP_SIZE-1)/2, y2=(MAP_SIZE-1)/2; //����λ��  int(n/2)
int player=0;
int toward[4][2]={{0,-1},{-1,-1},{-1,0},{-1,1}};

void clear_map(){
	for(int i=0;i<MAP_SIZE;i++){  //���̴�С i<n,j<n 
		for(int j=0;j<MAP_SIZE;j++){
			map[i][j]='_';
		}
	}
	int x1=(MAP_SIZE-1)/2, y1=(MAP_SIZE-1)/2,x2=(MAP_SIZE-1)/2, y2=(MAP_SIZE-1)/2;  //��������λ��  int(n/2)
	int player=0;
}

void ShowMap(int yh){
	system("cls");
	//ClearScreen();
	for(int i=0;i<MAP_SIZE;i++){   //���̴�С i<n,j<n
		for(int j=0;j<MAP_SIZE;j++){
			if(yh==1&&i==y1&&j==x1){
				cout<<"#"<<" ";
				continue;
			}
			if(yh==0&&i==y2&&j==x2){
				cout<<"*"<<" ";
				continue;
			}
			cout<<map[i][j]<<" ";
		}
		cout<<endl;
	}
}

void turn(int yh){
	int tf=1,pd=1;
	ShowMap(yh);
	if(yh==1){
		printf("���û�%s���壺\n",name1);
		while(tf){
			int move=getch();
			if(move=='w'&&(y1-1)>=0){
				y1--;
				ShowMap(yh);
			}
			if(move=='a'&&(x1-1)>=0){
				x1--;
				ShowMap(yh);
			}
			if(move=='s'&&(y1+1)<=MAP_SIZE-1){  //���̱߽� <=n-1
				y1++;
				ShowMap(yh);
			}
			if(move=='d'&&(x1+1)<=MAP_SIZE-1){
				x1++;
				ShowMap(yh);
			}
			if(map[y1][x1]!='_'){pd=0;}
			if(map[y1][x1]=='_'){pd=1;}
			if(pd==1&&move==13){
				map[y1][x1]='#';
				cout<<endl<<"���ѱ�����"<<endl;
				printf("�û�%s�������������\n",name1);
				tf=0;
			}
		}
	}
	if(yh==0){
		printf("���û�%s���壺\n",name2);
		while(tf){
			int move=getch();
			if(move=='w'&&(y2-1)>=0){
				y2--;
				ShowMap(yh);
			}
			if(move=='a'&&(x2-1)>=0){
				x2--;
				ShowMap(yh);
			}
			if(move=='s'&&(y2+1)<=MAP_SIZE-1){  //���̱߽� <=n-1
				y2++;
				ShowMap(yh);
			}
			if(move=='d'&&(x2+1)<=MAP_SIZE-1){
				x2++;
				ShowMap(yh);
			}
			if(map[y2][x2]!='_'){pd=0;}
			if(map[y2][x2]=='_'){pd=1;}
			if(pd==1&&move==13){
				map[y2][x2]='*';
				cout<<endl<<"���ѱ�����"<<endl;
				printf("�û�%s�������������\n",name2);
				tf=0;
			}
		}
	}
} 

bool scan_map(int yh){
	int x,y;
	char shuzu[10],zf;
	if(yh==1){
		x=x1;
		y=y1;
		zf='#';
	}
	else{
		x=x2;
		y=y2;
		zf='*';
	}
	for(int i=0;i<4;i++){
		memset(shuzu,0,10);
		for(int j=-4;j<=4;j++){
			int a=x+j*toward[i][0];
			int b=y+j*toward[i][1];
			shuzu[j+4]=map[b][a];
		}
		//cout<<endl<<i<<" ";
		//for(int m=0;m<9;m++) cout<<shuzu[m];
		//getch();
		int count=0;
		for(int k=0;k<9;k++){
			if(count==5){
				return TRUE;
			}
			if(shuzu[k]==zf) count++;
			else count=0;
			//cout<<endl<<count;
			//etch();
		}
		if(count==5) return TRUE;
	}
	return FALSE;
}

void login(){
	system("cls");
	cout<<"          ������ ע�� ������"<<endl<<"         �����1�����ǳ�(6���ַ�����)��"<<endl<<"          ";
	cin>>name1;
	gets(check);
	system("cls");
	cout<<"          ������ ע�� ������"<<endl<<"         �����2�����ǳ�(6���ַ�����)��"<<endl<<"          ";
	cin>>name2;
	gets(check);
	Sleep(800);
	system("cls");
	cout<<"          ע����ɣ�����"<<endl;
	pdlogin=TRUE;
}

void ShowMenu(int loc){
	char point[]="<-";
	system("cls");
	for(int i=0;i<3;i++){
		cout<<endl;
		for(int j=0;j<10;j++) cout<<" ";
		switch (i){
			case 0:cout<<"��������ʼ��Ϸ������";break;
			case 1:cout<<"���������ڡ���������";break;
			case 2:cout<<"�������˳�����������";break;
		}
		if(i==loc) printf(" %s",point);
	}
}

void menu(){	
	int local=0,pdlocal=1;
	ShowMenu(local);
	while(pdlocal){
		int getlocal=getch();
		if(getlocal=='w'&&local>0){
			local--;
			ShowMenu(local);
		}
		if(getlocal=='s'&&local<2){
			local++;
			ShowMenu(local);
		}
		if(getlocal==13){
			pdlocal=0;
		} 
	}
	system("cls");
	switch (local){
		case 0:{
			if(pdlogin==FALSE) login();
			clear_map();
			system("cls");
			cout<<"˵����#Ϊ���1����"<<endl<<"   *Ϊ���2����"<<endl<<"�����������������"<<endl;
			getch();
			cout<<"          ��Ϸ��ʼ������"<<endl;
			Sleep(1000);
			while(!scan_map(player)){
				player=!player;
				turn(player);
			}
			if(player==1) strcpy(winner,name1);
			else strcpy(winner,name2);
			Sleep(1500); 
			cout<<endl;
			printf("       ��ϲ%s��ʤ������\n�����������������",winner);
			getch();
			menu(); 
			break;
		}
		case 1:{
			cout<<endl<<"          ������Made By Kiriyan������"<<endl;
			Sleep(1000);
			cout<<"          ��������˳���������"<<endl;
			getch();
			menu();			
			break;
		}
		case 2:{
			cout<<"�����˳�������"; 
			Sleep(800);
			exit(0);
			break;
		}
	}
}

int main(){
	clear_map();
	cout<<endl<<"              ��ӭ�������������壡"<<endl;
	//int select=menu();
	Sleep(1000);
	menu();
} 
