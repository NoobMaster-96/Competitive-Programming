#include<bits/stdc++.h>
using namespace std;

class graph{
	vector<int> *adjlist;
	int N;
public:
	vector<bool> visited;
	graph(int n){
		N = n;
		adjlist = new vector<int>[N];
		visited = vector<bool>(N,false);
	}

	void addedge(int u, int v, bool bidir=true){
		adjlist[u].push_back(v);
		if(bidir){
			adjlist[v].push_back(u);
		}
	}
	
	void dfs(int source, int goal){
		visited[source] = true;
		cout<<source<<"->";
		if(source==goal){
			return;
		}
		for(auto nbr:adjlist[source]){
			if(!visited[nbr]){
				dfs(nbr,goal);
			}
		}
	}

	void bfs(int source, int goal){
		queue<int> q;
		q.push(source);
		visited[source] = true;
		while(!q.empty()){
			int node = q.front();
			cout<<node<<" ";
			q.pop();
			for(auto nbr:adjlist[node]){
				if(!visited[nbr]){
					q.push(nbr);
					visited[nbr] = true;
				}
			}
		}
	}
};

int main(){
	int V=6;
	graph g(6);
	g.addedge(1,0);
	g.addedge(1,2);
	g.addedge(2,3);
	g.addedge(2,4);
	g.addedge(3,5);
	g.addedge(3,4);
	g.addedge(4,0);
	for(int i=0;i<V;i++){
		g.visited[i] = false;
	}
	g.bfs(0,3);
	
	return 0;
}