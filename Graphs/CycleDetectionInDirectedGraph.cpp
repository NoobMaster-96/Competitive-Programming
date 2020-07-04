#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int n,e;
vector<int> g[300];

bool helper(int node, vector<bool> &vis, vector<bool> &s){
	vis[node] = true;
	s[node] = true;
	for(auto nbr:g[node]){
		if(s[nbr]){
			return true;
		}
		else if(!vis[nbr]){
			bool ans = helper(nbr,vis,s);
			if(ans){
				return true;
			}
		}
	}
	s[node] = false;
	return false;
}

bool containsCycle(){
	vector<bool> vis(n,false);
	vector<bool> s(n,false);
	return helper(0,vis,s);
}

int main(){
	cin>>n>>e;
	for(int i=0;i<e;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
	}
	cout<<containsCycle()<<endl;
}