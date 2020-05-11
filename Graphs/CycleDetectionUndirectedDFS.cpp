#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

class graph{
	vector<int> *adjlist;
	int N;
public:
	graph(int n){
		N = n;
		adjlist = new vector<int>[N];
	}

	void addedge(int u, int v, bool bidir=true){
		adjlist[u].push_back(v);
		if(bidir){
			adjlist[v].push_back(u);
		}
	}
	bool cycle_helper(int node, bool *visited, int parent){
		visited[node] = true;
		for(auto nbr:adjlist[node]){
			if(!visited[nbr]){
				bool cycle = cycle_helper(nbr,visited,node);
				if(cycle){
					return true;
				}
			}
			else if(nbr!=parent){
				return true;
			}
		}
		return false;
	}

	bool contains_cycle(){
		bool *visited = new bool[N];
		for(int i=0;i<N;i++){
			visited[i] = false;
		}
		return cycle_helper(0,visited,-1);
	}
};

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,e;
		cin>>n>>e;
		graph g(n);
		for(int i=0;i<e;i++){
			int u,v;
			cin>>u>>v;
			g.addedge(u,v);
		}
		cout<<g.contains_cycle()<<endl;
	}
}