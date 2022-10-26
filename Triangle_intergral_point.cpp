#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
 
float suank(float a,float b,float c,float d){
	float k1 = (d-b)/(c-a);
	return k1;
}
float suanb(float a,float b,float c,float d){
	float k1 = (d-b)/(c-a);
	float b1 = b - k1 * a;
	return b1;
}

int main(){
	float kb[3][2];
	float xy[3][2];
	float x1,y1,x2,y2,x3,y3;
	int v = 0;
	int n = 0;
	int m = 0;
	int k = 0;
	int pd = 1;
	int count = 0;
	float point[500][2];
	cout<<"请输入三个点的横纵坐标："<<endl;
	while(v < 3){
		scanf("%f %f",&xy[v][0],&xy[v][1]);
		if(xy[v][1] > xy[n][1]){
			n = v;
		}
		if(xy[v][1] < xy[m][1]){
			m = v;
		}
		v++;
	}
	x1 = xy[n][0];
	y1 = xy[n][1];
	x3 = xy[m][0];
	y3 = xy[m][1];

	for(int i=0;i<3;i++){
		if(i==m || i==n){
			continue;
		}
		k = i;
	}
	x2 = xy[k][0];
	y2 = xy[k][1];
	kb[0][0]=suank(x1,y1,x2,y2);
	kb[0][1]=suanb(x1,y1,x2,y2);
	kb[1][0]=suank(x1,y1,x3,y3);
	kb[1][1]=suanb(x1,y1,x3,y3);
	kb[2][0]=suank(x2,y2,x3,y3);
	kb[2][1]=suanb(x2,y2,x3,y3);
	

	float y_max = floor(y1);
	float y_mid1 = ceil(y2);
	float y_mid2 = floor(y2);
	float y_min = ceil(y3);
	float j = y_max;
	float x_min,x_max;
	//cout<<y_max<<" "<<y_mid1<<" "<<y_mid2<<" "<<y_min<<endl;
	
	while(j >= y_mid1){
		float xm1 = (j-kb[0][1])/kb[0][0];
		float xm2 = (j-kb[1][1])/kb[1][0];
		if(xm1 > xm2){
			x_max = floor(xm1);
			x_min = ceil(xm2);
		}
		else{
			x_max = floor(xm2);
			x_min = ceil(xm1);
		}
		for(float i=x_min;i<=x_max;i++){
			point[count][0]=i;
			point[count][1]=j;
			count++;
		}
		j--;
	}
	j = y_mid2;
	if(y_mid1 == y_mid2){
		j = y_mid2 - 1;
	}
	while(j >= y_min){
		float xm1 = (j-kb[1][1])/kb[1][0];
		float xm2 = (j-kb[2][1])/kb[2][0];
		if(xm1 > xm2){
			x_max = floor(xm1);
			x_min = ceil(xm2);
		}
		else{
			x_max = floor(xm2);
			x_min = ceil(xm1);
		}
		for(float i=x_min;i<=x_max;i++){
			point[count][0]=i;
			point[count][1]=j;
			count++;
		}
		j--;
	}
	cout<<"三角形内共有整数点："<<count<<"个"<<endl;
	for(int i=0;i<count;i++){
		cout<<point[i][0]<<" "<<point[i][1]<<endl;
	} 

}
