#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

//kosaraju's algorithm

vector<int> g[300];
vector<int> grr[300];

void dfs(int node, vector<bool> &vis, vector<int> &order){
	vis[node] = true;
	for(auto nbr:g[node]){
		if(!vis[nbr]){
			dfs(nbr,vis,order);
		}
	}
	order.push_back(node);
}

void r_dfs(int node, int col, vector<bool> &vis, vector<int> &cmp){
	vis[node] = true;
	cmp[node] = col;
	for(auto nbr:grr[node]){
		if(!vis[nbr]){
			r_dfs(nbr,col,vis,cmp);
		}
	}
}

int main(){
	
	int n,x;
	cin>>n>>x;
	while(x--){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		grr[b].push_back(a);
	}
	vector<bool> vis(n,0);
	vector<int> order;
	for(int i=0;i<n;i++){
		if(!vis[i]){
			dfs(i,vis,order);
		}
	}
	for(int i=0;i<n;i++){
		vis[i] = false;
	}
	for(int i=0;i<n;i++){
		cout<<order[i]<<" ";
	}
	cout<<endl;
	int col = 0;
	vector<int> cmp(n,-1);
	for(int i=n-1;i>=0;i--){
		if(!vis[order[i]]){
			r_dfs(order[i],col,vis,cmp);
			col++;
		}
	}
	cout<<col<<endl;
	for(int i=0;i<n;i++){
		cout<<cmp[i]<<" ";
	}
	cout<<endl;
}
