#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
using namespace std;
const int maxn = 257;
const int maxd = 25;
bool failed;
char s[maxn];

//����һ�������齫������������(���ܼ����ᳬ) 
//README!!! ��Ϊ��С�Ŀ������� �Ͱ��м�û�ո��������д�� ps:��д�ĵ�һ���汾 
struct node{
	int shu;
	queue<char> yidon; //�ƶ����� 
	//node(int shu){this->shu = shu;}
};
node Nod[257];
int Tree[1<<maxd];

bool pd_link(int nod){ //�жϽڵ��Ƿ����� 
	if(!Tree[nod]) return false;
	if(nod == 1) return true;
	nod = nod % 2 ? (nod-1)/2 : nod/2;
	pd_link(nod);
} 

int main(){
	freopen("���Ĳ�α���.in", "r", stdin);
	int du = 0, shu, count = 0; //Ĭ�϶�ȡ=0 
	string line, s;
	while(getline(cin, line)){
		memset(Tree, 0, sizeof(Tree));
		du = 0; s.clear(); count = 0;
		for(int i=0;i<line.length();i++){
			if(line[i] == '(' && line[i+1] == ')') break;
			if(line[i] == '('){du = 1; count++;continue;}
			if(line[i] == ')'){du = 0; s.clear();}
			if(!du) continue;
			else{
				if(line[i] == ','){
					stringstream ss(s);
					ss >> shu;
					//cout<<"*"<<s<<endl;
					Nod[count].shu = shu;
					du = 2; 
					continue;
				}
				if(du == 1){s.append(1, line[i]);} 
				else if(du == 2){Nod[count].yidon.push(line[i]);}
			}
		}
		int bh = 1, pd = 1, max = 1;
		for(int i=1;i<=count;i++){
			while(!Nod[i].yidon.empty()){
				if(Nod[i].yidon.front() == 'L') bh = bh * 2;
				else if(Nod[i].yidon.front() == 'R') bh = bh * 2 + 1;
				//cout<<bh<<" ";
				Nod[i].yidon.pop();
			}
			//cout<<endl;
			if(Tree[bh]){pd = 0; break;}
			Tree[bh] = Nod[i].shu;
			max = max > bh ? max : bh;
			bh = 1;
		}
		if(!pd) cout<<"-1";
		else{
			for(int i=2;i<=max;i++){
				if(Tree[i] != 0 && !pd_link(i)){
					pd = 0; 
					break;
				}
			}
			if(!pd) cout<<"-1";
			else{
				for(int i=1;i<=max;i++) if(Tree[i] != 0) cout<<Tree[i]<<" ";
			}
		}
		cout<<endl;
		node Nod[257];
	}
}



/*
//����������ָ�뽨�� (�ܼ�)
//�ڵ����� 
struct Node{
	bool have_value; //�Ƿ񱻸�ֵ��
	int v; //�ڵ�ֵ
	Node *left, *right;
	Node():have_value(false), left(NULL), right(NULL){} //���캯�� 
};
Node *root; //�������ĸ��ڵ�
//���ڶ������ǵݹ鶨��ģ��������ӽڵ����Ͷ���"ָ��ڵ����͵�ָ��"
//�� ����ڵ�����ΪNode, �������ӽڵ�����Ͷ���Node*
//ÿ����Ҫһ���µ�Nodeʱ����Ҫ��new����������ڴ�,��ִ�й��캯�������潫�˷�װ 
Node *newnode(){return new Node();}

void addnode(int v, char *s){
	int n = strlen(s);
	Node *u = root; //�Ӹ��ڵ㿪ʼ������
	for(int i=0;i<n;i++){
		if(s[i] == 'L'){
			if(u->left == NULL) u->left = newnode();
			u = u->left; //������ 
		}
		else if(s[i] == 'R'){
			if(u->right == NULL) u->right = newnode();
			u = u->right; //������ 
		}
	}
	if(u->have_value) failed = true;
	u->v = v; //��ֵ 
	u->have_value = true; //���  
}

bool read_input(){
	failed = false;
	root = newnode();
	for(;;){
		if(scanf("%s", s) != 1) return false;
		if(!strcmp(s, "()")) break;
		int v;
		sscanf(&s[1], "%d", &v); //sscanf ��s[1]��ʼ�� 
		addnode(v, strchr(s, ',')+1); 
		//strchr ���ش������ҵ�һ��','��ָ��,+1����ʾ"LL)"(���������) 
	}
	return true;
}

bool bfs(vector<int>& ans){
	queue<Node*> q;
	ans.clear();
	q.push(root); //��ʼʱֻ��һ������� 
	while(!q.empty()){
		Node *u = q.front(); q.pop();
		if(!u->have_value) return false; //�нڵ�û�б���ֵ��,������������ 
		ans.push_back(u->v); //���ӵ��������β�� 
		if(u->left != NULL) q.push(u->left); //�����ӽڵ�(�����)�Ž����� 
		if(u->right != NULL) q.push(u->right); //�����ӽڵ�(�����)�Ž����� 
	}
	return true; //������ȷ 
}
//��ʼ�Ͻ��� Ϊ�˽�ʡ�ڴ棬����һ����ɾ�� 
void remove_tree(Node *u){
	if(u == NULL) return; //��ǰ�ж�������Ϊ����ɾ
	remove_tree(u->left); //�ݹ��ͷ��������ռ�
	remove_tree(u->right); //�ݹ��ͷ��������ռ�
	delete u; //����u�������������ͷ�u�ڵ㱾����ڴ� 
}

vector<int> output;

int main(){
	freopen("���Ĳ�α���(��������).in", "r", stdin);
	while(read_input()){
		if(bfs(output) == true && failed == false){
			for(vector<int>::iterator it = output.begin(); it != output.end(); ++it){
				cout<<*it<<" ";
			}
		}
		else cout<<-1<<endl;
		cout<<endl;
		remove_tree(root);
		output.clear();
	}
}
*/

/*
//������������ָ��İ汾 ���ĸ����齨��(�ܼ�)���е���˫������ 
//�ĸ����飬�ֱ�洢��ڵ� �ҽڵ� �ڵ�ֵ �Ƿ���ֵ 
const int root = 1;
int cnt; //��cnt��������ʾ��ǰ�Ѵ洢�Ľڵ������ֵ 
int le[maxn], ri[maxn], V[maxn];
bool have_value[maxn];
void newtree(){
	le[root] = ri[root] = 0;
	have_value[root] = false;
	cnt = root;
}
int newnode(){
	int u = ++cnt;
	le[u] = ri[u] = 0;
	have_value[u] = false;
	return u;
}
void addnode(int v, char *s){
	int n = strlen(s);
	int u = root; //�Ӹ��ڵ㿪ʼ������
	for(int i=0;i<n;i++){
		if(s[i] == 'L'){
			if(le[u] == 0) le[u] = newnode();
			u = le[u]; //������ 
		}
		else if(s[i] == 'R'){
			if(ri[u] == 0) ri[u] = newnode();
			u = ri[u]; //������ 
		}
	}
	if(have_value[u]) failed = true; 
	V[u] = v; //��ֵ 
	have_value[u] = true; //��� 
}
vector<int> output;
bool bfs(vector<int>& ans){
	queue<int> q;
	ans.clear();
	q.push(root); //��ʼʱֻ��һ������� 
	while(!q.empty()){
		int u = q.front(); q.pop();
		if(!have_value[u]) return false; //�нڵ�û�б���ֵ��,������������ 
		ans.push_back(V[u]); //���ӵ��������β�� 
		if(le[u] != 0) q.push(le[u]); //�����ӽڵ�(�����)�Ž����� 
		if(ri[u] != 0) q.push(ri[u]); //�����ӽڵ�(�����)�Ž����� 
	}
	return true; //������ȷ 
}

bool read_input(){
	failed = false;
	for(;;){
		if(scanf("%s", s) != 1) return false;
		if(!strcmp(s, "()")) break;
		int v;
		sscanf(&s[1], "%d", &v); //sscanf ��s[1]��ʼ�� 
		addnode(v, strchr(s, ',')+1); 
		//strchr ���ش������ҵ�һ��','��ָ��,+1����ʾ"LL)"(���������) 
	}
	return true;
}

int main(){
	freopen("���Ĳ�α���(��������).in", "r", stdin);
	newtree();
	while(read_input()){
		if(bfs(output) == true && failed == false){
			for(vector<int>::iterator it = output.begin(); it != output.end(); ++it){
				cout<<*it<<" ";
			}
		}
		else cout<<-1<<endl;
		cout<<endl;
		memset(le, 0, maxn); memset(ri, 0, maxn); memset(V, 0, maxn);
		memset(have_value, 0, maxn);
		newtree();
		output.clear();
	}
}
*/

/*
//��չ�� 
//�ڴ�ز�����ά��һ�������б�����ʡ�ڴ棬����˼·���ǰ���һ�����Ľڵ�ĵ�ַ������
//Ȼ�����½�����ʱ������һ�����ڵ�ĵ�ַ���½�(����ԭ�е���) 
queue<Node*> freenodes;
Node node[maxn];

void init_node(){
	for(int i=0;i<maxn;i++) freenodes.push(&node[i]);
}

Node *newnode(){
	Node *u = freenodes.front();
	u->left = u->right = NULL; u->have_value = false; //��ʼ�� 
	freenodes.pop();
	return u;
}

void deletenode(Node *u){
	freenodes.push(u);
}
*/

