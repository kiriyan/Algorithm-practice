#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
const int maxn = 200;
int shu[maxn][2], cou = 0;
vector<int> str1, str2;
void dfs(int st1, int en1, int st2, int en2, int s){
	//��ʼ������ ���������� ��ǰ�ڵ��ܺ� 
	if(st1 == en1){
		cou++; 
		//cout<<cou<<" ";
		shu[cou][0] = s+str1[st1];
		shu[cou][1] = str1[st1];
		return;
	} //�ݹ�߽� 
	int node = str2[en2];
	for(int i=st1;i<=en1;i++){
		if(str1[i] == node){
			if(i != st1) dfs(st1, i-1, st2, i-1-st1+st2, s+node);
			if(i != en1) dfs(i+1, en1, i-st1+st2, en2-1, s+node);
		}
	}
}

int chazhao(int n){
	int min = 1000000, leaf = 10000;
	for(int i=1;i<=n;i++){
		if(min == shu[i][0]) leaf = leaf < shu[i][1] ? leaf : shu[i][1];
		else if(min > shu[i][0]){
			min = shu[i][0];
			leaf = shu[i][1];
		} 
	}
	return leaf;
}

void clear_shu(int n){
	for(int i = 0;i <= n; i++) shu[i][0] = shu[i][1] = 0;
}

int main(){
	freopen("��(Uva548).in", "r", stdin);
	int shu, n = 0, len;
	string line;
	while(getline(cin, line)){
		n++;
		stringstream ss(line);
		if(n%2) while(ss >> shu) str1.push_back(shu);
		else{
			while(ss >> shu) str2.push_back(shu);
			len = str1.size();
			dfs(0, len-1, 0, len-1, 0);
			cout<<chazhao(cou)<<endl;
			clear_shu(cou);
			cou = 0;
			str1.clear(); str2.clear();
		}
	}
}


/*
//��Ȼ�Ҳ�֪��Ϊʲô��Ҫ������֮���ٱ���һ�Σ������ǰ���ͳ��һ�´���ɣ� 
//��������������ĵ�һ���ַ����Ǹ������ֻ��������������ҵ�������֪����������������
//�����ͺ�������ˡ����������ȰѶ������������(��o��) . z ZȻ����ִ��һ�εݹ������
//�ҵ����Ž� 

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

const int maxv = 10000 + 10; //Ȩֵ������ͬ����Ȩֵ����ż��� 
int n;
struct node{
	int in_order, post_order;
	int lch, rch;
	node(int in_order=0,int post_order=0,int lch=0,int rch=0){
		this->in_order = in_order;
		this->post_order = post_order;
		this->lch = lch;
		this->rch = rch;
	}
}Nodes[maxv];

bool read_list(node *a, int mode){  
	//������΢��һ�£���Ϊ�ĳ��˽ṹ��,mode1��in, mode2��post 
	string line;
	if(!getline(cin, line)) return false;
	stringstream ss(line);
	n = 0;
	int x;
	if(mode == 1) while(ss >> x) a[n++].in_order = x;
	if(mode == 2) while(ss >> x) a[n++].post_order = x;
	return n > 0;
}

//��in_order[L1..R1]��post_order[L2..R2]����һ�Ŷ��������������� 
int build(int L1, int R1, int L2, int R2){
	if(L1 > R1) return 0; //����
	int root = Nodes[R2].post_order;
	int p = L1;
	while(Nodes[p].in_order != root) p++;
	int cnt = p - L1; //���ӽڵ�ĸ��� 
	Nodes[root].lch = build(L1, p-1, L2, L2+cnt-1);
	Nodes[root].rch = build(p+1, R1, L2+cnt, R2-1);
	return root;
}

int best, best_sum; //ĿǰΪֹ�����Ž�Ͷ�Ӧ��Ȩֵ֮��

void dfs(int u, int sum){
	sum += u;
	if(!Nodes[u].lch && !Nodes[u].rch){
		//Ҷ��
		if(sum < best_sum || (sum == best_sum && u < best)){
			best = u;
			best_sum = sum;
		}
	}
	if(Nodes[u].lch) dfs(Nodes[u].lch, sum);
	if(Nodes[u].rch) dfs(Nodes[u].rch, sum);
} 

int main(){
	freopen("��(Uva548).in", "r", stdin);
	while(read_list(Nodes, 1)){
		read_list(Nodes, 2);
		build(0, n-1, 0, n-1);
		best_sum = 1000000000;
		dfs(Nodes[n-1].post_order, 0);
		cout<<best<<endl;
	}
	return 0;
} 
*/
