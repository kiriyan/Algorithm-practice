#include <iostream>
using namespace std;
const int MAX_SIZE = 200000; 
typedef long long Ll;
Ll mat[100][100];

//虽然但是 最后还是超了（
//在计算过程中就要优化化简 
 
 
Ll combinat(int m, int n) {
    int i, j;
    if(n == 0 || m == n) return 1;  
    for(j = 0; j <= n; j++) { 
        mat[j][j] = 1;
        for(i = j+1; i <= m; i++) {
            if(j == 0)
                mat[i][j] = 1;
            else
                mat[i][j] = mat[i-1][j-1] + mat[i-1][j];
        } 
    }
    return mat[m][n];
}

Ll Fx(Ll x){
	Ll s1 = (x + 1) % 3;
	return (s1 - 1); 
}

int main(){
	int n, maxn;
	int shu[MAX_SIZE];
	cin>>n>>maxn;
	for(int i=0;i<n;i++) cin>>shu[i];
	
	//cout<<endl<<endl;
	
	int j = n;
	Ll s = 0, s1 = 0;
	for(int j=0;j<n;j++){
		for(int l=0;l<=shu[j];l++){
			s1 = 0;
			for(int r=l;r<=shu[j];r++){
				//cout<<combinat(r, l)<<" "<<Fx(combinat(r, l))<<endl;
				s1 += Fx(combinat(r, l));
			}
			s += s1;
		}
		s %= 1732073999;
		cout<<s<<endl;
		s = 0;
	}
} 
