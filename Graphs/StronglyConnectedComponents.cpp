#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

//kosaraju's algorithm

class graph{
	int N;
	vector<int> *adjlist;

public:
	graph(int n){
		adjlist = new vector<int>[n];
		N = n;
	}

	void addedge(int u, int v, bool bidir=false){
		adjlist[u].push_back(v);
		if(bidir){
			adjlist[v].push_back(u);
		}
	}

	void print(){
		for(int i=0;i<N;i++){
			cout<<i<<"->";
			for(auto entry:adjlist[i]){
				cout<<entry<<" ";
			}
			cout<<endl;
		}
	}

	void dfs(int node, vector<int> adjlist, vector<int> &ordering, vector<bool> &visited){
		visited[node] = true;
		for(auto nbr:adjlist[node]){
			if(!visited[nbr]){
				dfs(nbr,ordering,visited);
			}
		}
		ordering.push_back(node);
	}

	void reverse_dfs(int node, int col, vector<int> &cmp, vector<bool> &visited){
		visited[node] = true;
		for(auto nbr:radjlist[node]){
			if(!visited[nbr]){
				dfs(nbr,ordering,visited);
			}
		}
	}

	int kosaraju(int n){
		vector<int> radjlist[n];
		vector<int> order;
		vector<bool> vis(n,0);
		vector<int> cmp(n,0);
		for(int i=0;i<n;i++){
			for(auto j:adjlist[i]){
				radjlist[j].push_back(i);
			}
		}
		for(int i=0;i<n;i++){
			if(!vis[i]){
				dfs(i,order,vis);
			}
		}
		for(int i=0;i<n;i++){
			vis[i] = false;
		}

	}

};

int main(){
	int n;
	cin>>n;
	graph g(n);
	int e;
	cin>>e;
	while(e--){
		int u,v;
		cin>>u>>v;
		g.addedge(u,v);
	}
	cout<<g.kosaraju(0)<<endl;
}
