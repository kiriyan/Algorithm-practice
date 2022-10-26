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

//方法一：用数组将整棵树存下来(非密集，会超) 
//README!!! 因为不小心看错题了 就按中间没空格的输入来写了 ps:我写的第一个版本 
struct node{
	int shu;
	queue<char> yidon; //移动序列 
	//node(int shu){this->shu = shu;}
};
node Nod[257];
int Tree[1<<maxd];

bool pd_link(int nod){ //判断节点是否相连 
	if(!Tree[nod]) return false;
	if(nod == 1) return true;
	nod = nod % 2 ? (nod-1)/2 : nod/2;
	pd_link(nod);
} 

int main(){
	freopen("树的层次遍历.in", "r", stdin);
	int du = 0, shu, count = 0; //默认读取=0 
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
//方法二：用指针建树 (密集)
//节点类型 
struct Node{
	bool have_value; //是否被赋值过
	int v; //节点值
	Node *left, *right;
	Node():have_value(false), left(NULL), right(NULL){} //构造函数 
};
Node *root; //二叉树的根节点
//由于二叉树是递归定义的，其左右子节点类型都是"指向节点类型的指针"
//即 如果节点类型为Node, 则左右子节点的类型都是Node*
//每次需要一个新的Node时，都要用new运算符申请内存,并执行构造函数，下面将此封装 
Node *newnode(){return new Node();}

void addnode(int v, char *s){
	int n = strlen(s);
	Node *u = root; //从根节点开始往下走
	for(int i=0;i<n;i++){
		if(s[i] == 'L'){
			if(u->left == NULL) u->left = newnode();
			u = u->left; //往左走 
		}
		else if(s[i] == 'R'){
			if(u->right == NULL) u->right = newnode();
			u = u->right; //往右走 
		}
	}
	if(u->have_value) failed = true;
	u->v = v; //赋值 
	u->have_value = true; //标记  
}

bool read_input(){
	failed = false;
	root = newnode();
	for(;;){
		if(scanf("%s", s) != 1) return false;
		if(!strcmp(s, "()")) break;
		int v;
		sscanf(&s[1], "%d", &v); //sscanf 从s[1]开始读 
		addnode(v, strchr(s, ',')+1); 
		//strchr 返回从左往右第一个','的指针,+1即表示"LL)"(后面的内容) 
	}
	return true;
}

bool bfs(vector<int>& ans){
	queue<Node*> q;
	ans.clear();
	q.push(root); //初始时只有一个根结点 
	while(!q.empty()){
		Node *u = q.front(); q.pop();
		if(!u->have_value) return false; //有节点没有被赋值过,表明输入有误 
		ans.push_back(u->v); //增加到输出序列尾部 
		if(u->left != NULL) q.push(u->left); //把左子节点(如果有)放进队列 
		if(u->right != NULL) q.push(u->right); //把右子节点(如果有)放进队列 
	}
	return true; //输入正确 
}
//开始严谨（ 为了节省内存，将上一颗树删除 
void remove_tree(Node *u){
	if(u == NULL) return; //提前判断若本就为空则不删
	remove_tree(u->left); //递归释放左子树空间
	remove_tree(u->right); //递归释放右子树空间
	delete u; //调用u的析构函数并释放u节点本身的内存 
}

vector<int> output;

int main(){
	freopen("树的层次遍历(正常输入).in", "r", stdin);
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
//方法三：不用指针的版本 用四个数组建树(密集)，有点像双向链表 
//四个数组，分别存储左节点 右节点 节点值 是否有值 
const int root = 1;
int cnt; //用cnt计数器表示当前已存储的节点编号最大值 
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
	int u = root; //从根节点开始往下走
	for(int i=0;i<n;i++){
		if(s[i] == 'L'){
			if(le[u] == 0) le[u] = newnode();
			u = le[u]; //往左走 
		}
		else if(s[i] == 'R'){
			if(ri[u] == 0) ri[u] = newnode();
			u = ri[u]; //往右走 
		}
	}
	if(have_value[u]) failed = true; 
	V[u] = v; //赋值 
	have_value[u] = true; //标记 
}
vector<int> output;
bool bfs(vector<int>& ans){
	queue<int> q;
	ans.clear();
	q.push(root); //初始时只有一个根结点 
	while(!q.empty()){
		int u = q.front(); q.pop();
		if(!have_value[u]) return false; //有节点没有被赋值过,表明输入有误 
		ans.push_back(V[u]); //增加到输出序列尾部 
		if(le[u] != 0) q.push(le[u]); //把左子节点(如果有)放进队列 
		if(ri[u] != 0) q.push(ri[u]); //把右子节点(如果有)放进队列 
	}
	return true; //输入正确 
}

bool read_input(){
	failed = false;
	for(;;){
		if(scanf("%s", s) != 1) return false;
		if(!strcmp(s, "()")) break;
		int v;
		sscanf(&s[1], "%d", &v); //sscanf 从s[1]开始读 
		addnode(v, strchr(s, ',')+1); 
		//strchr 返回从左往右第一个','的指针,+1即表示"LL)"(后面的内容) 
	}
	return true;
}

int main(){
	freopen("树的层次遍历(正常输入).in", "r", stdin);
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
//扩展： 
//内存池操作：维护一个空闲列表来节省内存，大致思路就是把上一颗树的节点的地址存下来
//然后在新建树的时候用上一颗树节点的地址来新建(覆盖原有的树) 
queue<Node*> freenodes;
Node node[maxn];

void init_node(){
	for(int i=0;i<maxn;i++) freenodes.push(&node[i]);
}

Node *newnode(){
	Node *u = freenodes.front();
	u->left = u->right = NULL; u->have_value = false; //初始化 
	freenodes.pop();
	return u;
}

void deletenode(Node *u){
	freenodes.push(u);
}
*/

